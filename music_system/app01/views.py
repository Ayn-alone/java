from django.shortcuts import render, redirect


# Create your views here.

# 函数-html
def login(request):
    if request.method == "GET":
        return render(request, "login.html")


from django.http import JsonResponse
from app01.utils.db import DB
import hashlib  # 密码加密


def sign_up(request):
    if request.method == "GET":
        return render(request, "sign_up.html")

    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')

        # 密码加密（MD5示例，实际建议用更安全的方式如bcrypt）
        encrypted_pwd = hashlib.md5(password.encode()).hexdigest()

        # 检查用户名是否已存在
        sql_check = "SELECT * FROM user WHERE username = %s"
        if DB.fetchone(sql_check, [username]):
            return JsonResponse({'code': 0, 'msg': 'username already exists'})

        # 插入新用户
        sql_insert = """
            INSERT INTO user (username, password) 
            VALUES (%s, %s)
        """
        rowcount = DB.execute(sql_insert, [username, encrypted_pwd])
        if rowcount > 0:
            return redirect('/login/')
        else:
            return JsonResponse({'code': 0, 'msg': 'failed'})


import hashlib
from django.http import JsonResponse
from django.shortcuts import render
from .utils.db import DB  # 导入你的原生SQL工具类


def login(request):
    # 1. GET请求：返回登录页面
    if request.method == 'GET':
        return render(request, 'login.html')  # 对应前端login.html模板

    # 2. POST请求：处理登录逻辑
    elif request.method == 'POST':
        # 获取前端表单数据（name属性需和前端一致）
        username = request.POST.get('username', '').strip()
        password = request.POST.get('password', '').strip()

        # 3. 参数校验（非空）
        if not username:
            return JsonResponse({'code': 0, 'msg': '用户名不能为空'}, json_dumps_params={'ensure_ascii': False})
        if not password:
            return JsonResponse({'code': 0, 'msg': '密码不能为空'}, json_dumps_params={'ensure_ascii': False})

        # 4. 密码加密（和注册时的加密方式一致：MD5）
        encrypted_pwd = hashlib.md5(password.encode()).hexdigest()

        # 5. 原生SQL查询：验证用户名和密码是否匹配
        sql = """
            SELECT user_id, username 
            FROM user 
            WHERE username = %s AND password = %s
        """
        user = DB.fetchone(sql, [username, encrypted_pwd])

        # 6. 登录结果判断
        if user:
            # 登录成功：将用户ID存入Session（用于后续身份验证，如收藏、评论）
            request.session['user_id'] = user['user_id']
            request.session['username'] = user['username']  # 可选：存储用户名，前端显示
            return redirect("/home/")
        else:
            # 登录失败：用户名或密码错误
            return JsonResponse({'code': 0, 'msg': '用户名或密码错误'}, json_dumps_params={'ensure_ascii': False})


def home(request):
    # 1. 获取当前登录用户ID（从Session中取，未登录则为None）
    current_user_id = request.session.get('user_id')

    # 2. 原生SQL：查询所有歌手 + 统计关注量（按关注量降序）
    # 逻辑：LEFT JOIN 关联关注表，COUNT统计关注次数，GROUP BY歌手分组
    sql = """
        SELECT 
            s.singer_id,
            s.singer_name,
            s.region,
            s.age,
            s.intro,
            s.singer_photo,
            COUNT(f.user_id) AS follow_count  -- 统计关注量
        FROM 
            singer s
        LEFT JOIN 
            user_follow_singer f ON s.singer_id = f.singer_id  -- 关联关注表
        GROUP BY 
            s.singer_id  -- 按歌手ID分组（确保每个歌手只显示一条）
        ORDER BY 
            follow_count DESC;  -- 按关注量降序排序
    """
    singers = DB.fetchall(sql)  # 获取所有歌手数据（带关注量）

    # 3. 给每个歌手添加“是否已被当前用户关注”的标识（登录后才判断）
    if current_user_id:
        for singer in singers:
            # 查询当前用户是否关注该歌手
            follow_sql = """
                SELECT 1 FROM user_follow_singer 
                WHERE user_id = %s AND singer_id = %s
            """
            is_followed = DB.fetchone(follow_sql, [current_user_id, singer['singer_id']]) is not None
            singer['is_followed'] = is_followed  # 新增字段：True=已关注，False=未关注
    else:
        # 未登录用户：所有歌手均为“未关注”
        for singer in singers:
            singer['is_followed'] = False

    # 4. 传递歌手数据到前端页面
    return render(request, 'home.html', {
        'singers': singers,
        'current_username': request.session.get('username')  # 传递当前用户名（用于页面显示）
    })


from django.http import JsonResponse


def follow_singer(request):
    # 1. 验证登录状态
    current_user_id = request.session.get('user_id')
    if not current_user_id:
        return JsonResponse({
            'code': 0,
            'msg': '请先登录'
        }, json_dumps_params={'ensure_ascii': False})

    # 2. 获取前端传递的歌手ID和操作类型（follow=关注，unfollow=取消关注）
    singer_id = request.POST.get('singer_id')
    action = request.POST.get('action')  # action值：'follow' 或 'unfollow'

    if not singer_id or action not in ['follow', 'unfollow']:
        return JsonResponse({
            'code': 0,
            'msg': '参数错误'
        }, json_dumps_params={'ensure_ascii': False})

    # 3. 执行关注/取消关注逻辑
    if action == 'follow':
        # 关注：插入数据到user_follow_singer表（避免重复关注）
        sql = """
            INSERT IGNORE INTO user_follow_singer (user_id, singer_id)
            VALUES (%s, %s)
        """
        rowcount = DB.execute(sql, [current_user_id, singer_id])
        if rowcount > 0:
            msg = '关注成功'
        else:
            msg = '已关注该歌手'
    else:
        # 取消关注：删除关联数据
        sql = """
            DELETE FROM user_follow_singer
            WHERE user_id = %s AND singer_id = %s
        """
        DB.execute(sql, [current_user_id, singer_id])
        msg = '取消关注成功'

    return JsonResponse({
        'code': 1,
        'msg': msg
    }, json_dumps_params={'ensure_ascii': False})


from django.shortcuts import render, redirect
from django.http import JsonResponse
from .utils.db import DB


def singer_detail(request, singer_id):
    """歌手主页：展示歌手信息、专辑列表、歌曲列表（按收藏量排序）"""
    # 1. 获取当前登录用户ID（用于判断是否已收藏专辑/歌曲）
    current_user_id = request.session.get('user_id')

    # 2. 查询歌手基础信息（通过singer_id精准查询）
    singer_sql = """
        SELECT singer_id, singer_name, region, age, intro, singer_photo 
        FROM singer 
        WHERE singer_id = %s
    """
    singer = DB.fetchone(singer_sql, [singer_id])
    if not singer:  # 歌手不存在则跳回首页
        return redirect('/home/')

    # 3. 查询该歌手的所有专辑（按发行时间降序）
    album_sql = """
        SELECT album_id, album_name, release_time, cover 
        FROM album 
        WHERE singer_id = %s
        ORDER BY release_time DESC
    """
    albums = DB.fetchall(album_sql, [singer_id])

    # 4. 给专辑添加“是否已被当前用户收藏”的标识
    if current_user_id:
        for album in albums:
            collect_sql = """
                SELECT 1 
                FROM user_collect_album 
                WHERE user_id = %s AND album_id = %s
            """
            album['is_collected'] = DB.fetchone(collect_sql, [current_user_id, album['album_id']]) is not None
    else:
        for album in albums:
            album['is_collected'] = False

    # 5. 查询该歌手的所有歌曲（按收藏量降序排序）
    # 逻辑：关联user_collect_song表，统计收藏次数，LEFT JOIN确保单曲也能显示
    song_sql = """
        SELECT 
            s.song_id,
            s.song_name,
            s.duration,
            s.album_id,
            s.language,
            s.style,
            a.album_name,  -- 关联专辑名（单曲则为NULL）
            COUNT(c.user_id) AS collect_count  -- 统计收藏量
        FROM 
            song s
        LEFT JOIN 
            user_collect_song c ON s.song_id = c.song_id
        LEFT JOIN 
            album a ON s.album_id = a.album_id  -- 关联专辑表，获取专辑名
        WHERE 
            s.singer_id = %s
        GROUP BY 
            s.song_id
        ORDER BY 
            collect_count DESC;  -- 按收藏量降序
    """
    songs = DB.fetchall(song_sql, [singer_id])

    # 6. 给歌曲添加“是否已被当前用户收藏”的标识
    if current_user_id:
        for song in songs:
            collect_sql = """
                SELECT 1 FROM user_collect_song 
                WHERE user_id = %s AND song_id = %s
            """
            song['is_collected'] = DB.fetchone(collect_sql, [current_user_id, song['song_id']]) is not None
    else:
        for song in songs:
            song['is_collected'] = False

    # 7. 处理歌曲时长（秒转成“分:秒”格式，如281秒→4:41）
    for song in songs:
        minutes = song['duration'] // 60
        seconds = song['duration'] % 60
        song['duration_str'] = f"{minutes}:{seconds:02d}"  # 补0，确保格式统一（如4:05而非4:5）

    # 8. 传递数据到前端
    return render(request, 'singer_detail.html', {
        'singer': singer,
        'albums': albums,
        'songs': songs,
        'current_username': request.session.get('username')
    })



def collect_album(request):
    """收藏/取消收藏专辑（异步接口）"""
    current_user_id = request.session.get('user_id')
    if not current_user_id:
        return JsonResponse({'code': 0, 'msg': '请先登录'}, json_dumps_params={'ensure_ascii': False})

    # 获取前端参数
    album_id = request.POST.get('album_id')
    action = request.POST.get('action')  # 'collect'=收藏，'cancel'=取消收藏

    if not album_id or action not in ['collect', 'cancel']:
        return JsonResponse({'code': 0, 'msg': '参数错误'}, json_dumps_params={'ensure_ascii': False})

    if action == 'collect':
        # 收藏：插入数据（IGNORE避免重复收藏）
        sql = """
            INSERT IGNORE INTO user_collect_album (user_id, album_id)
            VALUES (%s, %s)
        """
        rowcount = DB.execute(sql, [current_user_id, album_id])
        msg = '收藏成功' if rowcount > 0 else '已收藏该专辑'
    else:
        # 取消收藏：删除数据
        sql = """
            DELETE FROM user_collect_album
            WHERE user_id = %s AND album_id = %s
        """
        DB.execute(sql, [current_user_id, album_id])
        msg = '取消收藏成功'

    return JsonResponse({'code': 1, 'msg': msg}, json_dumps_params={'ensure_ascii': False})


def collect_song(request):
    """收藏/取消收藏歌曲（异步接口）"""
    current_user_id = request.session.get('user_id')
    if not current_user_id:
        return JsonResponse({'code': 0, 'msg': '请先登录'}, json_dumps_params={'ensure_ascii': False})

    # 获取前端参数
    song_id = request.POST.get('song_id')
    action = request.POST.get('action')  # 'collect'=收藏，'cancel'=取消收藏

    if not song_id or action not in ['collect', 'cancel']:
        return JsonResponse({'code': 0, 'msg': '参数错误'}, json_dumps_params={'ensure_ascii': False})

    if action == 'collect':
        # 收藏：插入数据（IGNORE避免重复收藏）
        sql = """
            INSERT IGNORE INTO user_collect_song (user_id, song_id)
            VALUES (%s, %s)
        """
        rowcount = DB.execute(sql, [current_user_id, song_id])
        msg = '收藏成功' if rowcount > 0 else '已收藏该歌曲'
    else:
        # 取消收藏：删除数据
        sql = """
            DELETE FROM user_collect_song
            WHERE user_id = %s AND song_id = %s
        """
        DB.execute(sql, [current_user_id, song_id])
        msg = '取消收藏成功'

    return JsonResponse({'code': 1, 'msg': msg}, json_dumps_params={'ensure_ascii': False})


from django.shortcuts import render, redirect
from .utils.db import DB


def play_song(request, song_id):
    """歌曲播放页：展示播放器、歌曲信息、评论区"""
    # 获取当前登录用户信息（用于判断是否登录、发布评论）
    current_user_id = request.session.get('user_id')
    current_username = request.session.get('username')

    # 兼容GET/POST请求的来源参数：POST时从表单取，GET时从URL取
    from_page = request.POST.get('from_page') or request.GET.get('from')
    singer_id = request.POST.get('singer_id') or request.GET.get('singer_id')
    album_id = request.POST.get('album_id') or request.GET.get('album_id')
    playlist_id = request.POST.get('playlist_id') or request.GET.get('playlist_id')

    # 查询歌曲详情（关联歌手、专辑信息）
    song_sql = """
        SELECT 
            s.song_id, s.song_name, s.duration, s.language, s.style,
            si.singer_id, si.singer_name, si.singer_photo,
            a.album_id, a.album_name, a.cover
        FROM 
            song s
        LEFT JOIN 
            singer si ON s.singer_id = si.singer_id
        LEFT JOIN 
            album a ON s.album_id = a.album_id
        WHERE 
            s.song_id = %s
    """
    song = DB.fetchone(song_sql, [song_id])
    if not song:  # 歌曲不存在则跳回首页
        return redirect('/home/')

    # 处理歌曲时长（秒转“分:秒”）
    minutes = song['duration'] // 60
    seconds = song['duration'] % 60
    song['duration_str'] = f"{minutes}:{seconds:02d}"

    # 发布评论（POST请求）
    if request.method == 'POST' and current_user_id:
        comment_content = request.POST.get('comment_content', '').strip()
        if comment_content:
            # 插入评论到数据库
            insert_sql = """
                INSERT INTO comment (user_id, song_id, content, publish_time)
                VALUES (%s, %s, %s, NOW())  # NOW()获取当前时间（MySQL函数）
            """
            DB.execute(insert_sql, [current_user_id, song_id, comment_content])
            # redirect_url = f'/play/{song_id}/'
            # if from_page:
            #     redirect_url += f'?from_page={from_page}'
            #     if singer_id:
            #         redirect_url += f'&singer_id={singer_id}'
            #     if album_id:
            #         redirect_url += f'&album_id={album_id}'
            # return redirect(redirect_url)

    if request.method == 'POST' and not current_user_id:
        return JsonResponse({'code': 0, 'msg': '请先登录'}, json_dumps_params={'ensure_ascii': False})

    # 查询该歌曲的所有评论（按发布时间降序）
    comment_sql = """
            SELECT 
                c.content, c.publish_time,
                u.username  # 关联用户名，显示评论者
            FROM 
                comment c
            LEFT JOIN 
                user u ON c.user_id = u.user_id
            WHERE 
                c.song_id = %s
            ORDER BY 
                c.publish_time DESC
        """
    comments = DB.fetchall(comment_sql, [song_id])

    # 处理评论时间格式（如果数据库存储的是datetime，可格式化显示）
    for comment in comments:
        # 假设create_time是datetime类型，格式化为“YYYY-MM-DD HH:MM:SS”
        comment['create_time_str'] = comment['publish_time'].strftime('%Y-%m-%d %H:%M:%S')

    # 传递数据到前端
    return render(request, 'play_song.html', {
        'song': song,
        'comments': comments,
        'current_user_id': current_user_id,
        'current_username': current_username,
        'from_page': from_page,
        'singer_id': singer_id,
        'album_id': album_id,
        'playlist_id' : playlist_id,
    })



# 11.26
from django.shortcuts import render, redirect
from .utils.db import DB


def album_detail(request, album_id):
    """专辑详情页：展示专辑信息、关联歌曲列表"""
    # 1. 获取当前登录用户ID（用于判断是否收藏专辑）
    current_user_id = request.session.get('user_id')
    current_username = request.session.get('username')

    # 2. 查询专辑基础信息（关联歌手信息）
    album_sql = """
        SELECT 
            a.album_id, a.album_name, a.release_time, a.cover,
            s.singer_id, s.singer_name, s.singer_photo
        FROM 
            album a
        LEFT JOIN 
            singer s ON a.singer_id = s.singer_id
        WHERE 
            a.album_id = %s
    """
    album = DB.fetchone(album_sql, [album_id])
    if not album:  # 专辑不存在则跳回歌手主页
        return redirect('/home/')

    # 3. 查询该专辑下的所有歌曲（按歌曲ID排序）
    song_sql = """
        SELECT 
            s.song_id, s.song_name, s.duration, s.language, s.style,
            COUNT(c.user_id) AS collect_count
        FROM 
            song s
        LEFT JOIN 
            user_collect_song c ON s.song_id = c.song_id
        WHERE 
            s.album_id = %s
        GROUP BY 
            s.song_id
        ORDER BY 
            s.song_id ASC
    """
    songs = DB.fetchall(song_sql, [album_id])

    # 4. 处理歌曲时长（秒转“分:秒”）
    for song in songs:
        minutes = song['duration'] // 60
        seconds = song['duration'] % 60
        song['duration_str'] = f"{minutes}:{seconds:02d}"

    # 5. 标记歌曲是否被当前用户收藏
    if current_user_id:
        for song in songs:
            collect_sql = """
                SELECT 1 FROM user_collect_song 
                WHERE user_id = %s AND song_id = %s
            """
            song['is_collected'] = DB.fetchone(collect_sql, [current_user_id, song['song_id']]) is not None
    else:
        for song in songs:
            song['is_collected'] = False

    # 6. 标记专辑是否被当前用户收藏
    album['is_collected'] = False
    if current_user_id:
        album_collect_sql = """
            SELECT 1 FROM user_collect_album 
            WHERE user_id = %s AND album_id = %s
        """
        album['is_collected'] = DB.fetchone(album_collect_sql, [current_user_id, album_id]) is not None

    # 7. 传递数据到模板
    return render(request, 'album_detail.html', {
        'album': album,
        'songs': songs,
        'current_username': current_username
    })

from django.shortcuts import render, redirect
from django.http import JsonResponse
from .utils.db import DB
import hashlib


def personal(request):
    """个人中心：展示用户信息、收藏歌曲/专辑、关注歌手"""
    # 1. 验证登录状态（未登录则跳转到登录页）
    current_user_id = request.session.get('user_id')
    current_username = request.session.get('username')
    if not current_user_id:
        return redirect('/login/')

    # 2. 查询用户基本信息（用户名、注册时间）
    user_sql = """
        SELECT username, register_time 
        FROM user 
        WHERE user_id = %s
    """
    user_info = DB.fetchone(user_sql, [current_user_id])

    # 3. 查询用户收藏的歌曲（关联歌曲、歌手信息）
    collect_song_sql = """
        SELECT 
            s.song_id, s.song_name, s.duration,
            si.singer_name,
            ucs.collect_time
        FROM 
            user_collect_song ucs
        LEFT JOIN 
            song s ON ucs.song_id = s.song_id
        LEFT JOIN 
            singer si ON s.singer_id = si.singer_id
        WHERE 
            ucs.user_id = %s
        ORDER BY 
            ucs.collect_time DESC
    """
    collect_songs = DB.fetchall(collect_song_sql, [current_user_id])
    # 处理歌曲时长格式
    for song in collect_songs:
        minutes = song['duration'] // 60
        seconds = song['duration'] % 60
        song['duration_str'] = f"{minutes}:{seconds:02d}"

    # 4. 查询用户收藏的专辑（关联专辑、歌手信息）
    collect_album_sql = """
        SELECT 
            a.album_id, a.album_name, a.release_time, a.cover,
            si.singer_name,
            uca.collect_time
        FROM 
            user_collect_album uca
        LEFT JOIN 
            album a ON uca.album_id = a.album_id
        LEFT JOIN 
            singer si ON a.singer_id = si.singer_id
        WHERE 
            uca.user_id = %s
        ORDER BY 
            uca.collect_time DESC
    """
    collect_albums = DB.fetchall(collect_album_sql, [current_user_id])

    # 5. 查询用户关注的歌手
    follow_singer_sql = """
        SELECT 
            s.singer_id, s.singer_name, s.region, s.singer_photo,
            ufs.follow_time
        FROM 
            user_follow_singer ufs
        LEFT JOIN 
            singer s ON ufs.singer_id = s.singer_id
        WHERE 
            ufs.user_id = %s
        ORDER BY 
            ufs.follow_time DESC
    """
    follow_singers = DB.fetchall(follow_singer_sql, [current_user_id])

    # 查询用户创建的歌单
    playlist_sql = """
            SELECT playlist_id, playlist_name, create_time, intro 
            FROM playlist 
            WHERE user_id = %s 
            ORDER BY create_time DESC
        """
    playlists = DB.fetchall(playlist_sql, [current_user_id])

    # 查询每个歌单的歌曲数量
    for playlist in playlists:
        count_sql = "SELECT COUNT(*) FROM playlist_song WHERE playlist_id = %s"
        song_count = DB.fetchone(count_sql, [playlist['playlist_id']])['COUNT(*)']
        playlist['song_count'] = song_count


    # 传递数据到模板
    return render(request, 'personal.html', {
        'current_username': current_username,
        'user_info': user_info,
        'collect_songs': collect_songs,
        'collect_albums': collect_albums,
        'follow_singers': follow_singers,
        'playlists': playlists
    })


def change_password(request):
    """修改密码接口（异步）"""
    # 1. 验证登录状态
    current_user_id = request.session.get('user_id')
    if not current_user_id:
        return JsonResponse({'code': 0, 'msg': '请先登录'}, json_dumps_params={'ensure_ascii': False})

    # 2. 处理POST请求
    if request.method == 'POST':
        old_password = request.POST.get('old_password', '').strip()
        new_password = request.POST.get('new_password', '').strip()
        confirm_password = request.POST.get('confirm_password', '').strip()

        # 3. 参数校验
        if not old_password or not new_password or not confirm_password:
            return JsonResponse({'code': 0, 'msg': '请填写所有字段'}, json_dumps_params={'ensure_ascii': False})
        if new_password != confirm_password:
            return JsonResponse({'code': 0, 'msg': '两次密码不一致'}, json_dumps_params={'ensure_ascii': False})

        # 4. 验证旧密码是否正确
        user_sql = """
            SELECT password FROM user WHERE user_id = %s
        """
        user = DB.fetchone(user_sql, [current_user_id])
        encrypted_old_pwd = hashlib.md5(old_password.encode()).hexdigest()
        if user['password'] != encrypted_old_pwd:
            return JsonResponse({'code': 0, 'msg': '旧密码错误'}, json_dumps_params={'ensure_ascii': False})

        # 5. 更新新密码
        encrypted_new_pwd = hashlib.md5(new_password.encode()).hexdigest()
        update_sql = """
            UPDATE user SET password = %s WHERE user_id = %s
        """
        DB.execute(update_sql, [encrypted_new_pwd, current_user_id])

        return JsonResponse({'code': 1, 'msg': '密码修改成功，请重新登录'}, json_dumps_params={'ensure_ascii': False})

    # GET请求直接返回个人中心
    return redirect('/personal/')


def logout(request):
    """退出登录：清空Session"""
    request.session.flush()
    return redirect('/login/')


from django.http import JsonResponse
from .utils.db import DB

def create_playlist(request):
    """创建歌单（异步接口）"""
    current_user_id = request.session.get('user_id')
    if not current_user_id:
        return JsonResponse({'code': 0, 'msg': '请先登录'}, json_dumps_params={'ensure_ascii': False})

    if request.method == 'POST':
        playlist_name = request.POST.get('playlist_name', '').strip()
        intro = request.POST.get('intro', '').strip()

        if not playlist_name:
            return JsonResponse({'code': 0, 'msg': '歌单名称不能为空'}, json_dumps_params={'ensure_ascii': False})

        # 检查同名歌单（用户内唯一）
        check_sql = "SELECT 1 FROM playlist WHERE user_id = %s AND playlist_name = %s"
        if DB.fetchone(check_sql, [current_user_id, playlist_name]):
            return JsonResponse({'code': 0, 'msg': '已存在同名歌单'}, json_dumps_params={'ensure_ascii': False})

        # 创建歌单
        sql = "INSERT INTO playlist (user_id, playlist_name, intro) VALUES (%s, %s, %s)"
        DB.execute(sql, [current_user_id, playlist_name, intro])
        return JsonResponse({'code': 1, 'msg': '歌单创建成功'}, json_dumps_params={'ensure_ascii': False})

    return JsonResponse({'code': 0, 'msg': '请求方式错误'}, json_dumps_params={'ensure_ascii': False})


def add_song_to_playlist(request):
    """歌曲添加到歌单（异步接口）"""
    current_user_id = request.session.get('user_id')
    if not current_user_id:
        return JsonResponse({'code': 0, 'msg': '请先登录'}, json_dumps_params={'ensure_ascii': False})

    if request.method == 'POST':
        song_id = request.POST.get('song_id')
        playlist_id = request.POST.get('playlist_id')

        if not song_id or not playlist_id:
            return JsonResponse({'code': 0, 'msg': '参数错误'}, json_dumps_params={'ensure_ascii': False})

        # 检查歌单是否属于当前用户
        check_sql = "SELECT 1 FROM playlist WHERE playlist_id = %s AND user_id = %s"
        if not DB.fetchone(check_sql, [playlist_id, current_user_id]):
            return JsonResponse({'code': 0, 'msg': '无权操作该歌单'}, json_dumps_params={'ensure_ascii': False})

        # 添加歌曲到歌单（避免重复）
        sql = "INSERT IGNORE INTO playlist_song (playlist_id, song_id) VALUES (%s, %s)"
        rowcount = DB.execute(sql, [playlist_id, song_id])
        if rowcount > 0:
            return JsonResponse({'code': 1, 'msg': '添加成功'}, json_dumps_params={'ensure_ascii': False})
        else:
            return JsonResponse({'code': 0, 'msg': '歌曲已在歌单中'}, json_dumps_params={'ensure_ascii': False})

    return JsonResponse({'code': 0, 'msg': '请求方式错误'}, json_dumps_params={'ensure_ascii': False})


def playlist_detail(request, playlist_id):
    """歌单详情页：展示歌单信息和歌曲列表"""
    current_user_id = request.session.get('user_id')
    current_username = request.session.get('username')

    # 查询歌单信息
    playlist_sql = """
        SELECT p.playlist_id, p.playlist_name, p.intro, p.create_time,
               u.username AS creator_name
        FROM playlist p
        LEFT JOIN user u ON p.user_id = u.user_id
        WHERE p.playlist_id = %s
    """
    playlist = DB.fetchone(playlist_sql, [playlist_id])
    if not playlist:
        return redirect('/personal/')

    # 查询歌单中的歌曲
    song_sql = """
        SELECT s.song_id, s.song_name, s.duration, si.singer_name,
               ps.add_time
        FROM playlist_song ps
        LEFT JOIN song s ON ps.song_id = s.song_id
        LEFT JOIN singer si ON s.singer_id = si.singer_id
        WHERE ps.playlist_id = %s
        ORDER BY ps.add_time DESC
    """
    songs = DB.fetchall(song_sql, [playlist_id])
    # 处理时长
    for song in songs:
        minutes = song['duration'] // 60
        seconds = song['duration'] % 60
        song['duration_str'] = f"{minutes}:{seconds:02d}"

    return render(request, 'playlist_detail.html', {
        'playlist': playlist,
        'songs': songs,
        'current_username': current_username
    })

def get_playlists(request):
    """获取当前用户的歌单（异步接口）"""
    current_user_id = request.session.get('user_id')
    if not current_user_id:
        return JsonResponse({'playlists': []})

    sql = "SELECT playlist_id, playlist_name FROM playlist WHERE user_id = %s ORDER BY create_time DESC"
    playlists = DB.fetchall(sql, [current_user_id])
    return JsonResponse({'playlists': playlists})



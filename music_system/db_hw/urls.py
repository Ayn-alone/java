"""
URL configuration for db_hw project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
import app01.views as views

urlpatterns = [
    path('admin/', admin.site.urls),

    path('login/', views.login),
    path('sign_up/', views.sign_up),

    path('home/', views.home),

    path('follow_singer/', views.follow_singer),

# 歌手主页：path中的<int:singer_id>是动态参数，接收歌手ID
    path('singer/<int:singer_id>/', views.singer_detail, name='singer_detail'),
    # 专辑收藏接口
    path('collect_album/', views.collect_album, name='collect_album'),
    # 歌曲收藏接口（如果之前已有，确保路由一致）
    path('collect_song/', views.collect_song, name='collect_song'),

path('play/<int:song_id>/', views.play_song, name='play_song'),

path('album/<int:album_id>/', views.album_detail, name='album_detail'),  # 新增专辑详情路由

path('personal/', views.personal, name='personal'),          # 个人中心
    path('change_password/', views.change_password, name='change_password'),  # 修改密码
    path('logout/', views.logout, name='logout'),                # 退出登录

path('create_playlist/', views.create_playlist, name='create_playlist'),  # 创建歌单
    path('add_song_to_playlist/', views.add_song_to_playlist, name='add_song_to_playlist'),  # 添加歌曲到歌单
    path('playlist/<int:playlist_id>/', views.playlist_detail, name='playlist_detail'),  # 歌单详情

path('personal/get_playlists/', views.get_playlists, name='get_playlists'),
]

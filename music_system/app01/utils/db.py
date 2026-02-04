from django.db import connection

class DB:
    @staticmethod
    def execute(sql, params=None):
        """执行增删改SQL（返回影响行数）"""
        with connection.cursor() as cursor:
            cursor.execute(sql, params or ())
            return cursor.rowcount  # 影响的行数

    @staticmethod
    def fetchone(sql, params=None):
        """查询单条数据（返回字典）"""
        with connection.cursor() as cursor:
            cursor.execute(sql, params or ())
            columns = [col[0] for col in cursor.description]  # 获取字段名
            row = cursor.fetchone()
            return dict(zip(columns, row)) if row else None

    @staticmethod
    def fetchall(sql, params=None):
        """查询多条数据（返回字典列表）"""
        with connection.cursor() as cursor:
            cursor.execute(sql, params or ())
            columns = [col[0] for col in cursor.description]
            rows = cursor.fetchall()
            return [dict(zip(columns, row)) for row in rows]
/**
 * 比赛服务器数据库插入信息
 */
#ifndef INSERTSTUDENTINFORMATION_LOGUPDAO_H
#define INSERTSTUDENTINFORMATION_LOGUPDAO_H

#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include <string>
#pragma comment(lib, "libmysql.lib")

#include "MD5.h"    //md5密码加密
#include "FileIO.h" //读取比赛信息文件
#include "Student.h"//学生信息模板

class LogUpDao {

private:
    MYSQL mysql;
    MYSQL_RES *mysql_res;
    MYSQL_ROW mysql_row;
    MYSQL_FIELD *mysql_field;

public:
    //数据库初始化
    LogUpDao();


    //数据库结束
    ~LogUpDao();
};


#endif //INSERTSTUDENTINFORMATION_LOGUPDAO_H

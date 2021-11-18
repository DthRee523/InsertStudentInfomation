#include "LogUpDao.h"

//function LogUpDao
// @pragma
LogUpDao::LogUpDao(string sqlhost, string sqlUser, string password)
{
    //数据库初始化
    mysql_init(&mysql);
    if(mysql_real_connect(&mysql,
                          sqlhost.c_str(),
                          sqlUser.c_str(),
                          password.c_str(),
                          "syzoj",
                          3306,
                          NULL,
                          0))
    {
        //windows下用的编码格式为GB2312 Linux下删除此代码 UTF-8
        mysql_query(&mysql, "set names gb2312");
        cout << "数据库链接成功！" << endl;
    }
    else
    {
        std::cout << mysql_error(&mysql) << std::endl;
        exit(0);
    }
}
// function:  insertInformation
// @return : void
void LogUpDao::insertInformation(vector<Student> students)
{
    for (vector<Student>::iterator iterator = students.begin(); iterator != students.end(); iterator++)
    {
        //自定义sql语句
        string sql = "insert into user(username, email, password, information, ac_num, submit_num, is_show, public_email, rating, register_time, prefer_formatted_code, id) ";
        sql += "values('";
        sql += iterator->username;  //账号
        sql += "', '";
        sql += iterator->email;     //虚拟邮箱
        sql += "', '";
        sql += iterator->password;  //密码
        sql += "', '";
        sql += iterator->information;//学生信息
        sql += "', '";
        sql += "0";                 //初始化通过数量
        sql += "', '";
        sql += "0";                 //初始化提交数量
        sql += "', '";
        sql += "1";                 //账号设置为公开
        sql += "', '";
        sql += "1";                 //公开虚拟电子邮件
        sql += "', '";
        sql += "0";              //积分初始化
        sql += "', '";
        sql += "1635255795";       //虚拟注册时间
        sql += "', '";
        sql += "1";
        sql += "', '";
        sql += to_string(iterator->id);    //数据库id
        sql += "');";

        if (!mysql_query(&mysql, sql.c_str()))
        {
            cout << "学生 " << iterator->information << " 成功插入到数据库" << endl;
        }
        else
        {
            cout << "学生 " << iterator->information << " 数据库插入失败" << endl;
        }
    }
}

LogUpDao::~LogUpDao()
{
    //回收内存
    delete mysql_res;
    mysql_res = nullptr;
    //安全关闭mysql
    mysql_close(&mysql);
}

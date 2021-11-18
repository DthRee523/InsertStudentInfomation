#ifndef INSERTSTUDENTINFORMATION_STUDENT_H
#define INSERTSTUDENTINFORMATION_STUDENT_H

#include <string>
#include <iostream>
using namespace std;

struct Student
{
    int id;             //学生序号
    string username;    //账号
    string password;    //密码
    string email;       //虚拟邮箱
    string information;  //学生班级姓名信息
    string register_time;//虚假注册时间
};

#endif //INSERTSTUDENTINFORMATION_STUDENT_H

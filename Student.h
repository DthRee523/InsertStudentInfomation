#ifndef INSERTSTUDENTINFORMATION_STUDENT_H
#define INSERTSTUDENTINFORMATION_STUDENT_H

#include <string>
#include <iostream>
using namespace std;

struct Student
{
    string username;    //账号
    string password;    //密码
    string email;       //虚拟邮箱
    string information;  //学生班级姓名信息
    int acNum = 0;      //通过题数量 强制为 0
    int submitNum = 0;  //提交数量  强制为 0
    int isShow = 1;     //是否公开账号 强制公开
    int rating = 0;     //积分强制为 0
};

#endif //INSERTSTUDENTINFORMATION_STUDENT_H

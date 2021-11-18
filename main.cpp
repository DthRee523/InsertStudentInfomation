#include <iostream>
#include <vector>
#include <string>

#include "Student.h"
#include "LogUpDao.h"
#include "MD5.h"

using namespace std;

int main() {
    LogUpDao logUpDao("localhost", "root", "Liuhuan1");

    vector<Student> v_stu;
    Student student;
    student.username = "101";
    Md5Encode md5Encode;
    student.information = "≤‚ ‘–≈œ¢";
    student.password = md5Encode.Encode("1");
    student.email = "111@dthree.cn";
    v_stu.push_back(student);
    logUpDao.insertInformation(v_stu);
    return 0;
}

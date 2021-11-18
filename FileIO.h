/**
 * 读取比赛同学信息文本
 */
#ifndef INSERTSTUDENTINFORMATION_FILEIO_H
#define INSERTSTUDENTINFORMATION_FILEIO_H

#include <iostream>
#include <string>
#include <libxl.h>
#include <windows.h>    //获取桌面路径的头文件
#include <shlobj.h>     //获取桌面路径的头文件
#include <fstream>
#include <vector>
#pragma comment(lib,"libxl.lib")

#include "Student.h"
#include "MD5.h"

using namespace libxl;
using namespace std;

class FileIO
{
private:
    Book *book; //实例化表格
    Md5Encode md5Encode;    //密码加密
    Student student;        //单个学生信息
    vector<Student> students;//整个学生信息
    Sheet *sheet;           //表格sheet项

public:
    FileIO();
    //获取桌面路径
    string getDesktopPath();
    //获得学生信息
    vector<Student> getStudents(int idBegin, int begin, int end);
};

#endif //INSERTSTUDENTINFORMATION_FILEIO_H
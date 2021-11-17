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
#pragma comment(lib,"libxl.lib")

#include "Student.h"

using namespace libxl;
using namespace std;

class FileIO
{
public:
    //获取桌面路径
    string getDesktopPath();
};
#endif //INSERTSTUDENTINFORMATION_FILEIO_H

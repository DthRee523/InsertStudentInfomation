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
#pragma comment(lib,"libxl.lib")

#include "Student.h"
#include "MD5.h"

using namespace libxl;
using namespace std;

class FileIO
{
public:
    //获取桌面路径
    string getDesktopPath();
    //TODO 文件处理还没写完

};
#endif //INSERTSTUDENTINFORMATION_FILEIO_H

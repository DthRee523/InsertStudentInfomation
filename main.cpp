#include <iostream>
#include <vector>
#include <string>

#include "Student.h"
#include "LogUpDao.h"
#include "MD5.h"
#include "FileIO.h"

using namespace std;

int main() {
    LogUpDao logUpDao("localhost", "root", "Liuhuan1");
    FileIO *fileIo;
    fileIo = new FileIO();
    logUpDao.insertInformation(fileIo->getStudents(72, 0, 3));
    delete fileIo;
    fileIo = nullptr;
    return 0;
}

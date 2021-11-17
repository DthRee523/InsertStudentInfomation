cmake_minimum_required(VERSION 3.20)
project(InsertStudentInformation)

set(CMAKE_CXX_STANDARD 11)
set(mysqlInclude include)
set(mysqlLib lib)

include_directories(${mysqlInclude})
link_directories(${mysqlLib})
link_libraries(libmysql libxl)

add_executable(InsertStudentInformation main.cpp LogUpDao.cpp LogUpDao.h FileIO.cpp FileIO.h Student.h)

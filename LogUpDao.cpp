#include "LogUpDao.h"

LogUpDao::LogUpDao()
{
    //数据库初始化
    mysql_init(&mysql);
    if(mysql_real_connect(&mysql,
                          "localhost",
                          "root",
                          "Liuhuan1",
                          "db_test",
                          3306,
                          NULL,
                          0))
    {

    }
    else
    {
        std::cout << mysql_error(&mysql) << std::endl;
        exit(0);
    }
}

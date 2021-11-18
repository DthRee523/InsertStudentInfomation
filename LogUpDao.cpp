#include "LogUpDao.h"

//function LogUpDao
// @pragma
LogUpDao::LogUpDao(string sqlhost, string sqlUser, string password)
{
    //���ݿ��ʼ��
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
        //windows���õı����ʽΪGB2312 Linux��ɾ���˴��� UTF-8
        mysql_query(&mysql, "set names gb2312");
        cout << "���ݿ����ӳɹ���" << endl;
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
        //�Զ���sql���
        string sql = "insert into user(username, email, password, information, ac_num, submit_num, is_show, public_email, rating, register_time, prefer_formatted_code, id) ";
        sql += "values('";
        sql += iterator->username;  //�˺�
        sql += "', '";
        sql += iterator->email;     //��������
        sql += "', '";
        sql += iterator->password;  //����
        sql += "', '";
        sql += iterator->information;//ѧ����Ϣ
        sql += "', '";
        sql += "0";                 //��ʼ��ͨ������
        sql += "', '";
        sql += "0";                 //��ʼ���ύ����
        sql += "', '";
        sql += "1";                 //�˺�����Ϊ����
        sql += "', '";
        sql += "1";                 //������������ʼ�
        sql += "', '";
        sql += "0";              //���ֳ�ʼ��
        sql += "', '";
        sql += "1635255795";       //����ע��ʱ��
        sql += "', '";
        sql += "1";
        sql += "', '";
        sql += to_string(iterator->id);    //���ݿ�id
        sql += "');";

        if (!mysql_query(&mysql, sql.c_str()))
        {
            cout << "ѧ�� " << iterator->information << " �ɹ����뵽���ݿ�" << endl;
        }
        else
        {
            cout << "ѧ�� " << iterator->information << " ���ݿ����ʧ��" << endl;
        }
    }
}

LogUpDao::~LogUpDao()
{
    //�����ڴ�
    delete mysql_res;
    mysql_res = nullptr;
    //��ȫ�ر�mysql
    mysql_close(&mysql);
}

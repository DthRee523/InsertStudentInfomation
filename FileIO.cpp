#include "FileIO.h"

string FileIO::getDesktopPath()
{
    LPITEMIDLIST pidl;
    LPMALLOC pShellMalloc;
    char szDir[200];
    if (SUCCEEDED(SHGetMalloc(&pShellMalloc)))
    {
        if (SUCCEEDED(SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOP, &pidl))) {
            SHGetPathFromIDListA(pidl, szDir);
            pShellMalloc->Free(pidl);
        }
        pShellMalloc->Release();
    }
    return string(szDir);
}

FileIO::FileIO()
{
    book = xlCreateXMLBook();//����һ��XML��ʽ��XLSX��ʽ�� Execl2007���ϣ���ʵ�������ظ�ʵ����ָ�롣
    cout << "�ļ��ڴ�ɹ�����" << endl;
    sheet = nullptr;
}

vector<Student> FileIO::getStudents(int idBegin, int begin, int end)
{
    if (book->load("test.xlsx"))
    {
        cout << "�ļ���ȡ�ɹ���" << endl;
        sheet = book->getSheet(0);
        for(begin; begin < end; begin++)
        {
            student.id = idBegin;
            student.username = string(sheet->readStr(begin + 1, 4));
            student.password = md5Encode.Encode(string(sheet->readStr(begin + 1, 5)));
            student.information = string(sheet->readStr(begin + 1, 3));
            student.information += " ";
            student.information += string(sheet->readStr(begin + 1, 2));
            student.email = string(sheet->readStr(begin + 1, 5));
            student.email += "@dthree.cn";
            students.push_back(student);
            idBegin++;
        }
    }
    else
    {
        cout << "�ļ���ȡʧ��" << endl;
    }
    return students;
}
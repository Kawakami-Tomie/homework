#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student { // 学生结构体
    int ID;
    string name;
    float MathScore;
    float EngScore;
};

void createFile(string fileName) { // 创建新文件
    ofstream outfile(fileName, ios::out | ios::binary);//文件以输出方式打开(内存数据输出到文件),二进制方式
    if (!outfile) {
        cout << "创建文件失败！" << endl;
    }
    else {
        cout << "文件创建成功！" << endl;
    }
}

void printFile(string fileName) { // 输出文件内容
    ifstream infile(fileName, ios::in | ios::binary); //文件以输入方式打开(文件数据输入到内存)
    Student st;
    while (infile.read((char*)&st, sizeof(st)))//从文件中读取 sizeof(st) 个字符到 st 指向的缓存中
    {
        cout << "学号：" << st.ID << ", 姓名：" << st.name << ", 数学成绩：" << st.MathScore << ", 英语成绩：" << st.EngScore << endl;
    }
}

int main() {
    string fileName;
    cout << "请输入一个文件名（例如：*.data）：" << endl;
    cin >> fileName;

    ifstream infile(fileName, ios::in | ios::binary);
    if (!infile) { // 文件不存在
        cout << "没有找到该文件，将新建一个文件" << endl;
        createFile(fileName);
    }
    else  { // 文件存在，输出内容
        cout << "文件已存在，内容如下：" << endl;
        printFile(fileName);
    }
    infile.close();
    ofstream outfile;

    Student st;
     while (1) {
        cout << "请输入学生信息（学号 姓名 数学成绩 英语成绩）：" << endl;
        cin >> st.ID >> st.name >> st.MathScore >> st.EngScore;
        ofstream outfile(fileName, ios::app | ios::binary);//所有输出附加在文件末尾
        outfile.write((char*)&st, sizeof(st));//从st 指向的缓存写 sizeof(st) 个字符到文件中
          cout << "是否继续输入（Y/N）：" << endl;
        string flag;
        cin >> flag;

        if (flag == "N") 
        {
            outfile.close();
            cout << "所有成绩数据如下：" << endl;
            printFile(fileName);
            cout << "数据已存储到" << fileName << "文件中" << endl;
            break;
        }
    }

    return 0;
}

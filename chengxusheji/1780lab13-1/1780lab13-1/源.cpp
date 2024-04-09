#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student { // ѧ���ṹ��
    int ID;
    string name;
    float MathScore;
    float EngScore;
};

void createFile(string fileName) { // �������ļ�
    ofstream outfile(fileName, ios::out | ios::binary);//�ļ��������ʽ��(�ڴ�����������ļ�),�����Ʒ�ʽ
    if (!outfile) {
        cout << "�����ļ�ʧ�ܣ�" << endl;
    }
    else {
        cout << "�ļ������ɹ���" << endl;
    }
}

void printFile(string fileName) { // ����ļ�����
    ifstream infile(fileName, ios::in | ios::binary); //�ļ������뷽ʽ��(�ļ��������뵽�ڴ�)
    Student st;
    while (infile.read((char*)&st, sizeof(st)))//���ļ��ж�ȡ sizeof(st) ���ַ��� st ָ��Ļ�����
    {
        cout << "ѧ�ţ�" << st.ID << ", ������" << st.name << ", ��ѧ�ɼ���" << st.MathScore << ", Ӣ��ɼ���" << st.EngScore << endl;
    }
}

int main() {
    string fileName;
    cout << "������һ���ļ��������磺*.data����" << endl;
    cin >> fileName;

    ifstream infile(fileName, ios::in | ios::binary);
    if (!infile) { // �ļ�������
        cout << "û���ҵ����ļ������½�һ���ļ�" << endl;
        createFile(fileName);
    }
    else  { // �ļ����ڣ��������
        cout << "�ļ��Ѵ��ڣ��������£�" << endl;
        printFile(fileName);
    }
    infile.close();
    ofstream outfile;

    Student st;
     while (1) {
        cout << "������ѧ����Ϣ��ѧ�� ���� ��ѧ�ɼ� Ӣ��ɼ�����" << endl;
        cin >> st.ID >> st.name >> st.MathScore >> st.EngScore;
        ofstream outfile(fileName, ios::app | ios::binary);//��������������ļ�ĩβ
        outfile.write((char*)&st, sizeof(st));//��st ָ��Ļ���д sizeof(st) ���ַ����ļ���
          cout << "�Ƿ�������루Y/N����" << endl;
        string flag;
        cin >> flag;

        if (flag == "N") 
        {
            outfile.close();
            cout << "���гɼ��������£�" << endl;
            printFile(fileName);
            cout << "�����Ѵ洢��" << fileName << "�ļ���" << endl;
            break;
        }
    }

    return 0;
}

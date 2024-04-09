#include "bintree.h"
using namespace std;


int main() {
    BST flightSchedule;
    char choice = 'Y';
    do {
        srand(time(0));
        flightSchedule.clear();
        for (int i = 0; i < 31; i++) {
            int time = rand() % 1441;
            flightSchedule.insert(time);
        }

        cout << "���ɶ��������Ӧʱ������: " << endl;
        flightSchedule.displayInLevelOrder();
        cout << "�Զ���������ӡ�������: " << endl;
        flightSchedule.levelOrderTraversal(flightSchedule.root);
        cout << "�Ƿ��������ɣ�Y/N��" << endl;
        cin >> choice;
    } while (choice == 'Y');


    cout << "ʹ�õݹ��㷨ʵ�ֱ������£�" << endl;
    cout << "�������: ";
    flightSchedule.preOrderTraversal(flightSchedule.root);
    cout << endl;

    cout << "�������: ";
    flightSchedule.inOrderTraversal(flightSchedule.root);
    cout << endl;

    cout << "�������: ";
    flightSchedule.postOrderTraversal(flightSchedule.root);
    cout << endl;
    cout << "ʹ�õ����㷨ʵ�ֱ������£�" << endl;
    cout << "�������: ";
    flightSchedule.preorderTraversal(flightSchedule.root);
    cout << endl;

    cout << "�������: ";
    flightSchedule.inorderTraversal(flightSchedule.root);
    cout << endl;

    cout << "�������: ";
    flightSchedule.postorderTraversal(flightSchedule.root);
    cout << endl;

    cout << "********************�û���ѯ��һ���ѯ�����Ҹ����������ѯ���������ȣ�*******************" << endl;
    int shiTime = 0, fenTime = 0, queryTime = 0, shiTime1 = 0, fenTime1 = 0, queryTime1 = 0, ancestorTime = 0, findTime = 0;
    char chioce_one = 'Y',chioce_two='Y';
    do {
        cout << "������һ���ѯʱ�䣨ʱ����ÿո������" << endl;
        cin >> shiTime >> fenTime;
        queryTime = shiTime * 60 + fenTime;
        cout << "����� " << shiTime << ":" << fenTime << " ��ʱ���� " << flightSchedule.findClosestFlight(queryTime) / 60 << ":" << flightSchedule.findClosestFlight(queryTime) % 60 << ",";
        findTime = flightSchedule.findClosestFlight(queryTime);
        if (findTime > queryTime)cout << "�����ڲ�ѯʱ��" << endl;
        else   if (findTime == queryTime)cout << "�ҵ��ڲ�ѯʱ��" << endl;
        else   if (findTime < queryTime)cout << "�����ڲ�ѯʱ��" << endl;
        cout << "�Ƿ������ѯ��Y/N��" << endl;
        cin >> chioce_one;
    } while (chioce_one == 'Y');

    do {
        cout << "����������ѯʱ��1" << endl;
        cin >> shiTime >> fenTime;
        queryTime = shiTime * 60 + fenTime;
        cout << "����������ѯʱ��2" << endl;
        cin >> shiTime1 >> fenTime1;
        queryTime1 = shiTime1 * 60 + fenTime1;
        TreeNode* ancestor = flightSchedule.findLowestCommonAncestor(flightSchedule.root, queryTime, queryTime1);
        ancestorTime = ancestor->data;
        cout << "ʱ�� " << shiTime << ":" << fenTime<< "��"<< "ʱ�� " << shiTime1 << ":" << fenTime1 << "����С������ " << ancestorTime/60<<":"<<ancestorTime%60 << endl;
        cout << "�Ƿ������ѯ��Y/N��" << endl;
        cin >> chioce_two;
    } while (chioce_two == 'Y');
    return 0;
}

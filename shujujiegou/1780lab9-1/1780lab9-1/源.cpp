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

        cout << "生成二叉树与对应时间如下: " << endl;
        flightSchedule.displayInLevelOrder();
        cout << "对二叉树逐层打印结果如下: " << endl;
        flightSchedule.levelOrderTraversal(flightSchedule.root);
        cout << "是否重新生成（Y/N）" << endl;
        cin >> choice;
    } while (choice == 'Y');


    cout << "使用递归算法实现遍历如下：" << endl;
    cout << "先序遍历: ";
    flightSchedule.preOrderTraversal(flightSchedule.root);
    cout << endl;

    cout << "中序遍历: ";
    flightSchedule.inOrderTraversal(flightSchedule.root);
    cout << endl;

    cout << "后序遍历: ";
    flightSchedule.postOrderTraversal(flightSchedule.root);
    cout << endl;
    cout << "使用迭代算法实现遍历如下：" << endl;
    cout << "先序遍历: ";
    flightSchedule.preorderTraversal(flightSchedule.root);
    cout << endl;

    cout << "中序遍历: ";
    flightSchedule.inorderTraversal(flightSchedule.root);
    cout << endl;

    cout << "后序遍历: ";
    flightSchedule.postorderTraversal(flightSchedule.root);
    cout << endl;

    cout << "********************用户查询（一类查询：查找附近；二类查询：查找祖先）*******************" << endl;
    int shiTime = 0, fenTime = 0, queryTime = 0, shiTime1 = 0, fenTime1 = 0, queryTime1 = 0, ancestorTime = 0, findTime = 0;
    char chioce_one = 'Y',chioce_two='Y';
    do {
        cout << "请输入一类查询时间（时与分用空格隔开）" << endl;
        cin >> shiTime >> fenTime;
        queryTime = shiTime * 60 + fenTime;
        cout << "最靠近于 " << shiTime << ":" << fenTime << " 的时间是 " << flightSchedule.findClosestFlight(queryTime) / 60 << ":" << flightSchedule.findClosestFlight(queryTime) % 60 << ",";
        findTime = flightSchedule.findClosestFlight(queryTime);
        if (findTime > queryTime)cout << "且晚于查询时间" << endl;
        else   if (findTime == queryTime)cout << "且等于查询时间" << endl;
        else   if (findTime < queryTime)cout << "且早于查询时间" << endl;
        cout << "是否继续查询（Y/N）" << endl;
        cin >> chioce_one;
    } while (chioce_one == 'Y');

    do {
        cout << "请输入二类查询时间1" << endl;
        cin >> shiTime >> fenTime;
        queryTime = shiTime * 60 + fenTime;
        cout << "请输入二类查询时间2" << endl;
        cin >> shiTime1 >> fenTime1;
        queryTime1 = shiTime1 * 60 + fenTime1;
        TreeNode* ancestor = flightSchedule.findLowestCommonAncestor(flightSchedule.root, queryTime, queryTime1);
        ancestorTime = ancestor->data;
        cout << "时间 " << shiTime << ":" << fenTime<< "与"<< "时间 " << shiTime1 << ":" << fenTime1 << "的最小祖先是 " << ancestorTime/60<<":"<<ancestorTime%60 << endl;
        cout << "是否继续查询（Y/N）" << endl;
        cin >> chioce_two;
    } while (chioce_two == 'Y');
    return 0;
}

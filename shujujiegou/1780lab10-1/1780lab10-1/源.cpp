#include <iostream>
#include <string>
#include <vector>

using namespace std;


template <typename T>
class Queue {
private:
    vector<T> elements;

public:
    void push(const T& element) {
        elements.push_back(element);
    }

    void pop() {
        if (!empty()) {
            elements.erase(elements.begin());
        }
    }

    T front() {
        if (!empty()) {
            return elements[0];
        }
    }

    bool empty() {
        return elements.empty();
    }
};

class Graph {
private:
    int size;
    vector<string> node;//顶点
    vector<vector<int>> arc;//邻接

public:
    Graph(int s) : size(s) {
        // 初始化邻接矩阵
        node.resize(size);
        arc.resize(size, vector<int>(size, -1));
    }
    //Graph(){}
    void addNode(int index, const string& name) {//增加节点
        node[index - 1] = name;

    }

    void addEdge(int start, int end, int weight) {//增加边
        arc[start - 1][end - 1] = weight;
    }

    void removeNode(int index) {//删除节点
        node[index - 1] = "";
        for (int i = 0; i < size; ++i) {//同时对应的边也删除
            arc[i][index - 1] = -1;
            arc[index - 1][i] = -1;
        }
    }

    void removeEdge(int start, int end) {//删除边
        arc[start - 1][end - 1] = -1;
    }

    void displayGraph() {//打印图
        cout << string(8, ' '); // 12个空格用于对齐

        for (int i = 0; i < size; ++i) {
            cout << i + 1 << " " << node[i] << string(6 - node[i].size(), ' ');//打印第一排
        }
        cout << endl;

        for (int i = 0; i < size; ++i) {
            cout << i + 1 << " " << node[i] << string(8 - node[i].size(), ' ');

            for (int j = 0; j < size; ++j) {//打印权重
                if (arc[i][j] == -1) {
                    cout << "-\t";
                }
                else {
                    cout << arc[i][j] << "\t";
                }
            }
            cout << endl;
        }
    }

    void BFS(int start) {
        vector<bool> visited(size, false);
        Queue<int> q;
        q.push(start - 1);//从首节点开始遍历

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            if (!visited[currentNode]) {
                cout << currentNode + 1 << " " << node[currentNode] << endl;
                visited[currentNode] = true;//对访问元素进行标记
            }
            for (int i = 0; i < size; ++i) {//依次访问邻接点
                if (arc[currentNode][i] != -1 && !visited[i]) {
                    q.push(i);
                }
            }
        }
    }
};

int main() {
    Graph g(5);

    int choice;
    int start, end, weight;
    int index;
    string name;

    while (true) {
        cout << "1. 添加节点" << endl;
        cout << "2. 添加边" << endl;
        cout << "3. 删除节点" << endl;
        cout << "4. 删除边" << endl;
        cout << "5. 显示图" << endl;
        cout << "6. 遍历" << endl;
        cout << "7. 退出" << endl;
        cout << "请选择操作：";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "输入节点序号和名称：";
            cin >> index >> name;
           // Graph g(index);
            g.addNode(index, name);
            break;
        case 2:
            cout << "输入边的起始节点序号、到达节点序号和权重：";
            cin >> start >> end >> weight;
            g.addEdge(start, end, weight);
            break;
        case 3:
            cout << "输入要删除的节点序号：";
            cin >> index;
            g.removeNode(index);
            break;
        case 4:
            cout << "输入要删除边的起始节点序号和到达节点序号：";
            cin >> start >> end;
            g.removeEdge(start, end);
            break;
        case 5:
            g.displayGraph();
            break;
        case 6:
            cout << "输入起始节点序号进行遍历：";
            cin >> start;
            cout << "遍历结果：" << endl;
            g.BFS(start);
            break;
        case 7:
            return 0;
        default:
            cout << "输入无效操作..." << endl;
        }
    }

    return 0;
}

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
    vector<string> node;
    vector<vector<int>> arc;

public:
    Graph(int s) : size(s) {
        // 初始化邻接矩阵
        arc.resize(size, vector<int>(size, -1));
    }

    void addNode(const string& name) {
        node.push_back(name);
        size++;  // 更新节点个数
        for (auto& row : arc) {
            row.resize(size, -1);  // 更新每一行的长度
        }
        arc.push_back(vector<int>(size, -1));  // 添加新的一行
    }

    void removeNode(int index) {
        node.erase(node.begin() + index - 1);
        for (auto& row : arc) {
            row.erase(row.begin() + index - 1);  // 删除对应的列
        }
        arc.erase(arc.begin() + index - 1);  // 删除对应的行
        size--;  // 更新节点个数与序号
    }
      void addEdge(int start, int end, int weight) {
            arc[start - 1][end - 1] = weight;
        }
    void removeEdge(int start, int end) {//删除边
        arc[start - 1][end - 1] = -1;
    }

    void displayGraph() {
        cout << string(8, ' ');  // 12个空格用于对齐
        for (int i = 0; i < size; ++i) {
            cout << i + 1 << " " << node[i] << string(6 - node[i].size(), ' ');
        }
        cout << endl;
        for (int i = 0; i < size; ++i) {
            cout << i + 1 << " " << node[i] << string(8 - node[i].size(), ' ');
            for (int j = 0; j < size; ++j) {
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
        q.push(start - 1);

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            if (!visited[currentNode]) {
                cout << currentNode + 1 << " " << node[currentNode] << endl;
                visited[currentNode] = true;
            }
            for (int i = 0; i < size; ++i) {
                if (arc[currentNode][i] != -1 && !visited[i]) {
                    q.push(i);
                }
            }
        }
    }
};

int main() {
    Graph g(0);

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
            cout << "输入节点名称：";
            cin >> name;
            g.addNode(name);
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

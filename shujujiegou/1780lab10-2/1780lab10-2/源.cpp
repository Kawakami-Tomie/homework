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
        // ��ʼ���ڽӾ���
        arc.resize(size, vector<int>(size, -1));
    }

    void addNode(const string& name) {
        node.push_back(name);
        size++;  // ���½ڵ����
        for (auto& row : arc) {
            row.resize(size, -1);  // ����ÿһ�еĳ���
        }
        arc.push_back(vector<int>(size, -1));  // ����µ�һ��
    }

    void removeNode(int index) {
        node.erase(node.begin() + index - 1);
        for (auto& row : arc) {
            row.erase(row.begin() + index - 1);  // ɾ����Ӧ����
        }
        arc.erase(arc.begin() + index - 1);  // ɾ����Ӧ����
        size--;  // ���½ڵ���������
    }
      void addEdge(int start, int end, int weight) {
            arc[start - 1][end - 1] = weight;
        }
    void removeEdge(int start, int end) {//ɾ����
        arc[start - 1][end - 1] = -1;
    }

    void displayGraph() {
        cout << string(8, ' ');  // 12���ո����ڶ���
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
        cout << "1. ��ӽڵ�" << endl;
        cout << "2. ��ӱ�" << endl;
        cout << "3. ɾ���ڵ�" << endl;
        cout << "4. ɾ����" << endl;
        cout << "5. ��ʾͼ" << endl;
        cout << "6. ����" << endl;
        cout << "7. �˳�" << endl;
        cout << "��ѡ�������";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "����ڵ����ƣ�";
            cin >> name;
            g.addNode(name);
            break;
        case 2:
            cout << "����ߵ���ʼ�ڵ���š�����ڵ���ź�Ȩ�أ�";
            cin >> start >> end >> weight;
            g.addEdge(start, end, weight);
            break;
        case 3:
            cout << "����Ҫɾ���Ľڵ���ţ�";
            cin >> index;
            g.removeNode(index);
            break;
        case 4:
            cout << "����Ҫɾ���ߵ���ʼ�ڵ���ź͵���ڵ���ţ�";
            cin >> start >> end;
            g.removeEdge(start, end);
            break;
        case 5:
            g.displayGraph();
            break;
        case 6:
            cout << "������ʼ�ڵ���Ž��б�����";
            cin >> start;
            cout << "���������" << endl;
            g.BFS(start);
            break;
        case 7:
            return 0;
        default:
            cout << "������Ч����..." << endl;
        }
    }

    return 0;
}

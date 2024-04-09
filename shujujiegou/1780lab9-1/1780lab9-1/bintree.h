#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <climits>
using namespace std;
#ifndef __BINTREE_H
#define __BINTREE_H
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertHelper(root, val);
    }

    TreeNode* insertHelper(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        }
        else if (val > node->data) {
            node->right = insertHelper(node->right, val);
        }

        return node;
    }

    

    void clearTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }

    void clear() {
        clearTree(root);
        root = nullptr;
    }


    void printGivenLevel(TreeNode* node, int level,string  path) {
        if (node == NULL)
            return;
        if (level == 1) {
            cout << path; // ����ڵ�·��
            cout << " - " << node->data / 60 << ":" << node->data % 60 << endl; // ������ʱ��
        }
        else if (level > 1) {
            printGivenLevel(node->left, level - 1, path + "0"); // ������
            printGivenLevel(node->right, level - 1, path + "1"); // ������
        }
    }

    void displayInLevelOrder() {//���Ȼ�ȡ�������ĸ߶ȣ�Ȼ��Ӹ��ڵ㿪ʼ�����δ�ӡÿһ��Ľڵ�
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            printGivenLevel(root, i, "0");
        }
    }

    //����ӡ
    void levelOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {//�������
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {//�������У��Ƚ��������ӣ�Ȼ��ѭ�������׽�㣬���ҽ��ý�������������������������С�
                TreeNode* current = q.front();
                q.pop();

                int currentTime = current->data;
                cout << currentTime / 60 << ":" << currentTime % 60 << " ";

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            cout << endl; // ���б�ʾ��ǰ��������
        }
    }

    int height(TreeNode* node) {//�������Ե�ǰ�ڵ�Ϊ���������ĸ߶�
        if (node == nullptr) {
            return 0;
        }
        else {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }
    //�ݹ����
    //��������� �ȸ� ���� ����

    //��������� ���� �ٸ� ����

    //��������� ���� ���� �ٸ�
    //��
    void preOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            int nodTime = node->data;
            cout << nodTime / 60 << ":" << nodTime % 60 << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }
    //��
    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            int nodTime = node->data;
            cout << nodTime / 60 << ":" << nodTime % 60 << " ";
            inOrderTraversal(node->right);
        }
    }
    //��
    void postOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            int nodTime = node->data;
            cout << nodTime / 60 << ":" << nodTime % 60 << " ";
        }
    }
    //����������
    //����
    void preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                //cout << root->data << " ";
                int rootTime = root->data;
                cout << rootTime / 60 << ":" << rootTime % 60 << " ";

                s.push(root);     //�������Ľڵ������ӽڵ㣬�����ӽڵ���ջ��
                                  //�������Ľڵ������ӽڵ㣬�����ӽڵ���ջ�������ͱ�֤�����ӽڵ�������ӽڵ�֮ǰ�����ʡ�
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    //����
    void inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
                    //����ǰ�ڵ�����ӽڵ�������ջ��ֱ�����ӽڵ�Ϊ�ա�
                    //��ջ�е����ڵ�
                    //�ٽ���ǰ�ڵ�����ӽڵ���ջ

            }
            root = s.top();
            s.pop();
            // cout << root->data << " ";
            int rootTime = root->data;
            cout << rootTime / 60 << ":" << rootTime % 60 << " ";

            root = root->right;
        }
    }




    //����
    void postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1, s2;//s1����s2
        s1.push(root);
        while (!s1.empty()) {
            root = s1.top();
            s1.pop();
            s2.push(root);//����ýڵ������ӣ�������ѹ�� s1 ջ�С�
                          //����ýڵ����Һ��ӣ����Һ���ѹ�� s1 ջ�С�
            if (root->left != nullptr) {
                s1.push(root->left);
            }
            if (root->right != nullptr) {
                s1.push(root->right);
            }
        }
        while (!s2.empty()) {
            // cout << s2.top()->data << " ";
            int rootTime = s2.top()->data;
            cout << rootTime / 60 << ":" << rootTime % 60 << " ";

            s2.pop();
        }
    }
    int findClosestFlight(int val) {
        int closestTime = INT_MAX;
        getClosestFlight(root, val, closestTime);
        return closestTime;
    }
    

    void getClosestFlight(TreeNode* node, int val, int& closestTime) {//�ݹ����closestTime
        if (node != nullptr) {
            if (abs(node->data - val) < abs(closestTime - val)) {//�����ֵ������
                closestTime = node->data;
            }
            if (val < node->data) {//����������������
                getClosestFlight(node->left, val, closestTime);
            }
            else {
                getClosestFlight(node->right, val, closestTime);
            }
        }
    }
   
    TreeNode* findLowestCommonAncestor(TreeNode* node, int n1, int n2) {//�ҹ�ͬ����
        if (node == nullptr) return nullptr;

        if (node->data > n1 && node->data > n2) {//��ǰ�ڵ��ֵ�� n1 �� n2 ����˵���������������������
            return findLowestCommonAncestor(node->left, n1, n2);
        }

        if (node->data < n1 && node->data < n2) {//��С����������������������ϣ�����ǰ�ڵ㼴Ϊ�����������
            return findLowestCommonAncestor(node->right, n1, n2);
        }

        return node;
    }
};



#endif // !

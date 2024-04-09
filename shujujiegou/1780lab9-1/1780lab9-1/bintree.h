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
            cout << path; // 输出节点路径
            cout << " - " << node->data / 60 << ":" << node->data % 60 << endl; // 输出起飞时刻
        }
        else if (level > 1) {
            printGivenLevel(node->left, level - 1, path + "0"); // 左子树
            printGivenLevel(node->right, level - 1, path + "1"); // 右子树
        }
    }

    void displayInLevelOrder() {//首先获取整个树的高度，然后从根节点开始，依次打印每一层的节点
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            printGivenLevel(root, i, "0");
        }
    }

    //逐层打印
    void levelOrderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {//层序遍历
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {//借助队列，先将根结点入队，然后循环出队首结点，并且将该结点的左子树和右子树加入队列中。
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
            cout << endl; // 换行表示当前层输出完毕
        }
    }

    int height(TreeNode* node) {//计算了以当前节点为根的子树的高度
        if (node == nullptr) {
            return 0;
        }
        else {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            return max(leftHeight, rightHeight) + 1;
        }
    }
    //递归遍历
    //先序遍历： 先根 再左 再右

    //中序遍历： 先左 再根 再右

    //后序遍历： 先左 再右 再根
    //先
    void preOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            int nodTime = node->data;
            cout << nodTime / 60 << ":" << nodTime % 60 << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }
    //中
    void inOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            int nodTime = node->data;
            cout << nodTime / 60 << ":" << nodTime % 60 << " ";
            inOrderTraversal(node->right);
        }
    }
    //后
    void postOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            int nodTime = node->data;
            cout << nodTime / 60 << ":" << nodTime % 60 << " ";
        }
    }
    //迭代遍历法
    //先序
    void preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                //cout << root->data << " ";
                int rootTime = root->data;
                cout << rootTime / 60 << ":" << rootTime % 60 << " ";

                s.push(root);     //若弹出的节点有右子节点，则将右子节点入栈。
                                  //若弹出的节点有左子节点，则将左子节点入栈。这样就保证了左子节点会在右子节点之前被访问。
                root = root->left;
            }
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    //中序
    void inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
                    //将当前节点的左子节点依次入栈，直到左子节点为空。
                    //从栈中弹出节点
                    //再将当前节点的右子节点入栈

            }
            root = s.top();
            s.pop();
            // cout << root->data << " ";
            int rootTime = root->data;
            cout << rootTime / 60 << ":" << rootTime % 60 << " ";

            root = root->right;
        }
    }




    //后序
    void postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1, s2;//s1推入s2
        s1.push(root);
        while (!s1.empty()) {
            root = s1.top();
            s1.pop();
            s2.push(root);//如果该节点有左孩子，则将左孩子压入 s1 栈中。
                          //如果该节点有右孩子，则将右孩子压入 s1 栈中。
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
    

    void getClosestFlight(TreeNode* node, int val, int& closestTime) {//递归遍历closestTime
        if (node != nullptr) {
            if (abs(node->data - val) < abs(closestTime - val)) {//计算差值并更新
                closestTime = node->data;
            }
            if (val < node->data) {//遍历决定左子右子
                getClosestFlight(node->left, val, closestTime);
            }
            else {
                getClosestFlight(node->right, val, closestTime);
            }
        }
    }
   
    TreeNode* findLowestCommonAncestor(TreeNode* node, int n1, int n2) {//找共同祖先
        if (node == nullptr) return nullptr;

        if (node->data > n1 && node->data > n2) {//当前节点的值比 n1 和 n2 都大，说明最近公共祖先在左子树
            return findLowestCommonAncestor(node->left, n1, n2);
        }

        if (node->data < n1 && node->data < n2) {//都小，最近公共祖先在右子树上，否则当前节点即为最近公共祖先
            return findLowestCommonAncestor(node->right, n1, n2);
        }

        return node;
    }
};



#endif // !

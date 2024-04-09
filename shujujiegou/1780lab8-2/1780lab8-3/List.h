
#ifndef __LIST_H 
#define __LIST_H
using namespace std;

// 链表节点
template<typename T>
struct ListNode {
    T val;
    ListNode<T>* next;

    ListNode(T x) : val(x), next(nullptr) {}
};

// 链表类
template<typename T>
class List {
private:
    int _size = 0;

public:
    ListNode<T>* head;
    List() : head(nullptr) {}

    void insertAsLast(T val) {
        _size++;
        ListNode<T>* newNode = new ListNode<T>(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            ListNode<T>* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = newNode;
        }
    }

    void display() {
        ListNode<T>* cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    bool empty() {
        return head == nullptr;
    }

    T get_front() const{
        if (head != nullptr) {
            return head->val;
        }
        else{
            throw std::runtime_error("List is empty");
        }
    }

    void pop() {
        if (head != nullptr) {
            _size--;
            ListNode<T>* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int size() { return _size; }
};

#endif 

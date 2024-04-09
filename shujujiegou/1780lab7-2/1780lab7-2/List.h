#pragma once
#ifndef __List_H__
#define __List_H__
template<typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& item) : data(item), next(nullptr) {}
    };

    Node* head;

public:
    List() : head(nullptr) {}

    bool empty() {
        return head == nullptr;
    }

    T first() {
        if (!empty()) {
            return head->data;
        }
        else {
            cout << "List is empty!" << endl;
            return T();
        }
    }

    int size() {
        int count = 0;
        Node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    void insertAsfirst(const T& item) {
        Node* newNode = new Node(item);
        if (empty()) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void remove() {
        if (!empty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            cout << "List is empty!" << endl;
        }
    }
};

#endif

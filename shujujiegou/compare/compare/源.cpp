#include <iostream>

using namespace std;

template<typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode(T value) : data(value), next(nullptr) {}
};

template<typename T>
class List {
protected:
    ListNode<T>* head;
    int size;

public:
    List() : head(nullptr), size(0) {}

    virtual ~List() {
        clear();
    }

    void push_back(T value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            ListNode<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void pop_front() {
        if (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    T front() const {
        if (head != nullptr) {
            return head->data;
        }
        else {
            throw runtime_error("List is empty");
        }
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    void clear() {
        ListNode<T>* current = head;
        while (current != nullptr) {
            ListNode<T>* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }
};

template<typename T>
class Queue : public List<T> {
public:
    void enqueue(T value) {
        this->push_back(value);
    }

    void dequeue() {
        this->pop_front();
    }

    T front() const {
        return this->front();
    }

    int getSize() const {
        return this->getSize();
    }

    bool empty() const {
        return this->empty();
    }

    void clear() {
        this->clear();
    }

    bool isFrontSmallest() const {
        if (this->empty()) {
            throw runtime_error("Queue is empty");
        }

        T frontElement = this->front();
        ListNode<T>* current = this->head->next;
        while (current != nullptr) {
            if (current->data < frontElement) {
                return false;
            }
            current = current->next;
        }
        return true;
    }
};

int main() {
    Queue<int> myQueue;

    myQueue.enqueue(6);
    myQueue.enqueue(2);
    myQueue.enqueue(9);
    myQueue.enqueue(4);
    myQueue.enqueue(1);

    if (myQueue.isFrontSmallest()) {
        cout << "The front element of the queue is the smallest in the queue." << endl;
    }
    else {
        cout << "The front element of the queue is not the smallest in the queue." << endl;
    }

    return 0;
}

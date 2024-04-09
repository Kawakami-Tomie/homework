
#ifndef __QUEUE_H
#define __QUEUE_H
using namespace std;

// 队列类
template<typename T>
class Queue {
private:
    List<T> list;

public:
    void enqueue(T val) {
        list.insertAsLast(val);
    }

    T dequeue() {
        if (!list.empty()) {
            T val = list.get_front();
            list.pop();
            return val;
        }
        else {
            throw runtime_error("Queue is empty");
        }
    }

    T front() const {
        return this->list.get_front();
    }

    bool empty() {
        return list.empty();
    }

    void display() {
        list.display();
    }
    //判断列车头是否最小
    int Size() {
        return list.size();
    }
    bool front_min() {
        if (!list.empty()) {
            T min_val = list.get_front();
            ListNode<T>* cur = list.head->next;
            while (cur != nullptr) {
                if (cur->val < min_val) {
                    min_val = cur->val;
                }
                cur = cur->next;
            }
            return min_val == list.get_front();
        }
        else {
            throw runtime_error("Queue is empty");
        }
    }
    //一个轨道推入另一个轨道
    void enqueue_front_to_rear(Queue<T>& q) {
        if (!list.empty()) {
            T front_val = list.get_front();
            q.enqueue(front_val);
        }
        else {
            throw runtime_error("Queue is empty");
        }
    }

    T peek() {
        if (!this->list.head) {
            std::cerr << "Queue is empty" << std::endl;
            exit(1);
        }
        ListNode<T>* current = this->list.head;
        while (current->next) {
            current = current->next;
        }
        return current->val;
    }


};

#endif 
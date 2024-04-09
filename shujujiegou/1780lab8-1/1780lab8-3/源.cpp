#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "List.h"
#include "Queue.h"
using namespace std;


// 定义缓冲轨道和出发轨道
Queue<int> bufferTracks[4];//缓冲轨道队列中永远只有一个元素
Queue<int> setoffTrack;
int buffer0, buffer1, buffer2, buffer3;

void findtrack()
{

    if (!bufferTracks[0].empty())
    {
        buffer0 = bufferTracks[0].front();
    }
    else buffer0 = 99;

    if (!bufferTracks[1].empty())
    {
        buffer1 = bufferTracks[1].front();
    }
    else buffer1 = 99;

    if (!bufferTracks[2].empty())
    {
        buffer2 = bufferTracks[2].front();
    }
    else buffer2 = 99;

    if (!bufferTracks[3].empty())
    {
        buffer3 = bufferTracks[3].front();
    }
    else buffer3 = 99;

}

int findMin(int a, int b, int c, int d)
{
    int minVal = a;  // 假设第一个数为最小值
    if (b < minVal) {
        minVal = b;
    }
    if (c < minVal) {
        minVal = c;
    }
    if (d < minVal) {
        minVal = d;
    }
    return minVal;
}

int min_track()
{
    findtrack();
    int mintrack = findMin(buffer0, buffer1, buffer2, buffer3);
    if (mintrack == buffer0)return 0;
    else if (mintrack == buffer1)return 1;
    else if (mintrack == buffer2)return 2;
    else if (mintrack == buffer3)return 3;
    else return 99;
}

int main() {
    // 生成随机编组序列
again:
    vector<int> Arrival{1,4,5,6,3,2};
    random_device rd;
    mt19937 g(rd());
    shuffle(Arrival.begin(), Arrival.end(), g);
    Queue<int>arrival{};
    for (int i = 0; i < Arrival.size(); i++) {
           arrival.enqueue(Arrival[i]);
    }

    if (!setoffTrack.empty())//重新生成到达序列时先清空
    {
        int Tracklength = setoffTrack.Size();
        for (int i = 0; i < Tracklength; i++) {
            setoffTrack.dequeue();
        }

    }


    // 打印随机编组序列
    cout << "到达序列为：";  
    arrival.display();   
    cout << endl;
    // 只要到达轨道和缓冲轨道都不为空，就进行编组
    while (!(arrival.empty() && bufferTracks[0].empty() && bufferTracks[1].empty() && bufferTracks[2].empty() && bufferTracks[3].empty()))//到达序列非空执行
    {
        // 查找空闲的缓冲轨道
        int bufferTrack = -1;
        int count = 0;
        bool mini_flag = 0;
        int canpushtosetofftrack = -1;
        if (!arrival.empty())//到达队列非空时才进行空轨查找
        {
            for (int i = 0; i < 4; i++)
            {
                if (bufferTracks[i].empty())
                {
                    bufferTrack = i;
                    break;
                }
            }

            arrival.enqueue_front_to_rear(bufferTracks[bufferTrack]);//入缓冲轨道
            cout << arrival.front() << "号车厢推入" << bufferTrack + 1 << "#缓冲轨" << endl;

            

            if (arrival.front_min())//队首元素最小，再与缓冲轨道元素比较,可直接推入出发轨道
            {
                canpushtosetofftrack = min_track();
            min_flag:
                bufferTracks[canpushtosetofftrack].enqueue_front_to_rear(setoffTrack);;
                // 打印编组动作
                cout << bufferTracks[canpushtosetofftrack].front() << "号车厢从" << canpushtosetofftrack + 1 << "#缓冲轨推入出发区，出发队列为";
                setoffTrack.display();

                bufferTracks[canpushtosetofftrack].dequeue();//推入出发轨道后缓冲轨道为空

            }


             if(mini_flag==0)   arrival.dequeue();//到达队列删除队首   


        }
        //到达轨道清空，处理缓冲轨道
        else if (arrival.empty())
        {
            canpushtosetofftrack = min_track();//缓冲轨道自我比较找最小
            bufferTracks[canpushtosetofftrack].enqueue_front_to_rear(setoffTrack);;
            // 打印编组动作
            cout << bufferTracks[canpushtosetofftrack].front() << "号车厢从" << canpushtosetofftrack + 1 << "#缓冲轨推入出发区，出发队列为";
            setoffTrack.display();

            bufferTracks[canpushtosetofftrack].dequeue();//推入出发轨道后缓冲轨道为空


        }
      //专门处理一种情况
        if (!bufferTracks[0].empty())
        {
            if (!bufferTracks[1].empty())
            {
                if (!bufferTracks[2].empty())
                {
                    if (!bufferTracks[3].empty())
                    {
                        
                        if (arrival.Size() == 1)
                        
                        {
                               findtrack();
                               int BUFF = findMin(buffer0, buffer1, buffer2, buffer3);
                               // int BUFF = bufferTracks[i].front();
                                int ARR = arrival.front();
                                if (BUFF < ARR)
                                {
                                    bufferTrack = min_track();
                                    mini_flag = 1;
                                    canpushtosetofftrack = bufferTrack;
                                    goto min_flag;//2,1,4,5,6,3
                                }
                            
   
                        }

                            cout << "无法进行编组" << endl;
                            char choose = 'N';
                            cout << "是否重新编组（Y/N）" << endl;
                            cin >> choose;
                            if (choose == 'Y')
                                bufferTracks[0].dequeue();
                                bufferTracks[1].dequeue();
                                bufferTracks[2].dequeue();
                                bufferTracks[3].dequeue();
                                goto again;

         
                        
                    }
                }
            }
        }
    }
    char choose = 'N';
    cout << "是否重新编组（Y/N）" << endl;
    cin >> choose;
    if (choose == 'Y')goto again;
    //两条缓冲轨道

    vector<int> Arrival1{ 2,1,4,5,6,3,7,8,9,10 };
    random_device rd1;
    mt19937 g1(rd1());
    shuffle(Arrival1.begin(), Arrival1.end(), g1);
    Queue<int>arrival1{};
    Queue<int>arrival2{};
    for (int i = 0; i < Arrival1.size(); i++) {
        if(i % 2 == 0 ) arrival1.enqueue(Arrival1[i]);
        else if (i % 2 == 1) arrival2.enqueue(Arrival1[i]);
    }
    // 打印随机编组序列
    cout << "到达序列1为：";
    arrival1.display();
    cout << endl;
    cout << "到达序列2为：";
    arrival2.display();
    cout << endl;



    return 0;
}






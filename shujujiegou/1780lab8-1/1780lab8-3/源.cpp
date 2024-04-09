#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "List.h"
#include "Queue.h"
using namespace std;


// ���建�����ͳ������
Queue<int> bufferTracks[4];//��������������Զֻ��һ��Ԫ��
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
    int minVal = a;  // �����һ����Ϊ��Сֵ
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
    // ���������������
again:
    vector<int> Arrival{1,4,5,6,3,2};
    random_device rd;
    mt19937 g(rd());
    shuffle(Arrival.begin(), Arrival.end(), g);
    Queue<int>arrival{};
    for (int i = 0; i < Arrival.size(); i++) {
           arrival.enqueue(Arrival[i]);
    }

    if (!setoffTrack.empty())//�������ɵ�������ʱ�����
    {
        int Tracklength = setoffTrack.Size();
        for (int i = 0; i < Tracklength; i++) {
            setoffTrack.dequeue();
        }

    }


    // ��ӡ�����������
    cout << "��������Ϊ��";  
    arrival.display();   
    cout << endl;
    // ֻҪ�������ͻ���������Ϊ�գ��ͽ��б���
    while (!(arrival.empty() && bufferTracks[0].empty() && bufferTracks[1].empty() && bufferTracks[2].empty() && bufferTracks[3].empty()))//�������зǿ�ִ��
    {
        // ���ҿ��еĻ�����
        int bufferTrack = -1;
        int count = 0;
        bool mini_flag = 0;
        int canpushtosetofftrack = -1;
        if (!arrival.empty())//������зǿ�ʱ�Ž��пչ����
        {
            for (int i = 0; i < 4; i++)
            {
                if (bufferTracks[i].empty())
                {
                    bufferTrack = i;
                    break;
                }
            }

            arrival.enqueue_front_to_rear(bufferTracks[bufferTrack]);//�뻺����
            cout << arrival.front() << "�ų�������" << bufferTrack + 1 << "#�����" << endl;

            

            if (arrival.front_min())//����Ԫ����С�����뻺����Ԫ�رȽ�,��ֱ������������
            {
                canpushtosetofftrack = min_track();
            min_flag:
                bufferTracks[canpushtosetofftrack].enqueue_front_to_rear(setoffTrack);;
                // ��ӡ���鶯��
                cout << bufferTracks[canpushtosetofftrack].front() << "�ų����" << canpushtosetofftrack + 1 << "#������������������������Ϊ";
                setoffTrack.display();

                bufferTracks[canpushtosetofftrack].dequeue();//�����������󻺳���Ϊ��

            }


             if(mini_flag==0)   arrival.dequeue();//�������ɾ������   


        }
        //��������գ���������
        else if (arrival.empty())
        {
            canpushtosetofftrack = min_track();//���������ұȽ�����С
            bufferTracks[canpushtosetofftrack].enqueue_front_to_rear(setoffTrack);;
            // ��ӡ���鶯��
            cout << bufferTracks[canpushtosetofftrack].front() << "�ų����" << canpushtosetofftrack + 1 << "#������������������������Ϊ";
            setoffTrack.display();

            bufferTracks[canpushtosetofftrack].dequeue();//�����������󻺳���Ϊ��


        }
      //ר�Ŵ���һ�����
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

                            cout << "�޷����б���" << endl;
                            char choose = 'N';
                            cout << "�Ƿ����±��飨Y/N��" << endl;
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
    cout << "�Ƿ����±��飨Y/N��" << endl;
    cin >> choose;
    if (choose == 'Y')goto again;
    //����������

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
    // ��ӡ�����������
    cout << "��������1Ϊ��";
    arrival1.display();
    cout << endl;
    cout << "��������2Ϊ��";
    arrival2.display();
    cout << endl;



    return 0;
}






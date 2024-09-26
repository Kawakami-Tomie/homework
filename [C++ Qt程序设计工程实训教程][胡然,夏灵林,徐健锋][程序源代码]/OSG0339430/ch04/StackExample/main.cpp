#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    for (int i = 0; i < 5; i++)
    {
        cout << "push " << i << " to stack;" << endl;
        s.push(i);
    }
    while (!s.empty())
    {
        int top = s.top(); s.pop();
        cout << "pop " << top << " from stack;" << endl;
    }
    return 0;
}

#include "../leetcode.h"

class MyStack
{
private:
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);

        int size = q.size(); // rorate to make sure x is the first element of q;
        for (int i = 0; i < size - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int v = q.front();
        q.pop();
        return v;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main() {
    MyStack s;
    s.push(2);
    int a = s.top();
    s.push(1);
    a = s.top();
    a = s.pop();
    a = s.top();
    bool b = s.empty();
    cout << b;
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
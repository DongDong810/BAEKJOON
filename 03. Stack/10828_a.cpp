#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

int size()
{
    return pos;
}

int empty()
{
    return pos == 0;
}

void push(int x)
{
    dat[pos++] = x;
}

int pop()
{
    if (empty()) return -1;
    return dat[--pos];
}

int top()
{
    if (empty()) return -1;
    return dat[pos - 1];
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while (N-- > 0)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int num; 
            cin >> num; 
            push(num);
        }
        else if (s == "pop")
            cout << pop() << "\n"; 
        else if (s == "size")
            cout << size() << "\n"; 
        else if (s == "empty")
            cout << empty() << "\n"; 
        else
            cout << top() << "\n"; 
    }
}
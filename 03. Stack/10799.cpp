#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    stack<char> stk;
    int total = 0;
    char prev = 0;
    for (auto c : s)
    {
        if (c == '(')
            stk.push(c);
        else
        {
            stk.pop();
            int increase = (prev == '(') ? stk.size() : 1;
            total += increase;
        }
        prev = c;
    }
    cout << total;
}
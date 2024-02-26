#include <bits/stdc++.h>
using namespace std;

// '(' => -2 / '[' => -3 / ')' => 2 / ']' => 3
int main() 
{
    ios::sync_with_stdio (0);
    cin.tie(0);
    string s;
    cin >> s;
    stack<int> stk;
    int total = 0;
    bool isValid = true;
    for (auto c : s)
    {
        if (c == '(' || c == '[')
        {
            int num = (c == '(') ? -2 : -3;
            stk.push(num);
        }
        else
        {
            int tmp = 0;
            while (!stk.empty() && stk.top() > 0)
            {
                tmp += stk.top();
                stk.pop();
            }
            // -2 or -3
            int num = (c == ')') ? 2 : 3;
            if (stk.empty() || num != -stk.top())
            {
                isValid = false;
                break;
            }
            stk.pop();
            if (tmp == 0) stk.push(num);
            else stk.push(tmp * num);
        }
    }
    while (!stk.empty())
    {
        if (stk.top() < 0)
        {
            isValid = false;
            break;
        } 
        total += stk.top();
        stk.pop();
    } 
    if (isValid) cout << total;
    else cout << 0;
}
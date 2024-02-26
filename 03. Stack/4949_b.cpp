#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true)
    {
        string s;
        getline(cin, s);
        if (s == ".") break;
        stack<char> stk;
        bool isValid = true;
        for (auto c : s)
        {
            if (c == '(' || c == '[')
                stk.push(c);
            else if (c == ')' || c == ']')
            {
                char opp = (c == ')') ? '(' : '[';
                if (stk.empty() || stk.top() != opp)
                {
                    isValid = false;
                    break;
                }
                stk.pop();
            }  
        }
        if (!stk.empty()) isValid = false;
        if (isValid) cout << "yes\n";
        else cout << "no\n";
    }
}
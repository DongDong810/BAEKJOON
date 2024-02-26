#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    getline(cin, input);
    while (input != ".")
    {
        stack<char> stk;
        for (char c : input)
        {
            if (c == '.')
            {
                if (stk.size() == 0)
                    cout << "yes\n";
                else
                    cout << "no\n";
            }
            if (c == '(' || c == '[')
                stk.push(c);
            else if (c == ')' || c == ']')
            {
                char opp = (c == ')') ? '(' : '[';
                if (stk.size() == 0 || stk.top() != opp)
                {
                    cout << "no\n";
                    break;
                }
                else
                    stk.pop();
            }  
        }
        getline(cin, input);
    }
}
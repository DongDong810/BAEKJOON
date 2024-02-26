#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    stack<int> stk;
    while (N-- > 0)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int num; 
            cin >> num; 
            stk.push(num);
        }
        else if (s == "pop")
        {
            if (stk.size() == 0)
                cout << -1 << "\n";
            else  
            {
                int top = stk.top();
                stk.pop();
                cout << top << "\n";
            }         
        }
        else if (s == "size")
            cout << stk.size() << "\n"; 
        else if (s == "empty")
        {
            if (stk.size() == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }    
        else
        {
            if (stk.size() == 0)
                cout << -1 << "\n";
            else
                cout << stk.top() << "\n"; 
        }     
    }
}
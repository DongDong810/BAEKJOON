#include <bits/stdc++.h>
using namespace std;

list<char> L;
int M;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s >> M;

    for (auto c : s)
        L.push_back(c);
    auto cur = L.end();

    while (M-- > 0)
    {
        char com;
        cin >> com;
        switch (com)
        {
            case 'L': if (cur != L.begin())
                        cur--; break;
            case 'D': if (cur != L.end())
                        cur++; break;
            case 'B': if (cur != L.begin())
                        cur = L.erase(--cur); break;
            default: char c;
                     cin >> c; L.insert(cur ,c); 
        }
    }
    for (auto c : L)
        cout << c;
}
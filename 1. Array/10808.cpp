#include <bits/stdc++.h>
using namespace std;

string word;
int alphabet[26] = { };

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> word;
    for (auto c : word)
        alphabet[c - 'a'] += 1;
    
    for (int i = 0; i < 26; i++)
        cout << alphabet[i] << " ";
}
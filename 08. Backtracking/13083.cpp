#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N;
vector<int> cur;
vector<string> candidate;
int vis[10] = { };

void makePermutation()
{
    if (cur.size() == N)
    {
        string output;
        for (int n : cur)
            output += to_string(n);
        candidate.push_back(output);
    }

    for (int i = 0; i <= 9; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            cur.push_back(i);
            makePermutation();
            vis[i] = 0;
            cur.pop_back();
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string old;
    ll oldNum;
    cin >> old;
    N = old.size();
    oldNum = stoll(old);
    makePermutation();

    ll maxDiff = 0;
    string ans;
    for (string s : candidate)
    {
        ll curDiff = min(abs(stoll(s) - oldNum), (ll)pow(10, N) - abs(stoll(s) - oldNum));
        if (curDiff > maxDiff)
        {
            maxDiff = curDiff;
            ans = s;
        }
    }
    cout << ans;
}
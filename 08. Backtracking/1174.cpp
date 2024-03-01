#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N;
vector<int> cur = { };
vector<ll> order= { };
int iNum = 0;
bool found = false;

void makeCombination(int k, int start)
{
    if (cur.size() == k)
    {
        iNum++;
        ll tmp = 0;
        for (int i = 0; i < cur.size(); i++)
            tmp += cur[i] * pow(10, i);
        order.push_back(tmp);
        if (iNum == N)
            found = true;
        return;
    }

    for (int i = start; i <= 9; i++)
    {
        cur.push_back(i);
        makeCombination(k, i + 1);
        cur.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int choose = 1;
    while (choose <= 10 && !found)
        makeCombination(choose++, 0);

    if (found)
    {
        sort(order.begin(), order.end());
        cout << order[N-1];
    }
    else 
        cout << -1;
}
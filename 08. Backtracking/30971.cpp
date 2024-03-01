#include <bits/stdc++.h>
using namespace std;

int N, K;
int A[12], B[12], C[12], vis[12];
vector<int> cur, candidate;

void makePermutation() // idx: 새롭게 선택할 시식대 번호
{
    if (cur.size() == N)
    {
        int total = 0;
        for (int i = 1; i <= N-1; i++)
            total += (A[cur[i-1]] * B[cur[i]]);
        candidate.push_back(total);
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            if (cur.size() > 0 && C[cur[cur.size()-1]] * C[i] > K) continue;
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
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> B[i];    
    for (int i = 1; i <= N; i++)
        cin >> C[i];
    vis[12] = { };
    makePermutation();

    if (candidate.size() == 0) cout << -1;
    else cout << *max_element(candidate.begin(), candidate.end());
    return 0;
}
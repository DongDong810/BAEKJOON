#include <bits/stdc++.h>
using namespace std;

int N, K;
int dist[100010];
queue<int> Q;

int BFS()
{
    while (dist[K] == -1)
    {
        int cur = Q.front(); Q.pop();
        for (int nxt : {cur-1, cur+1, cur*2})
        {
            if (nxt < 0 || nxt  > 100000) continue;
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    return dist[K];
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    fill(dist, dist + 100010, -1);
    dist[N] = 0;
    Q.push(N);
    cout << BFS();
}
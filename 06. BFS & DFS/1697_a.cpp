#include <bits/stdc++.h>
using namespace std;

int N, K;
int vis[100010];
queue<int> Q;
int dx[3] = {1, -1, 2};

int BFS()
{
    int t = 0;
    while (true)
    {
        int rep = Q.size();
        for (int i = 0; i < rep; i++)
        {
            int cur = Q.front(); Q.pop();
            if (cur == K) return t;

            for (int dir = 0; dir < 3; dir++)
            {
                int nx;
                if (dir < 2)
                    nx = cur + dx[dir];
                else
                    nx = cur * 2;
                if (nx < 0 || nx  > 100000 || vis[nx]) continue;
                vis[nx] = 1;
                Q.push(nx);
            }
        }
        t++;
    }
    return -1; // not happen
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    vis[N] = 1;
    Q.push(N);
    cout << BFS();
}
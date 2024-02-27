#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int board[105][105];
int dist[105][105];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> Q;

void BFS()
{
    dist[0][0] = 1;
    Q.push({0, 0});
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (board[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = s[j] - '0';
            dist[i][j] = -1;
        }
    }

    // do BFS
    BFS();
    cout << dist[N-1][M-1];
}
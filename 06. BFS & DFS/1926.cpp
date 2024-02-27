#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[505][505];
bool vis[505][505];
int N, M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> Q;
int total = 0;
int maxA = 0;

int BFS(int x, int y)
{
    int area = 1;
    vis[x][y] = true;
    Q.push({x, y});
    while (!Q.empty())
    {
        int cx = Q.front().X;
        int cy = Q.front().Y;
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
            area++;
        }
    }
    return area;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    // do BFS
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 1 && !vis[i][j])
            {
                int tmp = BFS(i, j);
                maxA = max(tmp, maxA);
                total++;
            }
        }
    }
    cout << total << "\n" << maxA;
}
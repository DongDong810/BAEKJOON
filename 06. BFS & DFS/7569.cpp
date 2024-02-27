#include <bits/stdc++.h>
using namespace std;

int M, N, H;
int board[102][102][102];
int dist[102][102][102];
queue<tuple<int, int, int>> Q;
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

void BFS()
{
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        int cx = get<0>(cur);
        int cy = get<1>(cur);
        int cz = get<2>(cur);
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            int nz = cz + dz[dir];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= H || ny >= N || nz >= M)
                continue;
            if (board[nx][ny][nz] == -1 || dist[nx][ny][nz] >= 0)
                continue;
            dist[nx][ny][nz] = dist[cx][cy][cz] + 1;
            Q.push({nx, ny, nz});
        }   
    }
}

int check()
{
    int tmp = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (dist[i][j][k] == -1)
                    return -1;
                tmp = max(tmp, dist[i][j][k]);
            }
        }
    }
    return tmp;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> board[i][j][k];
                dist[i][j][k] = -1; // -1 초기화
                if (board[i][j][k] == 1) // 익은 경우
                {
                    dist[i][j][k] = 0;
                    Q.push({i, j, k});
                }
                if (board[i][j][k] == -1) // 빈 경우
                    dist[i][j][k] = 0;
            }
        }
    }

    // do BFS
    BFS();
    cout << check();
}
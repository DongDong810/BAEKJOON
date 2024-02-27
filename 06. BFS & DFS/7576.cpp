#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int board[1010][1010]; // 자동 0 초기화
int dist[1010][1010]; // 자동 0 초기화
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> Q;

void BFS()
{
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
}

int findMax()
{
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dist[i][j] == -1)
                return -1;
            tmp = max(tmp, dist[i][j]);
        }
    }    
    return tmp;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                Q.push({i, j});
            if (board[i][j] == 0)
                dist[i][j] = -1; // 익지 않은 것 표시
        }
    }

    // do BFS
    BFS();
    int date = findMax();
    std::cout << date;
}
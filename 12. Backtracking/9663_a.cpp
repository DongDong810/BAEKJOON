#include <bits/stdc++.h>
using namespace std;

int N;
int visited[16][16] = { };
int total = 0;
int dx[4] = {1, 1, -1, -1};
int dy[4] = {-1, 1, 1, -1};

void checkX(int x, int y, bool increase)
{
    // 가로 & 세로
    for (int i = 1; i <= N; i++)
    {
        if (increase)
        {
            if (visited[i][y] >= 0) visited[i][y] += 1;
            if (visited[x][i] >= 0) visited[x][i] += 1;
        }
        else
        {
            if (visited[i][y] > 0) visited[i][y] -= 1;
            if (visited[x][i] > 0) visited[x][i] -= 1;
        }
    }

    // 대각선
    for (int dir = 0; dir < 4; dir++)
    {
        int curX = x, curY = y;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        while (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
        {
            if (increase & visited[nx][ny] >= 0)
                visited[nx][ny] += 1;
            else if (!increase & visited[nx][ny] > 0)
                visited[nx][ny] -= 1;
            nx += dx[dir];
            ny += dy[dir];
        }
    }
}

void placeQueen(int depth) // depth: 행의 인덱스
{
    if (depth == N)
    {
        total += 1;
        return;
    }
    for (int c = 1; c <= N; c++)
    {
        if (!visited[depth][c])
        {
            visited[depth][c] = -1;
            checkX(depth, c, true);
            placeQueen(depth + 1);
            visited[depth][c] = 0;
            checkX(depth, c, false);
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    placeQueen(0);
    cout << total;
}
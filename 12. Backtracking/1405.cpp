#include <bits/stdc++.h>
using namespace std;

int N;
int board[100][100];
bool visited[100][100];
// 동 서 남 북 순서
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
double prob[4] = { };
double simple = 0;

void move(int x, int y, int repeat, double curProb)
{
    if (repeat == N)
    {
        simple += curProb;
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!visited[nx][ny])
        {
            move(nx, ny, repeat + 1, curProb * prob[i]);
            visited[nx][ny] = false;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < 4; i++)
    {
        double tmp;
        cin >> tmp;
        prob[i] = tmp / 100;
    }
    move(50, 50, 0, 1);
    cout.precision(20);
    cout << simple;
}
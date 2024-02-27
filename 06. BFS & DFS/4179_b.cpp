#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int R, C;
char board[1010][1010];
int human[1010][1010];
int fire[1010][1010];
queue<pair<int ,int>> Fire;
queue<pair<int ,int>> Human;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void BFS_Fire()
{
    while (!Fire.empty())
    {
        auto cur = Fire.front(); Fire.pop();
        for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if (board[nx][ny] == '#' || fire[nx][ny] != -1) continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                Fire.push({nx, ny});
            }
    }
}
 
int BFS_Human()
{
    while (!Human.empty())
    {
        auto cur = Human.front(); Human.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                return human[cur.X][cur.Y] + 1;
            // fire = -1 -> 벽 or 아예 불이 없는 경우
            if (fire[nx][ny] != -1 && human[cur.X][cur.Y] + 1 >= fire[nx][ny]) continue;
            if (board[nx][ny] == '#' || human[nx][ny] != -1) continue;
            human[nx][ny] = human[cur.X][cur.Y] + 1;
            Human.push({nx, ny});
        }
    }   
    return -1;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++)
        {
            board[i][j] = s[j];
            human[i][j] = -1;
            fire[i][j] = -1;
            if (s[j] == 'J')
            {
                human[i][j] = 0;
                Human.push({i, j});
            }
            else if (s[j] == 'F')
            {
                fire[i][j] = 0;
                Fire.push({i, j});
            }   
        }
    }

    // do BFS
    BFS_Fire();
    int result = BFS_Human();
    if (result > 0) cout << result;
    else cout << "IMPOSSIBLE";
}
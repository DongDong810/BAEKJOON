#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int R, C;
char board[1010][1010];
int dist[1010][1010];
queue<pair<int ,int>> Fire;
queue<pair<int ,int>> Human;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int BFS()
{
    while (!Human.empty())
    {
        // 사람 이동
        int rep = Human.size();
        for (int i = 0; i < rep; i++)
        {
            auto cur = Human.front(); Human.pop();
            if (board[cur.X][cur.Y] == 'F') continue;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                    return dist[cur.X][cur.Y] + 1;
                if (board[nx][ny] != '.' || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Human.push({nx, ny});
            }
        }
        // 불 이동
        rep = Fire.size();
        for (int i = 0; i < rep; i++)
        {
            auto cur = Fire.front(); Fire.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                if (board[nx][ny] == '.' || board[nx][ny] == 'J')
                {
                    board[nx][ny] = 'F';
                    Fire.push({nx, ny});
                }
            }
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
            dist[i][j] = -1;
            if (s[j] == 'J')
            {
                dist[i][j] = 0;
                Human.push({i, j});
            }
            else if (s[j] == 'F')
                Fire.push({i, j});
        }
    }

    // do BFS
    int result = BFS();
    if (result > 0) cout << result;
    else cout << "IMPOSSIBLE";
}
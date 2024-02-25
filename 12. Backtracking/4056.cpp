#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int T;
int board[9][9];
vector<pair <int, int>> blanks;
vector<pair <int, int>> box = {{0, 0}, {0, 3}, {0, 6},
                               {3, 0}, {3, 3}, {3, 6},
                               {6, 0}, {6, 3}, {6, 6}};

bool check()
{
    // 가로 & 세로
    int width[82] = { };
    int height[82] = { };
    for (int i = 0; i < 9; i ++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (width[board[i][j] + 9 * i] || height[board[i][j] + 9 * j])
                return false;
            width[board[i][j] + 9 * i] = 1;
            height[board[i][j] + 9 * j] = 1;
        }
    }
    // 3x3
    int square[82] = { };
    int rep = 0;
    for (pair<int, int> p : box)
    {
        for (int i = p.X; i < p.X + 3; i++)
        {
            for (int j = p.Y; j < p.Y + 3; j++)
            {
                if (square[board[i][j] + 9 * rep])
                    return false;
                square[board[i][j] + 9 * rep] = 1;
            }
        }
        rep++;
    }
    
    return true;
}

bool putNum(int i)
{
    if (i == 5)
    {
        if (check())
            return true;
        return false;
    }
    for (int num = 1; num <= 9; num++)
    {
        board[blanks[i].X][blanks[i].Y] = num;
         if (putNum(i + 1))
            return true;
    }
    // not found
    return false;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T-- > 0)
    {
        blanks.clear();
        for (int i = 0; i < 9; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < 9; j++)
            {
                int tmp = s[j] - '0';
                board[i][j] = tmp;
                if (tmp == 0)
                    blanks.push_back({i, j});
            }
        }

        if (putNum(0))
        {
            for (int i = 0; i < 9; i ++)
            {
                for (int j = 0; j < 9; j++)
                    cout << board[i][j];
                cout << "\n";
            }
            cout << "\n";
        }
        else
            cout << "Could not complete this grid.\n\n"; 
    }
}
#include <bits/stdc++.h>
using namespace std;

int N, D;
vector<vector<int>> checkList;
vector<vector<int>> board;
vector<int> nums;
int result[10][10];

bool putNum(int i)
{
    if (i == D)
        return true;

    vector<int> tmp(nums);  
    do
    {
        bool can = true;
        for (int j = 0; j < D; j++)
        {
            if (checkList[j][tmp[j]])
                {
                    can = false;
                    break;
                }
        }
        // 성공
        if (can)
        {
            for (int j = 0; j < D; j++)
            {
                board[i][j] = tmp[j];
                checkList[j][tmp[j]] = 1;
            }
            if (putNum(i + 1)) return true;
            for (int j = 0; j < D; j++)
            {
                board[i][j] = 0;
                checkList[j][tmp[j]] = 0;
            }
        }
    } while (next_permutation(tmp.begin(), tmp.end()));

    return false;
}

void show()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i < N - D && j >= N - D)
                cout << nums[j - N + D] << " ";
            else if (i >= N - D && j < N - D)
                cout << nums[i - N + D] << " ";
            else if (i < N - D && j < N - D)
                cout << 0 << " ";
            else
            {
                cout << board[i - N + D][j - N + D] << " ";
            }
        }
        cout << endl;
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> D;

    for (int i = 0; i < D; i++)
        nums.push_back(i);

    board.resize(D, vector<int>(D));
    checkList.resize(D, vector<int>(D));
    putNum(0);
    show();
}
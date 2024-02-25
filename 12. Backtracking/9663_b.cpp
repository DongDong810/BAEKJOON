#include <bits/stdc++.h>
using namespace std;

int N;
int total = 0;
bool isused1[16];
bool isused2[32];
bool isused3[32];

void placeQueen(int x) // 
{
    if (x == N)
    {
        total += 1;
        return;
    }

    for (int y = 0; y < N; y++)
    {
        if (!isused1[y] && !isused2[x + y] && !isused3[x - y + N - 1])
        {
            isused1[y] = true;
            isused2[x + y] = true;
            isused3[x - y + N - 1] = true;
            placeQueen(x + 1);
            isused1[y] = false;
            isused2[x + y] = false;
            isused3[x - y + N - 1] = false;
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
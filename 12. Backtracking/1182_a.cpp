#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[20];
int cases = 0;

void addSequences(int idx, int current)
{
    if (idx == N)
    {
        if (current == S)
            cases++;
        return;
    }

    addSequences(idx + 1, current);
    addSequences(idx + 1, current + arr[idx]);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    addSequences(0, 0);
    // 공집합 제외
    if (S == 0) 
        cases--;
    cout << cases;
}
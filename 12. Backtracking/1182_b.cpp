#include <bits/stdc++.h>
using namespace std;

int N, S;
int arr[20];
int cases = 0;

// n개 중에서 k개 뽑기
void makeCombination(int n, int k, int size, int current, int start)
{
    if (size == k)
    {
        if (current == S)
            cases++;
        return;
    }

    for (int i = start; i < N; i++)
    {
        makeCombination(n, k, size + 1, current + arr[i], i + 1);
    }

}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int num = 1; num <= N; num++)
    {
        makeCombination(N, num, 0, 0, 0);
    }

    cout << cases;
}
#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[110];
vector<int> results;

void makeSnow(int t, int idx, int cur)
{
    if (t == M || idx == N)
    {
        results.push_back(cur);
        return;
    }
    // 1칸
    if (idx < N)
        makeSnow(t + 1, idx + 1, cur + arr[idx + 1]);
    // 2칸
    if (idx < N - 1)
        makeSnow(t + 1, idx + 2, (int)(cur / 2) + arr[idx + 2]);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    makeSnow(0, 0, 1);

    vector<int>::iterator max_it = max_element(results.begin(), results.end());
    cout << *max_it;
}
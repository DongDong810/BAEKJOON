#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> arr, candidate, cur;
set<int> result;

void makeCombination(int n, int m, int start)
{
    if (cur.size() == m)
    {
        int total = 0;
        for (int num : cur)
            total += num;
        candidate.push_back(total);
        return;
    }

    for (int i = start; i < n; i++)
    {
        cur.push_back(arr[i]);
        makeCombination(n, m, i + 1);
        cur.pop_back();
    }
}

bool isPrime(int n)
{
    for (int i = 2; i <= (int)sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    makeCombination(N, M, 0);

    for (int num : candidate)
        if (isPrime(num))
            result.insert(num);
    
    if (result.size() == 0)
        cout << -1 << " ";
    else 
    {
        for (int num : result)
        cout << num << " ";
    }
}
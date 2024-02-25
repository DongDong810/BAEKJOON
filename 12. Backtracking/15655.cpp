#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
vector<int> current;

void makeCombination(int n, int m, int start)
{
    if (current.size() == m)
    {
        for (int n : current)
            cout << n << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i < n; i++)
    {
        current.push_back(arr[i]);
        makeCombination(n, m, i + 1);
        current.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    makeCombination(n, m, 0);
}
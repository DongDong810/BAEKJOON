#include <bits/stdc++.h>
using namespace std;

int n, m;

void makePermutation(vector<int>& current, vector<bool>& visited, int n, int m)
{
    if (current.size() == m)
    {
        for (int n : current)
            cout << n << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            current.push_back(i);
            makePermutation(current, visited, n, m);
            visited[i] = false;
            current.pop_back();
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> current;
    vector<bool> visited(n + 1, false);
    makePermutation(current, visited, n, m);
}
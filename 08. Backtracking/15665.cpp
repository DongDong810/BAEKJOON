#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> nums;
vector<int> current;

void makePermutation(int n, int m)
{
    if (current.size() == m)
    {
        for (int n : current)
            cout << n << " ";
        cout << "\n";
        return;
    }

    for (int num : nums)
    {
        current.push_back(num);
        makePermutation(n, m);
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
        nums.insert(tmp);
    }

    makePermutation(n, m);
}
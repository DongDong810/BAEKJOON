#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string old;
    ll oldNum;
    cin >> old; 
    int N = old.size();
    oldNum = stoll(old);
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ll maxDiff = 0;
    string ans;
    do
    {
        string tmp;
        for (int i = 0; i < N; i++)
            tmp += to_string(arr[i]);
        ll newNum =  stoll(tmp);
        if (newNum == oldNum) continue;
        ll curDiff = min(abs(newNum - oldNum), (ll)pow(10, N) - abs(newNum - oldNum));
        if (curDiff > maxDiff)
        {
            maxDiff = curDiff;
            ans = tmp;
        }
    } while (next_permutation(arr, arr + 10));
    std::cout << ans;
}
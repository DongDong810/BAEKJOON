#include <bits/stdc++.h>
using namespace std;

int T, k;
vector<string> arr(26);
string word, leet;

int check(int iWord, int iLeet)
{
    if (word.size() == iWord && leet.size() == iLeet)
        return 1;
    if (word.size() <= iWord || leet.size() <= iLeet)
        return 0;
    // word.size() > iWord && leet.size() > iLeet
    char c = word[iWord];
    if (arr[c - 'a'] != "")
    {
        string target = arr[c - 'a'];
        // leet에서 범위 넘는지 먼저 확인
        if (iLeet + target.size() - 1 < leet.size() && target == leet.substr(iLeet, target.size()))
        {
            if (check(iWord + 1, iLeet + target.size()))
                return 1;
        }
        else
            return 0;
    }
    else
    {
        for (int i = 1; i <= k; i++)
        {
            // leet에서 범위 넘는지 먼저 확인
            if (iLeet + i - 1 >= leet.size())
                continue;
            arr[word[iWord] - 'a'] = leet.substr(iLeet, i);
            if (check(iWord + 1, iLeet + i))
                return 1;
            arr[word[iWord] - 'a'] = "";
        }
    }
    return 0;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T-- > 0)
    {
        arr.assign(26, "");
        cin >> k >> word >> leet;
        cout << check(0, 0) << "\n";
    }
}
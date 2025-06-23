#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string word;
        cin >> word;
        if (n == 3)
        {
            if (word[0] == word[1] || word[2] == word[1])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        int hash[26] = {0};
        for (int i = 1; i < n - 1; i++)
        {
            hash[word[i] - 'a']++;
        }
        bool isRepeated = false;
        for (int i = 0; i < 26; i++)
        {
            if (hash[i] > 1)
            {
                isRepeated = true;
                break;
            }
        }
        if (isRepeated)
            cout << "Yes";
        else
            cout << "No";
        return 0;
    }
}
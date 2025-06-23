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
        string s;
        cin >> s;

        int freq[26] = {0};
        for (int i = 2; i < n; ++i)
        {
            freq[s[i] - 'a']++;
        }

        unordered_set<char> seen;
        seen.insert(s[0]);

        bool found = false;

        for (int i = 1; i < n - 1; i++)
        {
            char b = s[i];
            if (seen.count(b) || freq[b - 'a'] > 0)
            {
                found = true;
                break;
            }

            seen.insert(b);
            freq[s[i + 1] - 'a']--;
        }

        cout << (found ? "Yes" : "No") << '\n';
    }
    return 0;
}
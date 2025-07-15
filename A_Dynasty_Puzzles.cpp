    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector<string> names(n);
        for (int i = 0; i < n; i++)
            cin >> names[i];
        // dp[i][start][ending] = length of longest to form a dynasty with i names, start - first letter, ending - last letter
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(26, vector<int>(26, 0)));

        char ffirst = names[0].front();
        char llast = names[0].back();
        dp[0][ffirst][llast] = names[0].size();

        for (int i = 1; i < n; i++)
        {
            char first = names[i].front();
            char last = names[i].back();
            for (char c = 'a'; c <= 'z'; c++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (names[j].back() == first && dp[j][c - 'a'][first - 'a'] > 0)
                    {
                        dp[i][c - 'a'][last - 'a'] = max(
                            dp[i][c - 'a'][last - 'a'],
                            dp[j][c - 'a'][first - 'a'] + (int)names[i].size());
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int s = 0; s < 26; s++)
            {
                for (int e = 0; e < 26; e++)
                {
                    ans = max(ans, dp[i][s][e]);
                }
            }
        }
        cout << ans << endl;

        return 0;
    }
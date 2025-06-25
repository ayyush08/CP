#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n, int array_id, vector<pair<int, int>> &ans, int &op_count)
{
    for (int i = n - 1; i > 0; i--)
    {
        bool swapped = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                ans.push_back({array_id, j + 1});
                op_count++;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<pair<int, int>> ans;
        int op_count = 0;
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bubble_sort(a, n, 1, ans, op_count);
        bubble_sort(b, n, 2, ans, op_count);
        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i])
            {
                swap(a[i], b[i]);
                ans.push_back({3, i + 1});
                op_count++;
            }
        }

        cout << op_count << '\n';
        for (auto it : ans)
        {
            cout << it.first << ' ' << it.second << '\n';
        }
    }
    return 0;
}
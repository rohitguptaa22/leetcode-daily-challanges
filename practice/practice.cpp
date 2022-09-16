#include <bits/stdc++.h>
using namespace std;

// 1->1
// 2->0
// 3->1
// 4->1
// 6->0
// 8->0

// ans={4,3,1}

int main()
{
    vector<int> arr = {6, 3, 0, 1};
    int n = arr.size();
    vector<int> ans;
    sort(arr.begin(), arr.end());

    map<int, int> mp; // initialize and fill the map
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    cout << "before" << endl;
    for (auto x : mp)
    {

        cout << x.first << "->" << x.second << endl;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]])
        {
            if (mp[arr[i] * 2] > 0)
            {
                ans.push_back(arr[i]);
                mp[arr[i] * 2]--;
            }
            else
            {
                break;
            }
        }
    }

    // printing the map
    cout << "after" << endl;
    for (auto x : mp)
    {

        cout << x.first << "->" << x.second << endl;
    }
    cout << "ans print:- " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
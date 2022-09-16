// method 1
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &arr)
    {
        int n = arr.size();
        if (n % 2 == 1)
            return {};
        vector<int> ans;
        sort(arr.begin(), arr.end());

        map<int, int> mp; // initialize and fill the map
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        for (auto x : arr)
        {
            if (mp[x] == 0)
                continue;
            if (mp[x * 2] == 0)
                return {};
            if (mp[x] && mp[2 * x])
            {
                mp[2 * x]--;
                ans.push_back(x);
                mp[x]--;
            }
        }
        // if(ans.size()== n/2)
        return ans;
        // return {};
    }
};

// METHOD 2 same method different code
class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int n = changed.size();
        if (n % 2 == 1)
            return {};
        sort(changed.begin(), changed.end());
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[changed[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[changed[i]] == 0)
                continue;
            if (mp[changed[i] * 2] == 0)
                return {};
            ans.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i] * 2]--;
        }
        return ans;
    }
};
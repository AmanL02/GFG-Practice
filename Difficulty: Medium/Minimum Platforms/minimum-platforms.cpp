//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n) {
    int ans = 1;
    vector<std::pair<int, int>> times;

    // Combine arrival and departure times into a vector of pairs
    for (int i = 0; i < n; ++i) {
        times.emplace_back(arr[i], dep[i]);
    }

    // Sort the times based on arrival time
    sort(times.begin(), times.end());

    int temp = times[0].second;
    multiset<int> plat;
    plat.insert(temp);

    for (int i = 1; i < n; ++i) {
        bool flag = true;
        for (auto it = plat.begin(); it != plat.end(); ++it) {
            if (times[i].first > *it) {
                flag = false;
                plat.erase(it);
                plat.insert(times[i].second);
                break;
            }
        }
        if (flag) {
            ans++;
            plat.insert(times[i].second);
        }
        temp = times[i].second;
    }
    return ans;
}
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
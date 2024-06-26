//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> right;
        vector<int> left;
        stack<pair<int, int>> sr;
        stack<pair<int, int>> sl;
        for (int i = n - 1; i >= 0; i--) {
            if (sr.size() == 0) {
                right.push_back(n);
            } else if (sr.size() > 0 && sr.top().first < arr[i]) {
                right.push_back(sr.top().second);
            } else if (sr.size() > 0 && sr.top().first >=arr[i]) {
                while (sr.size() > 0 && sr.top().first >=arr[i]) {
                    sr.pop();
                }
                if (sr.size() == 0) {
                    right.push_back(n);
                } else {
                    right.push_back(sr.top().second);
                }
            }
            sr.push({arr[i], i});
        }
        reverse(right.begin(), right.end());
        for (int i = 0; i < n; i++) {
            if (sl.size() == 0) {
                left.push_back(-1);
            } else if (sl.size() > 0 && sl.top().first < arr[i]) {
                left.push_back(sl.top().second);
            } else if (sl.size() > 0 && sl.top().first >= arr[i]) {
                while (sl.size() > 0 && sl.top().first >=arr[i]) {
                    sl.pop();
                }
                if (sl.size() == 0) {
                    left.push_back(-1);
                } else {
                    left.push_back(sl.top().second);
                }
            }
            sl.push({arr[i], i});
        }
        vector<int> width(n);
        for (int i = 0; i < n; i++) {
            width[i] = right[i] - left[i] - 1;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * width[i];
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
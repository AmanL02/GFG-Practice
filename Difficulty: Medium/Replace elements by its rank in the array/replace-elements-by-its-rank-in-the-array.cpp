//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        set<int> temp;
        for(int i=0;i<N;i++){
            temp.insert(arr[i]);
        }
        unordered_map<int,int> mpp;
        int j=1;
        for(auto i=temp.begin();i!=temp.end();i++){
            mpp[*i]=j;
            j++;
        }
        vector<int> ans;
        for(int i=0;i<N;i++){
            if(mpp.find(arr[i])!=mpp.end()){
                ans.push_back(mpp[arr[i]]);
            }
        }
        return ans;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
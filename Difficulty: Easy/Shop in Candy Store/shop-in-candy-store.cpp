//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        vector<int> ans;
        int min_cost=0;
        int max_cost=0;
        vector<int> temp;
        for(int i=0;i<N;i++){
            temp.push_back(candies[i]);
        }
        sort(temp.begin(),temp.end());
        vector<int>temp2=temp;
        reverse(temp2.begin(),temp2.end());
        for(int i=0;i<temp.size();i++){
            min_cost+=temp[i];
            if(temp.size()>k){
                for(int j=0;j<k;j++){
                    temp.pop_back();
                }
            }
            else{
                int x=temp.size()-i+1;
                for(int j=0;j<x;j++){
                    temp.pop_back();
                }
            }
        }
        ans.push_back(min_cost);
        for(int i=0;i<temp2.size();i++){
            max_cost+=temp2[i];
            if(temp2.size()>k){
                for(int j=0;j<k;j++){
                    temp2.pop_back();
                }
            }
            else{
                int x=temp2.size()-i+1;
                for(int j=0;j<x;j++){
                    temp2.pop_back();
                }
            }
        }
        ans.push_back(max_cost);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
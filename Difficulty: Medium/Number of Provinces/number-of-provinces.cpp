//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // Depth-First Search function to explore all connected nodes
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;  // Mark the current node as visited
        for (int i = 0; i < adj.size(); i++) {
            // If there's a connection and the node hasn't been visited
            if (adj[node][i] == 1 && visited[i] == 0) {
                dfs(i, adj, visited);  // Recursively visit the connected node
            }
        }
    }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        int n = adj.size();
        int ans = 0;
        vector<int> visited(n, 0);  // Track visited nodes
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {  // If the node hasn't been visited
                ans++;  // We found a new province
                dfs(i, adj, visited);  // Explore all nodes in this province
            }
        }
        return ans;  // Return the total number of provinces
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
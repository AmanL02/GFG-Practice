//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(int node, vector<int> adj[], vector<int>& visited, vector<int>& ans) {
        visited[node] = 1;  // Mark the current node as visited
        ans.push_back(node); // Add the current node to the result
        for (int i = 0; i < adj[node].size(); i++) {
            if (visited[adj[node][i]] == 0) {
                DFS(adj[node][i], adj, visited, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);  // Initialize all nodes as unvisited
        vector<int> ans;
    
        // Start DFS from node 0
        DFS(0, adj, visited, ans);
    
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
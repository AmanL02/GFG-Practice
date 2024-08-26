//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        for(int i=0;i<V;i++){
            queue<pair<int,int>>qt;
            vector<int> visted(V,0);
            qt.push({i,-1});
        
        
        while(!qt.empty()){
            auto it=qt.front();
            qt.pop();
            int x=it.first;
            visted[x]=visted[x]+1;
            if(visted[x]>1){
                return 1;
            }
            for(int i=0;i<adj[x].size();i++){
                
                if(adj[x][i] == it.second)
                    continue;
                qt.push({adj[x][i],x});
            }
        }
        }
        return 0;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
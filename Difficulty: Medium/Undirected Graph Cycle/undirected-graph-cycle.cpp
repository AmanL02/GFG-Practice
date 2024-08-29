//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int node,int parent,vector<int>& visted,vector<int> adj[]){
        visted[node]=1;
        for(auto it : adj[node]){
            if(!visted[it]){
                if(dfs(it,node,visted,adj)==true){
                    return true;
                }
            }else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visted(V,0);
        for(int i=0;i<V;i++){
            if(!visted[i]){
                if(dfs(i,-1,visted,adj)==true){
                    return true;
                }
            }
        }
        return false;
        
        
        // for(int i=0;i<V;i++){
        //     queue<pair<int,int>>qt;
        //     vector<int> visted(V,0);
        //     qt.push({i,-1});
        //     while(!qt.empty()){
        //         auto it=qt.front();
        //         qt.pop();
        //         int x=it.first;
        //         visted[x]=visted[x]+1;
        //         if(visted[x]>1){
        //             return 1;
        //         }
        //         for(int i=0;i<adj[x].size();i++){
                    
        //             if(adj[x][i] == it.second)
        //                 continue;
        //             qt.push({adj[x][i],x});
        //         }
        //     }
        // }
        // return 0;
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
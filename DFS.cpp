#include<bits/stdc++.h>
using namespace std;

class Solution{
    
    public:
    
    void dfs(int node, vector<int>adj[], int vis[], vector<int>&ls){
        
        vis[node] = 1;
        ls.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
        }
    }
    
   
    vector<int> dfsOfGraph(int V, vector<int>adj[]){
        int vis[V] = {0};
        int start = 0;
        
        vector<int>ls;

        dfs(start,adj,vis,ls);
        return ls;
    }
};


void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAdj(int V,vector<int>adj[]){
    for(int i=0;i<V; i++){
        cout <<i<< "-->";
        for(int j=0; j<adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }cout << endl;
    }
}


int main(){
    int V = 5;
    vector<int>adj[5];
    
    addEdge(adj,0,2);
    addEdge(adj,2,4);
    addEdge(adj,0,1);
    addEdge(adj,0,3);
    
    printAdj(V,adj);
    
    Solution obj;
    
    vector<int>ans = obj.dfsOfGraph(V, adj);
    
    cout << "dfs" << endl;
    
    for(auto it: ans) cout <<it << " ";
    
    
    return 0;
}
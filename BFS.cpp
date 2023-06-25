#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:
    
    //In the code snippet you provided, vector<int> adj[] is an array of vectors. It is used to represent an adjacency list for a graph.
    
    // adj ek vectors hai woh contains arrays 
    vector<int> bfsGraph(int V, vector<int>adj[]){
        
        // visited array initialized with 0
        int vis[V] = {0};
        vis[0] = 1;
        
        // pushing the insitial starting node
        queue<int>q;
        q.push(0);
        vector<int>bfs;
        
        // iterate till the queue is empty
        while(!q.empty()){
            // queue mein node ka data dala hai node nahi 
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            /*
             e.g. 
             0-->{4,3,1}
             
             auto it: adj[] 
            */
            for(auto it: adj[node]){
                // if the neighbour has previously not been visited,
                // store in Q and mark as visited
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }   
        }
        return bfs;
    }
};

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int>&ans){
    for(auto it: ans)cout << it << " ";
}

void printAdj(int V, vector<int>adj[]){
    for(int i=0; i<V; i++){
        cout << i << "-->";
        for(int j =0; j<adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }cout << endl;
    }
}
    

int main(){
    int V = 6;
    vector<int>adj[6];
    cout << "Before " << endl;
    printAdj(V,adj);
    
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,0,4);
    
    cout << "After " << endl;
    printAdj(V,adj);
    
    
    
    Solution obj;
    vector<int>ans = obj.bfsGraph(5,adj);
    print(ans);
    
    
    
    return 0;
}
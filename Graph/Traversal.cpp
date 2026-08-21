//BFS TRAVERSAL OF A GRAPH

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
       // pehle visited array bana lo {0} , starting node ka visited = 1 mark kar do
      // phir Queue banao --> 1st node push karo, usse node me dalo , phir pop karo, phir vector<int> me dalo
     // uske baad Iterate kro --> ajd[nodes] k har element ko queue me push karo --> ye sab krte rho jab tak queue empty nhi hota
        
        int n = adj.size(); //equals to the size of nodes
        vector<int>bfs;
        
        int visited[n] = {0}; 
        visited[0] = 1;
        queue<int>q;
        q.push(0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            
            for(auto it : adj[node]){ //in 1st case for every element of adj[0] 
                if(visited[it] != 1){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};


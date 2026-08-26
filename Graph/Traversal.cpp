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

// ---------------------------------------------------DFS TRAVERSAL ------------------------------------------------------------------------------------------------------------------
class Solution {
  private:
  void traversal(int node, vector<vector<int>>& adj, int vis[], vector<int>&ls){
      
      vis[node] = 1;
      ls.push_back(node);
      for(auto it : adj[node]){ //adjacent k har element k liye
        if(!vis[it]){
            traversal(it, adj, vis, ls);
        }
      }
  }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        //Recrusion 
        /*
        Visited array banao , jo jo node visited hote jaye unhe 1 mark krte jao
        vector banake DFS store bhi krte jao
        phir adjacent node k 1st index k har element k liye recursive call krdo
        neighbours ko tabhi visit kro jab wo already visited na ho
        */ 
        vector<int>ls;
        int n = adj.size();
        int vis[n] = {0}; //initially zero for every node
        int start = 0;
        traversal(start , adj, vis, ls);
        return ls;
    }
};

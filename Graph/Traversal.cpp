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

// ----MAXIMUM ISS WAY SE TRAVERSE KAR RHE HOTE H GRAPH KO -------------------------------- JUST SEE THE WAY AND CHNAGE THE CONDITIONS ACCORDING TO THE QUESTION----------------------------------------------------
class Solution {
private:
void dfs(int row, int col, vector<vector<int>>&vis,vector<vector<int>>& grid, int delRow[], int delCol[]){

    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;
        
    for(int i=0; i<4; i++){

        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m &&
        !vis[nrow][ncol] && grid[nrow][ncol] == 1){

            dfs(nrow, ncol, vis, grid, delRow, delCol);
        }
    }
}
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        vector<vector<int>>vis(n, vector<int>(m,0));

        for(int j=0; j<m; j++){ //0 and last row me sara column traverse karo
            if(grid[0][j] == 1 && !vis[0][j]){
                dfs(0,j, vis, grid, delRow, delCol);
            }

            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                dfs(n-1, j, vis, grid, delRow, delCol);
            }
        }

        for(int i=0; i<n; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i, 0, vis, grid, delRow, delCol);
            }

             if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i, m-1, vis, grid, delRow, delCol);
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};

//

class Solution {
    private:
    void bfs(int row, int col,vector<vector<int>>&vis,vector<vector<char>> & grid){
        
        //sabse pehle jo row , col aaye unko visited mark karo
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row , col});
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            
            int row = q.front().first; //ye isliye store kr rhe h taki is row k sare neighbour
            int col = q.front().second; //iss col k sare neighbour ko traverse kr ske
            
            q.pop();
            
            //to traverse all the neighbouring nodes of any [row][col]
            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0  && ncol < m && 
                    !vis[nrow][ncol] && grid[nrow][ncol] == 'L'){
                        q.push({nrow , ncol});
                        vis[nrow][ncol] = 1; // don't forget
                    }
                }
            }
        }
    }
	public:
	int countIslands(vector<vector<char>> & grid) {
		int n = grid.size();
		int m = grid[0].size();
		int count = 0;
		
		vector<vector<int>> vis(n, vector<int>(m, 0)); // n row with all row having m, col
		
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < m; col++) {
				if(!vis[row][col] && grid[row][col] == 'L'){
				    
				    bfs(row , col, vis, grid);
				    count++;
				}
			}
		}
		return count;
	}
};


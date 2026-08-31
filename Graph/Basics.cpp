/*
 Adjacency Matrix Example it will always be V x V // and V is the number of nodes
 
 vector<vector<int>> matrix = {
    {0, 1, 1, 0},
    {1, 0, 0, 1},
    {1, 0, 0, 1},
    {0, 1, 1, 0}
};

Now example of Ajacency List

vector<vector<int>> adj = {
    {2},       // vertex 0
    {},        // vertex 1
    {0, 3, 4}, // vertex 2
    {2},       // vertex 3
    {2}        // vertex 4
};

The important part is:

vertex → its neighbours

So:

0 → 2
1 → nothing
2 → 0, 3, 4
3 → 2
4 → 2

*/ 
//------------------IMPORTANT------------------------------------------------------- To convert from Adjacency Matrix to Adjacency List------------------------------------------------------------------------


    int findCircleNum(vector<vector<int>>& isConnected) { // Here isConnected is Matrix
        int n = isConnected.size(); // here n is the number of nodes

        //convert from adj matrix to adjacency list
        vector<vector<int>> adjLs(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){ //same node khus se connected ho to ignore
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        //now we have Adjacency List



// -----------------------------------------> To convert from 2D array to Adjacency List-------------------------------------------------------

int countConnected(int V, vector<vector<int>>& edges) {
        
        //2 D array edges is given --> 1st convert it to adjacency list
        vector<int>adjLs[V]; // cause vertices = no og nodes
        
        //this is edge list we need to convert it into adjacency list
        
        for(int i=0; i<edges.size(); i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }
/*
Example of 2D array it will look something like this 

vector<vector<int>> edges = {
    {0, 3},
    {1, 4},
    {2, 5},
    {0, 2}
};
                 Only 2 Element will be there in 2D array  that is U node connected to V
*/ 
// ---------------------------------------------------------------------------------------------------------------------------------------------------
 //to traverse all the neighbouring nodes of any [row][col]

            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    
                    if(nrow >= 0 && nrow < n && ncol >= 0  && ncol < m && // this is the required condition here all the neighbour nodes are there
                     
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1'){ //while this conditions changes according to the requirements
                        q.push({nrow , ncol});
                        vis[nrow][ncol] = 1; // don't forget
                    }
                }
            }
//-------------------------------------------------------------------------------- If you only want the 4-direction traversal part, this is the core code ---------------------------------------------------------

int delRow[] = {-1, 0, 1, 0}; //ye tum clockwise likhe ho from up -> right -> down -> left
int delCol[] = {0, 1, 0, -1}; //ye tum clockwise likhe ho from up -> right -> down -> left

for(int i = 0; i < 4; i++) {
    int nrow = row + delRow[i];
    int ncol = col + delCol[i];

    if(nrow >= 0 && nrow < n &&
       ncol >= 0 && ncol < m) {

        // (nrow, ncol) is a valid neighbouring cell
    }
}






// -----------> To convert from 2D array to Adjacency List------------

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
        

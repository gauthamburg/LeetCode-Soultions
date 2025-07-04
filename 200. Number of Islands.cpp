class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0')return;

        grid[i][j]='0';

        dfs(grid,i-1,j);
        dfs(grid,i+1,j);       
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int rows=grid.size();
        int cols=grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }

        return count;
    }
};
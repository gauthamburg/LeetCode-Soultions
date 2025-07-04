class Solution {
public:
    void findArea(vector<vector<int>>&grid,int i,int j,int& a){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)return;
        
        a++;
        grid[i][j]=0;
        findArea(grid,i,j,a);

        findArea(grid,i-1,j,a);
        findArea(grid,i+1,j,a);       
        findArea(grid,i,j-1,a);
        findArea(grid,i,j+1,a);       
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxar=0;
        int rows=grid.size();
        int cols=grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    int area=0;
                    findArea(grid,i,j,area);
                    maxar=max(maxar,area);
                }
            }
        }

        return maxar;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    que.push({{i,j},0});
                }
            }
        }
        vector<int> drow={-1,0,1,0}; 
        vector<int> dcol={0,-1,0,1};
        int maxt=0;

        while(!que.empty()){
            int row=que.front().first.first;
            int col=que.front().first.second;
            int t=que.front().second;
            maxt=max(t,maxt);
            que.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]==1){
                   grid[nrow][ncol]=2;
                   que.push({{nrow,ncol},t+1});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                    break;
                }
            }
        }
        return maxt;

    }
};
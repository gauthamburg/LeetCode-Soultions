class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    setNum(matrix,i,j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==-9876543){
                    matrix[i][j]=0;
                }
            }
        }


    }

    void setNum(vector<vector<int>>& matrix,int r,int c){
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[r][i]!=0){
               matrix[r][i]=-9876543;
            }
        }
        for(int j=0;j<matrix.size();j++){
            if(matrix[j][c]!=0){
               matrix[j][c]=-9876543;
            }
        }      
    }
};
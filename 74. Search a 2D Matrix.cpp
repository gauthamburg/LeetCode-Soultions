class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int last=m*n-1;
        return bsrch(matrix,target,0,last);
    }

    bool bsrch(vector<vector<int>>& matrix, int target,int l,int r){
        int m=(l+r)/2;
        int row=m/matrix[0].size();
        int col=m%matrix[0].size();
        if(l>r){
            return false;
        }
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]<target){
            return bsrch(matrix,target,m+1,r);
        }
        else {
            return bsrch(matrix,target,l,m-1);
        }        
    }
};
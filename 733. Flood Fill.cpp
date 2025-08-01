class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int nw,int ol){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=ol){
            return;
        }

        image[i][j]=nw;

        dfs(image,i-1,j,nw,ol);
        dfs(image,i+1,j,nw,ol);
        dfs(image,i,j-1,nw,ol);
        dfs(image,i,j+1,nw,ol);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ol=image[sr][sc];
        if(ol==color)return image;
        dfs(image,sr,sc,color,ol);
        return image;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int num=board[i][j];
                if(num=='.'){
                    continue;
                }
                if(row[i].count(num)){
                    return false;
                }
                else{
                    row[i].insert(num);
                }
                if(col[j].count(num)){
                    return false;
                }
                else{
                    col[j].insert(num);
                } 

                int boxi=(i/3)*3 + (j/3);
                if(box[boxi].count(num)){
                    return false;
                }
                else{
                    box[boxi].insert(num);
                }                             

                
            }
        }  
        return true;     
    }
};
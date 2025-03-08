class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int minw=200;

         for(int i=0;i<(blocks.length()-k+1);i++){
            string sub = blocks.substr(i,k);
            int w=0;
            for(int i=0;i<k;i++){
                if(sub[i]=='W'){
                     w++;
                }
            }
            if(w<minw){
                minw=w;
            }

         }

         return minw;
        
    }

   
};
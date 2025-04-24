class Solution {
    public:
        int digitSum(int j){
            int sum = 0;
            while(j != 0){
                sum += j % 10;
                j = j / 10;
            }
            return sum;
        }

        int countLargestGroup(int n) {
            vector<int> a[37];

            for(int i = 1; i <= n; i++){
                int now = digitSum(i);
                a[now].push_back(i);
            }

            int maxsz = 0;
            int maxszcnt = 0;

            for(int i = 1; i <= 36; i++){
                int it = a[i].size();
                if(it > maxsz){
                    maxsz = it;
                    maxszcnt = 1;
                }
                else if(it == maxsz){
                    maxszcnt++;
                }
            }
            return maxszcnt;
        }
};


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)return stones[0];
        priority_queue<int> hp;
        for(int i=0;i<stones.size();i++){
            hp.push(stones[i]);
        }

        while(hp.size()>1){
            int first=hp.top();
            hp.pop();
            int secnd=hp.top();
            hp.pop();
            if(first>secnd){
                hp.push(first-secnd);
            }
        }

        if(hp.size()==1)return hp.top();
        else return 0;
    }
};
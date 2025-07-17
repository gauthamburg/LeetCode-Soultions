class KthLargest {
public:
    int k; 
    priority_queue<int, vector<int>, greater<int>> hp;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            hp.push(num);
            if (hp.size() > k) {
                hp.pop();
            }
        }
    }

    int add(int val) {
        hp.push(val);
        if (hp.size() > k) {
            hp.pop();  
        }
        return hp.top();  
    }
};

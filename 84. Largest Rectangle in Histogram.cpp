class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
          stack<int> st;
          int maxAr=0;
          int n=heights.size();

          for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
               int bi=heights[st.top()];
               st.pop();
               int pse=st.empty() ? -1:st.top();
               int nse=i;
               maxAr=max(maxAr,bi * (nse-pse-1));
            }
            st.push(i);
          }

          while(!st.empty()){
            int ci=heights[st.top()];
            st.pop();
            int pse=st.empty() ? -1:st.top();
            int nse=n;
            maxAr=max(maxAr,ci * (nse-pse-1));
          }


          return maxAr;
    }
};
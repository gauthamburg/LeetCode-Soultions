class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        for(auto& str:tokens){
           if(str=="+" || str=="-" || str=="*" || str=="/"){
              int a=sta.top();
              sta.pop();
              int b=sta.top();
              int c;
              sta.pop();
              if(str=="+"){
                c=a+b;
              }
              if(str=="-"){
                c=b-a;
              }
              if(str=="*"){
                c=a*b;
              }
              if(str=="/"){
                c=b/a;
              } 

              sta.push(c);             

           }
           else{
             sta.push(stoi(str));
           }
        }


        return sta.top();
    }
};
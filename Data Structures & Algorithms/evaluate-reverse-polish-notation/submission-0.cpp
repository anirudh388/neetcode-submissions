class Solution {
public:
    int operate(int a,int b,string tokens){
        if(tokens=="+"){
            return a+b;
        }
        if(tokens=="-"){
            return a-b;
        }
        if(tokens=="*"){
            return long (a)*long(b);
        }
        if(tokens=="/"){
            return a/b;
        }
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string &token:tokens){
            if(token=="+"||token=="-"||token=="*"||token=="/"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                int result=operate(a,b,token);
                st.push(result);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
        
    }
};

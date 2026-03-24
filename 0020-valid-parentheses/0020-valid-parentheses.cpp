class Solution {
public:
    bool isValid(string s) {
        if(s.size()==1) return false;
        stack<char>st;
        for(char c : s){
            if(c=='[' || c=='{' || c=='('){
                st.push(c);
            }
            else if(c==']' || c=='}' || c==')'){
               if(st.empty()) return false;

                if(c==')' && st.top()!='(') return false;
                if(c==']' && st.top()!='[') return false;
                if(c=='}' && st.top()!='{') return false;

                st.pop();
            }
        }
        return st.empty();
    }
};
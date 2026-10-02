class Solution {
public:
    void generate(int o, int c, vector<string> &ans,int n, string temp){
        if(o==n && c==n){
            ans.push_back(temp);
        }
        if(o<n){
            generate(o+1, c, ans, n, temp+"(");
        }
        if(c<o){
            generate(o, c+1, ans, n, temp+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(0,0, ans, n,"");
        return ans;
    }
};
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1) return 1;
        
        int j=0;
        int c=0;
        
        for(int i=0;i<chars.size();i++){
            if(i==0 || chars[i-1]==chars[i]){
                c++;
            }else{
                if(c==1){
                    chars[j]=chars[i-1];
                    c=1;
                    j++;
                }else{
                    chars[j]=chars[i-1];
                    string st=to_string(c);
                    j++;
                    for(int k=0;k<st.size();k++){
                        chars[j]=st[k];
                        j++;
                    }
                    c=1;

                }
            }
        }

        if(c!=1){
            chars[j]=chars[chars.size()-1];
            j++;
            string st=to_string(c);
            for(int k=0;k<st.size();k++){
                chars[j]=st[k];
                j++;
            }
            return j;
        }else if(c==1){
            chars[j]=chars[chars.size()-1];
        }
        return j+1;
    }
};
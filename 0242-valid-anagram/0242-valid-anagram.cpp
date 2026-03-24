class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>arr(26,0);

        for(char c : s){
            int a=c-'a';
            arr[a]++;
        }
        for(char c : t){
            int a=c-'a';
            arr[a]--;
        }
        for(int i : arr){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
};
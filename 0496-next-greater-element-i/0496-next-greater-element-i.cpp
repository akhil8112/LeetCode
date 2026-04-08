class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nxt(nums2.size(),-1);
        stack<int>st;

        for(int i=nums2.size()-1;i>=0;i--){

            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                nxt[i]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int n :  nums1){
            for(int m =0;m< nums2.size();m++){
                if(n==nums2[m]){
                    ans.push_back(nxt[m]);
                    
                }
            }
        }
        return ans;

    }
};
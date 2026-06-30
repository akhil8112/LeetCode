class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string s;

        int d=1;

        while(getline(ss,s,',')){
            d--;
            if(d<0) return false;
            if(s!="#") d+=2;
        }
        return d==0;
//har node ke liye slot reserve kar denge har node ke liye do jagah allocate ho jayengi phir left aur right aur har baar ek slot minus hota rahega aur jab # milega matlab null hai slot allocate nhi hoga
    }
};
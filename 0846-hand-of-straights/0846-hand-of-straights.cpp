class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int,int>mp;
        for(int i : hand){
            mp[i]++;
        }
        auto it=mp.begin();
        while(it!=mp.end()){
            if(it->second==0){
                it++;
                continue;
            }
            int start=it->first;
            auto temp=it;
            for(int i=0;i<groupSize;i++){
                auto curr = temp;
                for (int step = 0; step < i; step++) {
                    curr++;
                }

                if (curr->first != start+i || curr->second == 0)
                    return false;

                curr->second--;
            }
        }
        return true;
    }
};
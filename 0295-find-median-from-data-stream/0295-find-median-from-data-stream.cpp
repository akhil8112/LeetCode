class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>pqmin;
    priority_queue<int>pqmax;
    MedianFinder() {
     
    }
    
    void addNum(int num) {
        pqmax.push(num);
        pqmin.push(pqmax.top());
         
        pqmax.pop();

        if (pqmin.size() > pqmax.size()) {
            pqmax.push(pqmin.top());
            pqmin.pop();
        }


    }
    
    double findMedian() {
       if(pqmax.size()>pqmin.size()){
        return pqmax.top();
       }

       return (pqmax.top()+pqmin.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class SeatManager {
public:
    map<int,bool> mapp;
    int n = 0;
    
    SeatManager(int k) {
        n = k;
        for(int i=1;i<=n;i++){
            mapp[i]=true;
        }
    }
    
    int reserve() {
        int seat = mapp.begin()->first;
       mapp.erase(seat);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        mapp[seatNumber] = false;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>>vec;
    bool book(int start, int end) {
        for(int i=0;i<vec.size();i++){
            int r_start=vec[i].first;
            int r_end=vec[i].second;
            if(start<r_end&&end>r_start){
                return false;
            }
        }
        vec.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
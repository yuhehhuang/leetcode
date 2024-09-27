class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    vector<pair<int,int>>vec1;//at least one booked
    vector<pair<int,int>>vec2;//doubled booked
    bool book(int start, int end) {
        for(int i=0;i<vec2.size();i++){
            int r_start2=vec2[i].first;
            int r_end2=vec2[i].second;
            if(start<r_end2&&end>r_start2){
                return false;
            }
        }
        for(int i=0;i<vec1.size();i++){
            int r_start1=vec1[i].first;
            int r_end1=vec1[i].second;
            if(start<r_end1&&end>r_start1){
                vec2.push_back(make_pair(max(start,r_start1),min(end,r_end1)));
            }
        }
        vec1.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
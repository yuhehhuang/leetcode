class Solution {
public:
    void bfs(int key,vector<vector<int>>&rooms,unordered_set<int>&book){
        book.insert(key);
        for(int i=0;i<rooms[key].size();i++){
            if(book.find(rooms[key][i])==book.end()){
                bfs(rooms[key][i],rooms,book);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>book;
        bfs(0,rooms,book);
        return book.size()==rooms.size();
    }
};
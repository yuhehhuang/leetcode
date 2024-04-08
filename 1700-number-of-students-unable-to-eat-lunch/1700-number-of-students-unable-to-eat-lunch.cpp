class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stud;
        for(int i=0;i<students.size();i++)
            stud.push(students[i]);
        stack<int> sand;
        for(int i=sandwiches.size()-1;i>=0;i--)
            sand.push(sandwiches[i]);
        int repeat=0; int eaten=0;
        int n=stud.size();
        while(!sand.empty()&&repeat<n){
            if(sand.top()==stud.front()){
                sand.pop();
                stud.pop();
                eaten++;
                repeat=0;
            }
            else{
                int tmp=stud.front();
                stud.pop();
                stud.push(tmp);
                repeat++;
            }
        }
        return n-eaten;       
    }
};
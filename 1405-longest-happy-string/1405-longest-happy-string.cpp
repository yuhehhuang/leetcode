class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int,char>>que;
    if(a>0){
        que.push({a,'a'});
    }
    if(b>0){
        que.push({b,'b'});
    }
    if(c>0){
        que.push({c,'c'});
    }
    string ans="";
    while(!que.empty()){
        pair<int,char>element=que.top();
        que.pop();
        //case:處理連續三個相同char
        if(ans.size()>=2&&ans[ans.size()-1]==element.second&&ans[ans.size()-2]==element.second){
            if(que.empty()){
                break;
            }
            pair<int,char>element2=que.top();
            que.pop();
            ans+=element2.second;
            element2.first--;
            if(element2.first>0){
                que.push(element2);
            }
            que.push(element);
        }
        //case:沒有連續三個相同char
        else{
            ans+=element.second;
            element.first--;
            if(element.first>0){
                que.push(element);
            }
        }
    }
    return ans;
    }
};
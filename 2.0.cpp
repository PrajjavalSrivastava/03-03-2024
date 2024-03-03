class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>s;
        int n = h.size();
         int res = 0;
        for(int i=0;i<n;i++){
            while(s.empty() == false && h[s.top()]>h[i]){
                int t = s.top();
                s.pop();
                int curr;
                if(s.empty() == true){
                    curr = h[t]*i;
                }
                else{
                    curr = h[t]*(i-s.top()-1);
                }
                res = max(res,curr);
            }
        s.push(i);
        }
        while(s.empty() == false){
            int t = s.top();
            s.pop();
            int curr;
            if(s.empty() == true){
                curr = h[t]*n;
            }
            else{
                curr = h[t]*(n-s.top()-1);
            }
            res = max(res,curr);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
     int l=0,r=v.size()-1;
        vector<int> ans;
     while(l<r){
         if(v[l]+v[r]==t){
             ans.push_back(l+1);
             ans.push_back(r+1);
             return ans;
         }else if(v[l]+v[r]<t){
             l++;
         }else r--;
     }
     return ans;   
    }
};
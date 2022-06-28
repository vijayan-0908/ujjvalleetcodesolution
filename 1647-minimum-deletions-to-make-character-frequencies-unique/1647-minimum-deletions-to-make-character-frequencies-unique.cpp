class Solution {
public:
    int minDeletions(string s) {
        map<char,int> m;
        for(auto it:s) m[it]++;
        vector<int> v;
        for(auto it:m) v.push_back(it.second);
        sort(v.begin(),v.end(),greater<int>());
        int ans=0;
        int pre=v[0];
        for(int i=1;i<v.size();i++){
            if(pre==v[i] && v[i]!=0){
                ans++;
                v[i]--;
            }else if(v[i]>pre && v[i]!=0){
                int d=v[i]-pre;
                d++;
                v[i]-d>=0?ans+=d:ans+=v[i];
                v[i]-d>=0?v[i]-=d:v[i]=0;
            }
            pre=v[i];
        }
        
        return ans;
        
    }
};
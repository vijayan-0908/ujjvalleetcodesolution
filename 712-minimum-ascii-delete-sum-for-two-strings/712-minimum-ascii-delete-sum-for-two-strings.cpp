class Solution {
public:
    int minimumDeleteSum(string &a, string &b) {
        int m=a.size(),n=b.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++) dp[0][i]=b[i-1]+dp[0][i-1];
        for(int i=1;i<=m;i++) dp[i][0]=a[i-1]+dp[i-1][0];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(a[i-1]+dp[i-1][j],b[j-1]+dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
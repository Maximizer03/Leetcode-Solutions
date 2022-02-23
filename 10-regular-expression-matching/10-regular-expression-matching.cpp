class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        // dp[i][j]=> answer if substring s[0....i-1] matches with substr p[0....j-1]
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='*'){
                    dp[i][j]= dp[i][j-2] || (i && dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.'));
                }
                else{
                        dp[i][j]= i && dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
                }
            }
        }
        return dp[n][m];
    }
};
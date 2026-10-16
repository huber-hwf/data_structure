#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int slen=s.size(), plen=p.size();
       vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));
       dp[0][0]=true;
       for(int j=1; j<=plen; j++){
           if(j>=2&&p[j-1]=='*') dp[0][j]=dp[0][j-2];
       }
       for(int i=1; i<slen+1; i++){
           for(int j=1; j<plen+1; j++){
               if(s[i-1]==p[j-1]||p[j-1]=='.') dp[i][j]=dp[i-1][j-1];
               if(p[j-1]=='*'){
                   if(s[i-1]==p[j-2]||p[j-2]=='.'){
                       dp[i][j]=dp[i-1][j-2]||dp[i-1][j]||dp[i][j-2];
                   }
                   else dp[i][j]=dp[i][j-2];
               }
           }
       }
       return dp[slen][plen];
    }
};
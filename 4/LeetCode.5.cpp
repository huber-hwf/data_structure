#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<2) return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int beststart=0, bestlen=0;
        for(int len=1; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                int j=i+len-1;
                if(len<=2){
                    dp[i][j]=s[i]==s[j]?true:false;
                }else{
                    if(s[i]!=s[j]) dp[i][j]=false;
                    else dp[i][j]=dp[i+1][j-1]?true:false;
                }
                if(dp[i][j]&&len>bestlen){
                    beststart=i;
                    bestlen=len;
                }
            }
        }
        return s.substr(beststart, bestlen);
    }
};
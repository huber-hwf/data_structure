#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int m=cardPoints.size()-k;
        long long s=0, ans=0, sum=0;
        for(int i=0; i<cardPoints.size(); i++){
            s+=cardPoints[i];
            if(i==m-1) sum=s;
        }
        if(cardPoints.size()==k) return s;
        ans=sum;
        for(int i=m, j=0; i<cardPoints.size(); i++, j++){
            sum+=cardPoints[i]-cardPoints[j];
            ans=min(ans, sum);
        }
        return s-ans;
    }
};
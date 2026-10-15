#include<iostream>
#include<vector>
using namespace std;
class Solution {
private: vector<int> q=vector<int>(256,0);
public:
    int lengthOfLongestSubstring(string s) {
        fill(q.begin(), q.end(), 0);
        int res=0;
        int temp=0;
        for(int i=0, j=0; i<s.size(); i++){
            temp++;
            q[s[i]]++;
            while(q[s[i]]!=1) { q[s[j++]]--; temp--;}
            res=max(res, temp);
        }
        return res;
    }
};
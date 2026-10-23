#include<iostream>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0;
        int temp=0;
        for(int i=0, j=0; i<s.size(); i++){
            if(temp==k) return k;
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u')
                temp++;
            if(i>k-1){
                if(s[j]=='a'||s[j]=='e'||s[j]=='o'||s[j]=='i'||s[j]=='u')
                temp--;
                j++;
            }
            ans=max(temp, ans);
        }
        return ans;
    }
};
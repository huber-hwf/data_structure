#include<iostream>
using namespace std;
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=0;
        int temp=0;
        for(int i=0, j=0; i<blocks.size(); i++){
            if(blocks[i]=='W') temp++;
            if(i==k-1) ans=temp;
            if(i>k-1){
                if(blocks[j]=='W') temp--;
                j++;
                ans=min(ans, temp);
            }
        }
        return ans;
    }
};
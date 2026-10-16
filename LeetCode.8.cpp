#include<iostream>
class Solution {
private:
    unsigned int rvs(unsigned int x) {
        unsigned int ans=0;
        unsigned int temp=x;
        while(temp){
            ans=ans*10+temp%10;
            temp/=10;
        }
        return ans;
    }
public:
    int reverse(int x) {
        unsigned int temp=x>=0?x:-(unsigned)x;
        int max[10];
        int min[10];
        int limmax=INT_MAX;
        unsigned int limmin=-(unsigned)INT_MIN;
        int size=1e9;
        for(int i=9; i>=0; i--){
            max[i]=limmax%10;
            limmax/=10;
        }
        for(int i=9; i>=0; i--){
            min[i]=limmin%10;
            limmin/=10;
        }
        unsigned int y=temp;
        if(temp<size) return x>0?rvs(temp):-rvs(temp);
        if(x==0) return 0;
        for(int i=0; i<10; i++){
            if(x<0&&y%10<min[i]){
                return -rvs(temp);
            } 
            if(x<0&&y%10>min[i]){
                return 0;
            }
            if(x>0&&y%10<max[i]){
                return rvs(temp);
            }
            if(x>0&&y%10>max[i]){
                return 0;
            }
            y/=10;
        }
        return x>0?INT_MAX:INT_MIN;
    }
};
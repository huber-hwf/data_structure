#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        vector<int> num;
        bool isneg=false;
        bool flag=true;
        for(int i=0; i<s.size(); i++){
            if(flag){
                if((s[i]!=' '&&s[i]!='+'&&s[i]!='-')&&(s[i]<'0'||s[i]>'9'))
                return 0;
                else{
                    if(s[i]=='+'||s[i]=='-'){
                    isneg=s[i]=='-'?true:false;
                    flag=false;
                    }
                    if(s[i]>='0'&&s[i]<='9'){
                        flag=false;
                        num.push_back(s[i]-'0');
                    }
                }
            }else{
                if((s[i]<'0'||s[i]>'9')) break;
                else{
                    num.push_back(s[i]-'0');
                }
            }
        }
        reverse(num.begin(), num.end());
        while(num.size()>1&&!num.back()) num.pop_back();
        reverse(num.begin(), num.end());
        if(num.size()>10) return isneg?INT_MIN:INT_MAX;
        unsigned long long ans=0;
        bool zero=true;
        for(int i=0; i<num.size(); i++){
                ans=ans*10+num[i];
            }
        if(isneg&&ans>(unsigned)INT_MAX+1) return INT_MIN;
        else if(!isneg&&ans>INT_MAX) return INT_MAX;
        else return isneg?-(unsigned)ans:ans;
    }
};
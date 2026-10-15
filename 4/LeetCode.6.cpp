#include<iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int numstep=2*numRows-2;
        if(s.size()<=numRows||numRows==1)
        return s;
        string str;
        int step=0;
        for(int i=0; i<numRows; i++){
            int temp=i;
            str.push_back(s[temp]);
            while(true){
                if(i!=0&&i!=numRows-1){
                    int x=temp+numstep-i-1-step;
                    if(x<s.size())
                    str.push_back(s[x]);
                }
                temp+=numstep;
                if(temp<s.size()){
                    str.push_back(s[temp]);
                }
                else break;
            }
            if(i!=0&&i!=numRows-2) step++;
        }
        return str;
    }
};
#include<iostream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int map[26];
        map['I'-'A']=1;
        map['V'-'A']=5;
        map['X'-'A']=10;
        map['L'-'A']=50;
        map['C'-'A']=100;
        map['D'-'A']=500;
        map['M'-'A']=1000;
        string ans;
        while(num>0){
            if(num>=1000){
                num-=map['M'-'A'];
                ans+='M';
            }else if(num>=500){
                if(num/100==9){
                    num-=map['M'-'A']-100;
                    ans+="CM";
                }else{
                    num-=map['D'-'A'];
                    ans+='D';
                }
            }else if(num>=100){
                if(num/100==4){
                    num-=map['D'-'A']-100;
                    ans+="CD";
                }else{
                    num-=map['C'-'A'];
                    ans+='C';
                }
            }else if(num>=50){
                if(num/10==9){
                    num-=map['C'-'A']-10;
                    ans+="XC";
                }else{
                    num-=map['L'-'A'];
                    ans+='L';
                }
            }else if(num>=10){
                if(num/10==4){
                    num-=map['L'-'A']-10;
                    ans+="XL";
                }else{
                    num-=map['X'-'A'];
                    ans+='X';
                }
            }else if(num>=5){
                if(num==9){
                    num-=map['X'-'A']-1;
                    ans+="IX";
                }else{
                    num-=map['V'-'A'];
                    ans+='V';
                }
            }else{
                if(num==4){
                    num-=map['V'-'A']-1;
                    ans+="IV";
                }else{
                    num-=map['I'-'A'];
                    ans+='I';
                }
            }
        }
        return ans;
    }
};
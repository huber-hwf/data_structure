#include<iostream>
#include<vector>
using namespace std;
char key[2]={'(', ')'};
void generate(int n, char key[], int &ln, int &rn, string &temp, vector<string> ans){
    if(ln==n&&rn==n){
        ans.push_back(temp);
        cout<<"yes";
        return;
    }
    for(int i=0; i<2; i++){
        char ch=key[i];
        if(ch=='('){
            if(ln<n) {
                temp+='(';
                ln++;
            }
            else continue;
        }else{
            if(rn<ln) {
                temp+=')';
                rn++;
            }else{
                break;
            }
        }
        generate(n, key, ln, rn, temp, ans);
        temp.pop_back();
    }
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int ln=1, rn=0;
        string temp;
        temp+='(';
        vector<string> ans;
        generate(n, key, ln, rn, temp, ans);
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    Solution abs;
    auto ans=abs.generateParenthesis(n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }
    return 0;
}
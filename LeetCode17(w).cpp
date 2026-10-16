#include<iostream>
#include<vector>
using namespace std;
typedef struct Node{
            char alpha;
            Node* next;
            Node(char _alpha, Node* _next){
                alpha=_alpha;
                next=_next;
            }
        };
void find(vector<Node*> &hashtable, string digits, int pos, string &temp, vector<string> &ans){
    string s1=temp;
    string s2=temp;
    string s3=temp;
    if(pos==digits.size()-1){
        for(Node* p=hashtable[digits[pos]]; p; p=p->next){
            s1+=p->alpha;
            s2+=p->alpha;
            s3+=p->alpha;
            ans.push_back(s1);
            ans.push_back(s2);
            ans.push_back(s3);
        }
    }
    int ord=1;
    for(Node* p=hashtable[pos]; p; p=p->next){
        if(ord==1) s1+=p->alpha;
        if(ord==2) s2+=p->alpha;
        if(ord==3) s3+=p->alpha;
        ord++;
    }
    find(hashtable, digits, pos+1, s1, ans); find(hashtable, digits, pos+1, s2, ans); find(hashtable, digits, pos+1, s3, ans);
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<Node*> hashtable(8);
        for(int i=2; i<10; i++){
            int asc=(i-2)*3+97;
            for(int j=asc; j<asc+3; j++){
                Node* n=new Node(j, hashtable[i-2]);
                hashtable[i-2]=n;
            }
        }
        vector<string> answer;
        string t;
        find(hashtable, digits, 0, t, answer);
        return answer;
    }
};
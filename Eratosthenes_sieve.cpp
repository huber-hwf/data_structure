#include<iostream>
#include<vector>
using namespace std;
bool isprime(int n){
    if(n<2) return false;
    for(int i=2; i<sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    vector<bool> is_prime(n+1, true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2; i*i<n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<n; j++){
                is_prime[j]=false;
            }
        }
    }
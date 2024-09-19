#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int reduceFraction(int &a,int &b){
    int gcdans=gcd(a,b);
    a/=gcdans;
    b/=gcdans;
    return a/b;
}
int reduceFraction1(int &a,int &b){
    for(int i=2;i<min(a,b);i++){
        while(a%i==0 && b%i==0){
            a/=i;
            b/=i;
        }
    }
    return a/b;
}
int main(){
    int a=8,b=12;
    // int sf=reduceFraction(a,b);
    int sf=reduceFraction1(a,b);
    cout<<a<<"/"<<b<<endl;
    cout<<sf;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int nCr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

int pascalValueAtPos(int r,int c){
    int result=nCr(r-1,c-1);
    return result;
}

void printNthRow(int n){
    for(int i=1;i<=n;i++){
        cout<<pascalValueAtPos(n,i)<<" ";
    }
    cout<<endl;
}
void printNthRowOptimal(int n){
    cout<<1<<" ";
    int prev=1;
    for(int i=1;i<n;i++){
        prev=(prev*(n-i))/i;
        cout<<prev<<" ";
    }
    cout<<endl;
}
void printFirstNRows(int n){
    cout<<1<<endl;
    for(int i=2;i<=n;i++){
        int prev=1;
        cout<<1<<" ";
        for(int j=1;j<i;j++){
            prev=(prev*(i-j))/j;
            cout<<prev<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n=5,r=5,c=3;

    //method 1: Print value at position (r,c)
    cout<<"Pascal Triangle value at Position ("<<r<<","<<c<<") : "<<pascalValueAtPos(r,c)<<endl;

    //method 2: Print Nth row
    printNthRow(n);
    printNthRowOptimal(n);

    //method 3: Print first N Rows
    printFirstNRows(n);
    return 0;
}
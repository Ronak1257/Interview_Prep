#include<bits/stdc++.h>
using namespace std;

int countPath(int i,int j,int n,int m){
    if(i==n-1 && j==m-1) return 1;
    else if(i>=n || j>=m) return 0;
    return countPath(i+1,j,n,m)+countPath(i,j+1,n,m);
}

int usingRecursion(int n,int m){
    return countPath(0,0,n,m);
}

int countPath2(int i,int j,int n,int m,vector<vector<int>>&dp){
    if(i==n-1 && j==m-1) return 1;
    if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=countPath2(i+1,j,n,m,dp)+countPath2(i,j+1,n,m,dp);
}
int usingDp(int n,int m){
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    int num=countPath2(0,0,n,m,dp);
    if(n==1&& m==1) return num;
    return dp[0][0];
}
int usingMath(int n,int m){
    int N=m+n-2;
    int r=n-1;
    double res=1;
    for(int i=1;i<=r;i++){
        res=res*(N-r+i)/i;
    }
    return (int)res;
}
int main(){
    int n=3,m=7;
    // cout<<usingRecursion(n,m);
    // cout<<usingDp(n,m);
    cout<<usingMath(n,m);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void convertB(vector<vector<char>>&s,int n,int m,int i,int j){
    if(i<0 || i>=n || j<0 || j>=m || s[i][j] != 'O') return;
    s[i][j]='B';
    convertB(s,n,m,i,j-1);
    convertB(s,n,m,i,j+1);
    convertB(s,n,m,i-1,j);
    convertB(s,n,m,i+1,j);
}

vector<vector<char>> captureRegion(vector<vector<char>> &s, int n, int m) 
{
    for(int i=0;i<n;i++){
        if(s[i][0]=='O') convertB(s,n,m,i,0);
        if(s[i][m-1]=='O') convertB(s,n,m,i,m-1);
    }
    for(int j=0;j<m;j++){
        if(s[0][j]=='O') convertB(s,n,m,0,j);
        if(s[n-1][j]=='O') convertB(s,n,m,n-1,j);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='O') s[i][j]='X';
            if(s[i][j]=='B') s[i][j]='O';
        }
    }
    return s;
}

int main(){
    // vector<vector<char>>vec{{'X','O'},{'O','X'}};
    // vector<vector<char>>vec{{'X','X','X'},{'X','O','X'},{'X','X','X'}};
    vector<vector<char>>vec{{'X','X','X','O'},{'X','O','O','X'},{'X','O','O','X'},{'X','X','X','X'}};
    int n=vec.size();
    int m=vec[0].size();
    cout<<"Before : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<vector<char>>ans=captureRegion(vec,n,m);
    cout<<"After : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void rowColumnChange(vector<vector<int>>&v,int i,int j,int n,int m){
    for(int k=0;k<n;k++){
        if(v[k][j]!=0) v[k][j]=-1;
    }
    for(int k=0;k<m;k++){
        if(v[i][k]!=0) v[i][k]=-1;
    }
}
void bruteForceMethod(vector<vector<int>>&v,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0) rowColumnChange(v,i,j,n,m);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==-1) v[i][j]=0;
        }
    }
}

void withArray(vector<vector<int>>&v,int n,int m){
    vector<bool>rows(n);
    vector<bool>column(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                rows[i]=1; 
                column[j]=1;
            } 
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rows[i]==1 || column[j]==1) v[i][j]=0;
        }
    }
}

void withConstantSpace(vector<vector<int>>&v,int n,int m){
    bool col0=1;
    for(int i=0;i<n;i++){
        if(v[i][0]==0) col0=0;
    }
    for(int j=0;j<m;j++){
        if(v[0][j]==0) v[0][0]=0;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(v[i][j]==0){
                v[i][0]=0; 
                v[0][j]=0;
            } 
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(v[0][j]==0 || v[i][0]==0) v[i][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            v[i][0]=0;
        }
    }
    if(v[0][0]==0){
        for(int i=0;i<m;i++){
            v[0][i]=0;
        }
    }
}
int main(){
    vector<vector<int>>v={
        {5,8,0,1,6,8,9,0},
        {1,0,1,0,7,3,8,2},
        {1,1,1,1,7,2,8,3},
        {2,1,5,1,7,2,8,3},
    };
    int rows=v.size();
    int column=v[0].size();
    cout<<"\nOrigional Matrix"<<endl;
    for(auto i:v){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    // methods 1: no negative integer
    // bruteForceMethod(v,rows,column);

    //method 2: row and column array 
    // withArray(v,rows,column);

    //method 3: use constant space 
    withConstantSpace(v,rows,column);
    
    cout<<"\nNew Matrix"<<endl;
    for(auto i:v){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
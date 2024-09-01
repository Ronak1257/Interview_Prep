#include<bits/stdc++.h>
using namespace std;

void transform90(vector<vector<int>>&nums){
    int n=nums.size();
    int m=nums[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            swap(nums[i][j],nums[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(nums[i].begin(),nums[i].end());
    }
}

int main(){
    vector<vector<int>>nums{{1,2,3},{4,5,6},{7,8,9}};
    transform90(nums);
    int n=nums.size();
    int m=nums[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool binary2dSearch(vector<vector<int>>nums,int target){
    int row=0;
    int n=nums.size(),m=nums[0].size();
    for(int i=0;i<n;i++){
        if(nums[i][0]<=target && nums[i][m-1]>=target) row=i;
    }
    int s=0;
    int e=m-1;
    bool c=false;
    while(s<e){
        int mid=(s+e)/2;
        if(nums[row][mid]>target){
            e=mid-1;
        }
        else if(nums[row][mid]<target){
            s=mid+1;
        }
        else{
            c=true;
            break;
        }
    }
    return c;
}
int main(){
    vector<vector<int>>nums={
        {1,3,5,7},
        {8,10,11,14},
        {15,17,20,21}
        };
    cout<<binary2dSearch(nums,16);
    return 0;
}
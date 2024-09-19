#include<bits/stdc++.h>
using namespace std;

void subsetSum(vector<int>nums,int i,int sum,vector<int>&ans){
    if(i==nums.size()){
        ans.push_back(sum);
        return;
    }
    subsetSum(nums,i+1,sum+nums[i],ans);
    subsetSum(nums,i+1,sum,ans);
}
vector<int> usingRecursion(vector<int>nums){
    vector<int>ans;
    subsetSum(nums,0,0,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int>nums{5,2,1};
    vector<int>ans=usingRecursion(nums);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}
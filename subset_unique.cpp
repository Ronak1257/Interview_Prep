#include<bits/stdc++.h>
using namespace std;

void subset(vector<int>nums,int i,vector<int>temp,set<vector<int>>&ans){
    if(i==nums.size()){
        ans.insert(temp);
        return;
    }
    subset(nums,i+1,temp,ans);
    temp.push_back(nums[i]);
    subset(nums,i+1,temp,ans);
}

vector<vector<int>> unique_subset(vector<int>nums){
    set<vector<int>>ans;
    int n=nums.size();
    vector<int>temp;
    subset(nums,0,temp,ans);
    vector<vector<int>>ans1(ans.begin(),ans.end());
    return ans1;
}
int main(){
    vector<int>nums{1,2,2};
    vector<vector<int>>ans=unique_subset(nums);
    for(auto i:ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
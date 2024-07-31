#include<bits/stdc++.h>
using namespace std;

void allPermutation(int index,vector<int>&nums,vector<vector<int>>&ans){
    int n=nums.size();
    if(index==n){
        ans.push_back(nums);
        return;
    }
    for(int i=index;i<n;i++){
        swap(nums[index],nums[i]);
        allPermutation(index+1,nums,ans);
        swap(nums[index],nums[i]);
    }
}

void intutionAlgo(vector<int>&nums){
    int breakpoint=-1;
    for(int i=nums.size()-1;i>0;i--){
        if(nums[i]>nums[i-1]){
            breakpoint=i-1;
            break;
        }
    }
    if(breakpoint==-1){
        reverse(nums.begin(),nums.end());
    }
    else{
        for(int i=nums.size()-1;i>breakpoint;i--){
            if(nums[i]>nums[breakpoint]){
                swap(nums[i],nums[breakpoint]);
                break;
            }
        }
        reverse(nums.begin()+breakpoint+1,nums.end());
    }
}
int main(){
    vector<int>v={1,2,3};
    vector<vector<int>>ans;

    //bruteForce method : store all permutation and check and print next permutation
    allPermutation(0,v,ans);
    for(int i=0;i<ans.size();i++){
        if(ans[i]==v){
            cout<<"{"<<ans[i+1][0];
            for(int j=1;j<ans[i+1].size();j++){
                cout<<","<<ans[i+1][j];
            }
            cout<<"}"<<endl;           
        }
    }
    
    // in-built function
    next_permutation(v.begin(),v.end());
    cout<<"{"<<v[0]<<","<<v[1]<<","<<v[2]<<"}"<<endl;

    // intution algorithm
    v={1,2,3};
    intutionAlgo(v);
    cout<<"{"<<v[0]<<","<<v[1]<<","<<v[2]<<"}"<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int bruteForce(vector<int>nums){
    int water=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int lm=0,rm=0;
        int j=i;
        while(j>=0){
            lm=max(lm,nums[j]);
            j--;
        }
        j=i;
        while(j<n){
            rm=max(rm,nums[j]);
            j++;
        }
        water+=min(lm,rm)-nums[i];
    }
    return water;
}

int twoPointer(vector<int>nums){
    int n=nums.size();
    int l=0,r=n-1;
    int lm=0,rm=0;
    int res=0;

    while(l<=r){
        if(nums[l]<=nums[r]){
            if(nums[l]>=lm) lm=nums[l];
            else res+=lm-nums[l];
            l++;
        }else{
            if(nums[r]>=rm) rm=nums[r];
            else res+=rm-nums[r];
            r--;
        }
    }
    return res;
}

int main(){
    vector<int>nums{0,1,0,2,1,0,1,3,2,1,2,1};
    int trapWater=bruteForce(nums);
    int trapWateroptimal=twoPointer(nums);
    cout<<"Trapped Water : "<<trapWater<<endl;
    cout<<"Trapped Water Optimal : "<<trapWateroptimal<<endl;
    return 0;
}
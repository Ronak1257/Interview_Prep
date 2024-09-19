#include<bits/stdc++.h>
using namespace std;

int onePointer(vector<int>nums){
    int ans=0;
    while(true){
        ans=abs(nums[ans]);
        if(nums[ans]<0) return ans;
        nums[ans]*=-1;
    }
    return ans;
}
int bruteForce(vector<int>nums){
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]==nums[j]){
                return nums[i];
            }
        }
    }
    return -1;
}
int usingHash(vector<int>nums){
    map<int,int>map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
    }
    for(auto i:map){
        if(i.second>1){
            return i.first;
        }
    }
    return -1;
}
int main(){
    vector<int>nums={1,3,5,3,6,7};
    cout<<bruteForce(nums)<<endl;
    cout<<usingHash(nums)<<endl;
    cout<<onePointer(nums);
    return 0;
}
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
int main(){
    vector<int>nums={1,3,5,3,6,7};
    cout<<onePointer(nums);
    return 0;
}
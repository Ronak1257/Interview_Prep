#include<bits/stdc++.h>
using namespace std;

int mooresVoting(vector<int>nums){
    int count=1;
    int ele=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]==ele) count++;
        else{
            count--;
            if(count<=0){
                count++;
                ele=nums[i];
            }
        }
    }
    return ele;
}
int main(){
    vector<int>nums={2,3,4,2,2,2};
    cout<<mooresVoting(nums)<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int stockind(vector<int>nums){
    int maxPro=0;
    int n=nums.size();
    int minPri=INT_MAX;
    for(int i=0;i<n;i++){
        minPri=min(minPri,nums[i]);
        maxPro=max(maxPro,nums[i]-minPri);
    }
    return maxPro;
}

int main(){
    vector<int>nums={7,1,2,4,5,6,0};
    cout<<"Max profit can be : "<<stockind(nums)<<endl;
    return 0;
}
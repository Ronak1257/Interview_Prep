#include<bits/stdc++.h>
using namespace std;

int countseq(unordered_set<int>set,int i){
    int cnt=1;
    while(set.find(i+1)!=set.end()){
        i++;
        cnt++;
    }
    return cnt;
}

int longseq(vector<int>nums){
    unordered_set<int>set(nums.begin(),nums.end());
    int n=nums.size();
    int longest=1;

    for(auto i:set){
        if(set.find(i-1)==set.end()){
            longest=max(longest,countseq(set,i));
        }
    }
    return longest;
}
int main(){
    vector<int>nums{100,110,1,3,2,4};
    int ans=longseq(nums);
    cout<<ans<<endl;
    return 0;
}
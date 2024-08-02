#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> usingMath(vector<int>nums){
    int n=nums.size();
    int s=0,s2=0;
    int sn=(n*(n+1))/2;
    int s2n=(n*(n+1)*(2*n+1))/6;
    for(int i=0;i<n;i++){
        s+=nums[i];
        s2+=nums[i]*nums[i];
    }
    int t1=s-sn;
    int t2=(s2-s2n)/t1;
    vector<int>ans={(t1+t2)/2,(t2-t1)/2};
    return ans;
}

vector<int> usingXor(vector<int>nums){
    int xy=0,n=nums.size();
    for(int i=0;i<n;i++){
        xy^=nums[i];
        xy^=i+1;
    }
    int number=(xy & ~(xy-1));
    int one=0,zero=0;
    for(int i=0;i<n;i++){
        if((nums[i]&number)!=0) one^=nums[i];
        else zero^=nums[i];
    }
    for(int i=1;i<=n;i++){
        if((i&number)!=0) one^=i;
        else zero^=i;
    }
    int a1c=0,a2c=0;
    for(int i=0;i<n;i++){
        if(nums[i]==one) a1c++;
        else if(nums[i]==zero) a2c++;
    }
    if(a1c==2) return {one,zero};
    else return {zero,one};
}
int main(){
    vector<int>nums={1,2,2,3,5};
    // vector<int>ans=usingMath(nums);
    // cout<<"repeating : "<<ans[0]<<endl<<"missing : "<<ans[1]<<endl;

    vector<int>ans1=usingXor(nums);
    cout<<"repeating : "<<ans1[0]<<endl<<"missing : "<<ans1[1]<<endl;

    return 0;
}
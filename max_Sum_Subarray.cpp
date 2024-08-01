#include<bits/stdc++.h>
using namespace std;

int bruteForce(vector<int>nums){
    int maxSum=INT_MIN,si=0,ei=0;
    for(int i=0;i<nums.size();i++){
        int csum=0;
        for(int j=i;j<nums.size();j++){
            csum+=nums[j];
            if(csum>maxSum){
                maxSum=csum;
                si=i;
                ei=j;
            }
        }
    }
    cout<<"{";
    for(int i=si;i<=ei;i++){
        cout<<nums[i]<<" ";
    }
    cout<<"}"<<endl;
    return maxSum;
}

long long intutionAlgo(vector<int>nums){
    long long maxi=LONG_MIN;
    long long sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum>maxi) maxi=sum;
        if(sum<0) sum=0;
    }
    return maxi;
}

int main(){
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};

    cout<<bruteForce(nums)<<" is maxSum from bruteForce method"<<endl;
    
    //not print negative sum if possible insted print 0;
    cout<<"max sum with intution algorithm : "<<intutionAlgo(nums)<<endl;


    return 0;
}
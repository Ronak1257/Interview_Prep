#include<bits/stdc++.h>
using namespace std;

void swapGreaters(vector<int> &num1,vector<int> &num2,int i,int j){
    if(num1[i]>num2[j]) swap(num1[i],num2[j]);
}
void gapMethods(vector<int>&num1,vector<int>&num2,int n,int m){
    int len=n+m;
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            if(left<n && right>=n){
                swapGreaters(num1,num2,left,right-n);
            }
            else if(left>=n){
                swapGreaters(num2,num2,left-n,right-n);
            }
            else{
                swapGreaters(num1,num1,left,right);
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
}
int main(){
    vector<int>num1={1,4,8,10};
    vector<int>num2={2,3,9};
    gapMethods(num1,num2,num1.size(),num2.size());
    cout<<"Sorted Array :"<<endl;
    for(int i=0;i<num1.size();i++){
        cout<<num1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<num2.size();i++){
        cout<<num2[i]<<" ";
    }
    return 0;
}
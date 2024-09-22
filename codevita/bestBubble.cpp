#include<bits/stdc++.h>
using namespace std;

int minSwap(vector<int>arr){
    int n=arr.size();
    vector<int>arr2=arr;
    int swapc=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr2[j]>arr2[j+1]){
                swapc++;
                swap(arr2[j],arr2[j+1]);
            }
        }
    }
    int swapc2=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                swapc2++;
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return min(swapc,swapc2);
}

int main(){
    int n; cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int swap=minSwap(arr);
    cout<<swap<<endl;
    return 0;
}
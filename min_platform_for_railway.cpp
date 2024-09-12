#include<bits/stdc++.h>
using namespace std;

int countPlatform(vector<int>arr,vector<int>dep){
    int ans=1;
    for(int i=0;i<arr.size()-1;i++){
        int cnt=1;
        for(int j=i+1;j<arr.size();j++){
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) || (arr[j]>=arr[i] && dep[i]>=arr[j])) cnt++;
        }
        ans=max(ans,cnt);
    }
    return ans;
}

int countOptimal(vector<int>arr,vector<int>dep){
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int ans=1;
    int count=1;
    int i=1,j=0;
    int n=arr.size();
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        ans=max(ans,count);
    }
    return ans;
}

int main(){
    vector<int>arr{900,945,955,1100,1500,1800};
    vector<int>dep{920,1200,1130,1150,1900,2000};
    int count=countPlatform(arr,dep);
    int co=countOptimal(arr,dep);
    cout<<"Min no of platform required : "<<count<<endl;
    cout<<"Min no of platform required Optimal : "<<co<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};
bool comp(struct Job a,Job b){
    return a.profit>b.profit;
}

pair<int,int> jobSchedule(vector<Job>arr,int n){
    sort(arr.begin(),arr.end(),comp);
    int maxi=arr[0].dead;
    for(int i=1;i<n;i++){
        maxi=max(maxi,arr[i].dead);
    }
    vector<int>slot(maxi+1,-1);
    int cj=0,jp=0;
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                cj++;
                jp+=arr[i].profit;
                break;
            }
        }
    }
    return {cj,jp};
}
int main(){
    vector<Job>arr{{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    int n=arr.size();
    pair<int,int>ans=jobSchedule(arr,n);
    cout<<"Total Job Done : "<<ans.first<<"\nTotal Profit : "<<ans.second<<endl;
    return 0;
}
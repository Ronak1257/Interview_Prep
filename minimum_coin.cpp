#include<bits/stdc++.h>
using namespace std;

pair<int,vector<int>> findMinCoin(int n){
    int coin=0;
    vector<int>arr{1000,500,100,50,20,10,5,2,1};
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        if(n>=arr[i]){
            int temp=n/arr[i];
            coin+=temp;
            while(temp--){
                ans.push_back(arr[i]);
            }
            n%=arr[i];
        }
        if(n==0) break;
    }
    return {coin,ans};
}
int main(){
    int n=49;
    pair<int,vector<int>> mincoin=findMinCoin(n);
    cout<<"Min no of coins required : "<<mincoin.first<<endl;
    cout<<"Coins are : ";
    for(int i:mincoin.second){
        cout<<i<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct Item{
    int value;
    int weight;
};
bool comp(Item a,Item b){
    double a1=(double)a.value/a.weight;
    double a2=(double)b.value/b.weight;
    return a1>a2;
}
int fractional_knapsnap(vector<Item>arr,int n,int w){
    sort(arr.begin(),arr.end(),comp);
    int current_weight=0;
    double final_value=0.0;
    for(int i=0;i<n;i++){
        if(current_weight+arr[i].weight<=w){
            current_weight+=arr[i].weight;
            final_value+=arr[i].value;
        }
        else{
            int remain=w-current_weight;
            final_value+=(arr[i].value/(double)arr[i].weight)*(double)remain;
            break;
        }
    }
    return final_value;
}
int main(){
    vector<Item>arr{{60,10},{100,20},{120,30}};
    int n=arr.size();
    int w=50;
    int fract=fractional_knapsnap(arr,n,w);
    cout<<"Max Profit : "<<fract<<endl;
    return 0;
}
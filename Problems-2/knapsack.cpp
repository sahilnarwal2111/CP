#include<iostream>
using namespace std;
int rec(vector<int> wt, vector<int> val, int w, int i){
    if(i < 0) return 0;
    if(w<=0) return 0;
    if(wt[i]<=w){
    //included case
    int ans1 =  val[i] + rec(wt, val, w-wt[i], i-1);
    //not including 
    int ans2 = rec(wt,val,w,i-1);
    return max(ans1,ans2);
    }else{
        return rec(wt,val, w, i-1);
    }
}
int main(){
    int n,w;
    cin>>n>>w;
    vector<int> val, wt;
    while(n--){
        int weight,value;
        cin>>weight>>value;
        wt.push_back(weight);
        val.push_back(value);
    }
    cout<<rec(wt,val,w,val.size()-1)<<endl;

    return 0;
}
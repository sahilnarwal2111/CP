#include<iostream>
using namespace std;

bool rec(int i, vector<int> val, int s, int sum){
    if(i<0){
        if(sum == s) return 1;
        else return 0;
    }
    return rec(i-1,val,s-val[i],sum) || rec(i-1,val,s+val[i],sum);
}

int main(){
    int n, sum;
    cin>>n>>sum;
    vector<int> val(n);
    for(int i = 0 ; i < n ; i++) cin>>val[i];
    if (rec(val.size()-1,val,0,sum) == 1) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    return 0;
}
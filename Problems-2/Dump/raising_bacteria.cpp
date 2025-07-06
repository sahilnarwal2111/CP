#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int count_set_bits(int n){
    int cnt = 0;
    while(n>0){
        if((n&1)!=0) cnt++;
        n=n>>1;
    }
    return cnt;
}
int main(){
    int n; cin>>n;
    cout<<count_set_bits(n)<<endl;
    return 0;
}
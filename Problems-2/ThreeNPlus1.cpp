#include<iostream>
using namespace std;

int fun(int n){
    if(n<=1) return 1;
    if(n&1) return 1 + fun(3*n+1);
    else return  1 + fun(n/2);
}

int main(){
    int n;
    cin>>n;
    cout<<fun(n)<<endl;
    return 0;
}
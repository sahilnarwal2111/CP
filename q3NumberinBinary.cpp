//Print a number in binary recursively
#include<iostream>
#include <string>
#include <algorithm>
using namespace std;
void f(int n, string& str){
    if(n<=0) return;
    if(n%2==0) str = "0" + str;
    else str = "1" + str;
    f(n/2,str);
}

void bn(int n){
    if(n<=1){
        cout<<n<<' ';
        return;
    }
    else{
        bn(n/2);
        cout<<n%2<<' ';
    }
}

void adv(int n){
    if(n==0) return;
    adv(n>>1);
    cout<<(n&1);
}

using namespace std;
int main(){
    int n = 11;
    string str = "";
    // while(n>0){
    //     if(n%2==0) str+="0";
    //     else str+="1";
    //     n/=2;
    // }
    // reverse(str.begin(), str.end());
    // f(n,str);
    // cout<<str<<endl;
    adv(4);
    return 0;
}


/*
n>>2 = n/2
n&1 = n % 2
*/
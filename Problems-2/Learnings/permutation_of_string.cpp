#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

void permute(string &a, int l , int r){
    if(l == r){
        cout<<a<<'\n';
        return;
    }
    for(int i = l ; i <= r ; i++){
        swap(a[i],a[l]);
        permute(a,l+1,r);
        swap(a[i],a[l]);
    }
}

int main(){
    string a = "AAA";
    permute(a,0,a.size()-1);
    return 0;
}
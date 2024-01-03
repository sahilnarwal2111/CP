#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int hcf(int a , int b){
    int res = min(a,b);
    while(res>0){
        if(a%res == 0 && b%res == 0) break;
        res--;
    }
    return res;

}

int main(){
    cout<<hcf(1,4);
    return 0;
}
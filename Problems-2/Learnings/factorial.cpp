#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
long fact(int n){
        long ans =1;
        while(n >=1 ){
            ans*=n;
            n--;
        
        }
        return ans;
    }
int main(){
    cout<<fact(5)<<endl;
    return 0;
}
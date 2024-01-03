#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

int lcm(int a, int b){
    if(a>b){
        int ans = a;
        while(1){
            if(ans%a == 0 && ans%b== 0){
                return ans;
            }
            else ans++;
        }
    }
    else{
        int ans = b;
        while(1){
            if(ans%a == 0 && ans%b== 0){
                return ans;
            }
            else ans++;
        }
    }
}

int hcf(int a , int b){
    int res = min(a,b);
    while(res>0){
        if(a%res == 0 && b%res == 0) break;
        res--;
    }
    return res;

}

bool fact(int num, int a, int b){
    int n = num-1;
    int count = 0;
    vector<int> top2;
    while(n>=1 && count<2){
        if(num%n == 0){
            top2.push_back(n);
            count++;
        }
        n--;
    }
    if(top2[0] == b && top2[1] == a) return true;
    return false;
}
int main(){
    int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b;
        int ans = max(a,b) +1;
        while(1){
            if(fact(ans,a,b)){
                cout<<ans<<'\n';
                break;
            }
            ans++;
        }


    }
    return 0;
}
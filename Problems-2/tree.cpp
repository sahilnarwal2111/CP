#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;

    


};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str = "SSPPSPSPSPSPSPPS";
    int cnt = 0;
    for(auto ch : str) if(ch == 'S') cnt++;
    if(cnt & 1) cout<<"Not Possible"<<endl;
    else {
        int taken = 0;
        string res = "";
        for(int i = 0; i  < str.size(); i++){
            if(str[i] == 'S'){
                if(taken == 0){
                    res += str[i];
                    taken++;
                }
                else if(taken == 1){
                    res += str[i];
                    taken = 0;
                }
            }else if(taken == 1){
                continue;
            }
            else{
                res += str[i];
            }
        }
        cout<<str<<endl;
        cout<<res<<endl;
        long long ans = 1;
        int p_cnt = 1;
        for(int i = 0 ; i < res.size() ; i++){
            if(res[i] == 'P'){
                p_cnt++;
            }
            else{
                ans = ans * p_cnt;
                p_cnt = 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
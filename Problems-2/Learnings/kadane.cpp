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

string maxSum(string w,char x[], int b[],int n){
        // code here    
        unordered_map<char,int> map;
        for(int i = 0 ; i < n ; i++){
            map[x[i]] = b[i];
        }
        int cur = 0;
        int mx = INT_MIN;
        int st = 0, e = 0, s = 0;
        for(int i = 0 ; i < w.size(); i++){
            char c = w[i];
            if(map.find(c)!=map.end()){
                cur = cur + map[c];
            }else{
                cur = cur + w[i];
            }
            if(cur >   mx){
            mx = cur;
            st = s;
            e = i;
            }
            if(cur < 0){
                cur = 0;
            //   ans = "";/
                s = i + 1;
            }
        }
        cout<<mx<<endl;
        string ans = "";
        for(int i = st; i <= e ; i++) ans += w[i];
        return ans;
    }


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string w = "GvtRG";
    int n = 2;
    char x[] = {'t','v'};
    int b[] = {26, -640};

    cout<<maxSum(w,x,b,n)<<endl;

    // int arr[] = {71, -640, 26, 82, 71};
    // int cur = 0;
    // int mx = INT_MIN;
    // vector<int> ans;
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int st = 0, e = 0;
    // int s = 0;
    // for(int i= 0 ; i < n ; i++){
    //     cur = cur + arr[i];
        
    //     // mx = max(mx,cur);
    //     // ans.push_back(arr[i]);
    
    //     if(cur > mx){
    //         mx = cur;
    //         st = s;
    //         e = i;
            
    //     }
    //     if(cur < 0) {
    //         ans.clear();
    //         cur = 0;
    //         s = i + 1;
    //     }
        
    // }
    // cout<<mx<<endl;
    // for(int el : ans) cout<<el<<" ";
    // for(int i = st; i<=e; i++) cout<<arr[i]<<" ";
    // cout<<endl;
    // cout<<endl;
    // //for all negative

    return 0;
}

// GvtRG 71 -640 26 82 71
// 2
// t v
// 26 -640


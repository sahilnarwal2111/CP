#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <unordered_set>

#include <stack>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define int long long
#define endl '\n'
using namespace std;

bool rec(vector<int> & arr1, vector<int> & arr2, int i , int j , int cnt1, int cnt2, int k, int val){

}

void solve(){
    int n, m,k;
    cin>>n>>m>>k;
    int a1[n],a2[m];
    for(int i = 0 ; i < n ; i++) cin>>a1[i];
    for(int i = 0 ; i < m ; i++) cin>>a2[i];

    unordered_set<int> s1 ;
    unordered_set<int> s2 ;

    for(int i = 0 ; i < n ; i++){
        if(a1[i] <= k){
            s1.insert(a1[i]);
        }
    }
    for(int i = 0 ; i < m ; i++){
        if(a2[i] <= k){
            s2.insert(a2[i]);
        }
    }
    
    vector<int> arr1;
    vector<int> arr2;

    for(int x : s1) arr1.push_back(x);
    for(int x : s2) arr2.push_back(x);

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    unordered_set<int> s;
    for(int x : arr1) s.insert(x);
    for(int x : arr2) s.insert(x);

    if(arr1.size() < k/2) {
        cout<<"NO"<<endl;
        return;
    }
    if(arr2.size() < k/2) {
        cout<<"NO"<<endl;
        return;
    }

    int sum = 0;
    for(int x : s){
        sum += x;

    }
    int sum_needed = k * (k + 1);
    sum_needed /= 2;

    if(sum_needed == sum){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    
    

}
bool valid(vector<int> & arr){
        if(arr[1]-arr[0] > 0){
            for(int i = 1 ; i + 1 < arr.size(); i = i + 2){
                if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                    continue;
                }
                else{
                    return false;
                }
            }
            if(arr.size()&1){
                // continue;
            }else{
                if(arr[arr.size()-1] <= arr[arr.size()-2]){
                    return false;
                }
            }
            return 1;
        }
        else if(arr[0] > arr[1]){
            for(int i = 1; i +1 < arr.size() ; i = i + 2){
                if(arr[i] < arr[i-1] && arr[i] < arr[i+1]){
                    continue;
                }
                else{
                    return false;
                }
            }
            if(arr.size()&1){
                
            }
            else{
                if(arr[arr.size()-1] < arr[arr.size()-2]){
                    return false;
                }
            }
            return true;
        }
        else return false;
        return false;
    }


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // vector<int> arr =  {1,17,5,10,13,15,10,5,16,8};
    vector<int> arr =  {3,2,5};
    // vector<int> arr =  {1,2,3,4,5,6,7,8,9};
    // vector<int> arr =  {1,7,4,9,2,5};
    cout<<valid(arr)<<endl;
    for(auto & i : arr) cout<<i<<" ";
    cout<<endl;

}


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<numeric>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <ios>
// #define ll long long
#define int long long
using namespace std;



void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for(auto &p : arr)
        cin >> p.first >> p.second;
    
    sort(arr.begin(), arr.end(), [](const pair<int,int> &p1, const pair<int,int> &p2){
        if(p1.second < p2.second) return true;
        if(p1.second == p2.second) return p1.first < p2.first;
        return false;
    });
    multiset<int> st; // storing the ending of movie which ith person is watching
    int cnt = 0;
    for(int i = 0; i < n ; i++){
        int start = arr[i].first;
        //find suitable person who can watch this movie
        if(st.size() < k) {
            
            if(st.size() == 0)
                st.insert(arr[i].second);
            else if(start >= *st.begin()){

                auto itr = st.upper_bound(start);
                if(itr != st.begin()){
                    itr--;
                }
                st.erase(st.find(*itr));
                st.insert(arr[i].second);

            }else{
                st.insert(arr[i].second);
            }
            cnt++;
        }
        else if(start >= *st.begin()){

            auto itr = st.upper_bound(start);
                if(itr != st.begin()){
                    itr--;
                }
                st.erase(st.find(*itr));
                st.insert(arr[i].second);


            cnt++;
            // cout << i << " b" << endl;
            
        }
    }


    cout << cnt << '\n';
    
}    
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    // int tt;
    // cin >> tt;
    // while(tt--)
        solve();
    return 0;
}

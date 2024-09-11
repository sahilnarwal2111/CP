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
// #define int long long int
using namespace std;
class Data_structures{
    public:
        multiset<int> first, second;
        int size1 = 0;

        void set_size(int size){
            this->size1 = size;
        }

        void _insert(int x){
            first.insert(x);
            if(first.size() > size1){
                int ele = *first.rbegin();
                second.insert(ele);
                first.erase(first.find(ele));
            }
        }

        void _delete(int x){
            auto itr = second.find(x);
            if(itr == second.end()){
                // first mai present hai
                auto it = first.find(*itr);
                first.erase(first.find(x));
                if(!second.empty()){
                    int ele = *second.begin();
                    first.insert(ele);
                    second.erase(second.find(ele));
                }
            }else{
                // second mai present hai
                second.erase(itr);
            }

        }

        int find_median(){
            return *first.rbegin();
        }

        void print(){
            for(auto &itr : first){
                cout << itr << " ";
            }
            cout << endl;
            for(auto &itr : second){
                cout << itr << " ";
            }
            cout << endl;
        }
    };


void solve(){
    int n, k; 
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    
    Data_structures ds;
    
    int fs = (k + 1) / 2;
    ds.set_size(fs);

    int l = 0 , r= 0;
    for(int r = 0 ; r < n ; r++){
        ds._insert(arr[r]);
        if(r - l + 1 == k){
            cout << ds.find_median() << " ";
            ds._delete(arr[l]);
            l++;
        }
    }

    
   
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int tt;
    // cin >> tt;
    // while(tt--)
        solve();
    
    return 0;
}   
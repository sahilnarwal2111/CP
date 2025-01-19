// || =================================================================== ||
// ||                                                                     ||
// ||                   Reach Expert by May 2025                          ||
// ||                                                                     ||
// || =================================================================== ||
#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int long long 
#define endl "\n";
#define all(a) a.begin(), a.end()           
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key


long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod; 
        exp /= 2; 
    }
    return result;
}
bool check(vector<int> & arr, int k, int x){
    int ops = 0;
    for(auto el : arr){
        if(el < x){
            ops += x - el;
        }
        // if(ops > k)
        //     return 0;
    }
    return ops <= k;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;

    //lets try to find maximum value which i can assign to each card 
    int low = 0, high = 1e13;
    int max_common_val = 0;
    while(low <= high){
        int mid = (low + high) / 2LL;
        if(check(arr, k, mid)){
            max_common_val = mid;
            low = mid + 1LL;
        }else{
            high = mid - 1LL;
        }
    }
    // here we have found max_common_value
    // cout << max_common_val << endl;

    int x = 0;
    for(auto el : arr)
        if(el > max_common_val)
            x++;

    int ans = n * max_common_val - (n - 1LL);
    for(auto &i : arr)
        if(i >= max_common_val)
            i -= max_common_val;
        else {
            k -= (max_common_val - i);
            i = 0;
        }
    // cout << k << endl;
    // for(auto &i : arr)
    //     cout << i << " ";
    // cout << endl;

    // i will try to count firsts from left

    // // now count two max contingous segements
    // vector<int> segments;
    // int len = 0;
    // for(auto el : arr)
    //     if(el != 0){
    //         len++;
    //     }else{
    //         segments.push_back(len);
    //         len = 0;
    //     }
    // if(len != 0)
    //     segments.push_back(len);

    // sort(all(segments));
    // reverse(all(segments));

    // // cout << k << endl;

    // // for(auto el : segments)
    // //     cout << el << " ";
    // // cout << endl;

    // for(int i = 0 ; i < min(2LL, (int)segments.size()); i++)
    //     ans += segments[i];
    

    // cout << ans + k << endl;


    // int x = 0;
    // for(auto i : arr)
    //     if(i > 0)
    //         x++;
    
    cout << ans + x + min(n - x, k) << endl;
    int zero = 0;
    for(auto el : arr)
        if(el == 0)
            zero++;

    
    // cout << ans + x + min(zero, k) << endl;


}


signed main(){
    int t;
    cin >> t;
    while(t--)
        solve();
   
}
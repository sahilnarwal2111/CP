// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for(auto &i : arr)  
            cin >> i;

        vector<int> sums(n + 1, LLONG_MIN);
        for(int i = 0; i < n; i++){
            int sum =0;
            for(int j = i; j < n; j++){
                sum += arr[j];
                sums[j-i+1] = max(sums[j-i+1], sum);
            }   
        }
        // for(int len = 1; len <=n ; len++){
        //     cout << sums[len] << " ";
        // }
        // cout << endl;
        vector<int> ans(n + 1, 0);
        ans[0] = max(0ll, *max_element(sums.begin(), sums.end()));
        for(int k = 1; k <= n; k++){
            int adder = k * x;
            // length should be atleast k
            int maxSum = LLONG_MIN;
            for(int len = k; len <= n; len++){
                maxSum = max(maxSum, sums[len] + adder);
            }   
            ans[k] = max(maxSum, ans[k-1]);
        }
        for(auto i : ans)
            cout << i << " ";
        cout << endl;
    }

    
    return 0;
}
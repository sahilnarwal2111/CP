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
    int n, c, d;
    cin >> n >> c >> d;
    // c -> cost of removing
    // d -> cost of insertion
    vector<int> arr(n);
    for(auto &i : arr)
        cin >> i;
    sort(arr.begin(), arr.end());
    vector<int> brr;
    int costOfInsertions = 0;
    if(arr[0] != 1){
        brr.push_back(1);
        costOfInsertions += d;
    }
    brr.push_back(arr[0]);
    for(auto &i : arr)
        if(brr.back() != i)
            brr.push_back(i);
    int duplicates = arr.size() - brr.size();
    if(arr[0] != 1){
        duplicates++;
    }
    int ans = LLONG_MAX;
    int N = brr.size();
    for(int i = 1; i < N ; i++){
        // we consider to remove all brr starting from index i 
        int elementsToBeRemoved = N - i;
        // total cost = cost of inserting till now and removing the elment left right of i
        int cost = elementsToBeRemoved * c + costOfInsertions;
        ans = min(ans, cost);
        // we consider to add all the missing numbers
        int missing = brr[i] - brr[i-1] - 1;
        costOfInsertions += (missing * d);

    }
    // we reached the end of array and if we want to keep all the numbers and dont wanna to remove any one
    ans = min(ans, costOfInsertions);
    
    
    // also have a look at the case of size equals to largest element
    
    //duplicates removel cost need to be added in last
    cout << ans + duplicates * c << '\n';
}    
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cstdlib>
#include <sstream>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vp;
// #define "\n" endl;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    for(auto &i : arr) cin >> i;
    vector<int> values(m);
    sort(arr.begin(), arr.end());
    for(int i = 0; i < m; i++){
        int x = arr[i];
        int y;
        if(i != m - 1){
            y = arr[i+1];
        }else y = arr[0];

        if(y > x){
            values[i] = y - x - 1;
        }else{
            values[i] = n - x + y - 1;
        }
    }
    sort(values.begin(), values.end());
    reverse(values.begin(), values.end());
    
    int healthy = 0;
    int day = 0;
    for(int i = 0 ; i < m ; i++){
        values[i] -=  2 * day;
        if(values[i] > 0){
            if(values[i] == 1){
                healthy += 1;
                day++;
            }else{
                healthy += (values[i] - 1);
                day += 2;
            }

        }
    }
    cout << n - healthy << endl;
}
signed main(){
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    
    return 0;
}
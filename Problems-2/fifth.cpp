#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <unordered_set>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;

const int N = 10000007;
vector<bool> primes(N, true);

void solve(){
    int n,m; cin>>n>>m;
    int arr[n][m];
    for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < m ; j++) cin>>arr[i][j];

    int row[n], col[m];
    //row wise iterate
    for(int i = 0 ; i < n ; i++){
        int val = 0;
        for(int j = 0 ; j < m ; j++){
            int num = arr[i][j];
            if(primes[num]) continue;
            else{
                //next prime
                while(1){
                    num++;
                    if(primes[num] == 1) break;
                }
                int ans1= num-arr[i][j];
                //prev prime
                num = arr[i][j];
                while(1){
                    num--;
                    if(primes[num] == 1) break;
                }
                int ans2 = arr[i][j] - num;
                val+=min(ans1,ans2);
            }
            
        }
        row[i] = val;
    }
    //colunm wise iteration
    for(int i = 0 ; i < m ; i++){
        int val = 0;
        for(int j = 0 ; j < n ; j++){
            int num = arr[j][i];
            if(primes[num]) continue;
            else{
                //next prime
                while(1){
                    num++;
                    if(primes[num] == 1) break;
                }
                int ans1= num-arr[j][i];
                //prev prime
                num = arr[j][i];
                while(1){
                    num--;
                    if(primes[num] == 1) break;
                }
                int ans2 = arr[j][i] - num;
                val+=min(ans1,ans2);
            }   
        }
        col[i] = val;
        
    }
    int ans = INT_MAX;
    for(int i = 0 ; i < n ; i++) ans = min(ans, row[i]);
    for(int i = 0 ; i < m ; i++) ans = min(ans,col[i]);
    cout<<ans<<endl;  
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    primes[0] = primes[1]=0;
    for(int i = 2; i*i <= N; i++)
        if(primes[i])
            for(int j = i*i; j<=N; j+=i)
                primes[j] = 0;
    
    solve();
    return 0;
}
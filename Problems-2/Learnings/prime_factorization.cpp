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
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;

vector<int> prime_fact(int n){
    vector<int> ans ;
    for(int i = 2 ; i * i <= n; i++){
        while(n % i == 0){
            ans.push_back(i);
            n/=i;
        }
    }
    if( n > 1 ) ans.push_back(n);
    return ans;
}

void sieve(int n ){  //TC : O(N * log(logN))
    bool primes[n+1];
    fill(primes, primes + n + 1, true);
    primes[0] = primes[1] = false;
    for(int i = 2 ; i * i <= n; i++){
        if(primes[i])
            for(int j = i * i; j <= n; j+=i)
                primes[j] = false;   
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> facts = prime_fact(34);
    for(int el : facts) cout<<el<<" ";
    cout<<'\n';
    return 0;
}
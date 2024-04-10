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
// #define int long long
#define endl '\n'
using namespace std;


int __gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

long long lcm(long long a, long long b){
    return (a*b) / __gcd(a, b);
}

vector<vector<int> > sequence(int n){
    vector<vector<int> > operations;

    int limit = min(n, (int)floor(n/6) + 5);
    for(int i = 1; i <= limit; ++i){
        operations.push_back({i, i + 1, i + 2});
    }
    return operations;
}

int main() {
    cout<<(1<<2)<<endl;
    return 0;
}

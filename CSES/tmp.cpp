#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(4);
    ms.insert(5);
    ms.insert(6);
    ms.insert(7);

    auto itr = ms.begin();
    advance(itr, 2);

    cout << *itr << endl;

    ms.insert(8);

    cout << *itr << endl;

    return 0;
}
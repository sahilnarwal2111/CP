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
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str = "sahil";
    int start = 0;
    for(int len = 1; len + start <= str.size() ; len++){
        cout<<str.substr(start, len)<<" "<<str.substr(len)<<endl;
    }
    return 0;
}
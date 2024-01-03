#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

void rec(vector<string> &res, string temp, int open, int close, int n){
    if(temp.size() == 2 * n){
        res.push_back(temp);
        return;
    }

    if(open< n){
        rec(res, temp + '(', open +1, close, n);
    }
    if(close < open){
        rec(res, temp + ')', open, close + 1, n);

    }
}

int main(){
    vector<string> res ;
    int n; cin>>n;
    rec(res, "", 0,0,n);
    for(auto &str : res){
        cout<<str<<endl;
    }
    return 0;
}
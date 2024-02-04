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
    vector<int> arr1;
    arr1.push_back(6);
    arr1.push_back(7);
    vector<int> arr2;
    arr2.push_back(7);
    arr2.push_back(0);
    arr2.push_back(0);
    vector<int> ans (max(arr1.size(), arr2.size()),0);
    int n2 = arr2.size();
    int n1 = arr1.size();
    int diff = n2 - n1;
    for(int i = n1; i >=0 ; i--){
        int top = arr2[i + diff];
        int down = arr1[i];
        if(top >= down){
            ans[i+diff] = top - down;
        }else{
            arr1[i + diff -1]--;
            //complete this part of involing carry
            top = top + 10;
            ans[i+diff] = top - down;
        }
    }
    for(auto & el : ans) cout<<el<<" ";
    cout<<'\n';
    return 0;
}
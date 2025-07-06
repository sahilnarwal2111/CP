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
    arr1.push_back(1);
    arr1.push_back(2);
    // arr1.push_back(7);
    vector<int> arr2;
    arr2.push_back(1);
    arr2.push_back(0);
    arr2.push_back(0);
    // arr2.push_back(4);
    // arr2.push_back(5);
    // vector<int> ans (max(arr1.size(), arr2.size()),0);
    // int n2 = arr2.size();
    // int n1 = arr1.size();
    // int diff = n2 - n1;
    // for(int i = n1-1; i >=0 ; i--){
    //     int top = arr2[i + diff];
    //     int down = arr1[i];
    //     if(top >= down){
    //         ans[i+diff] = top - down;
    //     }else{
    //         for(int j = i - 1; j >= 0 ; j--){
    //             cout<<"entered loop"<<endl;
    //             if(arr2[j] == 0){
    //                 arr2[j] = 9;
    //                 cout<<"made 9"<<endl;
    //             }
    //             else if(arr2[j]!=0){
    //                 arr2[j]--;
    //                 cout<<"dec "<<endl;
    //                 break;
    //             }
    //         }
    //         for(auto & el : arr2) cout<<el<<" ";
    //         cout<<endl;
    //         top = top + 10;
    //         ans[i+diff] = top - down;
    //     }
    //     cout<<"TOP "<<top<<" "<<" DOWN "<<down<<" " <<ans[i + diff]<<" "<<endl;
        
    // }
    // for(int i = n2-n1-1 ; i>=0 ; i--){
    //     ans[i] = arr2[i];
    // }

    // cout<<'\n';
    // for(auto & el : ans) cout<<el<<" ";
    // cout<<'\n';
    // return 0;
    vector<int> ans (max(arr1.size(), arr2.size()),0);
    int n2 = arr2.size();
    int n1 = arr1.size();
    int diff = n2 - n1;
    for (int i = n1 - 1; i >= 0; i--) {
        int top = arr2[i + diff];
        int down = arr1[i];

        if (top >= down) {
            ans[i + diff] = top - down;
        } else {
            int j = i + diff - 1;
            while (j >= 0 && arr2[j] == 0) {
                arr2[j] = 9;
                j--;
            }

            if (j >= 0) {
                arr2[j]--;
                ans[j + diff] = top + 10 - down;
            } else {
                // Handle the case where there is no further borrow
                ans[i + diff] = top - down;
            }
        }
    }

    for (int i = 0; i < n2 - n1; i++) {
        ans[i] = arr2[i];
    }

    cout << '\n';
    for(auto & el : ans) cout << el << " ";
    cout << '\n';
    return 0;
}
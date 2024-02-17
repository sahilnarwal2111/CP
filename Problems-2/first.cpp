#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <map>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cstdlib>
#define mod (ll)(1e9+7)
// #define int long long
#define endl '\n'
using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int p = -1, n = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > 0){
                p = i;
                break;
            }
        }
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] < 0){
                n = i;
                break;
            }
        }
        // cout<<p<<" "<<n<<" ";
        for(int i = 0 ; i < nums.size() ; i++){
            if(i % 2 == 0){
                ans.push_back(nums[p]);
                p++;
                while(p < nums.size()){
                if(nums[p] > 0){
                    break;
                }
                else p++;
            }
            }
            else{
                ans.push_back(nums[n]);
                n++;
                while(n < nums.size()){
                if(nums[n] < 0){
                    break;
                }
                else n++;
            }
            }            
        }

        return ans;
    }



signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // //[3,1,-2,-5,2,-4]
    // vector<int> nums;
    // nums.push_back(3);
    // nums.push_back(1);
    // nums.push_back(-2);
    // nums.push_back(-5);
    // nums.push_back(2);
    // nums.push_back(-4);

    // vector<int> ans = rearrangeArray(nums);
    // for(int i = 0 ; i < ans.size() ; i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;

    // vector<int> arr;
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(4);
    // arr.push_back(5);
    // int a = 2;
    // int b = 1;

    // a = a + b - (b = a);
    // cout<<a<<" "<<b;
    vector<vector<int>> arr ;
    // vector<int> arr {1,2,3,4,5};
    // for(int i = 0 ; i < 5 ; i++) arr.push_back(i);
    // for(auto & i : arr) cout<<i<<" ";

    for(int i = 0 ; i < 3 ; i++){
        arr.push_back(vector<int>{1,2,3});
    }

    for(auto vec : arr){
        for(auto & i : vec){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// (1 2) 3 
//     (1 2) 3
//         2 1 3
//     2 (1 3)
//         2 3 1

// 1 (2 3)
//     (1 3) 2
//         3 1 2
//     1 (2 3)
//         1 3 2   



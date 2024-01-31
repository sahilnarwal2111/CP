#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set<int> arr;
        for(int i = 0 ; i < n ; i++) {
            int temp ; cin>>temp;
            arr.insert(temp);
        }
        set<int> temp;
        int ans = -1;
        for(int i = 1 ; i < 1024; i++){
            for(auto &el : arr){
                temp.insert(el ^ i);
            }
            if(temp == arr){
                ans = i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
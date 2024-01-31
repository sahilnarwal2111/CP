#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include <cstdlib>
#define mod (ll)(1e9+7)
#define ll long long
using namespace std;

void generate_lps_array(string str, int * lps){
    int n = str.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while( i < n ){
        if(str[i] == str[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if( len > 0 ){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
        
    }

}

vector<int> kmp(string pat, string txt){
    vector<int> ans ;
    int n = txt.size();
    int m = pat.size();
    int lps[m+1];
    generate_lps_array(pat, lps);
    //shifting the array lps
    for(int i = m-1 ; i >= 0 ; i++){
        lps[i+1] = lps[i];
    }
    lps[0] = 0;

    int j = 0;
    for(int i = 0 ; i < n ; ){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == m){
            ans.push_back((i+1) - m);
            j = lps[j];
        }
        else{ // string not matched
            if(j == 0 ){
                i++;
            }
            else 
          
    }



}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> ans = kmp("q","hqg");
    for(auto &el : ans) cout<<el<<" ";
    cout<<endl;
    return 0;
}
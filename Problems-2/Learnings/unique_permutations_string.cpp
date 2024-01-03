#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

void permute(string &a, int l , int r,set<string> &resSet){
    if(l == r){
        // cout<<a<<'\n';
        resSet.insert(a);
        return;
    }
    for(int i = l ; i <= r ; i++){
        swap(a[i],a[l]);
        permute(a,l+1,r,resSet);
        swap(a[i],a[l]);
    }
}



int main(){
    string str = "AAC";

    set<string> resSet ;

    permute(str,0,str.size()-1,resSet);
    vector<string> res ;
    for(auto &s : resSet) res.push_back(s);

    for(auto &s : res) cout<<s<<endl;
    return 0;
}
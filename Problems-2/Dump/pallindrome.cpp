#include<iostream>
#include <string>
#include <vector>
using namespace std;

vector<string>  res;

bool check(string str){
    int n = str.size();
    for(int i = 0 ; i < n/2 ; i++){
        if(str[i]!=str[n-i-1]) return false;
    }
    return true;
}

void backtrack(string str, string ans, int i){
    if(i == str.size()){
        if(ans.size()>0) {
            if(check(ans))
            res.push_back(ans);
        }
        return;
    }
    //Yes choice
    backtrack(str, ans + str[i], i+1);
    //No choice
    backtrack(str, ans, i+1);
}



int main(){
    string str = "aab";
    backtrack(str,"",0);
    for(auto &s : res) cout<<s<<endl;
    return 0;

}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> allStrings;

void backtrack(int index, int size, vector<int>& f, string curr){
    if(index == size){
        allStrings.push_back(curr);
        return;
    }
    for(int i = 0; i < 26; i++){
        if(f[i]>0){
            f[i]--;
            backtrack(index+1, size, f, curr + char(i+'a'));
            f[i]++;
        }
    }
}



int main(){
    string s; cin>>s;

    vector<int> f(26);

    for(auto &i:s ) f[i-'a']++;

    backtrack(0,s.size(), f, "");
    cout<<allStrings.size()<<endl;

    for(auto &i : allStrings) cout<<i<<endl;


    return 0;
}
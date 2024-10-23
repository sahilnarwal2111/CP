#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<numeric>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <ios>

// #define ll long long
#define int long long
using namespace std;
void solve(){
    string str;
    cin >> str;
    int k;
    cin >> k;
    vector<queue<int> > pos(10, queue<int> ());
    int ansSize = str.size() - k;
    string ans = "";
    for(int i = 0; i < str.size() ; i++){
        pos[str[i]- '0'].push(i);
    }

    int prev = -1;
    int lastContinue = -1;
    while(ans.size() < ansSize){
        int start = (prev == -1) ? 0 : prev + 1;
        int end = str.size() - (ansSize - ans.size()) ;
       
        int curIdx = -1;
        int minCharacter = 10;
        for(int i = 0; i < 10 ; i++){
            if(i == 0 && ans.size() == 0){
                continue;
            }
            if(!pos[i].empty() && pos[i].front() >= start && pos[i].front() <= end){
                int curChar = str[pos[i].front()] - '0';
                if(curChar <= minCharacter){
                    minCharacter = curChar;
                    curIdx = pos[i].front();
                }
            }
        }
        if(curIdx != -1){
            if(prev == -1) prev++;
            int diff = 0;
            if(prev == 0){
                diff = curIdx - prev;
            }else{
                diff = curIdx - prev - 1;
            }
            
            if(curIdx == 0) diff = 1;
            k = k - diff;
            
            if(curIdx != 0)
                ans += (str[curIdx]);
            if(k == 0){
                lastContinue = curIdx;
                break;
            }
        }else {
            lastContinue = curIdx;
            break;
        }
        //strike off the value in between [prev, curIdx]
        for(int i = 0; i < 10 ;i++){
            while(!pos[i].empty() && pos[i].front() <= curIdx){
                pos[i].pop();
            }
        }

        prev = curIdx;

    }
    if(lastContinue != -1){
        lastContinue++;
        for(int i = lastContinue; i < str.size() ; i++){
            ans += str[i];
        }
    }
    cout << ans << endl;
}    
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);    
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}
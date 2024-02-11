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

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
struct ComparePairs {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        // Sort in descending order based on the second element of the pair
        return a.second < b.second; // Note the "<" for descending order
    }
};
void solve() {
    int n; cin>>n;
    int arr[2*n];

    unordered_map<int,int> map;
    unordered_set<int> set;
    for(int i = 0 ; i < 2*n; i++) {
        cin>>arr[i];
        if(set.find(arr[i])!=set.end()){
            map[arr[i]] = i - map[arr[i]] -1;
        }
        else{
            set.insert(arr[i]);
            map[arr[i]] = i;
        }
    }
    // for(int i = 0 ; i < 2*n; i++){
    //     int cur = arr[i];
    //     if(map.find(cur)==map.end()){
    //         for(int j = i + 1; j < 2 *n ; j++){
    //             if(arr[j] == cur){
    //                 int dist = j - i - 1;
    //                 map[cur] = dist;
    //                 break;
    //             }
    //         }
    //     }
    // }
    priority_queue<pair<int, int>, vector<pair<int, int> >, ComparePairs> pq;
    for(auto itr = map.begin(); itr != map.end() ; itr++){
        int i = itr->first;
        int dist = itr->second;
        pq.push(make_pair(i,dist));
        // cout<<i<<" -> "<<dist<<endl;
    }
    // cout<<map.size()<<endl;
    // cout<<"sahil"<<endl;
    int ans[n];
    int i = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        ans[i++] = p.first;
        pq.pop();
    }
    for(int i = 0 ; i < n ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
}

void rec(vector<int> & nums, int i, vector<int> &cur){
    if(i == nums.size()){
        for(auto el : cur ) cout<<el<<" ";
         return;
    }
    cout<<endl;
    //take
    cur.push_back(nums[i]);
    rec(nums,i+1,cur);
    cur.pop_back();
    //not take
    rec(nums,i+1,cur);

}

int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
    int cnt = 0;
    int m = pattern.size();
    int n = nums.size();
    for(int i = 0 ; i + pattern.size() < nums.size(); i++){
        //now select a window of m + 1 elements
        // loop from i to i + m;
        int itr = 0; //it go till m
        bool flag = true;
        while(itr < m){
            //two el of nums i + itr & i + itr + 1
            if(pattern[itr] == 1){
                if(nums[itr + i] >= nums[itr + i + 1]){
                    flag = 0;
                    break;
                }
            }
            else if(pattern[itr] == 0){
                if(nums[itr + i] != nums[itr + i + 1]){
                    flag = 0;
                    break;
                }
            }
            else{
                if(nums[itr + i] <= nums[itr + i + 1]){
                    flag = 0;
                    break;
                }
            }
            itr++;
        }
        cnt+=flag;
    }   
    return cnt;     
}
int maxPalindromesAfterOperations(vector<string>& w) {
    int freq[26];
    memset(freq,0,sizeof(freq));
    int n = w.size();
    vector<int> nums;
    for(int i = 0; i < n ; i++){
        nums.push_back(w[i].size());
        string str = w[i];
        for(auto c : str){
            int idx = c - 'a';
            freq[idx]++;
        }
    }
    priority_queue<int> pq;
    for(int i = 0 ; i < 26 ; i++)
        pq.push(freq[i]);

    sort(nums.begin(),nums.end());
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        int req = nums[i];
        if(req <= pq.top()){
            int el = pq.top();
            pq.pop();
            el = el - req;
            pq.push(el);
            cnt++;
            nums[i] = -1; //means it is done

        }
        else{
            int req = nums[i];
            if(pq.top() & 1){
                int el = pq.top();
                req =- el -1;
                pq.push(1);
            }
            if(req > 0){
                if(pq.top() & 1){
                    int el = pq.top();
                    req =- el -1;
                    pq.push(1);
                }
            }else{
                cnt++;
                nums[i] = -1;
            }
        }
    }
    return cnt;

    
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    
    
    
    return 0;
}
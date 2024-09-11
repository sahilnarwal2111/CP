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
#define ll long long
using namespace std;

//making graph with all that
// we are having edges and weight
map<char, vector<pair<char, int>>> graph;
void createGraph(vector<char> &original, vector<char> & changed, vector<int> & cost){
    int n = original.size();
    for(int i = 0 ; i < n ; i++){
        char source = original[i];
        char dest = changed[i];
        graph[source].push_back({dest, cost[i]});
        // graph[dest].push_back({source, cost[i]});
    }
}

// final output
map<pair<char, char>, int> ans;
void dkAlgo(char source){
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int,int>>> pq;
    pq.push({0, source});
    ans[{source, source}] = 0;
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        char s = p.second;
        int cost = p.first;

        for(auto p : graph[s]){
            cout<<s<<" "<<cost<<endl;
            char dest = p.first;
            int costTo = p.second;
            int val = ans[{source,dest}];
            cout<<s<<" "<<dest<<"="<<val<<endl;
            if(val > costTo + cost){
                cout<<"Setting "<<s<<" "<<dest<<" = "<<cost + costTo<<endl;
                ans[{source,dest}] = costTo + cost;
                pq.push({costTo + cost , dest});
                cout<<"Pushing "<<dest<<" at cost "<<cost + costTo<<endl; 
            }
        }
    }
    
}


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<char> original , changed;
    vector<int> cost;
    /*
    original =
    ["a","b","c","c","e","d"]
    changed =
    ["b","c","b","e","b","e"]
    cost =
    [2,5,5,1,2,20]
     */
    original.push_back('a');
    original.push_back('b');
    original.push_back('c');
    original.push_back('c');
    original.push_back('e');
    original.push_back('d');
    changed.push_back('b');
    changed.push_back('c');
    changed.push_back('b');
    changed.push_back('e');
    changed.push_back('b');
    changed.push_back('e');
    cost.push_back(2);
    cost.push_back(5);
    cost.push_back(5);
    cost.push_back(1);
    cost.push_back(2);
    cost.push_back(20);

    createGraph(original, changed, cost);
    // map<char, vector<pair<char, int>>> graph;
    for(auto itr = graph.begin(); itr != graph.end(); itr++){
        cout<<"Source : "<<itr->first<<" ";
        auto v = itr->second;
        for(auto p : v){
            cout<<"{"<<p.first<<","<<p.second<<"}"<<" ";
        }
        cout<<endl;
    }

    //puting max
    for(int i = 0 ; i< original.size() ; i++){
        ans[{original[i], changed[i]}] = INT_MAX;
    }

    for(auto ch : original) dkAlgo(ch);
    // dkAlgo('c');

    // map<pair<char, char>, int> ans;

    for(auto itr = ans.begin(); itr != ans.end(); itr++){
        auto p = itr->first;
        cout<<"{"<<p.first<<","<<p.second<<"}"<<" "<<itr->second<<endl;
    }




    
    return 0;
}
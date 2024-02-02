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

class Node{
public: 
    bool isEndOfWord;
    Node * children[26];

    Node (){
        isEndOfWord = false;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = nullptr;
        }
    }
};

class Trie{
public :
    Node * root;

    Trie(){
        root = new Node();
    }

    void insert(string s){
        Node * cur = root;
        for(int i = 0 ; i < s.size(); i++){
            int idx = s[i] - 'a';
            if(cur->children[idx] == nullptr){
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->isEndOfWord = true;
    }

    bool search(string s){
        Node * cur = root;
        for(int i = 0 ; i < s.size(); i++){
            int idx = s[i] - 'a';
            if(cur->children[idx] == nullptr){
                return false;
            }
            cur = cur->children[idx];
        }
        return cur->isEndOfWord ;
    }
    int rec(Node * root){
        if(root == nullptr) return 0;
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            ans  += rec(root->children[i]);
        }
        return ans+1;
    }


};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Trie trie;
    string s = "ab";
    for(int i = 0 ; i < s.size(); i++){
        string str = s.substr(i);
        trie.insert(str);
        cout<<str<<endl;
    }
    cout << trie.rec(trie.root) << endl;
    // cout<<trie.count<<endl;
    return 0;
}
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
    bool isEOW ;
    Node * children[26];
    int freq;

    Node(){
        isEOW = false;
        for(int i = 0 ; i < 26 ; i++){
            children[i] = nullptr;
        }
        freq = 1;
    }

};

class Trie{
public:
    Node * root;
    Trie(){
        root = new Node();
    }
    void insert(string s){
        Node * cur = root;
        for(int i = 0 ;i < s.size(); i++){
            int idx = s[i] - 'a';
            if(cur->children[idx] == nullptr){
                cur->children[idx] = new Node();
            }
            else{
                cur->freq++;
            }
            cur = cur->children[idx];
        }
        cur->isEOW = true;
    }

    bool search(string s){
        Node * cur = root;
        for(int i = 0 ;i < s.size(); i++){
            int idx = s[i] - 'a';
            if(cur->children[idx] == nullptr){
                return false;
            }
            cur = cur->children[idx];
        }
        return cur->isEOW ;
    }

    void print(Node * root_ , char ch){
        if(root_ == nullptr){
            return;
        }
        cout<< ch << " - " << root_->freq << endl;
        for(int i = 0 ; i < 26; i++){
            if(root_->children[i] != nullptr){
                char ch = i + 'a';
                print(root_->children[i], ch);
            }
        }
    }
    void update(Node * root_){
        if(root_ == nullptr){
            return;
        }
        int cnt = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(root_->children[i] != nullptr){
                cnt++;
                update(root_->children[i]);
            }
        }
        root_->freq = cnt;
    }
    void prefix(Node * root, string str){
        if(root == nullptr){
            return;
        }
        if(root->freq != -1 && root->freq != 1){
            cout<<str<<endl;
            return;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(root->children[i] != nullptr){
                char ch = i + 'a';
                str+=ch;
                prefix(root->children[i], str);
                str.pop_back();
            }
        }
    }

};

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Trie trie;
    trie.insert("zebra");
    trie.insert("dog");
    trie.insert("duck");
    trie.insert("dove");
    trie.update(trie.root);
    trie.root->freq = -1;
    trie.prefix(trie.root, "");
    return 0;
}
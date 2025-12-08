#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq)
            return a->ch > b->ch;
        return a->freq > b->freq; 
    }
};

void dfs(Node* root, string code, vector<string>& res, map<char,int>& indexMap) {
    if (!root) return;
    if (!root->left && !root->right) {
        res[indexMap[root->ch]] = code;
    }
    dfs(root->left, code + "0", res, indexMap);
    dfs(root->right, code + "1", res, indexMap);
}

class Solution {
public:
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        map<char,int> indexMap;
        for(int i=0;i<N;i++) indexMap[S[i]] = i;
        vector<string> res(N);
        
        priority_queue<Node*, vector<Node*>, compare> pq;
        for(int i=0;i<N;i++)
            pq.push(new Node(S[i], f[i]));
        
        while(pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();
            
            Node* parent = new Node(min(left->ch, right->ch), left->freq + right->freq);
            parent->left = left;
            parent->right = right;
            
            pq.push(parent);
        }
        
        Node* root = pq.top();
        dfs(root, "", res, indexMap);
        
        return res;
    }
};

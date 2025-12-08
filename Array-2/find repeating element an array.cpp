#include<bits/stdc++.h>
using namespace std;

void findRepeatingElements(vector<int>& arr) {
    unordered_map<int,int> elementCount;
    for(auto i:arr) ++elementCount[i];
    
    cout<<"The repeating elements are: ";
    for(auto i:elementCount) {
        if(i.second > 1) cout<<i.first<<" ";
    }
}

int main() {
    vector<int> arr = {1,1,2,3,4,4,5,2};
    findRepeatingElements(arr);
    
    return 0;
}
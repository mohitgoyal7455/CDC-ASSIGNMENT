#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char getMaxOccurringChar(string s) {
        map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        int maxFreq = 0;
        char maxChar = '\0';

        for (auto it : freq) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                maxChar = it.first;
            }
        }

        return maxChar;
    }
};

int main() {
    string s = "samplestring";

    Solution obj;

    char ans = obj.getMaxOccurringChar(s);
    cout << "Max occurring character: " << ans << endl;
    return 0;
}
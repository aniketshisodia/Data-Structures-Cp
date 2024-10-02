// jai shree ram
#include <bits/stdc++.h>
using namespace std;
 
void f(string p, vector<int>& lps) {
    int i = 1, j = 0;
    int n = p.size();
    lps[0] = 0;  // Initialize first value of lps as 0
    while (i < n) {
        if (p[i] == p[j]) {
            lps[i] = j + 1;
            i++;
            j++;
        } else {
            if (j == 0) {
                lps[i] = 0;  // Important to set lps[i] to 0 when there's no match
                i++;
            } else {
                j = lps[j - 1];
            }
        }
    }
}
 
int search(string txt, string pat, vector<int>& lps) {
    int i = 0, j = 0;
    int pos = 0;
    while (i < txt.size()) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }
        if (j == pat.size()) {  // When we find a match
            pos++;
            j = lps[j - 1];  // Reset j to check for further matches
        } else if (i < txt.size() && txt[i] != pat[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;  // Increment i when no match and j is at the start
            }
        }
    }
    return pos;
}
 
int main() {
    string s, p;
    cin >> s >> p;
    vector<int> lps(p.size(), 0);  // Initialize the lps array with 0
    f(p, lps);
    cout << search(s, p, lps);
    return 0;
}
Sha

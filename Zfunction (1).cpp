// jai shree ram
#include <bits/stdc++.h>
using namespace std;

int  Z_function(string s , string p ) {
  string txt = (p + "#" + s);
  int n = txt.size();
  vector<int> Z(n , 0);  
  int left = 0 , right = 0;
  for(int i = 1 ; i < n ; ++i) {
    if(i > right) {
      left = right = i;
      while(right < n && txt[right] == txt[right - left]) {
        right++;
      }
      Z[i] = right - left;
      right--;
    }
    else {
      // if we are in a box 
      int k = i - left;
      if(Z[k] + i <= right) {
        Z[i] = Z[k];
      }
      else {
        left = i;
        while(right < n && txt[right] == txt[right-left]) {
          right++;
        }
        Z[i] = right - left;
        right--;
      }
    }
  }
  int pos = 0;
  for(auto i : Z) {
    if(i == p.size()) 
    pos++;
  }
  return pos;
}

void solve() {
  string s;
  cin>>s;
  string p;
  cin>>p;
  cout<<Z_function(s,p)<<"\n";
}

int main() 
{
  
  solve();
  return 0;
}

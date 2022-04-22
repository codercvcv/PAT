#include <bits/stdc++.h>
using namespace std;

int main() {
  int map[128] = {0}, c;
  vector<int> count(128, 0);
  string str;
  getline(cin, str);
  for (int i = 0; i < str.size(); ++i) count[str[i]]++;
  while (count['P'] > 0 || count['A'] > 0 || count['T'] > 0 || count['e'] > 0 ||
         count['s'] > 0 || count['t'] > 0) {
    if (count['P']-- > 0) cout << 'P';
    if (count['A']-- > 0) cout << 'A';
    if (count['T']-- > 0) cout << 'T';
    if (count['e']-- > 0) cout << 'e';
    if (count['s']-- > 0) cout << 's';
    if (count['t']-- > 0) cout << 't';
  }

  return 0;
}
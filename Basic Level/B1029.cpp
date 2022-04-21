#include <bits/stdc++.h>
using namespace std;

int main() {
  string str1, str2;
  unordered_map<char, bool> mp;
  cin >> str1 >> str2;
  transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
  transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
  for (int i = 0; i < str2.size(); ++i) {
    mp[str2[i]] = true;
  }

  for (int i = 0; i < str1.size(); ++i) {
    if (mp.find(str1[i]) == mp.end()) {
      cout << str1[i];
      mp[str1[i]] = true;
    }
  }

  return 0;
}
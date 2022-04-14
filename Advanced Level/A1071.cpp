#include <bits/stdc++.h>

using namespace std;

bool check(char c) {
  if (c >= '0' && c <= '9') return true;
  if (c >= 'A' && c <= 'Z') return true;
  if (c >= 'a' && c <= 'z') return true;
  return false;
}

int main() {
  unordered_map<string, int> mp;
  string str;
  getline(cin, str);
  for (int i = 0; i < str.size(); ++i) {
    string word;
    while (check(str[i])) {
      if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
      word.push_back(str[i++]);
    }
    if (word.empty() == false) {
      if (mp.find(word) != mp.end()) {
        mp[word]++;
      } else {
        mp.insert({word, 1});
      }
    }
  }

  string res;
  int count = -1;
  for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
    if (iter->second > count) {
      count = iter->second;
      res = iter->first;
    }
  }

  cout << res << " " << count;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> count(256, 0);
  int max_time = 0;
  string str;
  getline(cin, str);
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      count[str[i]]++;
      max_time = max(max_time, count[str[i]]);
    }
  }

  for (int i = 0; i < count.size(); ++i) {
    if (count[i] == max_time) {
      printf("%c %d", i, count[i]);
      break;
    }
  }

  return 0;
}
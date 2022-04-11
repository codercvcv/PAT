#include <bits/stdc++.h>

using namespace std;

int main() {
  int count[10] = {0};
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); ++i) {
    count[str[i] - '0']++;
  }

  for (int i = 0; i < 10; ++i) {
    if (count[i]) {
      cout << i << ":" << count[i] << endl;
    }
  }

  return 0;
}
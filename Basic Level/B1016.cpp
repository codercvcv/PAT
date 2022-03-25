#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s1, s2;
  char c1, c2;
  int i1 = 0, i2 = 0;
  cin >> s1 >> c1 >> s2 >> c2;
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] == c1) {
      i1 = i1 * 10 + c1 - '0';
    }
  }

  for (int i = 0; i < s2.size(); ++i) {
    if (s2[i] == c2) {
      i2 = i2 * 10 + c2 - '0';
    }
  }

  cout << i1 + i2;
  return 0;
}
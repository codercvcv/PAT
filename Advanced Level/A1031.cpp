#include <bits/stdc++.h>

using namespace std;

int main() {
  string str;
  cin >> str;
  int col = 0;
  const int len = str.size();
  int n1 = (len + 2) / 3, n3 = n1, n2 = len + 2 - n1 - n3;

  for (int i = 0; i < n1 - 1; ++i) {
    printf("%c", str[i]);
    for (int j = 0; j < n2 - 1; ++j)
      printf(" ");
    printf("%c\n", str[len - i - 1]);
  }

  for (int i = 0; i < n2; ++i) {
    printf("%c", str[n1 + i - 1]);
  }

  return 0;
}
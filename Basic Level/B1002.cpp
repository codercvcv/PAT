#include <bits/stdc++.h>

using namespace std;

const char change[10][10] = {"ling", "yi",  "er", "san", "si",
                             "wu",   "liu", "qi", "ba",  "jiu"};

int main() {
  string str;
  cin >> str;
  int sum = 0;
  for (int i = 0; i < str.size(); ++i) {
    sum += str[i] - '0';
  }

  int num = 0, ans[10] = {0};
  while (sum != 0) {
    ans[num++] = sum % 10;
    sum /= 10;
  }

  for (int i = num - 1; i >= 0; --i) {
    printf("%s", change[ans[i]]);
    i == 0 ? printf("\n") : printf(" ");
  }

  return 0;
}
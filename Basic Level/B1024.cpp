#include <bits/stdc++.h>

using namespace std;

int main() {
  string str;
  cin >> str;
  if (str[0] == '-') printf("-");
  int pos = 0;
  for (int i = 1; i < str.size(); ++i) {
    if (str[i] == 'E') pos = i;
  }

  int exp = fabs(atoi(string(str.begin() + pos + 1, str.end()).c_str()));
  if (str[pos + 1] == '-') {
    printf("0.");
    for (int i = 1; i < exp; ++i) printf("0");
    for (int i = 1; i < pos; ++i) {
      if (str[i] != '.') printf("%c", str[i]);
    }
  } else {
    printf("%c", str[1]);
    int count = 0;
    for (int i = 3; i < pos; ++i) {
      printf("%c", str[i]);
      count++;
      if (count == exp && i != pos - 1) printf(".");
    }
    while (count++ < exp) printf("0");
  }

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  const char map[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  char str[4][70];
  cin >> str[0] >> str[1] >> str[2] >> str[3];

  int count = 1;
  for (int i = 0; i < strlen(str[0]); i++) {
    if (str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G' &&
        count == 1) {
      printf("%s ", map[str[0][i] - 'A']);
      count++;
      continue;
    }
    if (str[0][i] == str[1][i] && str[0][i] >= '0' && str[0][i] <= '9' &&
        count == 2) {
      printf("%02d:", str[0][i] - '0');
      break;
    }
    if (str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'N' &&
        count == 2) {
      printf("%d:", str[0][i] - 'A' + 10);
      break;
    }
  }

  for (int i = 0; i < strlen(str[2]); i++) {
    if (str[2][i] == str[3][i] && (str[2][i] >= 'a' && str[2][i] <= 'z') ||
        (str[2][i] >= 'A' && str[2][i] <= 'Z')) {
      printf("%02d", i);
      break;
    }
  }

  return 0;
}
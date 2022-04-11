#include <bits/stdc++.h>

using namespace std;

const int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const char radix[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int check(const char check[]) {
  int ans = 0;
  for (int i = 0; i < 17; i++) {
    if (check[i] >= '0' && check[i] <= '9') {
      ans += (check[i] - '0') * weight[i];
    } else
      return -1;
  }

  return ans;
}

int main() {
  int N;
  char card[110][20];
  cin >> N;
  int count = 0, ans = 0;
  while (N--) scanf("%s", card[count++]);

  for (int i = 0; i < count; i++) {
    int valid = check(card[i]);
    if (valid < 0 || radix[valid % 11] != card[i][17]) {
      printf("%s\n", card[i]);
    } else
      ans++;
  }

  if (ans == count) printf("All passed\n");

  return 0;
}
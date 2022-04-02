#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
int ans[maxn] = {0};

int main() {
  int number, base;
  cin >> number >> base;
  int count = 0;
  do {
    ans[count++] = number % base;
    number /= base;
  } while (number);

  int left = 0, right = count - 1;
  bool flag = true;
  while (left < right) {
    if (ans[left++] != ans[right--]) {
      flag = false;
      break;
    }
  }

  flag == true ? printf("Yes\n") : printf("No\n");
  for (int i = count - 1; i >= 0; i--) {
    printf("%d", ans[i]);
    if (i > 0)
      printf(" ");
  }
  return 0;
}
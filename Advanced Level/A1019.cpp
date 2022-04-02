#include <bits/stdc++.h>

using namespace std;

bool Judge(vector<int> number) {
  int left = 0, right = number.size() - 1;
  while (left < right) {
    if (number[left++] != number[right--]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, b;
  cin >> n >> b;
  vector<int> number;
  do {
    number.push_back(n % b);
    n /= b;
  } while (n);

  bool flag = Judge(number);
  flag == true ? printf("Yes\n") : printf("No\n");

  for (int i = number.size() - 1; i >= 0; --i) {
    printf("%d", number[i]);
    if (i > 0) {
      printf(" ");
    }
  }
  return 0;
}
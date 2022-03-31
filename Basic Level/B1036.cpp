#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  char c;
  cin >> n >> c;
  int row = n, col;
  (row & 1) ? col = row / 2 + 1 : col = row / 2;
  for (int i = 0; i < row; ++i) printf("%c", c);
  printf("\n");

  for (int i = 2; i < col; ++i) {
    printf("%c", c);
    for (int j = 0; j < row - 2; j++) printf(" ");
    printf("%c\n", c);
  }
  
  for (int i = 0; i < row; ++i) printf("%c", c);

  return 0;
}
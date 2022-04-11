#include <bits/stdc++.h>

using namespace std;

int main() {
  int A[3], B[3], sum[3];
  scanf("%d.%d.%d %d.%d.%d", &A[0], &A[1], &A[2], &B[0], &B[1], &B[2]);
  int carry = 0;  // 进位
  sum[2] = (A[2] + B[2]) % 29;
  carry = (A[2] + B[2]) / 29;
  sum[1] = (A[1] + B[1] + carry) % 17;
  carry = (A[1] + B[1] + carry) / 17;
  sum[0] = A[0] + B[0] + carry;
  printf("%d.%d.%d", sum[0], sum[1], sum[2]);
  return 0;
}
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N, ans = 0;
  cin >> N;
  while (N != 1) {
    if (N & 1) {
      N = (N * 3 + 1) / 2;
    } else {
      N /= 2;
    }
    ++ans;
  }

  cout << ans;
  return 0;
}
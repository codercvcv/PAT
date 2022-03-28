#include <bits/stdc++.h>

using namespace std;

void shuffling(int cards[], int order[]) {
  int result[55] = {0};
  for (int i = 1; i <= 54; ++i) {
    result[order[i]] = cards[i];
  }
  for (int i = 1; i <= 54; ++i) {
    cards[i] = result[i];
  }
}

int main() {
  char mp[5] = {'S', 'H', 'C', 'D', 'J'};
  int n, cards[55], order[55];
  cin >> n;
  for (int i = 1; i <= 54; ++i) {
    cin >> order[i];
    cards[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    shuffling(cards, order);
  }
  for (int i = 1; i <= 54; ++i) {
    cards[i]--;
    printf("%c%d", mp[cards[i] / 13], cards[i] % 13 + 1);
    if (i < 54) printf(" ");
  }

  return 0;
}
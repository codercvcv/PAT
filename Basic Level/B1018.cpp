#include <bits/stdc++.h>

using namespace std;

int toInt(char c) {
  if (c == 'B') return 0;
  if (c == 'C') return 1;
  if (c == 'J') return 2;
}

int main() {
  int n;
  char a, b;
  cin >> n;
  char mp[3] = {'B', 'C', 'J'};
  int timesa[3] = {0}, timesb[3] = {0};
  int wina[3] = {0}, winb[3] = {0};
  while (n--) {
    cin >> a >> b;
    int k1 = toInt(a);
    int k2 = toInt(b);
    if ((k1 + 1) % 3 == k2) {
      timesa[0]++;
      timesb[2]++;
      wina[k1]++;
    }
    if ((k2 + 1) % 3 == k1) {
      timesa[2]++;
      timesb[0]++;
      winb[k2]++;
    }
    if (k1 == k2) {
      timesa[1]++;
      timesb[1]++;
    }
  }

  int id_a = 0, id_b = 0;
  for (int i = 0; i < 3; ++i) {
    if (wina[i] > wina[id_a]) id_a = i;
    if (winb[i] > winb[id_b]) id_b = i;
  }

  printf("%d %d %d\n", timesa[0], timesa[1], timesa[2]);
  printf("%d %d %d\n", timesb[0], timesb[1], timesb[2]);
  printf("%c %c", mp[id_a], mp[id_b]);
  return 0;
}
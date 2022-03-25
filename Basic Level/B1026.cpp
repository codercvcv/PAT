#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int c1, c2;
  cin >> c1 >> c2;
  int time = round((c2 - c1) / 100.0);
  printf("%02d:%02d:%02d", time / 3600, (time / 60) % 60, time % 60);

  return 0;
}
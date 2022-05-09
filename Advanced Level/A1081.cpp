#include <bits/stdc++.h>
using namespace std;

struct Fraction {
  int up;
  int down;
};

void reduction(Fraction& fraction) {
  if (fraction.down < 0) {
    fraction.down = -fraction.down;
    fraction.up = -fraction.up;
  }

  if (fraction.up == 0) {
    fraction.down = 1;
  } else {
    int temp = __gcd(abs(fraction.up), abs(fraction.down));
    fraction.up /= temp;
    fraction.down /= temp;
  }
}

void add(Fraction& data, const Fraction& value) {
  data.up = data.up * value.down + value.up * data.down;
  data.down *= value.down;
  reduction(data);
}

int main() {
  int n;
  cin >> n;
  Fraction ans;
  Fraction temp;
  ans.up = 0;
  ans.down = 1;
  while (n--) {
    scanf("%d/%d", &temp.up, &temp.down);
    reduction(temp);
    add(ans, temp);
  }

  if (ans.up == 0) cout << 0;
  if (ans.up >= ans.down) {
    cout << ans.up / ans.down;
    if (ans.up % ans.down != 0) cout << " ";
  }
  ans.up %= ans.down;
  if (ans.up != 0) {
    cout << ans.up << "/" << ans.down;
  }

  return 0;
}
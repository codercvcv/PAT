#include <bits/stdc++.h>
using namespace std;

long long to_knut(int knut, int sickle, int gallon) {
  return knut + sickle * 29 + gallon * 17 * 29;
}

int main() {
  int knut, sickle, gallon;
  int base_knut, base_sickle, base_gallon;
  scanf("%d.%d.%d %d.%d.%d", &base_gallon, &base_sickle, &base_knut, &gallon,
        &sickle, &knut);
  long long price = to_knut(base_knut, base_sickle, base_gallon);
  long long pay = to_knut(knut, sickle, gallon);
  long long remainder = pay - price;
  if (remainder < 0) {
    printf("-");
  }
  remainder = fabs(remainder);
  printf("%lld.%lld.%lld", remainder / 29 / 17, remainder / 29 % 17,
         remainder % 29);

  return 0;
}
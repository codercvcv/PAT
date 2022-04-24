#include <bits/stdc++.h>
using namespace std;

struct GasStation {
  double price_;
  double distance_;
};

int main() {
  int n;
  double c_max, distance, d_average;
  cin >> c_max >> distance >> d_average >> n;
  vector<GasStation> station(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> station[i].price_ >> station[i].distance_;
  }
  station[n].price_ = 0.0;
  station[n].distance_ = distance;
  sort(station.begin(), station.end(),
       [](const GasStation& sta1, const GasStation& sta2) {
         return sta1.distance_ < sta2.distance_;
       });
  if (station[0].distance_ != 0) {
    printf("The maximum travel distance = 0.00");
  } else {
    int now = 0;
    double ans = 0, now_tank = 0, MAX = c_max * d_average;
    while (now < n) {
      int k = -1;
      double min_price = INT_MAX;
      for (int i = now + 1;
           i <= n && station[i].distance_ - station[now].distance_ <= MAX;
           ++i) {
        if (station[i].price_ < min_price) {
          min_price = station[i].price_;
          k = i;
          if (min_price < station[now].price_) break;
        }
      }
      if (k == -1) break;
      double need = (station[k].distance_ - station[now].distance_) / d_average;
      if (min_price < station[now].price_) {
        if (now_tank < need) {
          ans += (need - now_tank) * station[now].price_;
          now_tank = 0;
        } else {
          now_tank -= need;
        }
      } else {
        ans += (c_max - now_tank) * station[now].price_;
        now_tank = c_max - need;
      }
      now = k;
    }
    if (now == n)
      printf("%.2f\n", ans);
    else
      printf("The maximum travel distance = %.2f\n",
             station[now].distance_ + MAX);
  }
}
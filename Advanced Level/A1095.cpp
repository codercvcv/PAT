#include <bits/stdc++.h>
using namespace std;

struct Car {
  string plate_;
  int status_;
  int time_;
};

bool cmp(const Car& car1, const Car& car2) {
  return car1.plate_ != car2.plate_ ? car1.plate_ < car2.plate_
                                    : car1.time_ < car2.time_;
}

bool cmp_time(const Car& car1, const Car& car2) {
  return car1.time_ < car2.time_;
}

int main() {
  int n, m;
  int hour, minute, second;
  int max_time = -1;
  cin >> n >> m;
  vector<Car> car(n);
  vector<Car> valid_record;
  map<string, int> parking_record;
  for (int i = 0; i < n; ++i) {
    string status;
    cin >> car[i].plate_;
    scanf("%d:%d:%d", &hour, &minute, &second);
    car[i].time_ = hour * 3600 + minute * 60 + second;
    cin >> status;
    if (status == "in")
      car[i].status_ = 0;
    else
      car[i].status_ = 1;
  }

  sort(car.begin(), car.end(), cmp);
  for (int i = 0; i < n - 1; ++i) {
    if (car[i].plate_ == car[i + 1].plate_ && car[i].status_ == 0 &&
        car[i + 1].status_ == 1) {
      valid_record.push_back(car[i]);
      valid_record.push_back(car[i + 1]);
      if (parking_record.find(car[i].plate_) != parking_record.end()) {
        parking_record[car[i].plate_] += car[i + 1].time_ - car[i].time_;
      } else {
        parking_record.insert({car[i].plate_, car[i + 1].time_ - car[i].time_});
      }
      max_time = max(max_time, parking_record[car[i].plate_]);
    }
  }

  sort(valid_record.begin(), valid_record.end(), cmp_time);
  for (int i = 0; i < m; ++i) {
    scanf("%d:%d:%d", &hour, &minute, &second);
    int time = hour * 3600 + minute * 60 + second;
    int count = 0;
    for (int j = 0; j < valid_record.size(); ++j) {
      if (valid_record[j].time_ > time) break;
      if (valid_record[j].time_ <= time && valid_record[j].status_ == 0)
        count++;
      else if (valid_record[j].time_ <= time && valid_record[j].status_ == 1)
        count--;
    }
    printf("%d\n", count);
  }

  for (auto iter : parking_record) {
    if (iter.second == max_time) {
      printf("%s ", iter.first.c_str());
    }
  }

  printf("%02d:%02d:%02d", max_time / 3600, max_time % 3600 / 60,
         max_time % 60);

  return 0;
}
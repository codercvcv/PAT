#include <bits/stdc++.h>
using namespace std;

struct Record {
  string name_;
  int month_;
  int day_;
  int hour_;
  int minute_;
  int time_;
  int state_;
};

bool cmp(const Record& r1, const Record& r2) {
  return r1.name_ != r2.name_ ? r1.name_ < r2.name_ : r1.time_ < r2.time_;
}

double CalculateBill(const Record& r1, const Record& r2,
                     const vector<int>& rate) {
  Record temp = r1;
  double money = 0.0;
  while (temp.day_ < r2.day_ || temp.hour_ < r2.hour_ ||
         temp.minute_ < r2.minute_) {
    money += rate[temp.hour_];
    temp.minute_++;
    if (temp.minute_ >= 60) {
      temp.minute_ = 0;
      temp.hour_++;
    }
    if (temp.hour_ >= 24) {
      temp.hour_ = 0;
      temp.day_++;
    }
  }

  return money / 100;
}

int main() {
  vector<int> rate(24);
  for (int i = 0; i < 24; ++i) {
    scanf("%d", &rate[i]);
  }

  int n;
  cin >> n;
  vector<Record> record(n);
  map<string, vector<Record>> custom;
  for (int i = 0; i < n; ++i) {
    string state;
    cin >> record[i].name_;
    scanf("%d:%d:%d:%d", &record[i].month_, &record[i].day_, &record[i].hour_,
          &record[i].minute_);
    record[i].time_ =
        record[i].day_ * 24 * 60 + record[i].hour_ * 60 + record[i].minute_;
    cin >> state;
    record[i].state_ = (state == "on-line") ? 1 : 0;
  }
  sort(record.begin(), record.end(), cmp);
  for (int i = 1; i < n; ++i) {
    if (record[i].name_ == record[i - 1].name_ && record[i].state_ == 0 &&
        record[i - 1].state_ == 1) {
      custom[record[i - 1].name_].push_back(record[i - 1]);
      custom[record[i].name_].push_back(record[i]);
    }
  }

  for (auto iter : custom) {
    vector<Record> temp = iter.second;
    double total = 0.0;
    int time = 0;
    printf("%s %02d\n", iter.first.c_str(), temp[0].month_);
    for (int i = 0; i < temp.size(); i += 2) {
      double money = CalculateBill(temp[i], temp[i + 1], rate);
      printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i].day_,
             temp[i].hour_, temp[i].minute_, temp[i + 1].day_,
             temp[i + 1].hour_, temp[i + 1].minute_,
             temp[i + 1].time_ - temp[i].time_, money);
      total += money;
    }
    printf("Total amount: $%.2f\n", total);
  }

  return 0;
}
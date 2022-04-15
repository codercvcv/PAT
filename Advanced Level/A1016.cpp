#include <bits/stdc++.h>

using namespace std;

struct Record {
  string name_;
  int state_;
  int month_;
  int day_;
  int hour_;
  int minute_;
};

bool cmp(const Record& r1, const Record& r2) {
  if (r1.name_ != r2.name_)
    return r1.name_ < r2.name_;
  else if (r1.day_ != r2.day_)
    return r1.day_ < r2.day_;
  else if (r1.hour_ != r2.hour_)
    return r1.hour_ < r2.hour_;
  else
    return r1.minute_ < r2.minute_;
}

double CalculateBill(Record r1, const Record& r2, const vector<int>& rate,
                     int& minutes) {
  double money = 0.0;
  while (r1.day_ < r2.day_ || r1.hour_ < r2.hour_ || r1.minute_ < r2.minute_) {
    money += rate[r1.hour_];
    minutes++;
    r1.minute_++;
    if (r1.minute_ >= 60) {
      r1.minute_ = 0;
      r1.hour_++;
    }
    if (r1.hour_ >= 24) {
      r1.hour_ = 0;
      r1.day_++;
    }
  }

  return money / 100;
}

int main() {
  int n;
  vector<int> rate(24);
  vector<Record> record;
  vector<Record> valid_record;
  for (int i = 0; i < 24; ++i) {
    scanf("%d", &rate[i]);
  }
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    Record temp;
    char state[10];
    char name[20];
    scanf("%s %d:%d:%d:%d %s", name, &temp.month_, &temp.day_, &temp.hour_,
          &temp.minute_, state);
    temp.name_ = name;
    if (strcmp(state, "on-line") == 0)
      temp.state_ = 0;
    else
      temp.state_ = 1;
    record.push_back(temp);
  }

  sort(record.begin(), record.end(), cmp);
  int i = 0;
  while (i < record.size()) {
    if (i + 1 < record.size()) {
      if (record[i].state_ == 0 && record[i + 1].state_ == 1) {
        valid_record.push_back(record[i]);
        valid_record.push_back(record[i + 1]);
        i += 2;
        continue;
      }
    }
    i += 1;
  }

  string name;
  double total = 0.0;
  i = 0;
  while (i < valid_record.size()) {
    if (name.empty() || name != valid_record[i].name_) {
      printf("%s %02d\n", valid_record[i].name_.c_str(),
             valid_record[i].month_);
      name = valid_record[i].name_;
      total = 0.f;
    }
    int minutes = 0;
    double money =
        CalculateBill(valid_record[i], valid_record[i + 1], rate, minutes);
    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", valid_record[i].day_,
           valid_record[i].hour_, valid_record[i].minute_,
           valid_record[i + 1].day_, valid_record[i + 1].hour_,
           valid_record[i + 1].minute_, minutes, money);
    total += money;
    if (i + 2 == valid_record.size() ||
        valid_record[i].name_ != valid_record[i + 2].name_) {
      printf("Total amount: $%.2f\n", total);
    }
    i += 2;
  }

  return 0;
}

/*
Test case:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line
*/
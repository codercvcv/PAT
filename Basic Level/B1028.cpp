#include <bits/stdc++.h>

using namespace std;

struct Person {
  char name_[20];
  int yy_;
  int mm_;
  int dd_;
} temp, oldest, youngest, upper, lower;

void Init() {
  lower.yy_ = oldest.yy_ = 2014;
  upper.yy_ = youngest.yy_ = 1814;
  oldest.mm_ = youngest.mm_ = upper.mm_ = lower.mm_ = 9;
  oldest.dd_ = youngest.dd_ = upper.dd_ = lower.dd_ = 6;
}

bool Less(const Person& p1, const Person& p2) {
  if (p1.yy_ != p2.yy_) return p1.yy_ > p2.yy_;
  if (p1.mm_ != p2.mm_) return p1.mm_ > p2.mm_;
  if (p1.dd_ != p2.dd_) return p1.dd_ > p2.dd_;
}

bool More(const Person& p1, const Person& p2) {
  if (p1.yy_ != p2.yy_) return p1.yy_ < p2.yy_;
  if (p1.mm_ != p2.mm_) return p1.mm_ < p2.mm_;
  if (p1.dd_ != p2.dd_) return p1.dd_ < p2.dd_;
}

int main() {
  int n;
  cin >> n;
  Init();
  int count = 0;
  while (n--) {
    scanf("%s %d/%d/%d", temp.name_, &temp.yy_, &temp.mm_, &temp.dd_);
    if (Less(temp, upper) && More(temp, lower)) {
      count++;
      if (Less(temp, youngest)) youngest = temp;
      if (More(temp, oldest)) oldest = temp;
    }
  }

  count == 0 ? printf("0")
             : printf("%d %s %s", count, oldest.name_, youngest.name_);

  return 0;
}
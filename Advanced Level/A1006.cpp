#include <bits/stdc++.h>

using namespace std;

struct Person {
  char name_[20];
  int in_hh_;
  int in_mm_;
  int in_ss_;
  int out_hh_;
  int out_mm_;
  int out_ss_;
} temp, first, last;

bool Early(const Person& p1, const Person& p2) {
  if (p1.in_hh_ != p2.in_hh_) return p1.in_hh_ < p2.in_hh_;
  if (p1.in_mm_ != p2.in_mm_) return p1.in_mm_ < p2.in_mm_;
  return p1.in_ss_ < p2.in_ss_;
}

bool Later(const Person& p1, const Person& p2) {
  if (p1.out_hh_ != p2.out_hh_) return p1.out_hh_ > p2.out_hh_;
  if (p1.out_mm_ != p2.out_mm_) return p1.out_mm_ > p2.out_mm_;
  return p1.out_ss_ > p2.out_ss_;
}

void Init() {
  first.in_hh_ = 24;
  first.in_mm_ = first.in_ss_ = 60;
  last.in_hh_ = last.in_mm_ = last.in_ss_ = 0;
}

int main() {
  int n;
  cin >> n;
  Init();
  while (n--) {
    scanf("%s %d:%d:%d %d:%d:%d", temp.name_, &temp.in_hh_, &temp.in_mm_,
          &temp.in_ss_, &temp.out_hh_, &temp.out_mm_, &temp.out_ss_);
    if (Early(temp, first)) first = temp;
    if (Later(temp, last)) last = temp;
  }

  printf("%s %s", first.name_, last.name_);
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct Student {
  string id_;
  int virtue_;
  int talent_;
  int level_;
  int sum_;
};

bool cmp(const Student& stu1, const Student& stu2) {
  if (stu1.level_ != stu2.level_)
    return stu1.level_ < stu2.level_;
  else if (stu1.sum_ != stu2.sum_)
    return stu1.sum_ > stu2.sum_;
  else if (stu1.virtue_ != stu2.virtue_)
    return stu1.virtue_ > stu2.virtue_;
  else
    return stu1.id_ < stu2.id_;
}

int main() {
  int n, low, high;
  cin >> n >> low >> high;
  vector<Student> student;
  for (int i = 0; i < n; ++i) {
    Student temp;
    cin >> temp.id_ >> temp.virtue_ >> temp.talent_;
    temp.sum_ = temp.virtue_ + temp.talent_;
    if (temp.talent_ >= low && temp.virtue_ >= low) {
      if (temp.virtue_ >= high && temp.talent_ >= high) {
        temp.level_ = 1;
      } else if (temp.virtue_ >= high) {
        temp.level_ = 2;
      } else if (temp.virtue_ >= temp.talent_) {
        temp.level_ = 3;
      } else {
        temp.level_ = 4;
      }
    } else {
      temp.level_ = 0;
    }
    if (temp.level_ != 0) student.push_back(temp);
  }

  sort(student.begin(), student.end(), cmp);
  cout << student.size() << endl;
  for (int i = 0; i < student.size(); ++i) {
    cout << student[i].id_ << " " << student[i].virtue_ << " "
         << student[i].talent_ << endl;
  }

  return 0;
}
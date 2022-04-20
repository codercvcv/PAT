#include <bits/stdc++.h>
using namespace std;

struct Student {
  string name_;
  string id_;
  int grade_;
};

bool cmp(const Student& stu1, const Student& stu2) {
  if (stu1.grade_ != stu2.grade_) return stu1.grade_ > stu2.grade_;
  return stu1.name_ < stu2.name_;
}

int main() {
  int n, low, top;
  bool flag = false;
  cin >> n;
  vector<Student> student(n);
  for (int i = 0; i < n; ++i) {
    cin >> student[i].name_ >> student[i].id_ >> student[i].grade_;
  }
  cin >> low >> top;
  sort(student.begin(), student.end(), cmp);

  for (int i = 0; i < n; ++i) {
    if (student[i].grade_ >= low && student[i].grade_ <= top) {
      cout << student[i].name_ << " " << student[i].id_ << endl;
      flag = true;
    }
  }

  if (flag == false) cout << "NONE" << endl;

  return 0;
}
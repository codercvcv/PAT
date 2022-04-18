#include <bits/stdc++.h>
using namespace std;

struct Student {
  string id_;
  string name_;
  int grade_;
};

bool cmp_id(const Student& stu1, const Student& stu2) {
  return stu1.id_ < stu2.id_;
}

bool cmp_name(const Student& stu1, const Student& stu2) {
  return stu1.name_ != stu2.name_ ? stu1.name_ < stu2.name_
                                  : stu1.id_ < stu2.id_;
}

bool cmp_grade(const Student& stu1, const Student& stu2) {
  return stu1.grade_ != stu2.grade_ ? stu1.grade_ < stu2.grade_
                                    : stu1.id_ < stu2.id_;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<Student> student(n);
  for (int i = 0; i < n; ++i) {
    cin >> student[i].id_ >> student[i].name_ >> student[i].grade_;
  }

  if (m == 1)
    sort(student.begin(), student.end(), cmp_id);
  else if (m == 2)
    sort(student.begin(), student.end(), cmp_name);
  else
    sort(student.begin(), student.end(), cmp_grade);

  for (int i = 0; i < n; ++i) {
    cout << student[i].id_ << " " << student[i].name_ << " "
         << student[i].grade_ << endl;
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Person {
  string name_;
  int age_;
  int worth_;
};

bool cmp(const Person& p1, const Person& p2) {
  if (p1.worth_ != p2.worth_)
    return p1.worth_ > p2.worth_;
  else if (p1.age_ != p2.age_)
    return p1.age_ < p2.age_;
  else
    return p1.name_ < p2.name_;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<Person> person(n);
  for (int i = 0; i < n; ++i) {
    cin >> person[i].name_ >> person[i].age_ >> person[i].worth_;
  }
  sort(person.begin(), person.end(), cmp);

  int count, low, top;
  for (int i = 0; i < m; ++i) {
    printf("Case #%d:\n", i + 1);
    bool flag = false;
    cin >> count >> low >> top;
    for (int j = 0; j < n; ++j) {
      if (count > 0 && person[j].age_ >= low && person[j].age_ <= top) {
        printf("%s %d %d\n", person[j].name_.c_str(), person[j].age_,
               person[j].worth_);
        count--;
        flag = true;
      }
      if (count == 0) break;
    }
    if (flag == false) cout << "None" << endl;
  }

  return 0;
}
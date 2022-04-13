#include <bits/stdc++.h>

using namespace std;

struct Student {
  string name;
  set<int> course;
};

int main() {
  int n, m;
  string name;
  cin >> n >> m;
  unordered_map<string, Student> mp;
  for (int i = 0; i < m; ++i) {
    int course, count;
    cin >> course >> count;
    for (int j = 0; j < count; ++j) {
      cin >> name;
      if (mp.find(name) != mp.end()) {
        mp[name].course.insert(course);
      } else {
        Student student;
        student.course.insert(course);
        student.name = name;
        mp.insert({name, student});
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cin >> name;
    int count = mp[name].course.size();
    cout << name << " " << count;
    if (count != 0) {
      for (auto iter = mp[name].course.begin(); iter != mp[name].course.end();
           ++iter) {
        cout << " " << *iter;
      }
    }
    cout << endl;
  }

  return 0;
}
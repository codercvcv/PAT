#include <bits/stdc++.h>

using namespace std;

struct User {
  string name;
  string password;
  bool modified{false};
};

bool crypt(User& user) {
  for (int i = 0; i < user.password.size(); ++i) {
    if (user.password[i] == '1') {
      user.password[i] = '@';
      user.modified = true;
    } else if (user.password[i] == '0') {
      user.password[i] = '%';
      user.modified = true;
    } else if (user.password[i] == 'l') {
      user.password[i] = 'L';
      user.modified = true;
    } else if (user.password[i] == 'O') {
      user.password[i] = 'o';
      user.modified = true;
    }
  }
  return user.modified;
}

int main() {
  int n, count = 0;
  cin >> n;
  vector<User> user(n);
  for (int i = 0; i < n; ++i) {
    cin >> user[i].name >> user[i].password;
    if (crypt(user[i])) count++;
  }

  if (count == 0) {
    n == 1 ? printf("There is %d account and no account is modified", n)
           : printf("There are %d accounts and no account is modified", n);
  } else {
    printf("%d\n", count);
  }

  for (int i = 0; i < n; ++i) {
    if (user[i].modified == true) {
      printf("%s %s\n", user[i].name.c_str(), user[i].password.c_str());
    }
  }

  return 0;
}
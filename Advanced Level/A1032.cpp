#include <bits/stdc++.h>
using namespace std;

struct Node {
  int address;
  int next;
  char data;
};

int main() {
  unordered_map<int, Node> mp;
  int head1, head2, n;
  Node node;
  cin >> head1 >> head2 >> n;
  for (int i = 0; i < n; ++i) {
    cin >> node.address >> node.data >> node.next;
    mp[node.address] = node;
  }

  list<Node> lst1;
  list<Node> lst2;
  while (head1 != -1) {
    lst1.push_back(mp[head1]);
    head1 = mp[head1].next;
  }

  while (head2 != -1) {
    lst2.push_back(mp[head2]);
    head2 = mp[head2].next;
  }

  int len = min(lst1.size(), lst2.size());
  while (lst1.size() > len) {
    lst1.pop_front();
  }

  while (lst2.size() > len) {
    lst2.pop_front();
  }

  while (!lst1.empty()) {
    if (lst1.front().address == lst2.front().address) break;
    lst1.pop_front();
    lst2.pop_front();
  }

  (lst1.empty() == true) ? printf("-1\n")
                         : printf("%05d", lst1.front().address);

  return 0;
}
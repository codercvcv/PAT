#include <bits/stdc++.h>
using namespace std;

struct Node {
  int address;
  int data;
  int next;
};

int main() {
  unordered_map<int, Node> mp;
  int head, n, m;
  Node node;
  cin >> head >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> node.address >> node.data >> node.next;
    mp[node.address] = node;
  }

  vector<Node> ans;
  for (int i = 0; i < n; ++i) {
    if (mp.find(head) == mp.end()) break;
    ans.push_back(mp[head]);
    head = mp[head].next;
  }

  int count = 0;
  n = ans.size();
  while (n / m > 0) {
    reverse(ans.begin() + count, ans.begin() + count + m);
    count += m;
    n -= m;
  }

  for (int i = 0; i < ans.size() - 1; ++i) {
    ans[i].next = ans[i + 1].address;
  }

  for (int i = 0; i < ans.size() - 1; ++i) {
    printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i].next);
  }
  printf("%05d %d -1\n", ans.back().address, ans.back().data);

  return 0;
}
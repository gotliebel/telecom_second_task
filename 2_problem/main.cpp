#include <iostream>
#include "forward_list.h"

int main() {
  ForwardList<int> l;
  l.push_front(10);
  l.push_front(11);
  l.push_front(12);
  l.push_front(13);
  for (int & it : l) {
    std::cout << it << ' ';
  }
  std::cout << '\n' << l[0] << '\n';
  l.pop_front();
  std::cout << l[0];
  return 0;
}

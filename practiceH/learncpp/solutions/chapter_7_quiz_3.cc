#include <iostream>

int accumulate(int n) {
  static int sum{};
  return sum += n;
}

int main() {
  std::cout << accumulate(4) << '\n';
  std::cout << accumulate(3) << '\n';
  std::cout << accumulate(2) << '\n';
  std::cout << accumulate(1) << '\n';

  return 0;
}

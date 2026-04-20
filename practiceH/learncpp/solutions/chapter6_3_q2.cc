#include <iostream>

constexpr bool isEven(int n) { return (n % 2) == 1; }

int main() {
  int number;
  std::cout << "Enter a number: ";
  std::cin >> number;
  if (isEven(number))
    std::cout << number << " is odd" << '\n';
  else
    std::cout << number << " is even" << '\n';

  return 0;
}

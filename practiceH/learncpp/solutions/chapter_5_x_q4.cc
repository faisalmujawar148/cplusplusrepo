#include <iostream>
#include <string>
#include <string_view>

std::string getName(int num) {
  std::cout << "Enter the name for person #" << num << ": ";
  std::string name{};
  std::getline(std::cin >> std::ws, name);

  return name;
}

int getAge(std::string_view sv) {

  std::cout << "Enter the age of " << sv << " : ";
  int age{};
  std::cin >> age;

  return age;
}

void printOlder(std::string_view n1, std::string_view n2, int a1, int a2) {
  if (a1 > a2)
    std::cout << n1 << "(age " << a1 << "> " << "is older than " << n2
              << "(age " << a2 << ")" << '\n';
  else
    std::cout << n2 << "(age " << a2 << "> " << "is older than " << n1
              << "(age " << a1 << ")" << '\n';
}

int main() {
  const std::string name1{getName(1)};
  const int age1{getAge(name1)};
  const std::string name2{getName(2)};
  const int age2{getAge(name2)};

  printOlder(name1, name2, age1, age2);
  return 0;
}

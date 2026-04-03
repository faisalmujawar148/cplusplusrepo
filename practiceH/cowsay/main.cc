#include <iostream>
#include <string>

const int BUFF_MAX = 38;

int main(int argc, char **argv) {
  std::string cow_template = "        \\   ^__^              \n"
                             "         \\  (oo)\\_______     \n"
                             "            (__)\\       )\\/  \n"
                             "                ||----w |      \n"
                             "                ||     ||      \n";
  int argscharcount = {0};
  if (argc <= 1) {
    if (argv[0])
      std::cout << "Usage: " << argv[0] << " <sentence>" << '\n';
    else
      std::cout << "Usage: <program name> <sentence>" << '\n';
    return 1;
  }
  int j = 0;

  for (int i = {0}; i < argc; i++) {
    j = 0;
    while (argv[i][j] != '\0' && i != 0) {
      std::cout << "Argument " << i << " letter " << j << " : " << argv[i][j++]
                << '\n';
      argscharcount++;
    }
  }
  /* Display speech bubble */
  for (int i = 1; i <= argscharcount; i++) {
    std::cout << "_";
  }
  std::cout << "\n< ";
  for (int i = 1; i < argc; i++) {
    std::cout << argv[i];
  }
  std::cout << ">\n";

  for (int i = 1; i <= argscharcount; i++) {
    std::cout << "_";
  }

  std::cout << cow_template;

  return 0;
}

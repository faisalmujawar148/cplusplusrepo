#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::string cow_template =
        "        \\   ^__^              \n"
        "         \\  (oo)\\_______     \n"
        "            (__)\\       )\\/  \n"
        "                ||----w |    \n"
        "                ||     ||    \n";
    // to check if there is anything to even print
    std::vector<std::string> msgs;
    if (argc > 1) {
        std::string string = argv[1];
	std::string mesg = "<";
	int count = 0;
        for (int i=0; i < string.size(); i++) {
		if (count >= 125){
			mesg += "> \n";
			msgs.push_back(mesg);
			mesg = "<";
			count = 0;
		}
		mesg += string[i];
		count++;
        }
    	if (!mesg.empty()){
		mesg += "> \n";
		msgs.push_back(mesg);
	}
    }

    for (int j = 0; j < msgs.size(); j++){
	    std::cout << msgs[j];
    }
    std::cout << cow_template;
    return 0;
}

#include <iostream>
#include <map>
#include <string>

void sym_code (char& a, std::string& b) {
    a = b[0];
}

int main() {
    std::string stop = "go", word;
    std::map<std::string, int> surname;
    do {
        std::cout << "Enter the last name of the patient who came up or enter next to call for an appointment:";
        std::cin >> word;
        if (word != "next") {
            if (surname.count(word) > 0) {
                std::map<std::string, int>::iterator it = surname.find(word);
                it -> second += 1;
            } else {
                surname.insert(std::pair<std::string, int>(word, 1));
            }
        }
        else {
            if (!surname.empty()) {
                std::map<std::string, int>::iterator it = surname.begin();
                std::cout << it->first << "\n";
                if ((it->second -= 1) == 0) {
                    surname.erase(it);
                }
            }
            else {
                std::cout << "The list is empty!\n";
            }
        }
        if (surname.begin() == surname.end()) {
            stop = "stop";
        }
    }while (stop != "stop");

    return 0;
}

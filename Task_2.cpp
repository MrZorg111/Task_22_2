#include <iostream>
#include <map>
#include <string>

void sym_code (char& a, std::string& b) {
    a = b[0];
}

int main() {
    std::map<char, std::string> registry;
    char sym;
    std::string surname, command;
    for (int i = 0; i < 10; i++) {
        std::cout << "Fill out the registration form by entering the names of the patients: ";
        std::cin >> surname;
        sym_code(sym, surname);
        registry.insert(std::pair<char, std::string>(sym, surname));
    }
    // Let's start calling patients!
    for (std::map<char, std::string>::iterator it = registry.begin(); it != registry.end(); it++) {
        std::cout << "To call the patient, enter the command (next):";
        std::cin >> command;
        std::cout << it -> second << "\n";
    }
    return 0;
}

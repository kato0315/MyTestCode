#include <iostream>
#include <string>
#include <cctype>

using std::string;

int main()
{
    /*string str("some ,,,!!string");
    auto size = str.size();
    
    for (int i = 0; i < str.size(); i++) {
        if (ispunct(str[i])) {
            for (int j = i; j < str.size() - 1; j++) {
                str[j] =  str[j + 1];
            }
            i--;
            size--;
        }
    }

    std::cout << str.substr(0, size) << std::endl;*/

    const string s = "Keep out!";
    for (auto &c : s) {
        std::cout << c;
    }

    return 0;
}
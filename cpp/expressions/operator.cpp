#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    short short_value = 32767;
    short_value++;
    std::cout << short_value << std::endl;

    vector<string> text;
    text.push_back("string test.");
    text.push_back("hello world");
    text.push_back("123321 ");
    text.push_back("");
    text.push_back("..3213 ");
    for (const auto &s : text) {
        std::cout << s;
        if (s.empty() || s[s.size() - 1] == '.') {
            std::cout << std::endl;
        }
        else {
            std::cout << " ";
        }

    }


    return 0;
}
#include <iostream>
#include <string>

using std::string;

int main()
{
    string s1;
    string s2 = s1;
    string s3 = "hello";
    string s4(10, 'c');//cccccccccc

    //std::cin >> s1 >> s2;
    //std::cout << s1 << s2 << std::endl;

    /*while (std::cin >> s1) {
        std::cout << s1 << std::endl;
    }*/

    std::cin >> s1;
    std::cin >> s2;

    if (s1 == s2) {
        std::cout << "s1 equals to s2" << std::endl;
    }
    else {
        std::cout << (s1 > s2 ? s1 : s2) << std::endl;
    }

    return 0;
}
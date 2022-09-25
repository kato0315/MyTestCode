#include <iostream>
#include <vector>
#include <cctype>
using std::vector;
using std::string;


int main()
{
    vector<int> ivec;
    vector<int> ivec2(ivec);    //copy
    vector<int> ivec3 = ivec;   //copy
    vector<string> v1{"a", "an", "the"};    //list initialization
    vector<int> ivec4(10, -1);
    vector<string> svec(10, "hi");
    vector<int> ivec5(10);  //value-initialized
    vector<string> svec2(10);   //value-initialized

    vector<int> v2;
    for (int i = 0; i < 100; i++) {
        v2.push_back(i);
    }

  //  std::cout << v2.size() << std::endl;

    for (int i = 0; i < v2.size(); i++) {
 //       std::cout << v2[i] << std::endl;
    }

    vector<string> s2;
    string word;

    while (std::cin >> word) {
        for (int i = 0; i < word.size(); i++) {
            if (islower(word[i])) {
                word[i] = toupper(word[i]);
            }
            
        }
        s2.push_back(word);
        std::cout << word << std::endl;
    }


    return 0;
}
#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using std::vector;
using std::iterator;

int main()
{
    std::string s("some string");

    for (auto it = s.begin(); it != s.end(); it++) {
        *it = toupper(*it);
    }
    std::cout << s << std::endl;

    vector<int> ivec{1,2,3,4,5,6,7,8,9,10};

    for (auto it = ivec.begin(); it != ivec.end(); it++) {
        *it *= 2;
        //std::cout << *it << std::endl;
    }

    auto beg = ivec.begin(), end = ivec.end();
    auto mid = ivec.begin() + (end - beg) / 2;

    int target = 4;
    while (mid != end && *mid != target) {
        if (target < *mid)
            end = mid;
        else
            beg = mid + 1;
        
        mid = beg + (end - beg) / 2;
    }

    std::cout << mid - beg << std::endl;


    return 0;
}
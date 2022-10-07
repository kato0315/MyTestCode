#include <iostream>
#include <string>
#include <iterator>

using std::string;

int sa[10];

int main()
{
    const unsigned int sz = 3;
    int ial[sz] = {0, 1, 2};
    int a2[] = {0, 1, 2};
    int a3[5] = {0, 1, 2};//a3[] = {0, 1, 2, 0, 0};
    string a4[3] = {"hi", "bye"};//a4[] = {"hi", "bye", ""};

    char aa1[] = {'C', '+', '+'};
    char aa2[] = {'C', '+', '+', '\0'};
    char aa3[] = "C++";
    //char aa4[6] = "Daniel";//error

    int arr[10];
    int *ptrs[10];
    int (*Parray)[10] = &arr;
    int (&arrRef)[10] = arr;

    int sa2[10];

    std::cout << *(std::begin(sa)) << std::endl;
    std::cout << *(std::begin(sa2)) << std::endl;
    auto n = std::end(sa) - std::begin(sa);
    std::cout << n << std::endl;

    return 0;
}
#include <iostream>

int fun()
{
    return 1;
}

int main()
{
    using my_int = int;
    int i = 0;

    int val1 = 1, val2 = 3;
    auto item = val1 + val2;
    //auto sz = 0, pi = 3.14;
    
    int &r = i;
    const int ci = i, &cr = ci;
    auto a = r;
    auto b = ci;
    auto c = cr;
    auto d = &i;

    /*a = 42;
    std::cout << "a:" << a << std::endl;
    std::cout << "r:" << r << std::endl;
    std::cout << "i:" << i << std::endl;
    b = 42;
    std::cout << "b:" << b << std::endl;
    std::cout << "ci:" << ci << std::endl;
    std::cout << "i:" << i << std::endl;
    c = 42;
    std::cout << "c:" << c << std::endl;
    std::cout << "cr:" << cr << std::endl;
    std::cout << "ci:" << ci << std::endl;
*/
    //d = 42; // error
    //auto e = &ci;
    //e = 42; //error
    //auto &g = ci;
    //g = 42; //error
    decltype(fun()) sum = i; //int sum = i
    //decltype((i)) e;

    int aa = 3, bb = 4;
    decltype(aa) cc = aa;
    std::cout << aa << cc;
    decltype(aa = bb) dd = aa;
    std::cout << aa << bb << dd;

    return 0;
}
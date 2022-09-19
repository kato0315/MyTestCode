#include <iostream>
int main()
{
    //int i = -1, &r = 0; //error, &r should be reference to const
    //int i2; int *const p2 = &i2;
    //const int i = -1, &r = 0;
    //int i2; const int *const p3 = &i2;
    //const int &const r2;// reference must be initialized
    int i = 0; const int i2 = i, &r = i; 

    
    return 0;
}
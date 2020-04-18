#include <iostream>
#include <cstdlib>


int main(int argc, char const *argv[])
{
    int n = 123;
    char num[4];
    sprintf(num,"%d",n);
    std::cout << (char *)num << std::endl;

    return 0;
}

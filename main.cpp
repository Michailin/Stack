#include <iostream>
#include "stack.h"

int main(int argc, char *argv[])
{
    Stack <int> tmp;
    for(int i = 0;i < 14000; i++)
        tmp.push(i);
    for(int i = 0; i < 14000; i++)
        std :: cout << tmp.pop() << std :: endl;
   // std :: cout << l << std :: endl;
    return 0;
}

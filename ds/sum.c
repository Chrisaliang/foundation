#include<stdio.h>

int main(int argc, char const *argv[])
{
    func(argc);
    return 0;
}


int func(int n){
    int i = 0, sum = 0;
    while (sum<n)
    {
        sum += ++i;
    }
    return i;
}

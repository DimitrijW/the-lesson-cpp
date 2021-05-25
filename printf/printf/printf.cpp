// printf.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

int main()
{
    unsigned long long zahl = 1000000000000000 ;
    std::cout << zahl << std::endl;
    printf("1[s] -> 1000[ms] -> 1000.000[us] -> 1000.000.000[ns]\n");
    printf("1.000.000.000.000 --> %ld\n", zahl);
    printf("1.000.000.000.000 --> %8lu\n", zahl);
    printf("1.000.000.000.000 --> %ull\n", zahl);
    printf("1.000.000.000.000 --> %I64d\n", zahl);
}


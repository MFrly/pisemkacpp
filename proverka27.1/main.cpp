#include <iostream>
#include "datum.h"

int main() {
    Datum d1;
    std::cout << "vychozi datum d1: " << d1 << std::endl;

    Datum d2(29, 2, 2024);
    Datum d2_copy(d2);
    std::cout << "datum d2 kopirovacim konstruktorem s parametry: " << d2_copy << std::endl;
    Datum d3(d2_copy);
    std::cout << "datum d3 kopirovacim konstruktorem: " << d3 << std::endl;



    int den, mesic, rok;
    std::cout << "Zadejte vlastni datum (den, mesic, rok): ";
    std::cout << "zadej den: "<< std::endl;
    std::cin >> den;
    std::cout << "zadej mesic: "<< std::endl;
    std::cin >> mesic;
    std::cout << "zadej rok: "<< std::endl;
    std::cin >> rok;
    d1.nastavDatum(den, mesic, rok);
    std::cout << "Datum d1 po zmene: " << d1 << std::endl;

    return 0;
}
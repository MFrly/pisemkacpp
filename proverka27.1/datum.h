//
// Created by student on 27.01.2025.
//
#ifndef DATUM_H
#define DATUM_H
#include <iostream>
#include <string>

class Datum {

public:
    Datum();
    Datum(int d, int m, int r);
    Datum(const Datum& other);

    int getDen() const;
    int getMesic() const;
    int getRok() const;

    void nastavDatum(int d, int m, int r);
    int pocetDniOd1970() const;
    std::string denVTydnu() const;

    friend std::ostream& operator<<(std::ostream& os, const Datum& datum);

private:
    int den, mesic, rok;
    static const int MIN_ROK = 1970;
    static const int MAX_ROK = 2050;

    bool jePlatneDatum(int d, int m, int r) const;
    bool jePrestupnyRok(int r) const;
    int pocetDniVMesici(int m, int r) const;
    void nastavSystemoveDatum();
};



#endif //DATUM_H

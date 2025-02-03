//
// Created by student on 27.01.2025.
//


#include "datum.h"
#include <ctime>

Datum::Datum() {
    nastavSystemoveDatum();
}

Datum::Datum(int d, int m, int r) {
    if (jePlatneDatum(d, m, r)) {
        den = d;
        mesic = m;
        rok = r;
    } else {
        nastavSystemoveDatum();
    }
}

Datum::Datum(const Datum& other) {
    den = other.den;
    mesic = other.mesic;
    rok = other.rok;
}

int Datum::getDen() const { return den; }
int Datum::getMesic() const { return mesic; }
int Datum::getRok() const { return rok; }

void Datum::nastavDatum(int d, int m, int r) {
    if (jePlatneDatum(d, m, r)) {
        den = d;
        mesic = m;
        rok = r;
    } else {
        std::cerr << "Neplatné datum!\n";
    }
}

int Datum::pocetDniOd1970() const {
    int pocetDni = 0;
    for (int r = MIN_ROK; r < rok; ++r) {
        pocetDni += jePrestupnyRok(r) ? 366 : 365;
    }
    for (int m = 1; m < mesic; ++m) {
        pocetDni += pocetDniVMesici(m, rok);
    }
    pocetDni += den - 1;
    return pocetDni;
}

std::string Datum::denVTydnu() const {
    static const std::string dny[] = {"pondeli", "uery", "streda", "ctvrtek", "patek", "sobota", "nedele"};
    return dny[pocetDniOd1970() % 7];
}

bool Datum::jePlatneDatum(int d, int m, int r) const {
    if (r < MIN_ROK || r > MAX_ROK || m < 1 || m > 12 || d < 1) return false;
    return d <= pocetDniVMesici(m, r);
}

bool Datum::jePrestupnyRok(int r) const {
    return (r % 4 == 0 && r % 100 != 0) || (r % 400 == 0);
}

int Datum::pocetDniVMesici(int m, int r) const {
    switch (m) {
        case 1:
            return 31;

        case 2:
            return jePrestupnyRok(r) ? 29 : 28;

        case 3:
            return 31;

        case 4:
            return 30;

        case 5:
            return 31;

        case 6:
            return 30;

        case 7:
            return 31;

        case 8:
            return 31;

        case 9:
            return 30;

        case 10:
            return 31;

        case 11:
            return 3;

        case 12:
            return 31;
    }
}

void Datum::nastavSystemoveDatum() {
    time_t t = time(0);
    tm* now = localtime(&t);
    den = now->tm_mday;
    mesic = now->tm_mon + 1;
    rok = now->tm_year + 1900;
}

std::ostream& operator<<(std::ostream& os, const Datum& datum) {
    os << datum.den << "." << datum.mesic << "." << datum.rok
       << " (" << datum.denVTydnu() << ")"
       << ", pocet dni od 1.1.1970: " << datum.pocetDniOd1970();
    return os;
}
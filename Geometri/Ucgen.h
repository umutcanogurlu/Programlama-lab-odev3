#include <iostream>
#include <cmath>
#include <array>
#include "Nokta.h"
#include "DogruParcasi.h"
using namespace std;

class Ucgen {
private:
    Nokta n1, n2, n3;

public:
    // Üç Nokta nesnesi alma
    Ucgen(const Nokta& n1, const Nokta& n2, const Nokta& n3) : n1(n1), n2(n2), n3(n3) {}

    // Get Metodları
    Nokta getN1() const { return n1; }
    Nokta getN2() const { return n2; }
    Nokta getN3() const { return n3; }

    // Set Metodları
    void setN1(const Nokta& n1) { this->n1 = n1; }
    void setN2(const Nokta& n2) { this->n2 = n2; }
    void setN3(const Nokta& n3) { this->n3 = n3; }

    // Alan Metodu
    double alan() const {
        double yarimCevre = cevre() / 2;
        double a = DogruParcasi(n1, n2).uzunluk();
        double b = DogruParcasi(n2, n3).uzunluk();
        double c = DogruParcasi(n1, n3).uzunluk();
        return sqrt(yarimCevre * (yarimCevre - a) * (yarimCevre - b) * (yarimCevre - c));
    }

    // Çevre Metodu
    double cevre() const {
        return DogruParcasi(n1, n2).uzunluk() + DogruParcasi(n2, n3).uzunluk() + DogruParcasi(n1, n3).uzunluk();
    }

    // Açılar Metodu
     double* acilar() const {
        static double aciDegerleri[3];
        double a = DogruParcasi(n1, n2).uzunluk();
        double b = DogruParcasi(n2, n3).uzunluk();
        double c = DogruParcasi(n1, n3).uzunluk();

        aciDegerleri[0] = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / M_PI;
        aciDegerleri[1] = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / M_PI;
        aciDegerleri[2] = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / M_PI;

        return aciDegerleri;
    }

    // toString Metodu
    std::string toString() const {
        return "Ucgen; Noktaları: " + n1.toString() + ", " + n2.toString() + ", " + n3.toString();
    }

    // Yazdır Metodu
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};
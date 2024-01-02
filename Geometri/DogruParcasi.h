#include <iostream>
#include <cmath>
#include <array>
#ifndef DOGRUPARCASI_H
#define DOGRUPARCASI_H
#include "Nokta.h"


class DogruParcasi {
private:
    Nokta u1, u2;

public:
    // İki uç noktayı Nokta nesnesi olarak alma
    DogruParcasi(const Nokta& u1, const Nokta& u2) : u1(u1), u2(u2) {}

    // Kopya yapma
    DogruParcasi(const DogruParcasi& dp) : u1(dp.u1), u2(dp.u2) {}

    // Orta nokta, uzunluk ve eğim 
    DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
        double yarimUzunluk = uzunluk / 2.0;
        double deltaX = yarimUzunluk * cos(egim);
        double deltaY = yarimUzunluk * sin(egim);
        u1.x = ortaNokta.x - deltaX;
        u1.y = ortaNokta.y - deltaY;
        u2.x = ortaNokta.x + deltaX;
        u2.y = ortaNokta.y + deltaY;
    }

    // Get ve Set Metotları
    void setP1(const Nokta& u1) { this->u1 = u1; }
    void setP2(const Nokta& u2) { this->u2 = u2; }
    Nokta getP1() const { return u1; }
    Nokta getP2() const { return u2; }

    // Uzunluk Metodu
    double uzunluk() const {
        return sqrt(pow(u2.x - u1.x, 2) + pow(u2.y - u1.y, 2));
    }

    // Orta Nokta Metodu
    Nokta ortaNokta() const {
        return Nokta((u1.x + u2.x) / 2.0, (u1.y + u2.y) / 2.0);
    }

    // Kesişim Noktası Metodu
    Nokta kesisimNoktasi(const Nokta& nokta) {
        double m = (u2.y - u1.y) / (u2.x - u1.x); // Doğru parçasının eğimi
        double b = u1.y - m * u1.x; // y eksenini kestiği nokta
        double perpendicularM = -1 / m; // Dik doğrunun eğimi
        double perpendicularB = nokta.y - perpendicularM * nokta.x; // Dik doğru için y ekseni kesme noktası
        double x = (perpendicularB - b) / (m - perpendicularM); // Kesişim noktasının x koordinatı
        double y = m * x + b; // Kesişim noktasının y koordinatı

        return Nokta(x, y);
    }

    // toString Metodu
    std::string toString() const {
        return "Dogru Parcasi: " + u1.toString() + " - " + u2.toString();
    }

    // Yazdır Metodu
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};
#endif // DOGRUPARCASI_H
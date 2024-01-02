#include <iostream>
#include <cmath>
#include <array>
#ifndef NOKTA_H
#define NOKTA_H


class Nokta {
public:
    double x, y;

    // (Parametresiz) Koordinatları orijine ayarlama
    Nokta() : x(0), y(0) {}

    // (Tek parametreli) İki koordinata aynı değeri atar
    Nokta(double val) : x(val), y(val) {}

    // (İki parametreli) x ve y koordinatları için iki double değişken alır
    Nokta(double x, double y) : x(x), y(y) {}

    // (Kopya oluşturma) Başka bir noktanın kopyasını oluşturur
    Nokta(const Nokta& nokta) : x(nokta.x), y(nokta.y) {}

    // (Ofset) Başka bir nokta ve ofset değerlerini alır
    Nokta(const Nokta& nokta, double ofset_x, double ofset_y) : x(nokta.x + ofset_x), y(nokta.y + ofset_y) {}

    // Set metodları
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void set(double x, double y) { setX(x); setY(y); }

    // Get metodları
    double getX() const { return x; }
    double getY() const { return y; }

    // toString metodu
    std::string toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    // yazdir metodu
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};

#endif // NOKTA_H
#include <iostream>
#include <cmath>
#include <array>
#include "Nokta.h"

class Daire {
private:
    Nokta merkez;
    double yaricap;

public:
    // Merkez ve yarıçapı parametre olarak alma
    Daire(const Nokta& merkez, double yaricap) : merkez(merkez), yaricap(yaricap) {}

    // Kopya üretme
    Daire(const Daire& daire) : merkez(daire.merkez), yaricap(daire.yaricap) {}

    // Başka bir daire nesnesi ve bir katsayı alarak kopyalama
    Daire(const Daire& daire, double katsayi) : merkez(daire.merkez), yaricap(daire.yaricap * katsayi) {}

    // Alan metodu
    double alan() const {
        return M_PI * yaricap * yaricap;
    }

    // Çevre metodu
    double cevre() const {
        return 2 * M_PI * yaricap;
    }

    // Kesişim metodu
    int kesisim(const Daire& other) const {
        double mesafe = sqrt(pow(merkez.x - other.merkez.x, 2) + pow(merkez.y - other.merkez.y, 2));
        if (mesafe < std::abs(yaricap - other.yaricap)) return 0; // Bir daire diğerinin içinde
        if (mesafe == 0 && yaricap == other.yaricap) return 1; // Dairelerin örtüşmesi
        return 2; // Hiç kesişim yok
    }

    // toString metodu
    std::string toString() const {
        return "Daire: Merkez = " + merkez.toString() + ", Yarıçap = " + std::to_string(yaricap);
    }

    // Yazdır metodu
    void yazdir() const {
        std::cout << toString() << std::endl;
    }
};
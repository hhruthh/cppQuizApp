#include "Intrebare.h"

#include <utility>

Intrebare::Intrebare(Tip tip, std::string intrebare, std::string raspuns) : tip(tip), intrebare(std::move(intrebare)), raspuns(std::move(raspuns)) {}

std::ostream &operator<<(std::ostream &os, const Intrebare &intrebare) {
    os << (intrebare.tip == Intrebare::GRILA ? 0 : 1) << "\n" << intrebare.intrebare << "\nR: " << intrebare.raspuns << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Intrebare &intrebare) {
    int tip;
    is >> tip;
    intrebare.tip = tip == 0 ? Intrebare::GRILA : Intrebare::TEXT;
    std::string line;
    is >> std::ws;
    while (std::getline(is, line)) {
        if (line.find("R: ") != std::string::npos) {
            break;
        }
        intrebare.intrebare += "\n" + line;
        is >> std::ws;
    }
    intrebare.intrebare.erase(0, 1);
    line.erase(0, 3);
    intrebare.raspuns = line;
    return is;
}

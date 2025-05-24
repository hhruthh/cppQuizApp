#ifndef PROIECT14_INTREBARE_H
#define PROIECT14_INTREBARE_H

#include <iostream>
#include <string>
#include <utility>

class Intrebare {
public:
    enum Tip { GRILA, TEXT };

private:
    Tip tip;
    std::string intrebare;
    std::string raspuns;

public:
    Intrebare() : tip(GRILA), intrebare(), raspuns() {};
    Intrebare(Tip tip, std::string intrebare) : tip(tip), intrebare(std::move(intrebare)), raspuns() {};
    Intrebare(Tip tip, std::string intrebare, std::string raspuns);
    [[nodiscard]] Tip getTip() const { return tip; };
    [[nodiscard]] const std::string &getIntrebare() const { return intrebare; };
    [[nodiscard]] const std::string &getRaspuns() const { return raspuns; };
    void setTip(Tip Tip) { this->tip = Tip; }
    void setIntrebare(const std::string &Intrebare) { this->intrebare = Intrebare; }
    void setRaspuns(const std::string &Raspuns) { this->raspuns = Raspuns; }
    [[nodiscard]] bool verificaRaspuns(const std::string &raspunsUtilizator) const { return raspuns == raspunsUtilizator; };

    bool operator==(const Intrebare &rhs) const { return tip == rhs.tip; };
    bool operator!=(const Intrebare &rhs) const { return tip != rhs.tip; }

    friend std::ostream &operator<<(std::ostream &os, const Intrebare &intrebare);
    friend std::istream &operator>>(std::istream &is, Intrebare &intrebare);
};


#endif //PROIECT14_INTREBARE_H

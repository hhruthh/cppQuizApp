#ifndef PROIECT14_TEST_H
#define PROIECT14_TEST_H

#define file1 "intrebari.txt"
#define file1Statistica "statistica.txt"

#include "Intrebare.h"
#include <vector>

class Test {
private:
    std::vector<Intrebare> intrebari;
//    int scor;

public:
    Test() : intrebari() {};
    void scriere();
    void citire();
    void meniu();
    void rezolvaTest();
    void afiseazaIntrebari();
    void adaugaIntrebare();
    void adaugaIntrebare(const Intrebare &intrebare) { intrebari.push_back(intrebare); };
    void stergeIntrebare(int nr = -1);
    static void scriereStatistica(int scor, int nrIntrebari, const std::string& Nume);
    static void afiseazaStatistica();

};


#endif //PROIECT14_TEST_H

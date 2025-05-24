#include "Test.h"
#include "fstream"
#include <conio.h>

void Test::rezolvaTest() {
    int scor = 0;
    std::string numeUtilizator;
    std::cout << "Introduceti-va numele: ";
    std::cin >> std::ws;
    getline(std::cin, numeUtilizator);
    for (int i = 0; i < intrebari.size(); i++) {
        std::cout << "Intrebarea " << i + 1 << ": " << std::endl << intrebari[i].getIntrebare();

        if (intrebari[i].getTip() == Intrebare::GRILA) {
            std::cout << "\nRaspuns: ";
            std::string raspuns;
            std::cin >> std::ws;
            getline(std::cin, raspuns);
            if (intrebari[i].verificaRaspuns(raspuns)) {
                std::cout << "Raspuns corect!" << std::endl << std::endl;
                scor++;
            } else {
                std::cout << "Raspuns gresit!" << std::endl << std::endl;
            }
        } else {
            std::cout << "\nRaspuns: ";
            std::string raspuns;
            std::cin >> std::ws;
            getline(std::cin, raspuns);
            if (intrebari[i].verificaRaspuns(raspuns)) {
                std::cout << "Raspuns corect!" << std::endl << std::endl;
                scor++;
            } else {
                std::cout << "Raspuns gresit!" << std::endl << std::endl;
            }
        }
    }
    std::cout << "\nScorul obtinut: " << scor << "/" << intrebari.size() << std::endl << std::endl;
    scriereStatistica(scor, intrebari.size(), numeUtilizator);
}

void Test::scriere() {
    std::ofstream out(file1);
    if (!out.is_open()) {
        std::cout << "Eroare la deschiderea fisierului!" << std::endl;
        return;
    }
    for (int i = 0; i < intrebari.size(); i++) {
        out << intrebari[i];
    }
    out.close();
}

void Test::citire() {
    std::ifstream in(file1);
    if (!in.is_open()) {
        std::cout << "Eroare la deschiderea fisierului!" << std::endl;
        std:: cout << "Creare fisier..." << std::endl;
        std::ofstream out(file1);
        if (!out.is_open()) {
            std::cout << "Eroare la deschiderea fisierului!" << std::endl;
            return;
        }
        out.close();
        return;
    }
    if (in.peek() == std::ifstream::traits_type::eof()) {
//        std::cout << "Fisierul este gol!" << std::endl;
        return;
    }
    while (!in.eof()) {
        if (in.peek() == std::ifstream::traits_type::eof()) {
            break;
        }
        Intrebare intrebare;
        in >> intrebare;
        intrebari.push_back(intrebare);
    }
    in.close();
}

void Test::scriereStatistica(int scor, int nrIntrebari, const std::string& Nume) {
    std::ofstream out(file1Statistica, std::ios::app);
    if (!out.is_open()) {
        std::cout << "Eroare la deschiderea fisierului!" << std::endl;
        return;
    }
    out << Nume << " " << scor << "/" << nrIntrebari << std::endl;
    out.close();
}

void Test::meniu() {
    int optiune;
    do {
        system("cls");
        std::cout << "1. Rezolva test" << std::endl;
        std::cout << "2. Afiseaza intrebari" << std::endl;
        std::cout << "3. Adauga intrebare" << std::endl;
        std::cout << "4. Sterge intrebare" << std::endl;
        std::cout << "5. Afiseaza statistica" << std::endl;
        std::cout << "0. Iesire" << std::endl;
        std::cout << "Optiune: ";
        optiune = getch() - '0';
        // std::cin >> optiune;
        system("cls");
        switch (optiune) {
            case 1:
                rezolvaTest();
                break;
            case 2:
                afiseazaIntrebari();
                break;
            case 3:
                adaugaIntrebare();
                break;
            case 4:
                stergeIntrebare();
                break;
            case 5:
                afiseazaStatistica();
                break;
            case 0:
                std::cout << "Iesire...\n";
                break;
            default:
                std::cout << "Optiune invalida!" << std::endl;
                break;
        }
        if (optiune) {
            std::cout << std::endl << "Apasati orice tasta pentru a continua...";
            getch();
        }
    } while (optiune != 0);
}

void Test::adaugaIntrebare() {
    std::cout << "Tip intrebare (0 - grila, 1 - text): ";
    int tip;
    tip = getch() - '0';
    // std::cin >> tip;
    std::cout << "\nIntrebare: ";
    std::string s;
    std::cin >> std::ws;
    getline(std::cin, s);
    if (tip == 0) {
        int nr;
        std::string temp;
        std::cout << "Introduceti numarul de variante: ";
        std::cin >> nr;
        for (int i = 1; i <= nr; i++) {
            std::cout << "Introduceti varianta " << i << ": ";
            std::cin >> std::ws;
            getline(std::cin, temp);
            s += "\n" + temp;
        }
    }
    Intrebare intrebare(tip == 0 ? Intrebare::GRILA : Intrebare::TEXT, s);
    std::cout << "Raspuns: ";
    std::string raspuns;
    std::cin >> std::ws;
    getline(std::cin, raspuns);
    intrebare.setRaspuns(raspuns);
    intrebari.push_back(intrebare);
    scriere();
}

void Test::afiseazaIntrebari() {
    for (int i = 0; i < intrebari.size(); i++) {
        std::cout << "Intrebarea " << i + 1 << ":\n" << intrebari[i].getIntrebare() << std::endl << std::endl;
    }
}

void Test::afiseazaStatistica() {
    std::ifstream in(file1Statistica);
    if (!in.is_open()) {
        std::cout << "Eroare la deschiderea fisierului!" << std::endl;
        std:: cout << "Creare fisier..." << std::endl;
        std::ofstream out(file1Statistica);
        if (!out.is_open()) {
            std::cout << "Eroare la deschiderea fisierului!" << std::endl;
            return;
        }
        out.close();
        return;
    }
    std::cout << "Statistica:\n";
    std::string line;
    in >> std::ws;
    while (std::getline(in, line)) {
        std::cout << line << std::endl;
        in >> std::ws;
    }
    std::cout << std::endl;
}

void Test::stergeIntrebare(int nr) {
    if (nr == -1) {
        afiseazaIntrebari();
        std::cout << "Introduceti numarul intrebarii de sters: ";
        std::cin >> nr;
    }
    if (nr < 1 || nr > intrebari.size()) {
        std::cout << "Intrebare invalida!" << std::endl;
        return;
    }
    intrebari.erase(intrebari.begin() + nr - 1);
    scriere();
}

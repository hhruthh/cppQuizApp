#include <iostream>
#include <cstring>
#include "Test.h"
#include <conio.h>

void meniu(Test &test);
int stoi(const std::string& s);

int main(int argc, char *argv[]) {
    Test test;
    test.citire();
    if (argc >= 2) {
        if (strcmp(argv[1], "-test") == 0 && argc == 2) {
            test.rezolvaTest();
        } else if (strcmp(argv[1], "-add") == 0 && argc == 2) {
            test.adaugaIntrebare();
            test.scriere();
        } else if (strcmp(argv[1], "-delete") == 0 && argc == 2) {
            test.stergeIntrebare();
            test.scriere();
        } else if (strcmp(argv[1], "-delete") == 0 && argc == 3) {
            test.stergeIntrebare(stoi(argv[2]));
            test.scriere();
        } else if (strcmp(argv[1], "-list") == 0 && argc == 2) {
            test.afiseazaIntrebari();
        } else if (strcmp(argv[1], "-statistics") == 0 && argc == 2) {
            Test::afiseazaStatistica();
        } else if (strcmp(argv[1], "-help") == 0) {
            std::cout << "Comenzi disponibile:\n";
            std::cout << "-test - rezolva testul\n";
            std::cout << "-add - adauga o intrebare\n";
            std::cout << "-delete - sterge intrebarea n\n";
            std::cout << "-delete n - sterge intrebarea n\n";
            std::cout << "-list - afiseaza intrebarile\n";
            std::cout << "-statistics - afiseaza statistica\n";
            std::cout << "-help - afiseaza aceasta lista\n";
        } else {
            std::cout << "Comanda invalida!\n";
        }
    } else if (argc == 1) {
        meniu(test);
    } else {
        std::cout << "Comanda invalida!\n";
    }

    return 0;
}

int stoi(const std::string& s) {
    int nr = 0;
    for (char i : s) {
        nr = nr * 10 + i - '0';
    }
    return nr;
}

void meniu(Test &test) {
    int optiune;
    do {
        system("cls");
        std::cout << "1. Afiseaza intrebari" << std::endl;
        std::cout << "2. Adauga intrebare" << std::endl;
        std::cout << "3. Sterge intrebare" << std::endl;
        std::cout << "4. Afiseaza statistica" << std::endl;
        std::cout << "0. Iesire" << std::endl;
        std::cout << "Optiune: ";
        optiune = getch() - '0';
        // std::cin >> optiune;
        system("cls");
        switch (optiune) {
            case 1:
                test.afiseazaIntrebari();
                break;
            case 2:
                test.adaugaIntrebare();
                break;
            case 3:
                test.stergeIntrebare();
                break;
            case 4:
                test.afiseazaStatistica();
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

// void meniu(Test &test) {
//     int optiune;
//     do {
//         system("cls");
//         std::cout << "1. Rezolva test" << std::endl;
//         std::cout << "2. Afiseaza intrebari" << std::endl;
//         std::cout << "3. Adauga intrebare" << std::endl;
//         std::cout << "4. Sterge intrebare" << std::endl;
//         std::cout << "5. Afiseaza statistica" << std::endl;
//         std::cout << "0. Iesire" << std::endl;
//         std::cout << "Optiune: ";
//         optiune = getch() - '0';
//         // std::cin >> optiune;
//         system("cls");
//         switch (optiune) {
//             case 1:
//                 test.rezolvaTest();
//                 break;
//             case 2:
//                 test.afiseazaIntrebari();
//                 break;
//             case 3:
//                 test.adaugaIntrebare();
//                 break;
//             case 4:
//                 test.stergeIntrebare();
//                 break;
//             case 5:
//                 test.afiseazaStatistica();
//                 break;
//             case 0:
//                 std::cout << "Iesire...\n";
//                 break;
//             default:
//                 std::cout << "Optiune invalida!" << std::endl;
//                 break;
//         }
//         if (optiune) {
//             std::cout << std::endl << "Apasati orice tasta pentru a continua...";
//             getch();
//         }
//     } while (optiune != 0);
// }

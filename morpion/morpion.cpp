#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <cctype>
#include <time.h>

using namespace std;

void sleep(int milliseconds);

void sleep(int milliseconds) // Cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
    while (clock() < time_end)
    {
    }
};
//string intel(string croix);

int main() {
    start:
    int choix, bot = 0, choix2, a;
    string a1 = "-", a2 = "-", a3 = "-", b1 = "-", b2 = "-", b3 = "-", c1 = "-", c2 = "-", c3 = "-", croix, restart, bott, res;
	cout << "-----------------------* MORPION *-----------------------" << endl;
	cout << "1 - IA" << endl;
	cout << "2 - 2 players" << endl;
	cout << "Choississez l'une des deux options : "; cin >> choix;
    system("cls");
    
    switch (choix)
    {
    case 1:
    ia:
        cout << "-----------------------* MORPION *-----------------------" << endl;
        cout << "1 - Easy" << endl;
        cout << "2 - Hard" << endl;
        cout << "Choississez l'une des deux options : "; cin >> choix2;

        cout << "En cour de lancement !" << endl;

        if (choix2 == 1 || choix2 != 2) {
            system("cls");
            cout << "-----------------------* MORPION *-----------------------" << endl;
            cout << "Mode : Easy" << endl;
            sleep(1000);
            for (int i = 1; i <= 15; i++) {
                system("cls");
                cout << "-----------------------* MORPION *-----------------------" << endl;
                cout << left << setw(5) << "" << left << setw(5) << "" << left << setw(5) << "A" << left << setw(5) << "B" << left << setw(5) << "C" << endl;
                cout << left << setw(5) << ""
                    << left << setw(5) << 1
                    << left << setw(5) << a1
                    << left << setw(5) << b1
                    << left << setw(5) << c1
                    << endl;
                cout << left << setw(5) << ""
                    << left << setw(5) << 2
                    << left << setw(5) << a2
                    << left << setw(5) << b2
                    << left << setw(5) << c2
                    << endl;
                cout << left << setw(5) << ""
                    << left << setw(5) << 3
                    << left << setw(5) << a3
                    << left << setw(5) << b3
                    << left << setw(5) << c3
                    << endl;
                afterP:
                cout << "Please enter a valid case. "; cin >> croix;
                if (croix == "A1" && a1 != "O") a1 = "X";
                else if (croix == "A2" && a2 != "O") a2 = "X";
                else if (croix == "A3" && a3 != "O") a3 = "X";
                else if (croix == "B1" && b1 != "O") b1 = "X";
                else if (croix == "B2" && b2 != "O") b2 = "X";
                else if (croix == "B3" && b3 != "O") b3 = "X";
                else if (croix == "C1" && c1 != "O") c1 = "X";
                else if (croix == "C2" && c2 != "O") c2 = "X";
                else if (croix == "C3" && c3 != "O") c3 = "X";
                else { goto afterP; }
                

                afterB:
                int bot = 1 + (rand() % 9);
                if (bot == 1 && a1 != "X") a1 = "O";
                else if (bot == 2 && a2 != "X") a2 = "O";
                else if (bot == 3 && a3 != "X") a3 = "O";
                else if (bot == 4 && b1 != "X") b1 = "O";
                else if (bot == 5 && b2 != "X") b2 = "O";
                else if (bot == 6 && b3 != "X") b3 = "O";
                else if (bot == 7 && c1 != "X") c1 = "O";
                else if (bot == 8 && c2 != "X") c2 = "O";
                else if (bot == 9 && c3 != "X") c3 = "O";
                else { goto afterB; }

                if (
                    /*horizontal*/
                    a1 + a2 + a3 == "XXX" ||
                    b1 + b2 + b3 == "XXX" || 
                    c1 + c2 + c3 == "XXX" ||
                    /*vertical*/
                    a1 + b1 + c1 == "XXX" ||
                    a2 + b2 + c2 == "XXX" ||
                    a3 + b3 + c3 == "XXX" ||
                    /*diagonal*/
                    a1 + b2 + c3 == "XXX" ||
                    a3 + b2 + c1 == "XXX"
                    ) {
                    system("cls");
                    cout << "-----------------------* MORPION *-----------------------" << endl;
                    cout << "You are a winner !" << endl;
                    cout << "Restart ? y/n : "; cin >> restart;
                    if (restart == "y") goto start;
                    cout << "" << endl;
                    break;
                }
                if (
                    /*horizontal*/
                    a1 + a2 + a3 == "OOO" ||
                    b1 + b2 + b3 == "OOO" ||
                    c1 + c2 + c3 == "OOO" ||
                    /*vertical*/
                    a1 + b1 + c1 == "OOO" ||
                    a2 + b2 + c2 == "OOO" ||
                    a3 + b3 + c3 == "OOO" ||
                    /*diagonal*/
                    a1 + b2 + c3 == "OOO" ||
                    a3 + b2 + c1 == "OOO"
                    ) {
                    system("cls");
                    cout << "-----------------------* MORPION *-----------------------" << endl;
                    cout << "GAME OVER !" << endl;
                    cout << "Restart ? y/n : "; cin >> restart;
                    if (restart == "y") goto start;
                    cout << "" << endl;
                    break;
                }
            };
            break;
        }

        cout << "-----------------------* MORPION *-----------------------" << endl;
        cout << "Mode : Hard" << endl;
        sleep(1000);
        
        for (int i = 1; i <= 15; i++) {
            system("cls");
            cout << "-----------------------* MORPION *-----------------------" << endl;
            cout << left << setw(5) << "" << left << setw(5) << "" << left << setw(5) << "A" << left << setw(5) << "B" << left << setw(5) << "C" << endl;
            cout << left << setw(5) << ""
                << left << setw(5) << 1
                << left << setw(5) << a1
                << left << setw(5) << b1
                << left << setw(5) << c1
                << endl;
            cout << left << setw(5) << ""
                << left << setw(5) << 2
                << left << setw(5) << a2
                << left << setw(5) << b2
                << left << setw(5) << c2
                << endl;
            cout << left << setw(5) << ""
                << left << setw(5) << 3
                << left << setw(5) << a3
                << left << setw(5) << b3
                << left << setw(5) << c3
                << endl;
        afterPP:
            cout << "Please enter a valid case. "; cin >> croix;
            if (croix == "A1" && a1 != "O") a1 = "X";
            else if (croix == "A2" && a2 != "O") a2 = "X";
            else if (croix == "A3" && a3 != "O") a3 = "X";
            else if (croix == "B1" && b1 != "O") b1 = "X";
            else if (croix == "B2" && b2 != "O") b2 = "X";
            else if (croix == "B3" && b3 != "O") b3 = "X";
            else if (croix == "C1" && c1 != "O") c1 = "X";
            else if (croix == "C2" && c2 != "O") c2 = "X";
            else if (croix == "C3" && c3 != "O") c3 = "X";
            else { goto afterPP; }


        afterBB:
            if (croix == "B2") {
                a = 1 + (rand() % 5);

                if (a == 1) {
                    res = "a1";
                }
                if (a == 2) {
                    res = "c1";
                }
                if (a == 3) {
                    res = "c2";
                }
                if (a == 4) {
                    res = "c3";
                }
                if (a == 5) {
                    res = "b3";
                }
            }
            else {

            }
            bott == res;
            if (bott == "a1" && a1 != "X") a1 = "O";
            else if (bott == "a2" && a2 != "X") a2 = "O";
            else if (bott == "a3" && a3 != "X") a3 = "O";
            else if (bott == "b1" && b1 != "X") b1 = "O";
            else if (bott == "b2" && b2 != "X") b2 = "O";
            else if (bott == "b3" && b3 != "X") b3 = "O";
            else if (bott == "c1" && c1 != "X") c1 = "O";
            else if (bott == "c2" && c2 != "X") c2 = "O";
            else if (bott == "c3" && c3 != "X") c3 = "O";
            else { goto afterBB; }

            if (
                /*horizontal*/
                a1 + a2 + a3 == "XXX" ||
                b1 + b2 + b3 == "XXX" ||
                c1 + c2 + c3 == "XXX" ||
                /*vertical*/
                a1 + b1 + c1 == "XXX" ||
                a2 + b2 + c2 == "XXX" ||
                a3 + b3 + c3 == "XXX" ||
                /*diagonal*/
                a1 + b2 + c3 == "XXX" ||
                a3 + b2 + c1 == "XXX"
                ) {
                system("cls");
                cout << "-----------------------* MORPION *-----------------------" << endl;
                cout << "You are a winner !" << endl;
                cout << "Restart ? y/n : "; cin >> restart;
                if (restart == "y") goto start;
                cout << "" << endl;
                break;
            }
            if (
                /*horizontal*/
                a1 + a2 + a3 == "OOO" ||
                b1 + b2 + b3 == "OOO" ||
                c1 + c2 + c3 == "OOO" ||
                /*vertical*/
                a1 + b1 + c1 == "OOO" ||
                a2 + b2 + c2 == "OOO" ||
                a3 + b3 + c3 == "OOO" ||
                /*diagonal*/
                a1 + b2 + c3 == "OOO" ||
                a3 + b2 + c1 == "OOO"
                ) {
                system("cls");
                cout << "-----------------------* MORPION *-----------------------" << endl;
                cout << "GAME OVER !" << endl;
                cout << "Restart ? y/n : "; cin >> restart;
                if (restart == "y") goto start;
                cout << "" << endl;
                break;
            }
        };

        cout << "" << endl;
        break;
    case 2:

        cout << "" << endl;
        break;
    default:
        goto ia;
        break;
    };



    return 0;
};
/*
string intel(string croix) {
    string result, a, res;
    if (croix == "B2") {
        a = 1 + (rand() % 5);

        if (a == "1") {
            res = "a1"; 
        }
        if (a == "2") {
            res = "c1";
        }
        if (a == "3") {
            res = "c2";
        }
        if (a == "4") {
            res = "c3";
        }
        if (a == "5") {
            res = "b3";
        }

    };
    result = res;
    return result;
}
*/
// int bot = 1 + (rand() % 9);
// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

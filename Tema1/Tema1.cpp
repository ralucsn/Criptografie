#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int baza1, baza2;
    string numarInit;
    vector <int> numarConv;



    cout << "Introduceti baza din care convertim: " << endl;
    cin >> baza1;
    while (baza1 < 2 || baza1>26) {
        cout << "Baza incorecta! Nu se afla intre 2 si 26!" << endl << "Introduceti o baza valida (intre 2 si 26): " << endl;
        cin >> baza1;
    }



    cout << "Introduceti baza in care vom converti: " << endl;
    cin >> baza2;
    while (baza1 < 2 || baza1>26) {
        cout << "Baza incorecta! Nu se afla intre 2 si 26!" << endl << "Introduceti o baza valida (intre 2 si 26): " << endl;
        cin >> baza1;
    }



    cout << "Introduceti numarul de convertit: " << endl;
    cin >> numarInit;
    if (baza1 == baza2) {
        cout << "Numarul convertit este egal cu cel initial!";
        return 0;
    }



    //verificam daca avem caractere de tip A-Z sau a-z
    numarConv.resize(numarInit.size());
    for (int i = 0; i < numarInit.size(); i++) {
        if ('0' <= numarInit[i] && numarInit[i] <= '9') {
            numarConv[i] = numarInit[i] - '0';
        }
        else if ('A' <= numarInit[i] && numarInit[i] <= 'Z') {
            numarConv[i] = numarInit[i] - 'A' + 10;
        }
        else if ('a' <= numarInit[i] && numarInit[i] <= 'z') {
            numarConv[i] = numarInit[i] - 'a' + 10;
        }
    }


    // transformam numarul in baza 10
    int produs = 1;
    int numarDec = 0;
    for (int i = numarConv.size() - 1; i >= 0; i--) {
        numarDec = produs * numarConv[i] + numarDec;
        produs = produs * baza1;
    }

    // transformam numarul din baza 10 in baza in care vrem sa il convertim
    vector <int> numarTradus;
    while (numarDec != 0) {
        int rest = numarDec % baza2;
        numarDec = numarDec / baza2;
        numarTradus.push_back(rest);  //stocam valorile numarului in oglinda
    }

    cout << "Numarul convertit din baza ";
    cout << baza1;
    cout << " in baza ";
    cout << baza2;
    cout << " este: " << endl;


    //afisam numarul in mod corect
    for (int i = numarTradus.size() - 1;i >= 0;i--) {
        if (0 <= numarTradus[i] && numarTradus[i] <= 9) {
            cout << numarTradus[i];
        }
        else
            cout << char(numarTradus[i] + 'A' - 10);
    }


    return 0;
}

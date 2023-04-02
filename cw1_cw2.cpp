#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// Cwiczenie 1 Liczenie znakow w tekscie
int liczenieznakow() {
    ifstream dokument;
    int licznik = 0;
    char znak;

    licznik = 0;
    dokument.open("/Users/perlowo/CLionProjects/untitled4/cw1.txt");
    while (!dokument.eof()) {
        dokument.get(znak);
        licznik++;
    }
    dokument.close();
    cout << "Liczba znakow w pliku wynosi " << licznik << endl;

    return 0;
}

// Cwiczenie 2 Analizator leksykalny

const int maxk = 100;

enum symbol {
    identyfikator, liczba, mr, wr, stajesie
};

// Struktura reprezentująca identyfikator
struct id {
    int k;
    char a[maxk];
};

// Globalne zmienne przechowujace aktualnie czytany symbol
symbol sym;
int licz;
id id_obj;

// Funkcja pomijajaca spacje w wejsciu
void skip_spaces() {
    char zn;
    cin >> zn;
    while (zn == ' ') cin >> zn;
    cin.putback(zn);
}

// Funkcja analizująca wejście
void analizaleksykalna() {
    char zn, zn1;
    skip_spaces();

    if (isalpha(cin.peek())) {
        id_obj.k = 0;
        while (isalnum(cin.peek())) {
            zn = cin.get();
            if (id_obj.k < maxk) {
                id_obj.a[id_obj.k] = zn;
                id_obj.k++;
            }
        }

        sym = identyfikator;
    } else if (isdigit(cin.peek())) {
        licz = 0;
        while (isdigit(cin.peek())) {
            licz = 10 * licz + (cin.get() - '0');
        }

        sym = liczba;
    } else if (cin.peek() == '<' || cin.peek() == ':' || cin.peek() == '>') {
        zn1 = cin.get();
        zn = cin.peek();
        if (zn == '=') {
            cin.get();
            if (zn1 == '<') {
                sym = mr;
            } else if (zn1 == '>') {
                sym = wr;
            } else {
                sym = stajesie;
            }
        } else {
            sym = symbol(zn1);
        }
    } else {
        sym = symbol(cin.get());
    }
}

// Funkcja przetwarzajaca symbole wejsciowe
void wejscie_analizator_leksykalny() {
    cout << "Analizator leksykalny: ";
    while (!cin.eof()) {
        analizaleksykalna();
        switch (sym) {
            case identyfikator:
                cout << "Identyfikator: ";
                for (int i = 0; i < id_obj.k; i++) {
                    cout << id_obj.a[i];
                }
                cout << endl;
                break;
            case liczba:
                cout << "Liczba: " << licz << endl;
                break;
            case mr:
                cout << "Symbol: <=" << endl;
                break;
            case wr:
                cout << "Symbol: >=" << endl;
                break;
            case stajesie:
                cout << "Symbol: " << id_obj.a[0] << endl;
                break;
        }
    }
}

int main() {
    liczenieznakow();
    wejscie_analizator_leksykalny();
    return 0;
}

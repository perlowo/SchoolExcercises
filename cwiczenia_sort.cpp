#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

// Sortowanie przez proste wybieranie
void pw(int a[], int n) {
    int i, j, k, x;
    for (i = 0; i < n - 1; i++) {
        k = i;
        x = a[i];
        for (j = i + 1; j < n; j++) {
            if (a[j] < x) {
                k = j;
                x = a[j];
            }
        }
        a[k] = a[i];
        a[i] = x;
    }
}

// Sortowanie przez wstawianie połówkowe
void wsp(int a[], int n) {
    int i, j, q, p, m, x;
    for (i = 1; i < n; i++) {
        x = a[i];
        q = 0;
        p = i - 1;
        while (q <= p) {
            m = (q + p) / 2;
            if (x < a[m]) {
                p = m - 1;
            } else {
                q = m + 1;
            }
        }
        for (j = i - 1; j >= q; j--) {
            a[j + 1] = a[j];
        }
        a[q] = x;
    }
}

// Sortowanie przez proste wstawianie
void prostew(int a[], int n) {
    int i, j, x;
    for (i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;
        while (j >= 0 && x < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

// Sortowanie bąbelkowe
void sb(int a[], int n) {
    int i, j, x;
    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            if (a[j - 1] > a[j]) {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
            }
        }
    }
}

// Sortowanie mieszane
void sm(int a[], int n) {
    int i, j, k, p, q, x;
    p = n;
    q = 2;
    while (q <= p) {
        for (j = p; j >= q; j--) {
            if (a[j - 1] > a[j]) {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
            }
        }
        q = k + 1;
        for (j = q; j <= p; j++) {
            if (a[j - 1] > a[j]) {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
            }
        }
        p = k - 1;
    }
}

// Sortowanie metodą Shella
void shellsort(int a[], int n) {
    const int t = 4;
    int h[t] = { 9, 5, 3, 1 };
    for (int m = 0; m < t; m++) {
        int k = h[m];
        for (int i = k; i < n; i++) {
            int j = i;
            int temp = a[i];
            while (j >= k && a[j - k] > temp) {
                a[j] = a[j - k];
                j -= k;
            }
            a[j] = temp;
        }
    }
}

int main() {
    srand(time(NULL)); // Inicjalizacja generatora liczb pseudolosowych
    const int n = 1000; // Rozmiar tablicy
    int tab[n]; // Tablica losowych liczb całkowitych
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % 1000 + 1; // Losowanie liczby z przedziału [1, 1000]
    }

// Pomiar czasu sortowania przez proste wybieranie
    auto start = chrono::steady_clock::now(); // Początek pomiaru czasu
    pw(tab, n);
    auto end = chrono::steady_clock::now(); // Koniec pomiaru czasu
    auto diff = end - start;
    cout << "Sortowanie przez proste wybieranie: " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

// Pomiar czasu sortowania przez wstawianie połówkowe
    start = chrono::steady_clock::now();
    wsp(tab, n);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "Sortowanie przez wstawianie połówkowe: " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

// Pomiar czasu sortowania przez proste wstawianie
    start = chrono::steady_clock::now();
    prostew(tab, n);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "Sortowanie przez proste wstawianie: " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

// Pomiar czasu sortowania bąbelkowego
    start = chrono::steady_clock::now();
    sb(tab, n);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "Sortowanie bąbelkowe: " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

// Pomiar czasu sortowania mieszane
    start = chrono::steady_clock::now();
    sm(tab, n);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "Sortowanie mieszane: " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

// Pomiar czasu sortowania metodą Shella
    start = chrono::steady_clock::now();
    shellsort(tab, n);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "Sortowanie metodą Shella: " << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    return 0;

}
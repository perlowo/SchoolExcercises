//
// Created by Wiktor Dudzinski on 16/04/2023.
//

struct Obiekt {
    int klucz;
};

void sortuj(int q, int p, Obiekt a[]) {
    int i = q, j = p;
    Obiekt x = a[(q + p) / 2];
    do {
        while (a[i].klucz < x.klucz) {
            i = i + 1;
        }
        while (x.klucz < a[j].klucz) {
            j = j - 1;
        }
        if (i <= j) {
            Obiekt w = a[i];
            a[i] = a[j];
            a[j] = w;
            i = i + 1;
            j = j - 1;
        }
    } while (i <= j);
    if (q < j) {
        sortuj(q, j, a);
    }
    if (i < p) {
        sortuj(i, p, a);
    }
}

void sortowanieSzybkie(int n, Obiekt a[]) {
    sortuj(0, n - 1, a);
}

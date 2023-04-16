//
// Created by Wiktor Dudzinski on 16/04/2023.
//
// sortowanie szybkie iteracyjnie

struct Obiekt {
    int klucz;
    // add other vars
};

void ss(int n, Obiekt a[], const int m) {
    int i, j, l, p, s = 1;
    Obiekt x, w;
    struct {
        int l, p;
    } stos[m];
    stos[1].l = 0;
    stos[1].p = n - 1;
    do {
        l = stos[s].l;
        p = stos[s].p;
        s = s - 1;
        do {
            i = l;
            j = p;
            x = a[(l + p) / 2];
            do {
                while (a[i].klucz < x.klucz) {
                    i = i + 1;
                }
                while (x.klucz < a[j].klucz) {
                    j = j - 1;
                }
                if (i <= j) {
                    w = a[i];
                    a[i] = a[j];
                    a[j] = w;
                    i = i + 1;
                    j = j - 1;
                }
            } while (i <= j);
            if (i < p) {
                s = s + 1;
                stos[s].l = i;
                stos[s].p = p;
            }
            p = j;
        } while (l < p);
    } while (s > 0);
}

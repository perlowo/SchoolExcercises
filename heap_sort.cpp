//
// Created by Wiktor Dudzinski on 16/04/2023.
//
// sortowanie stogowe

struct Obiekt {
    int klucz;
    //add vars
};

void przesiewanie(int q, int p, Obiekt a[]) {
    int i = q, j = 2 * i;
    Obiekt x = a[i];
    while (j <= p) {
        if (j < p && a[j].klucz < a[j+1].klucz) {
            j = j + 1;
        }
        if (x.klucz >= a[j].klucz) {
            goto label_13;
        }
        a[i] = a[j];
        i = j;
        j = 2 * i;
    }
    label_13:
    a[i] = x;
}

void sortowanieStogowe(int n, Obiekt a[]) {
    int q = n / 2 + 1, p = n;
    while (q > 1) {
        q = q - 1;
        przesiewanie(q, p, a);
    }
    while (p > 1) {
        Obiekt x = a[1];
        a[1] = a[p];
        a[p] = x;
        p = p - 1;
        przesiewanie(1, p, a);
    }
}

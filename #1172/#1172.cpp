int numarare(nod* p) {
    int c = 0;
    nod* curent = p;
    while (curent != nullptr) {
        c++;
        curent = curent->urm;
    }

    return c;
}
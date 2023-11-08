void adaugare(nod*& p, int x) {
    nod* nouNod = new nod;
    nouNod->info = x;
    nouNod->urm = nullptr;

    if (p == nullptr) {
        p = nouNod;
    }
    else {
        nod* curent = p;
        while (curent->urm != nullptr) {
            curent = curent->urm;
        }
        curent->urm = nouNod;
    }
}
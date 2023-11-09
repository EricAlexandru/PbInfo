void sterge(nod * & p, nod * q){
    nod* curent = p;
    if(curent == q){
        p = p->urm;
        delete curent;
    }
    while(curent != nullptr){
        if(curent->urm == q){
            nod* t = curent->urm;
            curent->urm = t->urm;
            delete t;
        }
        curent = curent->urm;
    }
}
void stergePrimul(nod*& p) {
	nod* t = p;
	p = p->urm;
	delete t;
}
void adaugareInainte(nod*& p, int x) {
	nod* nouNod = new nod;
	nouNod->info = x;
	nouNod->urm = p;
	p = nouNod;
}
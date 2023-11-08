void afisare(nod* p) {
	nod* curent = p;
	while (curent != nullptr) {
		cout << curent->info << ' ';
		curent = curent->urm;
	}
}
void LsiAdd(Nod*& head, int val, int x, int y){
    Nod* curent = head;
    Nod* prev = nullptr;

    while (curent != nullptr && curent->info != val)
    {
        prev = curent;
        curent = curent->leg;
    }

    if (curent != nullptr){
        Nod* nodNouX = new Nod;
        nodNouX->info = x;
        nodNouX->leg = curent;

        if (prev == nullptr){
            head = nodNouX;
        }
        else{
            prev->leg = nodNouX;
        }

        Nod* nodNouY = new Nod;
        nodNouY->info = y;
        nodNouY->leg = curent->leg;

        curent->leg = nodNouY;
    }
}
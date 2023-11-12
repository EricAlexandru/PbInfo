void FAdaugaInainte(Nod *&head)
{
    Nod *curent = head;
    while (curent != nullptr){
        if (curent->info % 2 != 0){
            Nod* nodNou = new Nod;
            nodNou->info = 2 * curent->info;
            nodNou->leg = curent;
            if (curent == head){
                head = nodNou;
            }
            else{
                Nod* prev = head;
                while (prev->leg != curent)
                {
                    prev = prev->leg;
                }
                prev->leg = nodNou;
            }
        }
        curent = curent->leg;
    }
}
#include <fstream>
using namespace std;

ifstream fisier_intrare("lantmaxim1.in");
ofstream fisier_iesire("lantmaxim1.out");

const int MAX_N = 25;
const int MAX_M = 200;

int matrice_adiacenta[MAX_N][MAX_N];
int cale[MAX_N], n, m, destinatie, lungime_curenta, lungime_maxima, vizitat[MAX_N];
int cale_curenta[MAX_N]; 


void copiazaCalea(int lungime) {
    for (int i = 1; i <= lungime; i++) {
        cale[i] = cale_curenta[i];
    }
}

void dfs(int pozitie, int nod_anterior) {
    for (int i = 1; i <= n; i++) {
        if (matrice_adiacenta[nod_anterior][i] == 1 && !vizitat[i]) {
            vizitat[i] = 1;
            cale_curenta[pozitie] = i;
            if (i == destinatie && pozitie > lungime_maxima) {
                copiazaCalea(pozitie);
                lungime_maxima = pozitie;
            } else {
                dfs(pozitie + 1, i);
            }
            vizitat[i] = 0;
        }
    }
}

int main() {
    fisier_intrare >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        fisier_intrare >> x >> y;
        matrice_adiacenta[x][y] = matrice_adiacenta[y][x] = 1;
    }
    fisier_intrare >> destinatie;

    for (int i = 1; i <= n; i++) {
        matrice_adiacenta[0][i] = 1;
    }
    matrice_adiacenta[0][destinatie] = 0;

    cale_curenta[0] = 0;
    lungime_maxima = 0;

    dfs(1, 0);

    for (int i = 1; i <= lungime_maxima; i++) {
        fisier_iesire << cale[i] << ' ';
    }

    return 0;
}

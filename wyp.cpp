#include <iostream>
#include <vector>

using namespace std;

struct prendkosc {
    double v;
    int x;
    int d;
};

struct ciong {
    int i;
    double v;
    double przeciecie; 
    int x;
};

int wcisnij_auto(vector<ciong> &ciag, vector<int> &dlugosci, prendkosc samochud, int index) {
    for(int i = 0; i < ciag.size(); i++) {
        int d = dlugosci[ciag[i].i] - dlugosci[index];
        double przeciecie_x = (ciag[i].x - d - samochud.x) / (samochud.v - ciag[i].v);
        if(przeciecie_x >= ciag[i].przeciecie) {
            return i;
        }
    }
    return -1;
}

vector<ciong> wcisnij_tira(vector<ciong> &ciag, vector<int> &dlugosci, int index, prendkosc tir1, prendkosc tir2) {
    double tiry_przeciecie;
    vector<ciong> kopia;

    for(int i = 0; i < ciag.size(); i++){
        auto c = ciag[i];
        int d = dlugosci[c.i] - dlugosci[index];
        tiry_przeciecie = (tir2.x - (c.x - d)) / (c.v - tir2.v);
        if(tiry_przeciecie < 0) break;
        kopia.push_back(c);
        if(tiry_przeciecie < c.przeciecie) {
            continue;
        } else {
            kopia[i].przeciecie = tiry_przeciecie;
            return kopia;
        }
    }
    tiry_przeciecie = (tir2.x - (tir1.x - tir1.d)) / (tir1.v - tir2.v);
    if(tiry_przeciecie >= 0) {
        if(tiry_przeciecie != 0 || (tiry_przeciecie == 0 && tir1.v <= tir2.v)){
            kopia.push_back(ciong{
                .i = index + 1,
                .v = tir1.v,
                .przeciecie = tiry_przeciecie,
                .x = tir1.x,
            });
        }
    }
    return kopia;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double W, M, w, m, v;
    int n, D;
    int x, d;
    prendkosc samochud;
    vector<ciong> ciag;
    vector<prendkosc> ciezarowki;
    vector<int> dlugosci;

    cin >> n >> D >> W >> M;
    samochud.v = W/M;
    samochud.d = D;
    samochud.x = 0;
    int odp = 1;

    cin >> x >> d >> w >> m;
    ciezarowki.push_back(prendkosc{
        .v = w/m,
        .x = x,
        .d = d,
    });
    dlugosci.push_back(d);

    for(int i = 1; i < n; i++) {
        cin >> x >> d >> w >> m;
        ciezarowki.push_back(prendkosc{
            .v = w/m,
            .x = x,
            .d = d,
        });
        dlugosci.push_back(d + dlugosci[i - 1]);
    }
    
    
     for(int i = n - 2; i >= 0; i--) {
        double przeciecie_przednia_x;
        prendkosc przednia = ciezarowki[i + 1];
        prendkosc tylnia = ciezarowki[i];
        
        v = przednia.v;
        x = przednia.x;
        d = przednia.d;

        int v_index = wcisnij_auto(ciag, dlugosci, samochud, i);        
        if(v_index != -1) {
            v = ciag[v_index].v;
            x = ciag[v_index].x;
            d = dlugosci[ciag[v_index].i] - dlugosci[i];
        }
        
        przeciecie_przednia_x = (x - d - samochud.x) / (samochud.v - v);
        double przeciecie_tylnia = (tylnia.x - (samochud.x - samochud.d)) / (samochud.v - tylnia.v);

        double przednia_y = v * przeciecie_przednia_x + (x - d);                            // a1 * x + (x1 - d1)
        double tylnia_y = tylnia.v * przeciecie_przednia_x  + tylnia.x;                     // a2 * x + x2

        double lot = przednia_y - samochud.d; 
        if(przeciecie_tylnia > przeciecie_przednia_x) {
        // if(lot < tylnia_y) {
            ciag = wcisnij_tira(ciag, dlugosci, i, przednia, tylnia);
        } else {
            odp++;
            ciag.clear();
        }
    }

    cout << odp;
    return 0;
}
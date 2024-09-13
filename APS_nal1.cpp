#include <iostream>

using namespace std;

struct sklad {
    int *S;
    int max;
    int vrh;
};

struct krozna_vrsta {
    int *Q;
    int max;
    int rep;
    int glava;
};

void PUSH(sklad &s, int vrednost) {
    if (s.vrh == s.max - 1) {
        cout << "napaka: POLNO" << endl;
    } else {
        s.vrh += 1;
        s.S[s.vrh] = vrednost;
    }
}

void POP(sklad &s) {
    if (s.vrh == -1) {
        cout << "napaka: SKLAD JE PRAZEN" << endl;
    } else {
        s.vrh -= 1;
        cout << "Podatek shranjen v vrhu sklada: " << s.S[s.vrh + 1] << endl;
    }
}

void VPISI(krozna_vrsta &q, int vrednost) {
    int nov_rep;
    nov_rep = q.rep + 1;
    if (nov_rep >= q.max) {
        nov_rep = 0;
    }
    if (q.glava == nov_rep) {
        cout << "napaka: POLNO" << endl;
    } else {
        q.Q[q.rep] = vrednost;
        q.rep = nov_rep;
    }
}

void BERI(krozna_vrsta &q) {
    int vrednost;
    if (q.glava == q.rep) {
        cout << "napaka: PRAZNO" << endl;
    } else {
        vrednost = q.Q[q.glava];
        q.glava += 1;
        if (q.glava >= q.max) {
            q.glava = 0;
        }
        cout << "VREDNOST V GLAVI: " << vrednost << endl;
    }
}

int main() {
    cout << "vnesite velikost sklada ali krozne vrste: " << endl;
    int max;
    cin >> max;

    sklad s{};
    s.max = max;
    s.vrh = -1;
    s.S = new int[s.max];

    krozna_vrsta q{};
    q.max = max;
    q.rep = 0;
    q.glava = 0;
    q.Q = new int[q.max];

    while (true) {
        cout << endl;
        cout << "Sklad izbira:" << endl;
        cout << "1. vnos podatka" << endl;
        cout << "2. Branje in izpis podatka" << endl;
        cout << "3. Izpis vsebine sklada" << endl << endl;
        cout << "Krozna vrsta izbira:" << endl;
        cout << "4. Vnos podatka" << endl;
        cout << "5. Branje podatka in izpis" << endl;
        cout << "6. Izpis polja Q" << endl;
        cout << "7. Izpis vrste od glave do repa" << endl << endl;
        cout << "8. Konec" << endl << endl;

        int izbira;
        cout << "vnesite steviko menija: " << endl;
        cin >> izbira;

        if (izbira == 1) {
            int x;
            cout << "doloci vrednost za vstavitev (int): ";
            cin >> x;

            PUSH(s, x);

        } else if (izbira == 2) {
            POP(s);

        } else if (izbira == 3) {
            cout << "izpis sklada do vrha: ";
            cout << "SKLAD[ ";
            for (int i = 0; i <= s.vrh; ++i) {
                cout << s.S[i] << " ";
            }
            cout << "]";
            cout << endl << endl;

        } else if (izbira == 4) {
            int y;
            cout << "doloci vrednost za vstavitev (int): ";
            cin >> y;

            VPISI(q, y);

        } else if (izbira == 5) {
            BERI(q);

        } else if (izbira == 6) {
            cout << "POLJE Q: [ ";
            for (int i = 0; i < q.max; ++i) {
                cout << q.Q[i] << " ";
            }
            cout << "]" << endl;
            cout << "GLAVA: " << q.glava << endl;
            cout << "REP: " << q.rep << endl;

        } else if (izbira == 7) {
            cout << "KROZNA VRSTA Q: [ ";
            int stevec = 0;
            int trenutni = q.glava;
            if (q.glava == q.rep) {
                cout << "";
            } else {
                while (stevec < q.max) {
                    cout << q.Q[trenutni] << " ";
                    trenutni = (trenutni + 1) % q.max;
                    stevec++;
                    if (trenutni == q.rep)
                        break;
                }
            }
            cout << "]" << endl;
            cout << "GLAVA: " << q.glava << endl;
            cout << "REP: " << q.rep << endl;

        } else if (izbira == 8) {
            break;
        }
    }

    delete[] s.S;
    delete[] q.Q;

    return 0;
}

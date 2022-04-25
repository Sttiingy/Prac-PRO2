#include "Album.h"

using namespace std;

Album::Album() {
    string idalb;
    ID = idalb;
    set<Fotografia> albuset;
    alb = albuset;
}

void Album::modifica_id(string id) {
    this->ID = id;
}

string Album::id_album() const{
    return ID;
}

bool Album::operator<(const Album &alb) const {
    if(ID != alb.id_album()) return ID < alb.id_album();
} 

bool Album::contiene_foto(const string& id_foto) {
    set<Fotografia>::iterator it = alb.begin();
    while(it != alb.end()) {
        Fotografia x = *it;
        if(x.id_foto() == id_foto) return true;
        ++it;
    }
    return false;
}

void Album::agrega_foto(Fotografia& f) {
    alb.insert(f);
}

void Album::lee_album(string id_album) {
    this ->ID = id_album;
    int num_f;
    cin >> num_f;
    for(int i = 0; i < num_f; ++i) {
        Fotografia f;
        int dia, mes, any;
        string id_foto;
        cin >> id_foto >> dia >> mes >> any;
        Fecha d;
        d.leer_fecha(dia, mes, any);
        f.crea_foto(id_foto, d);
        alb.insert(f);
    }
}

void Album::elimina_foto(const string& iden) {
    set<Fotografia>:: iterator it = alb.begin();
    while(it != alb.end()) {
        Fotografia x = *it;
        if(x.id_foto() == iden) {
            alb.erase(it);
            it = alb.end();
        }
        else ++it;
    }
}

void Album::obten_foto(const string& iden, bool& b) {
    set<Fotografia>::iterator it = alb.begin();
    while(it != alb.end() and not b) {
        Fotografia x = *it;
        if(x.id_foto() == iden) {
            x.imprime_foto();
            b = true;
        }
        else ++it;
    }
}

int Album::nr_fotos() {
    return alb.size();
}

set<Fotografia> Album::obten_set() {
    return alb;
}

void Album::imprime_album() {
    cout << ID << endl;
    set<Fotografia>::iterator it = alb.begin();
    while(it != alb.end()) {
        Fotografia x = *it;
        cout << "  ";
        x.imprime_foto();
        ++it;
    }
}

void Album::modifica_foto(Fotografia& f) {
    set<Fotografia>::iterator it = alb.begin();
    bool found = false;
    while(it != alb.end() and not found) {
        Fotografia x = *it;
        if(x.id_foto() == f.id_foto()) {
            found = true;
            alb.insert(it, f);
            alb.erase(it);
        }
        else ++it;
    }
}

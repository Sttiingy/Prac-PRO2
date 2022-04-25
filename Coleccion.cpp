#include "../Coleccion.h"

using namespace std;

Coleccion::Coleccion() {
    set<Album> colection_buida;
    colec = colection_buida;
    Album ALL_buit;
    ALL = ALL_buit;
    string id = "ALL";
    ALL.modifica_id(id);
}

bool Coleccion::contiene_album(const string& id_album) {
    if(id_album == "ALL") return true;
    set<Album>::iterator it = colec.begin();
    while(it != colec.end()) {
        Album x = *it;
        if(x.id_album() == id_album) return true;
        ++it;
    }
    return false;
}
void Coleccion::agrega_album(Album& al) {
    if(al.id_album() != "ALL") {
        set<Fotografia> aux = al.obten_set();
        set<Fotografia>::iterator it = aux.begin();
        while(it != aux.end()) {
            Fotografia x = *it;
            if(not ALL.contiene_foto(x.id_foto())) {
                ALL.agrega_foto(x);
            }
            else {
                set<Fotografia> aux2 = ALL.obten_set();
                set<Fotografia>::iterator it2 = aux2.begin();
                while(it2 != aux2.end()) {
                    Fotografia a = *it2;
                    if(a.id_foto() == x.id_foto()) al.modifica_foto(a);
                    ++it2;
                }
            }
            ++it;
        }
    cout << "Album en curso agregado a la coleccion." << endl;
    cout << "Album en curso, despues de agregar:" << endl;
    al.imprime_album();
    colec.insert(al);
    }
    else cout << "Identificador de album incorrecto. No se puede agregar." << endl;
}

void Coleccion::elimina_album(const string& id_album) {
    bool found = false;
    if(id_album != "ALL") {
        set<Album>::iterator it = colec.begin();
        while(it != colec.end()) {
            Album x = *it;
            if(x.id_album() == id_album) {
                colec.erase(it);
                it = colec.end();
            }
            else ++it;
        }
        cout << "Album eliminado de la coleccion." << endl;
    }
    else cout << "Identificador de album incorrecto. No se pudo eliminar" << endl;
}

Album Coleccion::obten_album(const string& id_album) {
    set<Album>::iterator it = colec.begin();
        while(it != colec.end()) {
            Album x = *it;
            if(x.id_album() == id_album) {
                return x;
            }
            else ++it;
        }
}

int Coleccion::nr_albumes() {
    return colec.size() + 1;
}

void Coleccion::lista_albumes() {
    set<Album>::iterator it = colec.begin();
    cout << "ALL";
    while(it != colec.end()) {
        Album x = *it;
        cout << ' ' << x.id_album();
        ++it;
    }
    cout << endl;
}

void Coleccion::agrega_foto_coleccion(Fotografia& f) {
    if(ALL.contiene_foto(f.id_foto())) cout << "Ya existe una foto con el mismo id. No se puede agregar." << endl;
    else {
        ALL.agrega_foto(f);
        cout << "Foto " << f.id_foto() << " agregada a la coleccion." << endl;
    }
}

void Coleccion::elimina_foto_coleccion(const string& id_foto) {
    if(ALL.contiene_foto(id_foto)) {
        ALL.elimina_foto(id_foto);
        set<Album>::iterator it = colec.begin();
        while(it != colec.end()) {
            Album x = *it;
            if(x.contiene_foto(id_foto)) {
                x.elimina_foto(id_foto);
                colec.erase(it);
                colec.insert(x);
            }
            else ++it;
        }
        cout << "Foto " << id_foto << " eliminada de la coleccion." << endl;
    }
    else cout << "No existe una foto con el id dado. No se puede eliminar." << endl;
}

void Coleccion::modifica_foto_coleccion(const string& id_mod, Fotografia& res) {
    if(ALL.contiene_foto(id_mod)) {
        ALL.modifica_foto(res); //No es una crida recursiva, es una altre funcio pertenyent a la classe album.
        set<Album>::iterator it = colec.begin();
        while(it != colec.end()) {
            Album x = *it;
            if(x.contiene_foto(id_mod)) {
                x.modifica_foto(res);
                colec.erase(it);
                colec.insert(x);
            }
            ++it;
        }
        cout << "Foto " << id_mod << " modificada en la coleccion." << endl;
    }
    else cout << "No existe una foto con el id dado. No se puede modificar." << endl;
}

void Coleccion::albumes_foto(const string& id_foto) {
    set<Album>::iterator it = colec.begin();
    bool first = true;
    if(ALL.contiene_foto(id_foto)) {
        cout << "ALL";
        while(it != colec.end()) {
            Album x = *it;
            if(x.contiene_foto(id_foto)) {
                cout << ' ' << x.id_album();
            }
            ++it;
        }
    }
    else cout << "No existe una foto con el id dado.";
    cout << endl;
}

void Coleccion::imprime_coleccion() {
    ALL.imprime_album();
    set<Album>::iterator it = colec.begin();
    while(it != colec.end()) {
        Album x = *it;
        x.imprime_album();
        ++it;
    }
}

Album Coleccion::busca_por_fecha(const Fecha& a, const Fecha& b, const string& id_album, const string& id_album_res) {
    Album res;
    res.modifica_id(id_album_res);
    set<Fotografia> aux;
    if(id_album == "ALL"){
        aux = ALL.obten_set();
        set<Fotografia>::iterator it2 = aux.begin();
        while(it2 != aux.end()) {
            Fotografia y = *it2;
            Fecha d = y.fecha_toma();
            if(d.fecha_valida(a, b)) {
                res.agrega_foto(y);
            }
            ++it2;
        
        }
    }
    else {
        set<Album>::iterator it = colec.begin();
        while(it != colec.end()) {
            Album x = *it;
            if(x.id_album() == id_album) {
                aux = x.obten_set();
                it = colec.end();
            }
            ++it;
        }
        set<Fotografia>::iterator it3 = aux.begin();
        while(it3 != aux.end()) {
            Fotografia y = *it3;
            Fecha d = y.fecha_toma();
            d.imprimir_fecha();
            if(d.fecha_valida(a, b)) {
                res.agrega_foto(y);
            }
            ++it3;
        }
    }
    return res;
}

Album Coleccion::busca_por_etiqueta(const string& et, const string& id_album, const string& id_album_res) {
    Album res;
    res.modifica_id(id_album_res);
    set<Fotografia> aux;
    if(id_album == "ALL"){
        aux = ALL.obten_set();
        set<Fotografia>::iterator it2 = aux.begin();
        while(it2 != aux.end()) {
            Fotografia y = *it2;
            if(y.contiene_etiqueta(et)) {
                res.agrega_foto(y);
            }
            ++it2;
        }
    }
    else {
        set<Album>::iterator it = colec.begin();
        while(it != colec.end()) {
            Album x = *it;
            if(x.id_album() == id_album) {
                aux = x.obten_set();
                it = colec.end();
                cout << "cumplido" << endl;
            }
            ++it;
        }
        set<Fotografia>::iterator it2 = aux.begin();
        while(it2 != aux.end()) {
            Fotografia f = *it2;
            if(f.contiene_etiqueta(et)) res.agrega_foto(f);
            ++it2;
        }
    }
    return res;
}

#include "Fotografia.hh"

using namespace std;

Fotografia::Fotografia() {
    string ID_F;
    id = ID_F;
    Fecha DAta;
    f = DAta;
    Netq = 0;
    set<string> etiquet;
    etiquetas = etiquet;
}

string Fotografia::id_foto() const{
    return id;
}

bool Fotografia::operator<(const Fotografia &fot) const {
    if(id != fot.id_foto()) return id < fot.id_foto();
}    

void Fotografia::agrega_etiqueta(const string& t) {
    etiquetas.insert(t);
}

void Fotografia::crea_foto(const string& i, const Fecha& d) {
    this->id = i;
    f = d;
    int n_et;
    cin >> n_et;
    Netq = n_et;
    for(int j = 0; j < n_et; ++j) {
        string t;
        cin >> t;
        etiquetas.insert(t);
    }
}

void Fotografia::imprime_foto() {
    cout << id << ' ';
    f.imprimir_fecha();
    cout << Netq;
    set<string>::iterator it = etiquetas.begin();
    bool first = true;
    if(Netq > 0) cout << ' ';
    while(it != etiquetas.end()) {
        string x = *it;
        if(first) {
            cout << x;
            first = false;
        }
        else cout << ' ' << x;
        ++it;
    }
    cout << endl;
}

Fecha Fotografia::fecha_toma() {
    return f;
}

bool Fotografia::contiene_etiqueta(const string& et) {
    if(etiquetas.find(et) != etiquetas.end()) return true;
    else return false;
}

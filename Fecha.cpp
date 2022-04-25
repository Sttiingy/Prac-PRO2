#include "Fecha.hh" 

using namespace std;

Fecha::Fecha() {
    dia = 0;
    mes = 0;
    any = 0;
}

void Fecha::leer_fecha(const int& d, const int& m, const int& a) {
    this ->dia = d;
    this ->mes = m;
    this ->any = a;
}

void Fecha::imprimir_fecha() {
    cout << dia << '/' << mes << '/' << any << ' ';
}

bool Fecha::fecha_valida(const Fecha& a, const Fecha& b) {
    if(a.any == b.any) {
        if(a.mes == b.mes) {
            if(a.dia == b.dia) {
                if(a.dia == dia and a.mes == mes and a.any == any)return true;
                else return false;
            }
            else if(a.dia <= dia and dia <= b.dia) return true;
        }
        else if (a.mes <= mes and mes <= b.mes) return true;
    }
    else if(a.any <= any and any <= b.any) return true;
    return false;
}

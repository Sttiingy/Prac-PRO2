#include <iostream>
#include <vector>
#include "coleccion.h"

using namespace std;

int main () {
    string orden;
    Album album_en_curso;
    Coleccion col;
    while(cin >> orden && orden != "acabar") {
        if(orden == "lee_album") { /*1 done*/
            string id_album;
            cin >> id_album;
            cout << "# lee_album " << id_album << " ..." << endl;
            Album al;
            al.lee_album(id_album);
            album_en_curso = al;
            cout << "Album " << id_album << " leido." << endl;
        }
        else if(orden == "agrega_foto") {  /*2 done*/ 
            string id_foto;
            cin >> id_foto;
            int dia, mes, any;
            cin >> dia >> mes >> any;
            Fecha d;
            d.leer_fecha(dia, mes, any);
            Fotografia f;
            f.crea_foto(id_foto, d);
            cout << "# agrega_foto " << f.id_foto() << " ..." << endl;
            if(not album_en_curso.contiene_foto(id_foto)) {
                album_en_curso.agrega_foto(f);
                cout << "Foto " << f.id_foto() << " agregada al album en curso." << endl;
            }
            else cout << "El album en curso ya contiene una foto con el identificador " << f.id_foto() << endl;
        }
        else if(orden == "elimina_foto") {   /*3 done*/
            bool b = false;
            string id_foto;
            cin >> id_foto;
            cout << "# elimina_foto " << id_foto << endl;
            if(album_en_curso.contiene_foto(id_foto)) {
                cout << "Foto " << id_foto << " eliminada del album en curso." << endl;
                album_en_curso.elimina_foto(id_foto);
            }
            else cout << "El album en curso no contiene una foto con el identificador " << id_foto << endl;
        }
        else if(orden == "obten_foto") {    /*4 done*/
            string id_foto;
            cin >> id_foto;
            bool b = false;
            cout << "# obten_foto " << id_foto << endl;
            album_en_curso.obten_foto(id_foto, b);
            if(not b) cout << "El album en curso no contiene una foto con el identificador " << id_foto << endl;
        }
        else if(orden == "nr_fotos") {    /*5 done*/
            int nr_fotos = album_en_curso.nr_fotos();
            cout << "# nr_fotos" << endl;
            cout << nr_fotos << endl;
        }
        else if(orden == "agrega_album") {    /*6 done*/
            cout << "# agrega_album" << endl;
            if(not col.contiene_album(album_en_curso.id_album())) {
                col.agrega_album(album_en_curso);
            }
            else cout << "Identificador de album incorrecto. No se puede agregar." << endl;
            
        }
        else if(orden == "elimina_album") {    /*7  done*/
            string id_album;
            cin >> id_album;
            cout << "# elimina_album " << id_album << endl;
            if(not col.contiene_album(id_album)) cout << "Identificador de album incorrecto. No se puede eliminar." << endl;
            else col.elimina_album(id_album);
        }
        else if(orden == "obten_album") {    /*8 done*/
            string id_album;
            cin >> id_album;
            cout << "# obten_album " << id_album << endl;
            if(col.contiene_album(id_album)) {
                album_en_curso = col.obten_album(id_album);
                album_en_curso.imprime_album();
            }
            else cout << "No existe un album con el id dado." << endl;
        }
        else if(orden == "nr_albums") {    /*9 done*/
            int nr_albumes = col.nr_albumes();
            cout << "# nr_albums" << endl;
            cout << nr_albumes << endl;
        }
        else if(orden == "lista_albumes") {    /*10 done*/
            cout << "# lista_albumes" << endl;
            col.lista_albumes();
        }
        else if(orden == "agrega_foto_coleccion") {    /*11 done*/
            string id_foto;
            cin >> id_foto;
            int dia, mes, any, n_et;
            cin >> dia >> mes >> any;
            Fecha d;
            d.leer_fecha(dia, mes, any);
            Fotografia f;
            f.crea_foto(id_foto, d);
            cout << "# agrega_foto_coleccion " << id_foto << " ..." << endl;
            col.agrega_foto_coleccion(f);
        }
        else if(orden == "elimina_foto_coleccion") {    /*12 done*/
            string id_foto;
            cin >> id_foto;
            cout << "# elimina_foto_coleccion " << id_foto << endl;
            col.elimina_foto_coleccion(id_foto);
        }
        else if(orden == "modifica_foto_coleccion") {    /*13 done*/
            string id_foto;
            cin >> id_foto;
            cout << "# modifica_foto_coleccion " << id_foto << " ..." << endl;
            int dia, mes, any, n_et;
            cin >> dia >> mes >> any;
            Fecha d;
            d.leer_fecha(dia, mes, any);
            Fotografia f;
            f.crea_foto(id_foto, d);
            col.modifica_foto_coleccion(id_foto, f);
        }
        else if(orden == "albumes_foto") {    /*14 done*/
            string id_foto;
            cin >> id_foto;
            cout << "# albumes_foto " << id_foto << endl;
            col.albumes_foto(id_foto);
        }
        else if(orden == "busca_por_fecha") {    /*15 done*/
            int dia, mes, any;
            cin >> dia >> mes >> any;
            Fecha a;
            a.leer_fecha(dia, mes, any);
            cin >> dia >> mes >> any;
            Fecha b;
            b.leer_fecha(dia, mes, any);
            string id_album;
            cin >> id_album;
            string id_album_res;
            cin >> id_album_res;
            cout << "# busca_por_fecha ";
            a.imprimir_fecha();
            cout << '-';
            b.imprimir_fecha();
            cout << ' ' << id_album << ' ' <<  id_album_res << endl;
            if(col.contiene_album(id_album)) {
                album_en_curso = col.busca_por_fecha(a, b, id_album, id_album_res);
                album_en_curso.imprime_album();
            }
            else cout << "No existe un album con el id dado." << endl;
        }
        else if(orden == "busca_por_etiqueta") {    /*16 done*/
            string et;
            cin >> et;
            string id_album;
            cin >> id_album;
            string id_album_res;
            cin >> id_album_res;
            cout << "# busca_por_etiqueta " << et << ' ' << id_album << ' ' << id_album_res << endl;
            if(col.contiene_album(id_album)) {
                album_en_curso = col.busca_por_etiqueta(et, id_album, id_album_res);
                album_en_curso.imprime_album();
            }
            else cout << "No existe un album con el id dado" << endl;
        }
/*  17    else if(orden == "evalua_consulta_booleana") {
            Aun no he pensado como hacer esta funcion porque no entiendo del todo arboles 
            y prefiero darle un repaso antes de escribir una barbaridad.
        }*/
        else if(orden == "imprime_album_en_curso") {    /*18 done*/
            cout << "# imprime_album_en_curso" << endl;
            album_en_curso.imprime_album();
        }
/*19*/  else if(orden == "imprime_coleccion") {
            cout << "# imprime_coleccion" << endl;
            col.imprime_coleccion();
        }
    }
}

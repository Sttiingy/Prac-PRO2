/** @file Album.hh
    @brief Especificación de la clase Album
*/

#ifndef _ALBUM_HH_
#define _ALBUM_HH_
#endif

#include "Fotografia.hh"

#ifndef NO_DIAGRAM  // ver explicacion en Prenda.hh
#endif

using namespace std;

/** @class Album
    @brief Representa un album

    Dispone de dos estados posibles (inicializada / no inicializada); si está inicializada tiene un peso máximo y un color y puede contener prendas de dicho color hasta alcanzar dicho peso máximo; si no está inicializada no contiene ninguna prenda y solo se puede inicializar

    Todas las operaciones son de <b>coste constante</b> salvo las indicadas */
class Album {

private: 
    string ID;
    set<Fotografia> alb;

public:
    //Constructora
    
    /** @brief Constructora por defecto;
     
        Se ejecuta automaticamente al declarar un album.
        \pre <em>cierto</em>
        \post Nos crea un album vacio.
    */
    Album ();
    
    
    //Modificadoras
    
    /** @brief Agregadora de fotos al parametro implicito
     
        Se ejecuta cuando queremos agregar una foto al album dado.
        \pre <em>cierto</em>
        \post Nos añade la foto al album indicado y además obtenemos un booleno el cual nos dice si la operación se ha realizado con extio.
    */
    void agrega_foto(Fotografia& f);
    

    /** @brief Eliminadora de fotos al parametro implicito
     
        Se ejecuta cuando queremos eliminar una foto al album dado.
        \pre <em>cierto</em>
        \post Nos elimina la foto del album indicado.
    */
    void elimina_foto(const string& id);    
    
    void modifica_foto(Fotografia& f);
    
    void modifica_id(string id);
    
    void copia_album(Album al);
    
    //Consultoras
    
    /** @brief Consultora de fotografias del parametro implicito.
    
        Se ejecuta cuando queremos consultar si esa foto existe en el album y en caso afirmativo la imprime.
        \pre <em>cierto</em>
        \post Nos dice si una foto dada existe en el album y si es asi la imprime.
    */
    void obten_foto(const string& id, bool& b);
    
    
    /** @brief Consultora del tamaño del album
     
        Se ejecuta cuando queremos saber el tamaño de un album dado.
        \pre <em>cierto</em>
        \post Devuelve el tamaño del parametro implicito.
    */
    int nr_fotos();


    /** @brief Consultora del indentificador.

        Se ejecuta cuando queremos saber el identificadir del parametro implicito
        \pre <em>cierto</em>
        \post Devuelve un string con el identificador del album dado.
    */
    string id_album()const;
    
    set<Fotografia> obten_set();
    
    bool contiene_foto(const string& id);
    
    
    //Lectura y Escritura
    
    /** @brief Lectora de album.
     
        Se ejecuta cuando queremos leer un album.
        \pre <em>cierto</em>
        \post Devuelve un album con un identificador y las fotos que pertenecen a dicho album.
    */
    void lee_album(string id);
    
    
    /** @brief Escritora de albumes
     
        Se ejecuta cuando queremos imprimir un album dado por pantalla.
        \pre <em>cierto</em>
        \post Imprime el album en el terminal.
    */
    void imprime_album();
    
    bool operator<(const Album &alb) const;
};

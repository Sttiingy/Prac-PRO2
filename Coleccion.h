/** @file Coleccion.hh
    @brief Especificación de la clase Cubeta
*/

#ifndef _COLECCION_HH_
#define _COLECCION_HH_
#endif

#include "Album.hh"

#ifndef NO_DIAGRAM
#endif

using namespace std;

/** @class Coleccion
    @brief Representa una coleccion

    Dispone de dos estados posibles (inicializada / no inicializada); si está inicializada tiene un peso máximo y un color y puede contener prendas de dicho color hasta alcanzar dicho peso máximo; si no está inicializada no contiene ninguna prenda y solo se puede inicializar

    Todas las operaciones son de <b>coste constante</b> salvo las indicadas */
class Coleccion {
    
private:
    set<Album> colec;
    Album ALL;
public:
    //Constructora
    
    /** @brief Constructora por defecto;
     
        Se ejecuta automaticamente al declarar una coleccion
        \pre <em>cierto</em>
        \post Nos crea una coleccion vacia.
    */
    Coleccion ();
    
    
    //Modificadoras
    
    /** @brief Agragadora de albumes;
     
        Se ejecuta automaticamente al querer agregar un album a la coleccion.
        \pre <em>cierto</em>
        \post Devuelve el parametro implicito con el album dado añadido.
    */
    void agrega_album (Album& al);
    
    
    /** @brief Eliminadora de albumes;
     
        Se ejecuta cuando queremos eliminar un album de la coleccion.
        \pre <em>cierto</em>
        \post Devuelve la coleccion sin el album indicado.
    */
    void elimina_album(const string& id_album);
    
    
    /** @brief Agregadora de fotografias;
     
        Se ejecuta cuando queremos agregar una fotografia a la coleccion.
        \pre <em>cierto</em>
        \post Devuelve dicha coleccion con la foto dada añadida.
    */
    void agrega_foto_coleccion(Fotografia& f);
    
    
    /** @brief Eliminadora de fotografias;
     
        Se ejecuta cuando queremos eliiminar una fotografia a la coleccion.
        \pre <em>cierto</em>
        \post Devuelve dicha coleccion con la foto dada eliminada.
    */
    void elimina_foto_coleccion(const string& id);
    
    /** @brief Modificadora de fotografias;
     
        Se ejecuta cuando queremos modificar una fotografia a la coleccion.
        \pre <em>cierto</em>
        \post Devuelve la foto con un identificador modificada por la nueva foto con el mismo identificador.
    */
    void modifica_foto_coleccion(const string& id, Fotografia& f);
    
    
    //Consultoras
    
    /** @brief Consultora de albumes;
     
        Se ejecuta cuando queremos saber si un album pertenece a la coleccion.
        \pre <em>cierto</em>
        \post Devuelve falso si el album no pertenece a la coleccion y si pertenece devuelve cierto y el album indicado.
    */
    bool contiene_album(const string& id);
    
    
    /** @brief Consultora del numero de albumes;
     
        Se ejecuta cuando queremos saber el numero de albumes de una coleccion.
        \pre <em>cierto</em>
        \post Devuelve el numero de albumes del parametro implicito(incluido ALL).
    */
    int nr_albumes ();
    
    
    /** @brief Consultora del numero de albumes que contine una fotografia dada;
     
        Se ejecuta cuando queremos saber a cuantos albumes diferentes de ALL pertenece la foto cuyo identificador se nos da.
        \pre <em>cierto</em>
        \post Devuelve el numero de albumes al cual pertenece la foto cuyo identificador se nos da sin contar el album ALL.
    */
    int nr_albumes_foto(const string& id);
    

    //Lectura y Escritura
    
    /** @brief  Escritora de un album perteneciente a una coleccion;
     
        Se ejecuta cuando queremos escribir por pantalla un album de la coleccion.
        \pre <em>cierto</em>
        \post Devuelve el album indicado de la coleccion dada por pantalla.
    */
    Album obten_album(const string& id);
    
    
    /** @brief Escritora del listado de albumes;
     
        Se ejecuta para escribir por pantalla todos los albumes de la coleccion.
        \pre <em>cierto</em>
        \post Devuelve por pantalla el listado de los identificadores de los albumes de la coleccion(incluido ALL)
    */
    void lista_albumes();
    
    
    /** @brief Escritora de los albumes a los cuales pertenece una foto dada;
     
        Se ejecuta para escribir por pantalla todos los albumes de la coleccion a los cuales pertenece una foto dada.
        \pre <em>cierto</em>
        \post Devuelve por pantalla el listado de albumes de la coleccion a los que pertenece una foto cuyo identificador se nos da.
    */
    void albumes_foto(const string& id);
    

    /** @brief Escritora de la coleccion entera.
     
        Se ejecuta para escribir por pantalla todos los albumes y todas las fotos de dichos albumes de la coleccion.
        \pre <em>cierto</em>
        \post Devuelve por pantalla el listado de albumes de la coleccion y sus respectivas fotos.
    */
    void imprime_coleccion();
    
    
    //Busqueda

    /** @brief Buscadora por fecha;
     
        Se ejecuta para crear un nuevo album al cual pertenecen unas fotos dado un rango de fechas.
        \pre <em>cierto</em>
        \post Devuelve un album contenedor con las fotos pertenecientes al rango de fotos indicado.
    */
    Album busca_por_fecha(const Fecha& a, const Fecha& b, const string& id_album, const string& id_album_res);
    
    
    /** @brief Buscadora por etiqueta;
     
        Se ejecuta para crear un nuevo album al cual pertenecen unas fotos dado una etiqueta.
        \pre <em>cierto</em>
        \post Devuelve un album contenedor con las fotos las cuales contienen la etiqueta dada.
    */
    Album busca_por_etiqueta(const string& et, const string& iden, const string& id);
};

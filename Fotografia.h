/** @file Fotografia.hh
    @brief Especificación de la clase Fotografia
*/

#ifndef _FOTOGRAFIA_HH_
#define _FOTOGRAFIA_HH_
#endif

#ifndef NO_DIAGRAM   
#include "Fecha.hh"
#include <iostream>
#include <set>
#include <string>
#endif

using namespace std;

/** @class Fotografia
    @brief Representa una fotografia con identificador, un numero de etiquetas y sus etiquetas correspondientes.

*/

class Fotografia {
    
private:
    string id; //Identificador de la foto
    Fecha f;  //Fecha en que se tomó la foto
    int Netq;//Numero de etiquetas
    set<string> etiquetas; //vector de las etiquetas de tamaño Netq
    
public:
    //Constructoras 

    /** @brief Creadora por defecto

        Se ejecuta automáticamente al declarar una fotografia.
        \pre <em>cierto</em>
        \post El resultado es una fotografia vacia.
    */  
    Fotografia ();
    
    
    /** @brief Creadora de fotografia con identificador y fecha 

        Se ejecuta cuando queremos darle un identificador y una fecha a la fotografia dada.
        \pre <em>cierto</em>
        \post El resultado es el parametro implicito con su identificador y con la fecha en la que se tomó.
    */  
    void crea_foto(const string& s, const Fecha& d);
    
    
    //Modificadoras
    
    /** @brief Agragadora de etiqueta. 

        Se ejecuta al querer añadir una etiqueta
        \pre <em>cierto</em>
        \post La etiqueta ha quedado agragada a la fotografia seleccionada.
    */
    void agrega_etiqueta(const string& etiq);
    
    
    /** @brief Eliiminadora de etiqueta

        Se ejecuta al querer eliminar una etiqueta
        \pre <em>cierto</em>
        \post La etiqueta ha quedado eliminada de la fotografia seleccionada
    */
    void elimina_etiqueta(const string& etiq);
    
    
    //Consultoras
    
    /** @brief Consultora de etiqueta.

        Se ejecuta al querer saber si una etiqueta pertenece al parametro implicito.
        \pre <em>cierto</em>
        \post Existe dicha etiqueta,  1 si la contiene, 0 si no es asi.
    */
    bool contiene_etiqueta(const string& s);
    
    
    /** @brief Consultora del indentificador.

        Se ejecuta cuando queremos saber el identificadir del parametro implicito
        \pre <em>cierto</em>
        \post Devuelve un string con el identificador del parametro implicito.
    */
    string id_foto() const;
    
    
    /** @brief Consultora de la fecha en la que se tomó la foto.

        Se ejecuta cuando queremos saber la fecha del parametro implicito
        \pre <em>cierto</em>
        \post Devuelve la fecha de la fecha en la que se tomó la foto.
    */
    Fecha fecha_toma();
    
    
    /** @brief Consultora del numero de etiquetas.

        Se ejecuta cuando queremos saber el numero de etiquetas del parametro implicito
        \pre <em>cierto</em>
        \post Devuelve el numero de etiquetas que contiene la foto.
    */
    int nr_etiquetas();
    
     
    //Escritura
    
    /** @brief Escritora de fotografias.

        Se ejecuta cuando queremos que se imprima por pantalla el parametro impicito.
        \pre <em>cierto</em>
        \post Escribe la fotografia con su identificador, la fecha en que se tomo y la lista de etiquetas en orden lexicográfico ascendente.
    */
    void imprime_foto();
    
    bool operator<(const Fotografia &fot) const;

};

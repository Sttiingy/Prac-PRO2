/** @file fecha.hh
    @brief Especificación de la clase Fecha
*/

#ifndef _FECHA_HH_
#define _FECHA_HH_
#endif

#ifndef NO_DIAGRAM   
#include <iostream>

#endif

using namespace std;

/** @class Fecha
    @brief Representa la fecha con el di ael mes y el año en que se tomó una foto.

    Todas las operaciones son de <b>coste constante</b>
*/

class Fecha {

private:
    int dia;
    int mes;
    int any;

public:
    //Constructora
    
    /** @brief Constructora por defecto;
     
        Se ejecuta automaticamente al declarar una fecha.
        \pre <em>cierto</em>
        \post Nos crea una fecha con dia, mes y año vacios.
    */
    Fecha ();
    
    //Consultora
    
    bool fecha_valida(const Fecha& a, const Fecha& b);
    //Escritura y Lectura
    
    /** @brief Escritora de la fecha.
     
        Se ejecuta para imprimir por pantalla el parametro implicito.
        \pre <em>cierto</em>
        \post Escribe el dia, el mes, y el año de la fecha.
    */
    void leer_fecha(const int& dia, const int& mes, const int& any);
    
    
    /** @brief Escritora de la fecha.
     
        Se ejecuta para imprimir por pantalla el parametro implicito.
        \pre <em>cierto</em>
        \post Escribe el dia, el mes, y el año de la fecha.
    */
    void imprimir_fecha();
};

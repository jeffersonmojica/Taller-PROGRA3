//
// Created by alejo on 14/05/2024.
//

#ifndef TALLER_PROGRA3_PUNTO1_5_H
#define TALLER_PROGRA3_PUNTO1_5_H

// Función para buscar todas las ocurrencias de una subcadena dentro de otra
// Retorna el número total de ocurrencias encontradas
int buscarSubcadena(const char *cadena, const char *subcadena, int posicionInicio);

// Función que valida si una cadena inicia con otra
// Retorna:
// 1 si la cadena base inicia con la subcadena,
// 0 si no inicia con la subcadena,
// -1 si hay un error
int cadenaIniciaCon(const char *cadenaBase, const char *subcadena);

#endif //TALLER_PROGRA3_PUNTO1_5_H

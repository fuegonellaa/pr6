/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * 2º de Carrera
 * Práctica 6. Búsqueda de Patrones
 * Referencia:
 * https://github.com/garamira/CyA-P06-Patterns
 * \author Antonella Sofía García Álvarez
 * Contact: alu0101227610@ull.edu.es */

#include <string>
#include "set.h"

class Automaton {
  private:
  Set alphabet_;
  std::string pattern_;

  public:

  ///Constructor
  Automaton(std::string pattern);
  ///Destructor
  ~Automaton();

 /**
    * \brief Checks if the string's valid
    * \param tocheck string to check
  */
  bool isValid(std::string tocheck);
 /**
    * \brief Checks if the pattern it's in the string
    * \param tocheck pattern to check
  */
  int inString(std::string tocheck);

};
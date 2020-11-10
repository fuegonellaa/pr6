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

#include "automaton.h"

///Constructor
Automaton::Automaton(std::string pattern) : alphabet_(256) {
  for (int letter = 97; letter <= 122; letter++) {
    alphabet_.AddToSet(letter);
  }
  pattern_ = pattern;
}

///Destructor
Automaton::~Automaton() { }

///Checks if the string's valid
bool Automaton::isValid(std::string tocheck) {
  for (int pos = 0; pos < tocheck.length(); pos++) {
    if (alphabet_.isInSet((int)tocheck[pos])) {
      continue;
    } 
    return false;
  }
  return true;
}

///Checks if the pattern is in the string
int Automaton::inString(std::string tocheck) {
  if (!isValid(tocheck)) {
    return 0;
  } 
  if (tocheck.length() < pattern_.length()) {
    return 1;
  }
  int state = 0;
  for (int pos = 0; pos < tocheck.length(); pos++) {
    if (tocheck[pos] == pattern_[state]) {
      state++;
    } else if (state != 0 && tocheck[pos] == pattern_[0]) {
      state = 1;
    } else {
      state = 0;
    }
    if (state == pattern_.length()) {
      return 2;
    } 
  }
  return 1;
}

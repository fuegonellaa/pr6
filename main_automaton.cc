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

#include <fstream>
#include <iostream>

#include "automaton.h"

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "The right way of executing this code is ./pattern_search pattern infile.txt outfile.txt" << std::endl;
    std::cout << "Use -h or --help to see more information about this code" << std::endl;
    return 1;
  } else if (argc != 4) {
    std::string help = "--help";
    std::string help2 = "-h";
    std::cout << "The right way of executing this code is ./pattern_search pattern infile.txt outfile.txt" << std::endl;
     if (help.compare(argv[1]) == 0 || help2.compare(argv[1]) == 0) {
      std::cout << "This program reads strings from a file, and says if a pattern is in them" << std::endl;
      return 0;
    }
    return 1;
  }

  Automaton automaton(argv[1]);
  std::ifstream infile;
  std::ofstream outfile;

  infile.open(argv[2]);
  outfile.open(argv[3]);

  std::string tocheck;
  while (std::getline(infile,tocheck)) {
    switch (automaton.inString(tocheck)) {
    case 0:
      outfile << "Error" << std::endl;
      break;
    case 1:
      outfile << "No" << std::endl;
      break;
    case 2:
      outfile << "Si" << std::endl;
      break;
    }
  }

  infile.close();
  outfile.close();
}

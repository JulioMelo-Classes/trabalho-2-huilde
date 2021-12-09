#ifndef CANALDETEXTO.H
#define CANALDETEXTO.H
#include "Sistema.h"
#include "Usuario.h"
#include "Menssagem.h"
#include <istream>
#include <ostream>
#include <sstream>

class CanalDeTexto{
public:

unsigned int CanalDeTexto_id; //numero inteiro contendo id do servidor

std::string canal_name; // string contendo o nome do canal de texto

Usuario* dono; // ponteiro para o dono do canal de texto

std::vector<Menssagem> menssagens; // vetor contendo as menssagens do servidor  
};


#endif
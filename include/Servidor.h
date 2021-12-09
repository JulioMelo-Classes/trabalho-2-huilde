#ifndef SERVIDOR.H
#define SERVIDOR.H
#include "Sistema.h"
#include "Usuario.h"
#include "Menssagem.h"
#include "CanalDeTexto.h"
#include <istream>
#include <ostream>
#include <sstream>

class Servidor{
public:

unsigned int Server_id; //numero inteiro contendo id do servidor

std::string Server_name; // string contendo o nome do servidor

Usuario* dono; // ponteiro para o dono do servidor

string descricao; //String contendo a descrição do servidor

string codigoConvite = ""; // String contendo código de convite, como padrão uma string vazia
  
};

#endif
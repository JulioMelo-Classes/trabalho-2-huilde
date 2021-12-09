#ifndef MENSSAGEM.H
#define MENSSAGEM.H
#include "Sistema.h"
#include "Usuario.h"
#include <istream>
#include <ostream>
#include <sstream>

class Menssagem{
public:

unsigned int Mensagem_id; //numero inteiro contendo id da mensagem

string dataHora; // string contendo  um texto representando um timestamp com a data e hora em que a mensagem foi enviada no formato

Usuario* Remetente; // ponteiro para o quem enviou a menssagem

string conteudo ; //String com o conteúdo da menssagem
  
};

#endif
#ifndef CANALDETEXTO_H
#define CANALDETEXTO_H
#include "Sistema.h"
#include "Usuario.h"
#include "Menssagem.h"
#include <istream>
#include <ostream>
#include <sstream>

class CanalTexto{
private:

unsigned int CanalDeTexto_id; //numero inteiro contendo id do canal de texto

std::string canal_name; // string contendo o nome do canal de texto

Usuario* dono; // ponteiro para o dono do canal de texto

std::vector<Menssagem> menssagens; // vetor contendo as menssagens do servidor  
public:

//construtor do classe servidor
CanalTexto(unsigned int id,string nome,Usuario* criador );

/*! retorna o nome do canal
	@return canal_name
*/

string get_name();



/*! retorna o id do canal de texto
	@return CanalDeTexto_id
*/
int get_id();


/*! adiciona uma menssagem ao servidor

*/
void add_mensagem(string data_hora, string conteudo_da_mensagem,Usuario* dono);


/*! retorna o vetor de menssagens
	@return menssagens
*/
std::vector<Menssagem> get_mensagens();

};

#endif
#ifndef SERVIDOR_H
#define SERVIDOR_H
#include "Sistema.h"
#include "Usuario.h"
#include "Menssagem.h"
#include "CanalDeTexto.h"
#include <istream>
#include <ostream>
#include <sstream>

class Servidor{
private:

unsigned int Server_id; //numero inteiro contendo id do servidor

std::string Server_name; // string contendo o nome do servidor

Usuario* Server_dono; // ponteiro para o dono do servidor

string descricao; //String contendo a descrição do servidor

string codigoConvite = ""; // String contendo código de convite, como padrão uma string vazia

std::vector<CanalTexto> canaisTexto; // vetor contendo todos os canais de texto do servidor

std::vector<Usuario*> Participantes; //Um vetor contendo referências para todos os participantes deste servidor. 
public:
//construtor do classe servidor
Servidor(int id,string nome,Usuario* dono);


/*! retorna o nome do servidor
	@return Server_name
*/

string get_name();


/*! retorna o ponteiro para o dono do servidor
	@return Server_dono
*/
Usuario* get_dono();

/*! Modifica o descricao para o valor passado no parâmetro
	@param nome passa a ser o novo valor de descricao
*/
void set_descricao(string nome);

/*! Modifica o codigoConite para o valor passado no parâmetro
	@param codigo passa a ser o novo valor de codigoConvite
*/
void set_codigo(string codigo);

};

#endif
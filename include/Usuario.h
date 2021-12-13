#ifndef USUARIO_H
#define USUARIO_H
#include "Sistema.h"
#include <istream>
#include <ostream>
#include <sstream>

using namespace std;
class Usuario{
private:
unsigned int User_id; //numero inteiro contendo id do usuário

string User_name; // string contendo o nome do usuário

string User_email; // string contendo o e-mail do usuário

string User_senha; // string contendo a senha do usuário

public:  

string get_email();
	/*! retorna o e-mail do usuario
	@return e-mail registrado no usuário
*/
void set_email(string email);
/*! Modifica o User_email para o valor passado no parâmetro
	@param email passa a ser o novo valor do User_email
*/


void set_name(string nome);
/*! Modifica o User_name para o valor passado no parâmetro
	@param nome passa a ser novo valor do User_email
*/

void set_id(unsigned int id);
/*! Modifica o User_id para o valor passado no parâmetro
	@param id passa a ser novo valor do User_id
*/

void set_senha(string senha);
/*! Modifica o User_senha para o valor passado no parâmetro
	@param senha passa a ser novo valor do User_senha
*/

unsigned int get_id();
	/*! retorna o id do usuario
	@return id registrado no usuário
*/

string get_senha();
	/*! retorna a senha do usuario
	@return senha registrada do usuário
*/

/*! retorna o nome do usuario
	@return User_name registrado no usuário
*/
string get_name();
};

#endif
#include "Sistema.h"
#include "Usuario.h"
#include "Menssagem.h"
#include "CanalDeTexto.h"
#include "Servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
	for (int i = 0; i < Usuarios_criados.size(); i++){
		if (email == Usuarios_criados[i]->get_email()){
			return "Usuário já existe!";
		}
	}
Usuario* criado = new Usuario;
criado->set_email(email);
criado->set_id(Usuarios_criados.size());
criado->set_senha(senha);
criado->set_name(nome);
Usuarios_criados.push_back(criado);

return "Usuário criado";
}

std::string Sistema::delete_user (const std::string email, const std::string senha){
	for (int i = 0; i < Usuarios_criados.size(); i++)
	{
		if(Usuarios_criados[i]->get_email() == email){
		
			for (int k = 0; k < Usuarios_logados.size(); k++)
			{
				if(Usuarios_criados[i]->get_id() == Usuarios_logados[k].first){
					return "usuário não pode ser excluido pois está logado";
				}
			}

	Usuarios_criados[i]->set_email("email-anônimo");
	Usuarios_criados[i]->set_id(-1);
	Usuarios_criados[i]->set_name("Usuário removido");
	Usuarios_criados.erase(Usuarios_criados.begin()+i);
	return "Usuário removido";
	}
	
	}
	return "Usuário não cadastrado!";
}

string Sistema::login(const string email, const string senha) {
	for(int i = 0; i < Usuarios_criados.size(); i++)
	{	
		
		if(Usuarios_criados[i]->get_email() == email && Usuarios_criados[i]->get_senha() == senha){
			for (int  k = 0; k < Usuarios_logados.size(); k++)
			{
				if(Usuarios_criados[i]->get_id() == Usuarios_logados[k].first){
					return "Usuário já está logado";
				}
			}
			

			Usuarios_logados.emplace(Usuarios_criados[i]->get_id(),make_pair(NULL,NULL));
			std::string retorno = "Logado como:";
			retorno += Usuarios_criados[i]->get_email();
		return retorno;}	
	}
	



	return "Senha ou usuário inválidos!";
}

string Sistema::disconnect(int id) {
	for (int i = 0; i < Usuarios_logados.size(); i++)
	{if(id==Usuarios_logados[i].first){
		return "Ainda estou fazendo essa parte";
	}
	}
	

	return "Não está conectado";
}

string Sistema::create_server(int id, const string nome) {
	return "create_server NÃO IMPLEMENTADO";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
	return "set_server_desc NÃO IMPLEMENTADO";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
	return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers(int id) {
	return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(int id, const string nome) {
	return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
	return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
	return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
	return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
	return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
	return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::remove_channel(int id, const string nome) {
	return "remove_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
	return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
	return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
	return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
	return "list_messages NÃO IMPLEMENTADO";
}


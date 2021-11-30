#include "Sistema.h"
#include "auxiliares.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

#include "Sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
int UserIDs =1;
/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
	for (int i = 0; i < Usuarios_criados.size(); i++){
		if (email == Usuarios_criados[i].User_email){
			return "Usuário já existe!";
		}
	}
Usuario criado;
criado.User_email = email;
criado.User_id =UserIDs;
UserIDs++;
criado.User_senha = senha;
criado.User_name = nome;
Usuarios_criados.push_back(criado);

return " Usuário criado";
}

std::string Sistema::delete_user (const std::string email, const std::string senha){
	return "delete_user NÃO IMPLEMENTADO";
}

string Sistema::login(const string email, const string senha) {
	return "login NÃO IMPLEMENTADO";
}

string Sistema::disconnect(int id) {
	return "disconnect NÃO IMPLEMENTADO";
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


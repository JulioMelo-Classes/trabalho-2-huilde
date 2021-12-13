#include "Sistema.h"
#include "Usuario.h"
#include "Menssagem.h"
#include "CanalDeTexto.h"
#include "Servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include  <map>
#include <cctype>
#include <ctime>

using namespace std;
/* COMANDOS */
int Users_id=0; // inteiro contendo o número do id do próximo usuário que será criado
int Servers_id = 0; // inteiro contendo o número do id do próximo servidor que será criado

Usuario* Sistema::dono_id(int id){
	for (int i = 0; i < Usuarios_criados.size(); i++){
		if(id == Usuarios_criados[i]->get_id()){
			return Usuarios_criados[i];
		}
	}
	
	return Usuarios_criados[0];
}

bool Sistema::logado(unsigned int id){
	std::map<int,std::pair<unsigned int , unsigned int>>::iterator it;
	it = Usuarios_logados.find(id);
	return it != Usuarios_logados.end();
}

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
	//refatorar código criando um construtor
	criado->set_email(email);
	criado->set_id(Users_id);
	Users_id++;
	criado->set_senha(senha);
	criado->set_name(nome);
	Usuarios_criados.push_back(criado);

	return "Usuário criado";
}

std::string Sistema::delete_user (const std::string email, const std::string senha){
	for (int i = 0; i < Usuarios_criados.size(); i++){

		if(Usuarios_criados[i]->get_email() == email){

			for (int k = 0; k < Usuarios_logados.size(); k++){

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
	for(int i = 0; i < Usuarios_criados.size(); i++){	
		
		if(Usuarios_criados[i]->get_email() == email && Usuarios_criados[i]->get_senha() == senha){

			for (int  k = 0; k < Usuarios_logados.size(); k++){

				if(Usuarios_criados[i]->get_id() == Usuarios_logados[k].first){
					return "Usuário já está logado";
				}
			}
			
			Usuarios_logados.emplace(Usuarios_criados[i]->get_id(),make_pair(999,999));
			std::string retorno = "Logado como:";
			retorno += Usuarios_criados[i]->get_email();
		return retorno;}	
	}
	return "Senha ou usuário inválidos!";
}

string Sistema::disconnect(int id) {
	if(logado(id)){
		return "Não está conectado";
	}

 Usuarios_logados.erase(id);
 
return "Usuario removido " + Usuarios_criados[id]->get_email();

}

string Sistema::create_server(int id, const string nome) {
	if(!logado(id)){
		return "Não está conectado";
	}

	for (int i = 0; i < Servidores.size(); i++){

		if(nome == Servidores[i].get_name()){
			return "Já existe um servidor com esse nome";	
		}

	}

	Servidor criado = Servidor(Servers_id, nome ,Usuarios_criados[id]);
	Servers_id++;
	Servidores.push_back(criado);
	return "servidor "+criado.get_name()+" criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
	if(!logado(id)){
		return "Não está conectado";
	}
 //percorrendo os servidores e comparando os nomes
	for (int i = 0; i < Servidores.size(); i++){	
		// caso o nome seja igual, checa o dono
		if(Servidores[i].get_name()==nome){
			// caso o nome seja igual, altera a descrição
			if(Servidores[i].get_dono()==Usuarios_criados[id]){
				Servidores[i].set_descricao(nome);
				return "descrição do servidor "+ nome+" alterada";
			}

			else{
				return "Você não pode alterar a descrição de um servidor que não foi criado por você";
			}
		}
	}
	return "Servidor ("+nome+") não existe";}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
	if(!logado(id)){
		return "Não está conectado";
	}
	//percorrendo os servidores e comparando os nomes
	for (int i = 0; i < Servidores.size(); i++){
		// caso o nome seja igual, checa o dono
		if(Servidores[i].get_name()==nome){
			// caso seja o dono, altera o convite
			if(Servidores[i].get_dono()==Usuarios_criados[id]){
				Servidores[i].set_codigo(codigo);
				if(codigo == ""){
					return "Código de convite do servidor "+ nome+" removido";
				}
				return "Código de convite do servidor "+ nome+" alterado";
			}
			else{
				return "Você não pode alterar o Código de convite de um servidor que não foi criado por você";
			}
		}
	}
	return "Servidor ("+nome+") não existe";
}

string Sistema::list_servers(int id) {
	if(!logado(id)){
		return "Não está conectado";
	}

	string NomeServidores = Servidores[0].get_name();
	for (int i = 1; i < Servidores.size(); i++){
		NomeServidores += "\n"+ Servidores[i].get_name();
	}

	return NomeServidores;
}

string Sistema::remove_server(int id, const string nome) {
	if(!logado(id)){
		return "Não está conectado";
	}
	for (int i = 0; i < Servidores.size(); i++){

		if(Servidores[i].get_name()==nome){
			if(Servidores[i].get_dono()==Usuarios_criados[id]){
			//apagando o servidor do array
			Servidores.erase(Servidores.begin()+id);			
			//checagem de usuarios logados no servidor Usarios_logados
			for (int k = 0; k < Usuarios_logados.size(); k++){
				if(Usuarios_logados.at(k).first = id ){
					Usuarios_logados.at(k).second = 999;
					Usuarios_logados.at(k).first = 999;
				}
			}
		
				return "Servidor ("+ nome +") removido";
			}
			else{
				return "Você não é o dono do seridor ("+nome +")";
			}
		}
	}
return "Servidor ("+nome+") não encontrado";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
	if(!logado(id)){
	return "Não está conectado";
	}
for(int i = 0; i < Servidores.size(); i++){

	if(Servidores[i].get_name()==nome){
		// as 3 condições para poder entrar no servidor(ser dono, servidor livre ou colocar o código correto)
		if(Servidores[i].get_codigo()==""|| Servidores[i].get_codigo()==codigo || Servidores[i].get_dono()== Usuarios_criados[id]){
			Servidores[i].add_participante(Usuarios_criados[id]); 
			Usuarios_logados.at(id).first = Servidores[i].get_id();
			return "Entrou no servidor com sucesso";}
		else {
			return "Servidor precisa de código de convite";
		}
	}

}
	return "Servidor "+ nome +" não encontrado";
}

string Sistema::leave_server(int id, const string nome) {
	if(!logado(id)){
	return "Não está conectado";
	}
	if(Usuarios_logados.at(id).first == 999){
		return "Você não participa de nenhum servidor"; 
	}
	for (size_t i = 0; i <Servidores.size(); i++){

		if(Servidores[i].get_name() == nome){
			if(Usuarios_logados.at(id).first == Servidores[i].get_id()){
				Usuarios_logados.at(i).second = 999;
				Usuarios_logados.at(i).first = 999;
				return "Você saiu do servidor "+ nome;
		}
			else{
				return "Você não está nesse servidor";
			}
		}
	}

	return "Servidor "+ nome + " não encontrado";
}

string Sistema::list_participants(int id){
	if(!logado(id)){
		return "Não está conectado";
	}
	//string contendo o conteudo que será retornado
	std::string retorno;
	//inteiro contendo o numero do id do servior
	int servidor = Usuarios_logados.at(id).first;
	cout<<"listando Participantes:"<<endl;
	cout<<"-----------------"<<endl;
 	Usuarios_logados.at(id).first;
	// refatorar código posteriormente
	for(int i = 0; i < Servidores.size(); i++){
		if(servidor == Servidores[i].get_id()){
			for (int k = 0; k < Servidores[i].get_Participantes().size(); k++){
				cout<<Servidores[i].get_Participantes()[k]->get_name()<<endl;
			}	
		return "-----------------";
		}
	}
return "-----------------";
}

string Sistema::list_channels(int id) {
	if(!logado(id)){
		return "Não está conectado";
	}
	int servidor = Usuarios_logados.at(id).first; // inteiro contendo o id do servidor
	cout<<"Listando canais:"<<endl<<"-----------------"<<endl;
	for(int i = 0; i < Servidores[servidor].get_canais().size(); i++){
		cout<<Servidores[servidor].get_canais()[i].get_name()<<endl;
	}

	return "-----------------";
}

string Sistema::create_channel(int id, const string nome) {
	if(!logado(id)){
		return "Não está conectado";
	}
	int servidor = Usuarios_logados.at(id).first;
	// refatorar código posteriormente
	for (int i = 0; i < Servidores.size(); i++){

		if(servidor == Servidores[i].get_id()){
			for (int k = 0; k < Servidores[i].get_canais().size() ; k++){
				// verifficando se o nome já existe
				if(Servidores[i].get_canais()[k].get_name() == nome){
					return "canal "+ nome + " já existente";
				}	
			}
		
			CanalTexto canal = CanalTexto(id,nome, dono_id(id));
			Servidores[i].aumenta_id();
			Servidores[i].add_canal(canal);
			return "canal "+nome +" criado";
		}
	}
	return "não foi possível criar o servidor";
}

string Sistema::remove_channel(int id, const string nome) {
if(!logado(id)){
	return "Não está conectado";
}
	// funcionalidade não implementada
// int servidor = Usuarios_logados.at(id).first;
// int canal = Usuarios_logados.at(id).second;
// 		for (int k = 0; k < Servidores[i].get_canais().size() ; k++)
// 		{	// verifficando se o nome já existe
// 			if(Servidores[servidor].get_canais()[k].  == nome){
// 				return "canal "+ nome + " já existente";
// 			}	
// 		}
// 		Servidores[i].add_canal(canal);



	return "Canal removido";
}

string Sistema::enter_channel(int id, const string nome) {
	if(!logado(id)){
		return "Não está conectado";
	}
	
	int servidor = Usuarios_logados.at(id).first; // inteiro contendo o id do servidor
	for (int i = 0; i < Servidores[servidor].get_canais().size(); i++){

		if(Servidores[servidor].get_canais()[i].get_name()==nome){

			Usuarios_logados.at(id).second = Servidores[servidor].get_canais()[i].get_id();
			return"Entrou no canal "+nome;
		}
	}

	return "Servidor "+ nome +" não existe";
}

string Sistema::leave_channel(int id) {
	if(!logado(id)){
		return "Não está conectado";	
	}
	Usuarios_logados.at(id).second = 999;
		return "Você deixou o canal";
}

string Sistema::send_message(int id, const string mensagem) {
	if(!logado(id)){
		return "Não está conectado";
	}
	int servidor = Usuarios_logados.at(id).first;
	int canal = Usuarios_logados.at(id).second;
	if(canal == 999){
		return "Você não pode enviar uma menssagem sem estar em um canal";
	}

	Usuario* remetente = Usuarios_criados[id];
	Servidores[servidor].get_canais()[canal].add_mensagem("hora",mensagem,remetente);
	return "Menssagem enviado com sucesso";
}

string Sistema::list_messages(int id) {
	if(!logado(id)){
	return "Não está conectado";
	}
	int servidor =  Usuarios_logados.at(id).first;
	int canal = Usuarios_logados.at(id).second;
	if(canal == 999|| servidor== 999){
		return "Você não pode visizualizar menssagens sem estar em um canal";
	}

	return "list_messages NÃO IMPLEMENTADO";
}


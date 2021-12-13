#include "Sistema.h"
#include "Usuario.h"
#include "Menssagem.h"
#include "CanalDeTexto.h"
#include "Servidor.h"
#include <string>
using namespace std;

std::string Servidor::get_name(){
return Server_name;
};

Servidor::Servidor(int id,string nome,Usuario* dono){
Server_id = id;
Server_name = nome;
Server_dono = dono;
}

Usuario* Servidor::get_dono(){
   return Server_dono; 
}

void Servidor::set_descricao(string nome){
	descricao = nome;
}

void Servidor::set_codigo(string codigo){
    codigoConvite = codigo;
}

string Servidor::get_codigo(){
    return codigoConvite;
}
std::vector<Usuario*> Servidor::get_Participantes(){
    return Participantes;
}

unsigned int Servidor::get_id(){
    return Server_id;
}

void Servidor::add_participante(Usuario* participante){
    Participantes.push_back(participante);
}


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

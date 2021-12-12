#include "Sistema.h"
#include "Usuario.h"
#include "Menssagem.h"
#include "CanalDeTexto.h"
#include "Servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

string Usuario::get_email(){
    return User_email;
};

void Usuario::set_email(string email){
User_email = email;
}

void Usuario::set_name(string nome){
User_name = nome;
}

void Usuario::set_id(unsigned int id){
User_id = id;
}
void Usuario::set_senha(string senha){
User_senha = senha;
}

unsigned int Usuario::get_id(){
return User_id;
}

string Usuario::get_senha(){
    return User_senha;
};
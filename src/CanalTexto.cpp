#include "Sistema.h"
#include "Usuario.h"
#include "Menssagem.h"
#include "CanalDeTexto.h"
#include "Servidor.h"
#include <iostream>

using namespace std;

string CanalTexto::get_name(){
    return canal_name;
}


CanalTexto::CanalTexto(unsigned int id,string nome,Usuario* criador){
    canal_name = nome;
    CanalDeTexto_id = id;
    dono =  criador;
}
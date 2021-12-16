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

int CanalTexto::get_id(){
    return CanalDeTexto_id;
}

void CanalTexto::add_mensagem(string data_hora,string conteudo_da_mensagem,Usuario* dono){
    Menssagem nova = Menssagem( 0,data_hora, conteudo_da_mensagem,dono);
    int id=0;
    menssagens.push_back(nova);
}

//isso aqui viola a condição do trabalho!!! você não pode retornar esse vetor
std::vector<Menssagem> CanalTexto::get_mensagens(){
    return menssagens;
}
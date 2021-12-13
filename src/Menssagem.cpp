#include "Sistema.h"
#include "Usuario.h"
#include "Menssagem.h"
#include "CanalDeTexto.h"
#include "Servidor.h"
#include <string>
#include <iostream>

Menssagem::Menssagem(int id, string data, string menssagem, Usuario* quemenviou){
    Mensagem_id = id;
    dataHora = data;
    conteudo = menssagem;
    Remetente = quemenviou;
}
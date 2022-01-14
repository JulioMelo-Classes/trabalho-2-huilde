# Base para a atividade 02 de LP1

Use esse esqueleto de classes para iniciar a terceira atividade.

Existe um executor que faz a interpretação dos comandos e executa o método correto do sistema.

## Para compilar

Com makefiles:
```console
mkdir build
make
```

Com cmake:
```console
mkdir build
cd build
cmake ..
cmake --build .
```

Escolha uma das duas formas de build e ignore a outra.

## Para executar
Você pode rodar o sistema e em logo depois digitar os comandos seguidos de ENTER
```console
cd build
./concordo
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
cd build
./concordo < ../data/script_comandos.txt
```

# Avaliação
## Funcionalidades
- A1.2 ok
Aqui você poderia ter usado o construtor
- A1.3 ok
Como conversamos, essa solução é um pouco custosa, mas vou considerar uma vez que não restringi a forma. No entanto você deveria deletar os usuários no quit.
- A1.4 ok
- A2.1 ok
- A2.2 ok
- A2.3 ok
- A2.4 ok
- A2.5 ok
- A2.6 ok
Vou considerar mas não entendi sua estratégia de colocar o id pra 999, aqui você poderia simplesmente colocar o id 0, uma vez que 999 é um id válido.
- A2.7 ok
- A2.8 ok
- A2.9 10%
Vou penalizar aqui uma vez que você violou a restrição do trabalho
- B1.1 10%
Vou penalizar aqui uma vez que você violou a restrição do trabalho
- B1.2 10%
Vou penalizar aqui uma vez que você violou a restrição do trabalho
- B1.3 ok
- B1.4 ok
- B1.5 nok
- B2.1 10%
Além de não funcionar, pelo fato de fazer acesso a uma cópia da lista de canais, você violou a restrição do trabalho.
- B2.2 nok

## Classes
- Servidor 80%
Vou remover 20% por ter violado a restrição de retorno de containers.
- Canal ok
- Mensagem ok

## Boas Práticas
- Documentação ok
- Testes nok
A ideia aqui é que você enviasse alguns scripts com testes planejados por você
- Organização 75%
Vou remover pontos por causa de erros de indentação no código.

## Observações
Uma coisa que você poderia modularizar era o gerenciamento dos ids, da forma que você fez, dificulta uma solução de reuso de ids.

Para resolver os pontos onde você viola as restrições e acessa os containers via get/diretamente, você deveria ter usado métodos, como conversamos na entrevista.
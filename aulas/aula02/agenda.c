#include <stdio.h>
#include "agenda.h" // para as bibliotecas/interfaces que criamos essa é a forma de adicionar/implementar

Agenda criar_agenda(int tamanho){
    Agenda agenda;
    agenda.tamanho = tamanho;
    agenda.quantidade = 0;
    return agenda;
}
void adicionar_contato(Agenda *agenda, Contato contato){
    if(agenda->tamanho == agenda->quantidade){
        printf("agenda lotada\n");
        return;
    }
    agenda->contatos[agenda->quantidade] = contato;
    agenda->quantidade++;
}
void listar_contato(Agenda *agenda){
    if(agenda->quantidade == 0){
        printf("agenda vazia\n");
        return;
    }
    for (int i=0; i<agenda->quantidade; i++){
        printf("%s-%s\n", agenda-contatos[i].nome, agenda->contatos[i].telefone);
    }
}
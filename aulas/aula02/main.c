#include <stdio.h>
#include "agenda.h"

int main (){
    Agenda agenda = criar_agenda(10);

    Contato contato;
    strpcy(contato.nome, "jose");
    strpcy(contato.telefone, "1111-1111");

    adicionar_contato(&agenda, contato);
    listar_contato(&agenda);

    Contato outro;
    strpcy(outro.nome, "maria");
    strcpy(outro.numero, "2222-2222");

    adicionar_contato(&agenda, contato);
    listar_contato(&agenda);
    return 0;
}
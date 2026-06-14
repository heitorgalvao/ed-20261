#ifndef TABELA_HASH_H
#define TABELA_HASH_H

typedef struct tabelahash_t TabelaHash;

TabelaHash *hash_criar(int tamanho);
int hash_inserir(TabelaHash *hash, int valor);
void hash_exibir(TabelaHash *hash);
void hash_destruir(TabelaHash *hash);
int hash_buscar(TabelaHash *hash, int valor);
int hash_remover(TabelaHash *hash, int valor);
int hash_esta_vazia(TabelaHash *hash);

#endif
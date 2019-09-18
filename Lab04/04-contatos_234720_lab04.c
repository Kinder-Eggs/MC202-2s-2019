#include <stdio.h>
#include <string.h>
//Gabriel Costa Kinder - 234720
struct pessoa{ // define uma struct com uma string para cada elemento, possundo o tamanho maximo +1
  char nome[51];
  char end[101];
  char tel[13];
  char ani[9];
};
// Declaracoes das funcoes utilizadas
void inserir_pessoa(struct pessoa pessoas[], int cont);
int remover_pessoas(struct pessoa pessoas[], int cont);
int delete_pessoa(struct pessoa pessoas[], int n, int cont);
void buscar_pessoa(struct pessoa pessoas[], int cont);
void imprimir_pessoas(struct pessoa pessoas[], int cont);

int main() {
  int cont = 0;
  struct pessoa pessoas[1000]; // gera um vetor contendo mil pessoas
  char comando;
  // comeca a ler o comando e agindo de acordo
  scanf("%c", &comando);
  while(comando != 'f'){
    if (comando == 'i'){
      inserir_pessoa(pessoas, cont);
      cont++;
    }
    if (comando == 'r'){
      cont = remover_pessoas(pessoas, cont);
    }
    if (comando == 'b'){
      buscar_pessoa(pessoas, cont);
    }
    if (comando == 'p'){
      imprimir_pessoas(pessoas, cont);
    }
    scanf(" %c", &comando);
  }
}
// Adiciona os dados digitados em uma das pessoas geradas no vetor
void inserir_pessoa(struct pessoa pessoas[], int cont) {
  scanf(" %[^\n]", &pessoas[cont].nome);
  scanf(" %[^\n]", &pessoas[cont].end);
  scanf(" %[^\n]", &pessoas[cont].tel);
  scanf(" %[^\n]", &pessoas[cont].ani);
  printf("Contato para %s inserido.\n\n", pessoas[cont].nome);
  cont++;
}
// Sobrescreve os dados da pessoa apagada com o da proxima pessoa da lista, repete com a proxima ate chegar ao final
int remover_pessoas(struct pessoa pessoas[], int cont) {
  int removidos = 0;
  char nome_aux[51];
  scanf(" %s", nome_aux);
  for (int i = 0; i < cont; i++) {
    if(strcmp(pessoas[i].nome, nome_aux) == 0) {
      cont = delete_pessoa(pessoas, i, cont);
      i--;
      removidos++;
    }
  }
  printf("Contatos de %s removidos: %d.\n\n", nome_aux, removidos);
  return cont;
}

int delete_pessoa(struct pessoa pessoas[], int n, int cont) {
  for(int i = n; i < (cont-1); i++){
    pessoas[i] = pessoas[i+1];
  }
  cont--;
  return cont;
}
// busca nomes contendo a string digitada e imprime todos na tela
void buscar_pessoa(struct pessoa pessoas[], int cont) {
  char nome_aux[51];
  int n, v = 0;
  scanf(" %s", nome_aux);
  printf("Resultado da busca:\n");
  for(int i = 0; i < cont; i++){
    n = 0;
    for(int j = 0; j < strlen(pessoas[i].nome)+1; j++) {
      if (n==strlen(nome_aux)){
        printf("(%d) %s	%s	%s	%s\n\n", (i+1), pessoas[i].nome, pessoas[i].end, pessoas[i].tel, pessoas[i].ani);
        v = 1;
        break;
      }
      if(nome_aux[n]==(pessoas[i].nome)[j]) {
        n++;
      }
    }
  }
  if (v == 0){
    printf("Nenhum contato.\n\n");
  }
}
//imprime todas as pessoas existentes na ordem de insercao
void imprimir_pessoas(struct pessoa pessoas[], int cont) {
  printf("Listagem:\n");
  if(cont == 0){
    printf("Nenhum contato.\n");
  }
  for(int i = 0; i < cont; i++){
    printf("(%d) %s	%s	%s	%s\n", (i+1), pessoas[i].nome, pessoas[i].end, pessoas[i].tel, pessoas[i].ani );
  }
  printf("\n");
}

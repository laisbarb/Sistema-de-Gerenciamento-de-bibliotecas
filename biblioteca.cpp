#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAX_USUARIOS 100
#define MAX_LIVROS 100
#define MAX_FILA 50
 
struct Usuario {
   char nome[50];
   char cpf[15];
   int idade;
   char matricula[20]; 
   char telefone[15];
   char email[50];
};
 
struct Livro {
   char titulo[100];
   char autor[50];
};
 
struct PedidoAluguel {
   struct Usuario usuario;
   struct Livro livro;
};
 
struct Fila {
   struct PedidoAluguel dados[MAX_FILA];
   int inicio;
   int fim;
   int total;
};
 
struct Emprestimo {
   struct Usuario usuario;
   struct Livro livro;
   struct Emprestimo *proximo;
};
 
struct Emprestimo *inicioHistorico = NULL;
 
void inserirHistorico(struct Usuario usuario, struct Livro livro) {
   struct Emprestimo *novo = malloc(sizeof(struct Emprestimo));
   if (!novo) {
       printf("Erro ao alocar memória!\n");
       return;
   }
   novo->usuario = usuario;
   novo->livro = livro;
   novo->proximo = NULL;
 
   if (inicioHistorico == NULL) {
       inicioHistorico = novo;
       return;
   }
 
   struct Emprestimo *atual = inicioHistorico;
   struct Emprestimo *anterior = NULL;
 
   while (atual != NULL) {
       if (strcmp(atual->usuario.matricula, usuario.matricula) == 0) {
           while (atual->proximo != NULL &&
                  strcmp(atual->proximo->usuario.matricula, usuario.matricula) == 0) {
               atual = atual->proximo;
           }
           novo->proximo = atual->proximo;
           atual->proximo = novo;
           return;
       }
       anterior = atual;
       atual = atual->proximo;
   }
   anterior->proximo = novo;
}
 
void trocarLivros(struct Livro *livroA, struct Livro *livroB) {
    struct Livro temp = *livroA;
    *livroA = *livroB;
    *livroB = temp;
}
 
void ordenarLivrosPorTitulo(struct Livro livros[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(livros[j].titulo, livros[j + 1].titulo) > 0) {
                trocarLivros(&livros[j], &livros[j + 1]);
            }
        }
    }
}
 
void ordenarLivrosPorAutor(struct Livro livros[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (strcmp(livros[j].autor, livros[j + 1].autor) > 0) {
                trocarLivros(&livros[j], &livros[j + 1]);
            }
        }
    }
}
 
int main() {
  struct Usuario usuarios[MAX_USUARIOS];
  struct Livro livros[MAX_LIVROS];
  struct Fila fila;
  int totalUsuarios = 0;
  int totalLivros = 0;
  fila.inicio = -1;
  fila.fim = -1;
  fila.total = 0;
  int opcao;
 
  do {
      printf("\nSISTEMA DE BIBLIOTECA\n");
      printf("1. Adicionar Usuario\n");
      printf("2. Listar Usuarios\n");
      printf("3. Adicionar Livro\n");
      printf("4. Listar Livros (Ordenado)\n");
      printf("5. Entrar na fila de aluguel\n");
      printf("6. Atender proximo da fila\n");
      printf("7. Mostrar fila de espera\n");
      printf("8. Visualizar historico de emprestimos\n");
      printf("0. Sair\n");
      printf("Escolha: ");
      scanf("%d", &opcao);
      while (getchar() != '\n');
 
      switch(opcao) {
          case 1: {
              if (totalUsuarios >= MAX_USUARIOS) {
                  printf("Limite de usuarios atingido!\n");
                  break;
              }
              printf("\nCadastro de Usuario\n");
              printf("Nome: ");
              fgets(usuarios[totalUsuarios].nome, 50, stdin);
              usuarios[totalUsuarios].nome[strcspn(usuarios[totalUsuarios].nome, "\n")] = '\0';
              printf("CPF: ");
              fgets(usuarios[totalUsuarios].cpf, 15, stdin);
              usuarios[totalUsuarios].cpf[strcspn(usuarios[totalUsuarios].cpf, "\n")] = '\0';
              printf("Idade: ");
              scanf("%d", &usuarios[totalUsuarios].idade);
              while (getchar() != '\n');
              printf("Matricula: ");
              fgets(usuarios[totalUsuarios].matricula, 20, stdin);
              usuarios[totalUsuarios].matricula[strcspn(usuarios[totalUsuarios].matricula, "\n")] = '\0';
              printf("Telefone: ");
              fgets(usuarios[totalUsuarios].telefone, 15, stdin);
              usuarios[totalUsuarios].telefone[strcspn(usuarios[totalUsuarios].telefone, "\n")] = '\0';
              printf("Email: ");
              fgets(usuarios[totalUsuarios].email, 50, stdin);
              usuarios[totalUsuarios].email[strcspn(usuarios[totalUsuarios].email, "\n")] = '\0';
              totalUsuarios++;
              printf("Usuario cadastrado com sucesso!\n");
              break;
          }

          case 2: {
               if (totalUsuarios == 0) {
                   printf("Nenhum usuario cadastrado.\n");
                   break;
               }
               printf("\nLista de Usuarios\n");
               for (int i = 0; i < totalUsuarios; i++) {
                   printf("Usuario %d:\n", i + 1);
                   printf("Nome: %s\n", usuarios[i].nome);
                   printf("CPF: %s\n", usuarios[i].cpf);
                   printf("Idade: %d\n", usuarios[i].idade);
                   printf("Matricula: %s\n", usuarios[i].matricula);
                   printf("Telefone: %s\n", usuarios[i].telefone);
                   printf("Email: %s\n", usuarios[i].email);
               }
               break;
           }
 
           case 3: {
               if (totalLivros >= MAX_LIVROS) {
                   printf("Limite de livros atingido!\n");
                   break;
               }
               printf("\nCadastro de Livro\n");
               printf("Titulo: ");
               fgets(livros[totalLivros].titulo, 100, stdin);
               livros[totalLivros].titulo[strcspn(livros[totalLivros].titulo, "\n")] = '\0';
               printf("Autor: ");
               fgets(livros[totalLivros].autor, 50, stdin);
               livros[totalLivros].autor[strcspn(livros[totalLivros].autor, "\n")] = '\0';
               totalLivros++;
               printf("Livro cadastrado com sucesso!\n");
               break;
           }
 
           case 4: {
               if (totalLivros == 0) {
                   printf("Nenhum livro cadastrado.\n");
                   break;
               }
 
               struct Livro livrosOrdenados[MAX_LIVROS];
               for(int i = 0; i < totalLivros; i++) {
                   livrosOrdenados[i] = livros[i];
               }
 
               int escolhaOrdenacao = 0;
               printf("\nComo deseja ordenar a lista de livros?\n");
               printf("1. Por Titulo\n");
               printf("2. Por Autor\n");
               printf("Escolha: ");
               scanf("%d", &escolhaOrdenacao);
               while (getchar() != '\n');
 
               switch(escolhaOrdenacao) {
                   case 1:
                       ordenarLivrosPorTitulo(livrosOrdenados, totalLivros);
                       break;
                   case 2:
                       ordenarLivrosPorAutor(livrosOrdenados, totalLivros);
                       break;
                   default:
                       printf("Opcao invalida! Mostrando na ordem de cadastro.\n");
                       break;
               }
 
               printf("\n--- Lista de Livros ---\n");
               for (int i = 0; i < totalLivros; i++) {
                   printf("Titulo: %s\n", livrosOrdenados[i].titulo);
                   printf("Autor: %s\n", livrosOrdenados[i].autor);
                   printf("--------------------\n");
               }
               break;
           }
 
           case 5: {
               if (fila.total >= MAX_FILA) {
                   printf("Fila cheia!\n");
                   break;
               }
               if (totalUsuarios == 0 || totalLivros == 0) {
                   printf("Cadastre pelo menos um usuario e um livro.\n");
                   break;
               }
               printf("\nUsuarios:\n");
               for (int i = 0; i < totalUsuarios; i++) {
                   printf("%d. %s (Matricula: %s)\n", i+1, usuarios[i].nome, usuarios[i].matricula);
               }
               int escolhaUsuario;
               printf("Escolha o usuario: ");
               scanf("%d", &escolhaUsuario);
               while (getchar() != '\n');
               if (escolhaUsuario < 1 || escolhaUsuario > totalUsuarios) {
                   printf("Usuario invalido.\n");
                   break;
               }
               printf("\nLivros:\n");
               for (int i = 0; i < totalLivros; i++) {
                   printf("%d. %s (Autor: %s)\n", i+1, livros[i].titulo, livros[i].autor);
               }
               int escolhaLivro;
               printf("Escolha o livro: ");
               scanf("%d", &escolhaLivro);
               while (getchar() != '\n');
               if (escolhaLivro < 1 || escolhaLivro > totalLivros) {
                   printf("Livro invalido.\n");
                   break;
               }
               if (fila.inicio == -1) fila.inicio = 0;
               fila.fim = (fila.fim + 1) % MAX_FILA;
               fila.dados[fila.fim].usuario = usuarios[escolhaUsuario - 1];
               fila.dados[fila.fim].livro = livros[escolhaLivro - 1];
               fila.total++;
               printf("%s entrou na fila para alugar '%s'\n",
                      usuarios[escolhaUsuario - 1].nome,
                      livros[escolhaLivro - 1].titulo);
               break;
           }
 
           case 6: {
               if (fila.total == 0 || fila.inicio == -1) {
                   printf("Fila vazia!\n");
                   break;
               }
               struct PedidoAluguel atendido = fila.dados[fila.inicio];
               printf("\nAtendendo:\n");
               printf("Usuario: %s (Matricula: %s)\n", atendido.usuario.nome, atendido.usuario.matricula);
               printf("Livro: %s\n", atendido.livro.titulo);
               printf("Livro alugado com sucesso!\n");
               inserirHistorico(atendido.usuario, atendido.livro);
               if (fila.inicio == fila.fim) {
                   fila.inicio = -1;
                   fila.fim = -1;
               } else {
                   fila.inicio = (fila.inicio + 1) % MAX_FILA;
               }
               fila.total--;
               break;
           }
 
           case 7: {
               if (fila.total == 0 || fila.inicio == -1) {
                   printf("Fila vazia!\n");
                   break;
               }
               printf("\nFila de Espera\n");
               int pos = fila.inicio;
               for (int i = 0; i < fila.total; i++) {
                   printf("%d. %s - Livro: %s\n", i+1,
                          fila.dados[pos].usuario.nome,
                          fila.dados[pos].livro.titulo);
                   pos = (pos + 1) % MAX_FILA;
               }
               break;
           }
 
           case 8: {
               if (inicioHistorico == NULL) {
                   printf("Nenhum empréstimo registrado.\n");
                   break;
               }
               printf("\nHistorico de Emprestimos\n");
               struct Emprestimo *atual = inicioHistorico;
               while (atual != NULL) {
                   printf("Usuario: %s (Matricula: %s)\n", atual->usuario.nome, atual->usuario.matricula);
                   printf("Livro: %s\n", atual->livro.titulo);
                   atual = atual->proximo;
               }
               break;
           }
           case 0: {
               printf("Encerrando o sistema...\n");
               break;
           }
 
           default:
               printf("Opcao invalida!\n");
      }
  } while (opcao != 0);
  struct Emprestimo *tmp;
  while (inicioHistorico != NULL) {
      tmp = inicioHistorico;
      inicioHistorico = inicioHistorico->proximo;
      free(tmp);
  }
  return 0;
}
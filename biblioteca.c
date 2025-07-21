/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#include <string.h>
 
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
 


struct Fila {

    struct Usuario dados[MAX_FILA];

    int inicio;

    int fim;

    int total;

};
 
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

        printf("4. Listar Livros\n");

        printf("5. Entrar na fila de aluguel\n");

        printf("6. Atender proximo da fila\n");

        printf("7. Mostrar fila de espera\n");

        printf("0. Sair\n");

        printf("Escolha: ");

        scanf("%d", &opcao);

        getchar();

        switch(opcao) {

            case 1: { 

                if (totalUsuarios >= MAX_USUARIOS) {

                    printf("Limite de usuarios atingido!\n");

                    break;

                }

                printf("Cadastro de Usuario");

                printf("Nome: ");

                fgets(usuarios[totalUsuarios].nome, 50, stdin);

                usuarios[totalUsuarios].nome[strcspn(usuarios[totalUsuarios].nome, "\n")] = '\0';

                printf("CPF: ");

                fgets(usuarios[totalUsuarios].cpf, 15, stdin);

                usuarios[totalUsuarios].cpf[strcspn(usuarios[totalUsuarios].cpf, "\n")] = '\0';

                printf("Idade: ");

                scanf("%d", &usuarios[totalUsuarios].idade);

                getchar();

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

                printf("\nUsuario adicionado com sucesso!\n");

                break;

            }

            case 2: { 

                if (totalUsuarios == 0) {

                    printf("\nNenhum usuario cadastrado!\n");

                    break;

                }

                printf("\n Lista de Usuarios\n");

                for (int i = 0; i < totalUsuarios; i++) {

                    printf("\nUsuario %d:\n", i+1);

                    printf("Nome: %s\n", usuarios[i].nome);

                    printf("CPF: %s\n", usuarios[i].cpf);

                    printf("Idade: %d\n", usuarios[i].idade);

                    printf("Matricula: %s\n", usuarios[i].matricula);

                    printf("Telefone: %s\n", usuarios[i].telefone);

                    printf("Email: %s\n", usuarios[i].email);

                    printf("-----------------------");

                }

                break;

            }

            case 3: { 

                if (totalLivros >= MAX_LIVROS) {

                    printf("Limite de livros atingido!\n");

                    break;

                }

                printf("\n--- Cadastro de Livro ---\n");

                printf("Titulo: ");

                fgets(livros[totalLivros].titulo, 100, stdin);

                livros[totalLivros].titulo[strcspn(livros[totalLivros].titulo, "\n")] = '\0';

                printf("Autor: ");

                fgets(livros[totalLivros].autor, 50, stdin);

                livros[totalLivros].autor[strcspn(livros[totalLivros].autor, "\n")] = '\0';

                totalLivros++;

                printf("\nLivro adicionado com sucesso!\n");

                break;

            }

            case 4: { 

                if (totalLivros == 0) {

                    printf("\nNenhum livro cadastrado!\n");

                    break;

                }

                printf("\n--- Lista de Livros ---\n");

                for (int i = 0; i < totalLivros; i++) {

                    printf("\nLivro %d:\n", i+1);

                    printf("Titulo: %s\n", livros[i].titulo);

                    printf("Autor: %s\n", livros[i].autor);

                }

                break;

            }

            case 5: { 

                if (fila.total >= MAX_FILA) {

                    printf("Fila cheia!\n");

                    break;

                }

                if (totalUsuarios == 0) {

                    printf("Nenhum usuario cadastrado!\n");

                    break;

                }

                printf(" Usuarios Disponiveis ");

                for (int i = 0; i < totalUsuarios; i++) {

                    printf("%d. %s (Matricula: %s)\n", i+1, usuarios[i].nome, usuarios[i].matricula);

                }

                int escolha;

                printf("\nEscolha o usuario: ");

                scanf("%d", &escolha);

                getchar();

                if (escolha < 1 || escolha > totalUsuarios) {

                    printf("Opcao invalida!\n");

                    break;

                }


                if (fila.inicio == -1) {

                    fila.inicio = 0;

                }

                fila.fim = (fila.fim + 1) % MAX_FILA;

                fila.dados[fila.fim] = usuarios[escolha-1];

                fila.total++;

                printf("\n%s entrou na fila de espera!\n", usuarios[escolha-1].nome);

                break;

            }

            case 6: { 

                if (fila.inicio == -1) {

                    printf("Fila vazia! Nenhum usuario para atender.\n");

                    break;

                }

                struct Usuario atendido = fila.dados[fila.inicio];

                printf("\nAtendendo usuario:\n");

                printf("Nome: %s\n", atendido.nome);

                printf("Matricula: %s\n", atendido.matricula);

                printf("Livro alugado com sucesso!\n");

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

                if (fila.inicio == -1) {

                    printf("Fila vazia!\n");

                    break;

                }

                printf(" Fila de Espera");

                int pos = fila.inicio;

                for (int i = 0; i < fila.total; i++) {

                    printf("%d. %s (Matricula: %s)\n", i+1, fila.dados[pos].nome, fila.dados[pos].matricula);

                    pos = (pos + 1) % MAX_FILA;

                }

                break;

            }

            case 0: {

                printf("\nEncerrando o sistema...\n");

                break;

            }

            default: {

                printf("\nOpcao invalida! Tente novamente.\n");

            }

        }

    } while (opcao != 0);

    return 0;

}
 
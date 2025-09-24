# Sistema de Gerenciamento de Biblioteca em C++

![Linguagem C](https://img.shields.io/badge/Language-C-blue.svg) ![Compilador](https://img.shields.io/badge/Compiler-GCC-orange.svg) ![Licença](https://img.shields.io/badge/License-MIT-yellow.svg)

Um sistema de gerenciamento de biblioteca desenvolvido em C++, operado via linha de comando (CLI). Este projeto foi criado para demonstrar a aplicação prática de estruturas de dados e algoritmos fundamentais.

## 📝 Sobre o Projeto

Este é um programa de console que simula as operações básicas de uma biblioteca, permitindo o cadastro de usuários e livros, o gerenciamento de uma fila de espera para aluguéis e a visualização do histórico de empréstimos. O foco principal não é a interface, mas sim a lógica de programação e a correta implementação e manipulação de diferentes estruturas de dados.

### ✨ Principais Funcionalidades

* **Cadastro de Usuários e Livros:** Permite adicionar, armazenar e listar múltiplos usuários e livros.
* **Listagem Ordenada:** Oferece a opção de listar os livros do acervo em ordem alfabética, seja por título ou por autor.
* **Fila de Espera:** Implementa um sistema de fila (FIFO - First-In, First-Out) para gerenciar os pedidos de aluguel de forma justa.
* **Histórico de Empréstimos:** Mantém um registro de todos os livros que foram emprestados, vinculando o livro ao usuário.
* **Interface de Menu:** Interação com o usuário através de um menu de opções simples e intuitivo no terminal.

## 🧠 Estruturas de Dados e Conceitos Aplicados

O núcleo deste projeto é a demonstração dos seguintes conceitos de Ciência da Computação:

* **`struct`**: Utilizada para modelar as entidades do sistema (Usuário, Livro, Pedido, Empréstimo).
* **Arrays**: Usados para o armazenamento principal dos cadastros de usuários e livros.
* **Filas (Queue)**: Implementada com um array circular para gerenciar a lista de espera de aluguéis de forma eficiente.
* **Listas Encadeadas (Linked List)**: Usada para criar o histórico de empréstimos, permitindo um crescimento dinâmico do número de registros.
* **Algoritmos de Ordenação (Sorting)**: Implementação do algoritmo Bubble Sort para ordenar o acervo de livros.
* **Gerenciamento de Memória Dinâmica**: Uso de `malloc()` e `free()` para alocar e liberar memória para os nós da lista encadeada do histórico.

## 👨‍💻 Autor

Feito por **Lais Barbosa**.


#include <stdio.h>

void menu(){
  printf("\n");
  printf("+-----------------------------------+\n");
  printf("|----------------MENU---------------|\n");
  printf("| 1 - Começar o jogo ---------------|\n");
  printf("| 2 - Criar personagem -------------|\n");
  printf("| 3 - Exibir personagens -----------|\n");
  printf("| 4 - Editar personagens -----------|\n");
  printf("| 5 - Excluir personagem ------------|\n");
  printf("+-----------------------------------+\n");
  printf("Escolha a opção desejada:\n");
  int opcao;
  scanf("%d", &opcao);

  switch(opcao){
    case 1:
      // comecarJogo();
      break;
    case 2:
      // criarPersonagem();
      break;
    case 3:
      // exibirPersonagens();
      break;
    case 4:
      // editarPersonagens();
      break;
    case 5:
      // excluirPersonagem();
      break;
    default:
      printf("Você deve escolher uma entre as opções mostradas.\n");
      menu();
  }
}

int main(){
  printf("Bem-vindo(a) ao melhor jogo de todos os tempos da última semana!\n");
  menu();
}
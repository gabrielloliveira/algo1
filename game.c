#include <stdio.h>

void criarPersonagem(){
  struct personagem{
    char nome[255];
    int vida;
    int ataque;
    int especial;
    int defesa;
  };
  struct personagem jogador;
  jogador.vida = 100;
  jogador.especial = 50;
  printf("Digite o nome do seu personagem:\n");
  scanf (" %255[^\n]", jogador.nome);
  printf("Digite a quantidade de dano que o ataque do seu personagem causa: (1-20)\n");
  scanf(" %d", &jogador.ataque);
  
  // Blingadem para o usuário não digitar valores fora do intervalo de 1-50
  int next = 0;
  do{
    if(jogador.ataque >=1 && jogador.ataque <= 50){
      next = 1;
    }
    else{
      next = 0;
      printf("Você deve digitar um valor entre 1-50\n");
      scanf(" %d", &jogador.ataque);
    }
  }while(next == 0);

  printf("Agora digite o valor de dano que seu escudo consegue absorver: (1-20)\n");
  scanf(" %d", &jogador.defesa);

  // Blingadem para o usuário não digitar valores fora do intervalo de 1-20 para a defesa
  next = 0;
  do{
    if(jogador.defesa >=1 && jogador.defesa <= 20){
      next = 1;
    }
    else{
      next = 0;
      printf("Você deve digitar um valor entre 1-20 para o seu escudo\n");
      scanf(" %d", &jogador.defesa);
    }
  }while(next == 0);

  printf("nome: %s\nvida: %d\nataque: %d\nespecial: %d\nescudo: %d\n", jogador.nome, jogador.vida, jogador.ataque, jogador.especial, jogador.defesa);

}

void menu(){
  printf("\n");
  printf("+-----------------------------------+\n");
  printf("|----------------MENU---------------|\n");
  printf("| 1 - Começar o jogo ---------------|\n");
  printf("| 2 - Criar personagem -------------|\n");
  printf("| 3 - Exibir personagens -----------|\n");
  printf("| 4 - Editar personagens -----------|\n");
  printf("| 5 - Excluir personagem -----------|\n");
  printf("+-----------------------------------+\n");
  printf("Escolha a opção desejada:\n");
  int opcao;
  scanf("%d", &opcao);

  switch(opcao){
    case 1:
      // comecarJogo();
      break;
    case 2:
      criarPersonagem();
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
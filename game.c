#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declarando a estrutura para o tipo personagem de forma global
struct personagem{
  char nome[255];
  int vida;
  int ataque;
  int especial;
  int defesa;
};
struct personagem jogador[50];

// Função para o algoritmo 'pausar' a execução enquando o usuário não digitar um enter
void pause(){
  printf("Aperte enter para continuar...\n");
  char buffer[80];
  fgets(buffer, sizeof buffer, stdin);
  getchar();
  void menu();
  menu();
}

// Função que cria o personagem que vai ser controlado pelo usuário
void criarPersonagem(){
  if(jogador[0].vida == 100){
    printf("Você já criou seu personagem. Comece o jogo\n");
    pause();
  }else{
    jogador[0].vida = 100;
    jogador[0].especial = 50;
    printf("Digite o nome do seu personagem:\n");
    scanf (" %255[^\n]", jogador[0].nome);
    printf("Digite a quantidade de dano que o ataque do seu personagem causa: (1-30)\n");
    scanf(" %d", &jogador[0].ataque);
    
    // Blingadem para o usuário não digitar valores fora do intervalo de 1-30
    int next = 0;
    do{
      if(jogador[0].ataque >=1 && jogador[0].ataque <= 30){
        next = 1;
      }
      else{
        next = 0;
        printf("Você deve digitar um valor entre 1-30\n");
        scanf(" %d", &jogador[0].ataque);
      }
    }while(next == 0);

    printf("Agora digite o valor de dano que seu escudo consegue absorver: (1-20)\n");
    scanf(" %d", &jogador[0].defesa);

    // Blingadem para o usuário não digitar valores fora do intervalo de 1-20 para a defesa
    next = 0;
    do{
      if(jogador[0].defesa >=1 && jogador[0].defesa <= 20){
        next = 1;
      }
      else{
        next = 0;
        printf("Você deve digitar um valor entre 1-20 para o seu escudo\n");
        scanf(" %d", &jogador[0].defesa);
      }
    }while(next == 0);

    // printf("nome: %s\nvida: %d\nataque: %d\nespecial: %d\nescudo: %d\n", jogador[0].nome, jogador[0].vida, jogador[0].ataque, jogador[0].especial, jogador[0].defesa);
    printf("Parabéns! Você criou seu personagem\n");
    pause();
  }  
}

// Mostra todos personagens criados
void exibirPersonagens(){
  // Verificação para saber se existe os outro jogadores
  if(jogador[1].vida != 100){
    // Criando os jogadores inimigos
    char possiveisNomes[50][255] = {
      " ",
      "Mago Mutante",
      "Gatinho Fofo",
      "SPP",
      "Troll de Gelo",
      "Feiticeira Sombria",
      "Goblim",
      "Caçador de bruxos",
      "Arqueiro",
      "Fantasma",
      "Coração cremoso",
      "Eu sou seu pai",
      "Prova de algoritmo",
      "Hu3Hu3",
      "Cavaleiro solitário",
      "The little boss",
      "Oi sumida rs",
      "Café com leite",
      "Mercado de trabalho",
      "Essa barra que é gostar de você",
      "ENEM",
      "Máscara",
      "Gurú do Himalaia",
      "Java",
      "Usuário Final",
      "Bug Escondido",
      "Scooby Doo",
      "Ben 10",
      "Tundercats",
      "Goku",
      "Vegeta",
      "Bills",
      "Jiren",
      "Whis",
      "Zen oh",
      "Yugi",
      "Tio do jackie chan",
      "Talismã do dragão",
      "Megazord",
      "Shenlong",
      "Thanos",
      "Peter do DeadPool",
      "Logan",
      "Homer",
      "Bart",
      "Lisa",
      "Marge",
      "Lindinha",
      "Florzinha",
      "Docinho"
    }; 
    
    for(int i = 1; i < 50; ++i){
      jogador[i].vida = 100;
      jogador[i].especial = 50;
      jogador[i].ataque = (rand()%29) + 1;
      jogador[i].defesa = (rand()%19) + 1;
      strcpy(jogador[i].nome, possiveisNomes[i]);
    }
  }
  if(jogador[0].vida == 100){
    printf("+-----------Jogadores------------+\n");
    for (int i = 0; i < 50; ++i){
      printf("| %d - %s\n", i+1, jogador[i].nome);
    }
    printf("+--------------------------------+\n");
  }else{
    // Mostra somente os jogadores controlados pelo jogo
    printf("+-----------Jogadores------------+\n");
    for (int i = 1; i < 50; ++i){
      printf("| %d - %s\n", i, jogador[i].nome);
    }
    printf("+--------------------------------+\n");
  }
  pause();
}

void comecarJogo(){
  if(jogador[0].vida == 100){
    printf("Tem jogador\n");
  }else{
    printf("Antes de iniciar o jogo você deve criar o seu personagem!\n");
    pause();
  }
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
      comecarJogo();
      break;
    case 2:
      criarPersonagem();
      break;
    case 3:
      exibirPersonagens();
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
  srand(time(NULL));
  printf("Bem-vindo(a) ao melhor jogo de todos os tempos da última semana!\n");
  menu();
}
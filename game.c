#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 50


// Pesquisar sobre atoi e atof
// Declarando a estrutura para o tipo personagem de forma global
struct personagem{
  char nome[255];
  int vida;
  int ataque;
  int especial;
  int defesa;
};
struct personagem jogador[TAM];
int tamanho = 9;

// Função para o algoritmo 'pausar' a execução enquando o usuário não digitar um enter
void pause(){
  printf("Aperte enter para continuar...\n");
  char buffer[80];
  fgets(buffer, sizeof buffer, stdin);
  getchar();
  system("cls || clear");
  void menu();
  menu();
}

void criaInimigo(){
  // Criando os jogadores inimigos
  char possiveisNomes[9][255] = {
    "Gatinho Fofo",
    "SPP",
    "Essa barra que é gostar de você",
    "Feiticeira Sombria",
    "Tio do jackie chan",
    "Oi sumida rs",
    "Homer",
    "Mercado de trabalho",
    "Coração cremoso"
  }; 

  if(jogador[1].vida != 100){
    for(int i = 0; i < 9; ++i){
      jogador[i].vida = 100;
      jogador[i].especial = 50;
      jogador[i].ataque = (rand()%29) + 1;
      jogador[i].defesa = (rand()%19) + 1;
      strcpy(jogador[i].nome, possiveisNomes[i]);
    }
  }
}

// Função que cria o personagem
void criarPersonagem(){
  char aux[80];
  // Adiciono o jogador na posição tamanho porque ela guarda a quantidade de
  // jogadores cadastrados (que também é o primeiro índice vazio no vetor)
  jogador[tamanho].vida = 100;
  jogador[tamanho].especial = 50;
  printf("Digite o nome do seu personagem:\n");
  scanf (" %255[^\n]", jogador[tamanho].nome);
  printf("Digite a quantidade de dano que o ataque do seu personagem causa: (1-30)\n");
  
  // Blindagem para não receber caractere ou string
  scanf(" %80[^\n]", aux);
  jogador[tamanho].ataque = atoi(aux);
  if (jogador[tamanho].ataque == 0){
    do{
      printf("Você deve digitar um número\n");  
      scanf(" %80[^\n]", aux);
      jogador[tamanho].ataque = atoi(aux);
    }while(jogador[tamanho].ataque == 0);
  }
  // Blingadem para o usuário não digitar valores fora do intervalo de 1-30
  int next = 0;
  do{
    if(jogador[tamanho].ataque >=1 && jogador[tamanho].ataque <= 30){
      next = 1;
    }
    else{
      next = 0;
      printf("Você deve digitar um valor entre 1-30\n");
      scanf(" %d", &jogador[tamanho].ataque);
    }
  }while(next == 0);

  printf("Agora digite o valor de dano que seu escudo consegue absorver: (1-20)\n");
  
  // Blingagem para não receber caractere ou string
  scanf(" %80[^\n]", aux);
  jogador[tamanho].defesa = atoi(aux);
  if (jogador[tamanho].defesa == 0){
    do{
      printf("Você deve digitar um número\n");
      scanf(" %80[^\n]", aux);
      jogador[tamanho].defesa = atoi(aux);
    }while(jogador[tamanho].defesa == 0);
  }

  // Blingadem para o usuário não digitar valores fora do intervalo de 1-20 para a defesa
  next = 0;
  do{
    if(jogador[tamanho].defesa >=1 && jogador[tamanho].defesa <= 20){
      next = 1;
    }
    else{
      next = 0;
      printf("Você deve digitar um valor entre 1-20 para o seu escudo\n");
      scanf(" %d", &jogador[tamanho].defesa);
    }
  }while(next == 0);

  printf("Parabéns! Você criou seu personagem\n");
  tamanho++;
  pause();  
}

// Mostra todos personagens do jogo
void exibirPersonagens(){
  printf("+-----------Jogadores------------+\n");
  int indice = 1;
  for (int i = 0; i < tamanho; ++i){
    if (jogador[i].vida == 100){
      printf("| %d - %s\n", indice, jogador[i].nome);
      indice++;
    }
  }
  printf("+--------------------------------+\n");
}
// Edita o personagem escolhido
void editarPersonagens(int numPersonagem){
  int next = 0;
  numPersonagem--;
  do{
    if (numPersonagem >= 0 && numPersonagem < tamanho){
      printf("Qual o novo nome do personagem?\n");
      scanf(" %255[^\n]", jogador[numPersonagem].nome);
      printf("Qual o tamanho do dano do seu ataque? 1-30\n");
      scanf(" %d", &jogador[numPersonagem].ataque);

      do{
        if(jogador[numPersonagem].ataque >=1 && jogador[numPersonagem].ataque <= 30){
          next = 1;
        }
        else{
          next = 0;
          printf("Você deve digitar um valor entre 1-30\n");
          scanf(" %d", &jogador[numPersonagem].ataque);
        }
      }while(next == 0);

      printf("Agora digite o valor de dano que o escudo vai absorver: 1-20\n");
      scanf(" %d", &jogador[numPersonagem].defesa);

      do{
        if(jogador[numPersonagem].defesa >=1 && jogador[numPersonagem].defesa <= 20){
          next = 1;
        }
        else{
          next = 0;
          printf("Você deve digitar um valor entre 1-20 para o escudo\n");
          scanf(" %d", &jogador[numPersonagem].defesa);
        }
      }while(next == 0);

      printf("Jogador alterado com sucesso!\n");
      printf("%s\n", jogador[numPersonagem].nome);
      pause();      

    }else{
      printf("Você só pode digitar valores entre 1-%d\n", tamanho);
      scanf("%d", &numPersonagem);
      numPersonagem--;
    }
  }while(next == 0);
}

// Função que retorna o indíce do vetor do personagem 
int retornaIndiceDoPersonagem(int numDigitado){
  int indice = 1;
  for (int i = 0; i < TAM; ++i){
    if (jogador[i].vida == 100){
      if(indice == numDigitado){
        return i;
      }
      indice++;
    }
  }

  return 0;
}

// Exclui o personagem
void excluirPersonagem(int numPersonagem){
  int num = retornaIndiceDoPersonagem(numPersonagem);
  char nomeJogador[255];
  strcpy(nomeJogador, jogador[num].nome);
  for (int i = numPersonagem; i < TAM; ++i){
    strcpy(jogador[i-1].nome, jogador[i].nome);
    jogador[i-1].ataque = jogador[i].ataque;
    jogador[i-1].defesa = jogador[i].defesa;
    if(i == TAM - 1){
      jogador[i].vida == -1;
    }
  }
  tamanho--;
  // strcpy(jogador[num].nome, "excluido");
  // jogador[num].vida = -1;
  printf("Jogador %s excluído com sucesso!\n", nomeJogador);
  pause();
}

// Começa o jogo
void comecarJogo(){
  char aux[80];
  int numPersonagem;
  // Verifica se tem personagem criado pelo usuário
  if(jogador[9].vida == 100){
    printf("%d tamanho\n", tamanho);
    // Tamanho - 1 é o tamanho do vetor de personagens já criado
    if(tamanho - 1 > 9){
      printf("Escolha um personagem para jogar dos quais você criou:\n");
      printf("+-------Com qual você quer jogar?---------+\n");  
      int indice = 1;
      for (int i = 9; i < tamanho; ++i){
        printf("| %d - %s\n", indice, jogador[i].nome);
        indice++;
      }
      printf("+-----------------------------------------+\n");
      scanf(" %80[^\n]", aux);
      numPersonagem = atoi(aux);
      if (numPersonagem == 0){
        do{
          printf("Você deve digitar um número\n");
          scanf(" %80[^\n]", aux);
          numPersonagem = atoi(aux);
        }while(numPersonagem == 0);
      }else if (numPersonagem >=1 && numPersonagem <= indice){
        indice = 1;
        int indiceJogadorNoVetor;
        for (int i = 9; i < tamanho; ++i){
          if (indice == numPersonagem){
            indiceJogadorNoVetor = i;  
          }
          indice++;
        }
        printf("Jogador escolhido foi: %s\n", jogador[indiceJogadorNoVetor].nome);
        printf("Aperte enter para começar o jogo...\n");
        char buffer[80];
        fgets(buffer, sizeof buffer, stdin);
        getchar();
        system("cls || clear");
      }else{
        int next = 0;
        do{
          printf("Você deve digitar um número entre 1 e %d\n", indice);
          scanf(" %80[^\n]", aux);
          numPersonagem = atoi(aux);
          if (numPersonagem >=1 && numPersonagem <= indice){
            next = 1;
          }
        }while(next == 0);
      }
    }else{
      printf("Você vai começar com %s\n", jogador[9].nome);
      printf("Aperte enter para começar o jogo...\n");
      char buffer[80];
      fgets(buffer, sizeof buffer, stdin);
      getchar();
      system("cls || clear");
    }
  }else{
    printf("Antes de iniciar o jogo você deve criar o seu personagem!\n");
    pause();
  }
}

// Mostra o menu e vê qual opção o usuário escolheu
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
  int opcao, numPersonagem;
  char aux[80];
  scanf(" %80[^\n]", aux);
  opcao = atoi(aux);
  if (opcao == 0){
    do{
      printf("Você deve digitar um número entre 1 e 5\n");
      scanf(" %80[^\n]", aux);
      opcao = atoi(aux);
    }while(opcao == 0);
  }
  switch(opcao){
    case 1:
      comecarJogo();
      break;
    case 2:
      criarPersonagem();
      break;
    case 3:
      exibirPersonagens();
      pause();
      break;
    case 4:
      exibirPersonagens();
      printf("Qual o número do personagem que você deseja editar?\n");
      scanf(" %80[^\n]", aux);
      numPersonagem = atoi(aux);
      if (numPersonagem == 0){
        do{
          printf("Você deve digitar somente um número\n");
          scanf(" %80[^\n]", aux);
          numPersonagem = atoi(aux);
        }while(numPersonagem == 0);
      }
      editarPersonagens(numPersonagem);
      break;
    case 5:
      exibirPersonagens();
      printf("Qual o número do personagem que você quer excluir?\n");
      scanf(" %80[^\n]", aux);
      numPersonagem = atoi(aux);
      if (numPersonagem == 0){
        do{
          printf("Você deve digitar somente um número\n");
          scanf(" %80[^\n]", aux);
          numPersonagem = atoi(aux);
        }while(numPersonagem == 0);
      }
      excluirPersonagem(numPersonagem);
      break;
    default:
      printf("Você deve escolher uma entre as opções mostradas.\n");
      pause();
      break;
  }    
}

int main(){
  srand(time(NULL));
  printf("Bem-vindo(a) ao melhor jogo de todos os tempos da última semana!\n");
  criaInimigo();
  menu();
}
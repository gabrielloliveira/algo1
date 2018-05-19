#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 50

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
int exibirPersonagens(){
  if (tamanho > 0){
    printf("+-----------Jogadores------------+\n");
    int indice = 1;
    for (int i = 0; i < tamanho; ++i){
      if (jogador[i].vida == 100){
        printf("| %d - %s\n", indice, jogador[i].nome);
        indice++;
      }
    }
    printf("+--------------------------------+\n");
    return 1;
  }else{
    printf("Não possui nenhum jogador no game.\n");
    return 0;
  }
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

// Variação da função de excluir inimigo, sem chamada para função menu e sem mensagem imprimindo na tela
void mataInimigo(int numPersonagem){
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
  printf("Jogador %s excluído com sucesso!\n", nomeJogador);
  pause();
}

void executaPartida(int indiceJogador){
  printf("Bem-vindo(a) %s, o jogo funciona dessa maneira:\n", jogador[indiceJogador].nome);
  printf("Aparecerá os inimigos aleatoriamente. Você tem direito a 1 ataque por vez.\n");
  printf("Após 3 ataques você tem a opção de lançar um poder especial com dano de 50.\n");
  printf("Sua vida é de 100. Cada inimigo que você mata, ganha +1 no escore total.\n");
  printf("Saiba que a sua vida não regenera.\n");
  printf("Boa Sorte!\n\n");
  int inimigo;
  char aux[80];
  do{
    int escore = 0;
    // tamanho -2 é o indicedo último inimigo
    inimigo = rand()%(tamanho-2);
    printf("%d inimigo\n", inimigo);
    printf("Você vai lutar com: %s\n", jogador[inimigo].nome);
    printf("Vida: %d\n", jogador[inimigo].vida);
    printf("Ataque: %d\n", jogador[inimigo].ataque);
    printf("Escudo: %d\n", jogador[inimigo].defesa);
    printf("Especial: %d\n", jogador[inimigo].especial);
    do{
      int cEspecial = 0;
      // if (){
        
      // }
      printf("Digite 1 para atacar:\n");
      scanf(" %80[^\n]", aux);
      do{
        if(atoi(aux) != 1){
          do{
            printf("Você deve digitar o número 1\n");  
            scanf(" %80[^\n]", aux);
          }while(atoi(aux) != 1); 
        }
      }while(atoi(aux) != 1);

      int dano = jogador[indiceJogador].ataque - jogador[inimigo].defesa;
      if (dano < 0){
        dano *= -1;
      }
      jogador[inimigo].vida -= dano;
      cEspecial++;
      if(jogador[inimigo].vida <= 0){
        jogador[inimigo].vida = 0;
        printf("------------------------------\n");
        printf("Vida do inimigo: %d\n", jogador[inimigo].vida);
        printf("Parabéns! Você venceu essa luta.\n");
        printf("------------------------------\n");
        escore++;
        break;
      }else{
        printf("------------------------------\n");
        printf("Vida do inimigo: %d\n", jogador[inimigo].vida);
        printf("Vez do inimigo.\n");
        printf("------------------------------\n");
      }
      int danoInimigo = jogador[inimigo].ataque - jogador[indiceJogador].defesa;
      if (danoInimigo < 0){
        danoInimigo *= -1;
      }
      jogador[indiceJogador].vida -= danoInimigo;
      if(jogador[indiceJogador].vida <= 0){
        jogador[indiceJogador].vida = 0;
        printf("------------------------------\n");
        printf("Sua vida: %d\n", jogador[indiceJogador].vida);
        printf("Que pena! Você perdeu. Game Over.\n");
        printf("Seu escore: %d\n", escore);
        pause();
        printf("------------------------------\n");
      }else{
        printf("------------------------------\n");
        printf("Sua vida: %d\n", jogador[indiceJogador].vida);
      }
    }while(jogador[inimigo].vida > 0);
    mataInimigo(inimigo+1);
    printf("Seu escore: %d\n", escore);
  }while(jogador[indiceJogador].vida > 0);
}

// Começa o jogo
void comecarJogo(){
  char aux[80];
  int numPersonagem;
  // Verifica se tem personagem criado pelo usuário
  if(jogador[9].vida == 100){
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
        executaPartida(indiceJogadorNoVetor);
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
      executaPartida(9);
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
  printf("| 6 - Sair do game -----------------|\n");
  printf("+-----------------------------------+\n");
  printf("Escolha a opção desejada:\n");
  int opcao, numPersonagem, temPersonagem;
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
      temPersonagem = exibirPersonagens();
      pause();
      break;
    case 4:
      temPersonagem = exibirPersonagens();
      if (temPersonagem == 1){
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
      }else{
        pause();
      }
      break;
    case 5:
      temPersonagem = exibirPersonagens();
      if (temPersonagem == 1){
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
      }else{
        pause();
      }
      break;
    case 6:
      exit(1);
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
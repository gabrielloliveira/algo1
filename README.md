# Projeto Final Algoritmos e Programação I

- Projeto final da disciplina Algoritmos e Programação I do curso de Sistemas de Informação.
- O projeto final se trata de um jogo RPG desenvolvido na linguagem C, criado usando os fundamentos de programação vistos em sala de aula. Ex.: ```funções```, ```vetores```, ```matrizes```, ```estruturas```, etc.

## Do propósito:
- Trata-se de um trabalho universitário que visa compor a última nota da matéria Algoritmos e Programação I utilizando os conceitos de programação apresentados em sala.  

## Do desenvolvimento:
- O jogo foi criado utilizando o S.O. Ubuntu 18.04 LTS
- A versão do compilador é GCC 7.3.0

## Da aplicação:
- O game possui as características de um sistema CRUD.
- Quando o jogo é executado, é exibido no terminal ou CMD, o menu da aplicação.
- Todas as entradas do usuário são verificadas para eliminar qualquer tipo de bug que possa ocasionar a má execução do código e/ou a finalização do programa.

#### Criar personagem.
- Um personagem tem atributos de nome, vida, ataque, defesa, especial, quantidade máximo de escores conseguidos pelo usuário e um campo que identifica se o personagem foi criado pelo usuário, chamado criadoPorUsuario, que recebe um número inteiro.
- Quando o usuário está criando o personagem, só poderá escolher os valores de alguns atributos. São eles: Nome, ataque e defesa. Os demais campos têm valores pré-definidos.

#### Exibir personagem.
- Essa função retorna o nome de todos os personagens cadastrados no jogo e quantidade máxima de escores que o usuário conseguiu com o personagem.

#### Editar personagem.
- Esta função exibe a tabela com os personagens cadastrados e solicita do usuário o ID do personagem a ser editado.
- Se o usuário inserir um número válido, o jogo mostrará um painel com as demais informações do personagem, como vida, ataque, defesa e especial.
- O usuário só poderá editar os valores de nome, vida e ataque.

#### Excluir personagem.
- Esta função também exibe uma tabela com os personagens cadastrados e solicita do usuário o ID do personagem a ser excluído.
- Caso o usuário insira um ID válido, o personagem será excluído do game.

#### Começar o jogo.
- Esta função primeiro verifica se o usuário criou um personagem, caso não tenha criado, exibe a mensagem que deve ser criado.
- Caso o usuário tenha criado somente um personagem, o jogo automaticamente irá começar com esse personagem.
- Se o usuário criou mais de um personagem, o jogo mostra uma tabela com os personagens que ele criou e solicita para que escolha um personagem para começar o jogo.
- A opção de começar a partida sorteia os inimigos com quem o usuário vai lutar de forma aleatória. 
- O usuário só poderá começar a partida após criar seu personagem. Caso ele tenha criado mais de um, o game irá solicitar com qual personagem o usuário irá jogar.  
- O modo de combate é de 1 ataque por vez.
- O jogo solicita que o usuário aperte a tecla número 1 para lançar o ataque.
- Após 3 ataques, o jogador do usuário tem a opção de lançar o seu especial (dano 50).
- A partida acaba quando o usuário morre, ou seja, tem a vida de seu personagem igual a 0.

## Das limitações:
- O jogo não possui integração com banco de dados, ou seja, toda vez que o jogo é reiniciado as configurações voltam ao padrão.
- Não foi implementada nenhum tipo de interface gráfica ou animação.
- O jogo não possui classes para os personagens, nem aumento de nível do jogador conforme o tempo jogado.
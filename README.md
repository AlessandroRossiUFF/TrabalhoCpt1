1) O tabuleiro deve ser representado por uma matriz 8x8 de números inteiros. As casas vazias possuem
o valor 0. As pedras brancas são indicadas pelo valor 1 e as pedras pretas pelo valor -1.

2) Cada jogada é representada pelo struct jogada (indicado abaixo).
3) Faça uma função IniciaTabuleiro(), que receba uma matriz como parâmetro e retorne o tabuleiro na
posição inicial.

4) O programa deve ter uma função DesenhaTabuleiro(), que receba o tabuleiro (matriz) e desenhe na
tela as pedras já colocadas no tabuleiro da melhor forma possível (parecendo uma matriz na tela). A
função também deve indicar na tela a numeração das linhas e colunas.


5) Faça uma função EscolheJogada(), na qual o jogador da vez indique uma linha e uma coluna onde ele
deseja colocar sua pedra. A jogada (struct jogada) deve ser retornada pela função.

6) Faça uma função ExecutaJogada() que recebe o tabuleiro (matriz), o jogador da vez e a jogada (struct
jogada) retornada pela função EscolheJogada(). Se a jogada for válida, a função deve modificar o
tabuleiro de acordo com as regras e retornar 1; caso contrário, deve manter o tabuleiro como está e
retornar 0.

7) Se a função ExecutaJogada() retornar 0, o programa deve indicar que a jogada é inválida e solicitar
uma nova jogada. Isso deve acontecer até que o jogador da vez informe uma jogada válida.
Considere, nessa primeira versão do trabalho, que sempre existirá pelo menos uma jogada valida.

8) Se a função ExecutaJogada() retornar 1, o programa deve mudar o jogador da vez.
9) Quando nenhuma casa estiver vazia, o jogo deve informar quem foi o jogador vencedor ou se houve
empate.
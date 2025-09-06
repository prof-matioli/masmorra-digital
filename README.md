# masmorra-digital
Desafio simples para os alunos praticarem lógica de programação e manipulação de vetores e matrizes.
  
Clone o repositório e então dê checkout no branch que deseja analisar.  
Cada fase do desafio é um branch no repositório: fase1, fase2, fase3 e fase4  

# Fase Bonus

## Explicação das Funcionalidades Bônus Implementadas:

### Inimigos ('I'):

* __Lógica__: Foram adicionados inimigos ao mapa. A lógica de movimento agora inclui uma verificação que impede o herói de se mover para uma casa ocupada por um inimigo. É uma extensão simples da verificação de colisão com paredes.

* __Código__: Um if adicional dentro do while principal verifica se a próxima posição contém um 'I'.*

### Coleta de Moedas ('M'):

* __Lógica__: O mapa agora contém moedas. Uma nova variável, moedasColetadas, foi criada para rastrear quantas moedas o herói pegou. Quando o herói se move para uma casa com uma moeda, a moeda "desaparece" (o herói a ocupa) e o contador é incrementado. O placar de moedas é exibido a cada turno.

* __Código__: Uma variável moedasColetadas e uma verificação if para a casa 'M' foram adicionadas. A interface do usuário também foi atualizada para mostrar a contagem.

### Mapa Aleatório:

* __Lógica__: Esta é a mudança mais significativa. Em vez de um mapa fixo, a masmorra é gerada proceduralmente no início do programa. Isso garante que cada partida seja única, aumentando o fator "replay".

* __Código:__

  - Uso das bibliotecas <stdlib.h> e <time.h>.

  - srand(time(NULL)); é chamado no início para "semear" o gerador de números aleatórios, garantindo que a sequência de números seja diferente a cada execução.

  - O mapa é primeiro preenchido com chão e depois as paredes da borda são desenhadas.

  - Um laço for é usado para posicionar um número definido de paredes internas, moedas, inimigos e a saída em posições aleatórias.

  - É crucial a verificação dentro de um do-while para garantir que um novo item só seja colocado em uma casa vazia (' '), evitando que paredes, moedas ou a saída apareçam umas sobre as outras ou sobre a posição inicial do herói.
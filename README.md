# Escada Rolante
Este projeto foi desenvolvido como parte da disciplina de Sistemas Operacionais, com o objetivo de abordar a resolução de um problema relacionado à escada rolante. O desafio foi proposto durante a Maratona de Programação 2021 promovida pela Sociedade Brasileira de Computação (SBC-ICPC).

# Descrição do Problema
Você acaba de inventar um novo tipo de escada rolante: uma escada rolante dupla. Escadas rolantes normais levam as pessoas de uma das pontas para a outra, mas não na direção contrária, enquanto que as escadas rolantes duplas podem levar pessoas de qualquer uma das pontas para a outra.
Leva-se 10 segundos para que a escada rolante dupla leve uma pessoa de uma das pontas até a outra. Isto é, se a pessoa entra na escada rolante dupla em uma das pontas no momento I, então vai sair na outra ponta no momento T + 10 - esta pessoa não estará mais na escada rolante dupla no momento T + 10.
A todo momento que ninguém esteja usando a escada rolante dupla, ela estará parada. Portanto, inicialmente ela esta parada.
Quando a escada rolante dupla está parada e uma pessoa entra por uma das pontas, a escada rolante dupla se ligará automaticamente e se moverá na direção que aquela pessoa quer ir.
Se uma pessoa chegar na escada rolante dupla e esta já estiver movendo-se na direção que a pessoa quer ir, então a pessoa entrará nela imediatamente. Caso contrário, se a escada rolante estiver se movendo na direção oposta, a pessoa terá que esperar até que a escada rolante pare e só então a pessoa poderá entrar nela.
A escada rolante dupla é tão larga que ela pode acomodar inúmeras
pessoas entrando nela ao mesmo tempo.
A escada rolante dupla tem um efeito bem estranho, provavelmente relacionado a alguma propriedade da física quântica (ou simplesmente ao acaso): nenhuma pessoa vai chegar na escada rolante dupla no momento exato em que ela está prestes a parar.
Agora que você sabe como a escada rolante dupla funciona, você terá a tarefa de simulá-la. Dada a informação de N pessoas, incluindo o momento em que elas chegaram na escada rolante dupla e em qual direção elas querem andar, você tem que descobrir qual o último momento em que a escada para.


# Objetivo do Projeto
O objetivo deste projeto é proporcionar uma experiência prática na resolução de problemas computacionais complexos, estimulando o raciocínio lógico e a aplicação de conceitos de Sistemas Operacionais.

# Entendendo o Codigo
Para resolver o problema proposto defini 3 estados para a escada rolante, sendo eles: Parado = 0, Esquerda = 1 e Direita = 2. Para conseguir implementar o projeto, tive que utilizar fila (FIFO). No entanto, tendo em vista que na escada as pessoas querem ir da direita para a esquerda e da esquerda para a direita, tendo isso em mente, criei 2 ponteiros, sendo l = Aponta o primeiro elemento da fila e r = Aponta o último elemento da fila. Na fila, adicionei um vetor f = N + 1, caso a fila chegue a ter tamanho N, e N foi definido como 10000, que seria o máximo de eventos possíveis para esse problema. O tamanho da fila seria r - l. Passei a estrutura de ponteira para a fila e criei inserção no fim (Push), retirada do início (pop), front foi utilizado para resolver o problema que se a fila estiver vazia, ela retorna um número muito grande (infinito).

Na main do programa, N será o primeiro número a ser lido e indica o número de eventos, o número de chegadas na fila. Defino as filas f_esq e f_dir, fila esquerda e direita. Inicio a fila vazia, apontando = 0. Criei um for de tamanho N, ele lê 2 inteiros em cada linha, que serão t = Tempo de chegada da pessoa e d = direção, ou seja, 0 significa que ela quer ir da esquerda para a direita e 1 significa que ela quer ir da direita para a esquerda. Logo com essa informação, criei 2 condicionais: se d == 0, vamos adicionar na fila da esquerda, caso contrário, adicionamos na fila da direita.

Para controlar o sistema, precisei criar 4 variáveis: i = número de eventos processados até aquele momento, Estado = Estado da escada, podendo ser parado, esquerda ou direita, t = tempo atual iniciando em 0, e previsão_parada = tempo previsto para que a escada entre no estado de parada. Enquanto não processamos todos os eventos, ou seja, i < N, pegamos o primeiro elemento de cada fila, e = Tempo de chegada do primeiro elemento da fila da esquerda, D = Tempo de chegada do primeiro elemento da fila da direita. Logo, criei condicionais para resolver nosso problema, sendo elas: se estamos no tempo previsto para a escada parar, temos que checar realmente se ela vai parar. No caso, se os 2 elementos primeiro das filas não têm que entrar na fila agora, o estado da escada então é parada. Caso a escada esteja parada, temos que ver as 3 situações possíveis para essa escada, ou seja, ela pode ir para a esquerda, ir para a direita ou continuar parada. Na condicional, adicionei tempo atual + 10, como solicitado no enunciado.

# Contribuidores
- Pablo Borba Leal

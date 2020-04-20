# Conhecimento necessário

## 1. O que é terminal?

A palavra terminal se refere a computadores antigos cujo o objetivo era oferecer uma interface para acesso a uma rede. Porém, atualmente usamos essa palavra para se referir a um software que realiza comandos simples através de texto.

![Hello World](https://i.imgur.com/30ELbWL.png)

## 2. O que é standard output and input?

A entrada e saída de dados padrão (standard IO) são canais de comunicação entre o programa e o ambiente externo ao programa. Por exemplo, quando se conecta a `standard output` conseguimos mandar dados para um terminal (imprimir dados na tela), assim, possibilitando o uso de comandos como: `console.log` em Javascript, `print` em python, `printf` em C e `echo` em PHP. Já com a standard input conseguimos pegar dados que o usuário digitar no terminal como quando se usa comandos como `input` em Python e `fgets` em C.

## 3. Por que escolhemos C?

C é como uma linguagem mãe para a maioria das linguagens mais populares de hoje em dia. Como exemplos notáveis há Java e Javascript que foram intensamente influenciados por C, além disso, nela temos que lidar com a memória de forma mais direta do que com as outras linguagens, assim, conseguimos compreender conceitos de maior nível e as suas vantagens em cada linguagem como Garbage Collectors ou Ownership Model de Rust.

# Informações extra.

## 1. Como fazer os desafios?

Para realizar os desafios é necessário fazer um FORK desse repositório e resolver os desafios em arquivos com os seus respectivos nomes, assim, quando tiver terminado alguns desafios e quiser que alguém os avalie, de commit em suas novas resoluções e as mande no canal #ajuda-geral no Discord do IO Land. Lembrando que ninguém vai dar-te respostas completas e sim dicas de como melhorar o seu código ou lógica.

## 2. Como pedir ajuda?

Peça ajuda no servidor do discord, porém, não peça resoluções completas, o objetivo é aprendizado. Se você não consegue utilizar esses desafios como meio de aprender então não deveria estar fazendo-os.

# Desafios

## Básico

### 1. helloworld.c

Como primeiro desafio, iremos utilizar a `Standard Output` para fazer o nosso programa se comunicar com o mundo exterior. Para isso, você deve ter instalado o compilador de C e fazer com que o seu programa diga `Hello, World!` no `terminal`.


![Hello World](https://i.imgur.com/9tqfVto.gif)


### 2. oi.c

Nesse desafio iremos usar a `Standard Input`. Pergunte ao usuário qual é seu nome e então faça com que o programa diga `Oi,*Nome*`.

![Hello World](https://i.imgur.com/cUUCnIq.gif)

### 3. variables.c

Utilizando o conceito de variáveis, faça um programa que imprima na tela o resultado das 4 operações matemáticas básicas (adição, subitração ...) envolvendo dois números inteiros guardados em variáveis.

![Hello World](https://i.imgur.com/m2zAhrR.gif)

**Dicas** - Estude todos os tipos de dados em C, tais como: Int, Char, Float, Double e String.

### 4. pode_beber.c

Utilizando o conceito de condicionais (**if**, **else** e **else if**), faça um programa que receba a idade do usuário e imprima na tela se ele pode ou não beber.

![Hello World](https://i.imgur.com/thGLBXP.gif)

**OBS → só podera beber quem tem +18 anos.**

### 5. looooping.c

Faça um programa que entre com um valor **N** e depois coloque na tela o resultado dos números de 0 à **N** elevados ao quadrado utilizando de uma das estruturas de repetição (`for`, `while`, `do while`)

![Hello World](https://i.imgur.com/6p3zfuJ.gif)

### 6. velocidade.c

Faça um programa que receba do usuário uma velocidade em **m/s** e converta para **km/h**. ****Imprima esse valor na tela.

![Hello World](https://i.imgur.com/NsPJtVR.gif)

### 7. calculadora.c

Receba dois numeros do usuário e a operação que será realizada. Utilizando de `funções` e outros conceitos cálcule o resultado da operação e imprima na tela.

![Hello World](https://i.imgur.com/I40C2Vc.gif)

**Sugestão 1** - Utilize o conceito de recursão e faça sua calculadora poder suportar o algoritmo de cálculo da sequência de fibonnaci.

### Extra. salario.c

Faça um programa que utilizando uma unica função chamada `calcular_salario` que receberá as horas trabalhadas consiga calcular o salário. 

- Função do salário por hora: (hora-2)^2

### Extra - pontos.c

Crie um programa utilizando de funções para calcular a distância entre 2 pontos.

**A se pensar** →

- O que são bibliotecas? O que significa `stdio.h` e porque temos que utilizar `#` na frente de certas coisas?
- Como juntar dois códigos e utilizar funções de outro código?

### 8. media_notas.c

Peça que o usuário entre com 10 notas e armazene-as em um `array` . Imprima na tela a média delas.

![Hello World](https://i.imgur.com/NYCT5eN.gif)

### Extra - iguais.c

Faça um programa que peça valores que serão armazenados em 2 `arrays` e imprima na tela os elementos que estão em ambos ao mesmo tempo.

## Pascal e seu triângulo top

### 9. piramide_numeros.c

       1 
      2 2
     3 3 3
    4 4 4 4

**Dica** - Preste atenção no uso de ESPAÇO entre os números.
**Dica** - É recomendado o uso da lib strings.h

![](https://i.imgur.com/vDK7UXn.gif)

### 10. triangulo_de_pascal.c

Imprima um triângulo de pascal de 4 camadas. 

       1 
      1 1
     1 2 1
    1 3 3 1

![Hello World](https://i.imgur.com/cXZ3seK.gif)

### 11. funcionarios.c

Uma certa empresa quer catalogar os funcionários e suas respectivas funções. Crie um programa que catalogue os funcionários utilizando `structs` e `arrays` e faça com que o usuário consiga incluir informações de vários funcionários.

### 12. array_dinamico.c

Escreva um programa que receba um número **N** que será passado para um função responsável por alocar um espaço de memória de tamanho **N**.

**Dicas →** Estude o que são ponteiros e pra que usar as funções `malloc`, `calloc` e `memset`.

### 13. read_arq.c

Você deverá criar um arquivo .txt em seu computador com algumas informações, tais como: nome de uma biblioteca, nome dos livros que ela possui, categoria de livros, etc. Utilizando do artifício de programação você terá de ler os dados desse .txt e mostrar na tela esses dados organizados.

**Dicas →** Estude sobre a função `fopen`.

## A biblioteca do Sr. Chiyoku

Se ao menos eu não tivesse ficado abaixo daquela macieira… Assim como aconteceu com Newton, aconteceu comigo, porém, devido a um grande azar, uma ENORME maçã, da macieira de uma biblioteca qualquer, caiu acertando a minha cara e me fazendo desmaiar. 

— XXXX, você está bem? — Abrindo os olhos, vi o vulto de uma pessoa com um bigode extremamente estiloso.

 — O-oo o oi — Respondi ainda tonto.

 — Ainda bem que está vivo… Vi você caído e pensei que tinha desmaiado de fome ou algo assim — Respondeu o homem, que agora de forma mais clara percebi que era um bibliotecário. 

— Ah! É que uma maçã caiu na minha cabeça.

Com essa resposta, o bibliotecário começou a rir. Achei um pouco desagradável rir de minha situação, porém, compreendi que era um pouco estúpida. Após isso, o bibliotecário se sentou ao meu lado e começou a falar:

— Ai ai, agora vou voltar a descansar. Se importa se eu ficar deitado aqui de baixo da macieira junto a você?

— Eeeeeeé, não — Respondi de forma relutante.

Após alguns minutos, interrompendo o canto dos pássaros e o silêncio que reinava em meio a tal jardim, o bibliotecário se põe a falar.

— Esse jardim é um bom lugar para ficar e remover um pouco do estresse, sabe?! … recentemente estou tendo diversos problemas nessa biblioteca.

— Que tipos de problemas?

— Essa biblioteca é realmente enorme e recentemente decidi cuidar dela sozinho, sem nenhum outro bibliotecário. O problema é que há muitos livros e alguns deles eu simplesmente não sei onde estão ou se foram emprestados… mesmo com todos os tipos de organização e categorização de livros que fiz, ainda é bem difícil conseguir catalogar tudo.

— Que triste…

Eita! Que bibliotecário chato! Além de vir perturbar minha paz, começa a falar aleatoriamente de sua vida... não sei se seria desagradável mudar de lugar, mas sinto que terei que fazer isso!

— O que está fazendo deitado no gramado debaixo dessa macieira no jardim de uma biblioteca? - Perguntou o Bibliotecário interrompendo meu incrível silêncio de novo.

— Estava apenas descansando… mesmo que seja um mau hábito, venho aqui para trabalhar e descansar já que é um local bem **CALMO** e **SILENCIOSO** de ficar.

— HO, HO, HO Trabalhar aqui? Trabalha fazendo o quê?

— Sou programador à distância.

— OOOH!!! Julgo que algo como… Computadores podem resolver meu problema! Que tal… posso pagar bem caso você queira construir sistemas com computadores que consiga resolver meus problemas!

Sei que bibliotecas não são lugares que dão muito dinheiro… então só para recusar de maneira menos desagradável fiz uma pergunta decisiva.

— E… quanto seria?

— Olha… Depende das coisas que você pode me oferecer, mas penso que para um sistema considerado bom eu pagaria mais ou menos XXXX KVKE!

Não pude acreditar no momento… Aquilo era como o salário de um ano de programador, eu poderia aproveitar isso e comprar uma XXXX!

— É pode ser. - Respondi de forma relutante.

Vi que nuvens escuras estavam cada vez mais próximas e então, com medo de perder meus pertences para chuva, levantei de forma calma e sem me despedir sai correndo em direção a minha casa.

> Faça o programa especificado pelo bibliotecário.

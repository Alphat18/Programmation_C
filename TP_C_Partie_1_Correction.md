# <span style="color:green">Cours de Programmation C</span>

## <span style="color:blue">Partie 1: *Introduction à la compilation, Variables et Opérations*</span>

Nous allons dans ce cours apprendre à programmer dans le **langage C**. Le C est un langage de programmation permettant d'écrire des **programmes informatiques**, eux-mêmes servant de base à tous types de logiciels. La programmation est aujourd'hui un outil essentiel, quel que soit le domaine d'étude.

Le C est un langage assez ancien, mais encore très utilisé aujourd'hui, et qui pose les bases de bien d'autres langages plus récents.

Commençons tout d'abord par prendre un exemple très simple de programme:


```c
#include <stdio.h>

int main() {
  printf("Hello World!");
}
```

    Hello World!

Ce programme permet simplement d'afficher la phrase `Hello World!`. Notre premier objectif va être de réussir à **éxecuter** ce programme (c'est-à-dire faire en sorte que l'ordinateur effectue ce qui est écrit dans le programme).

- Recopier le programme dans un fichier nommé `hello.c` quelque part dans votre ordinateur (je vous conseille de créer un **dossier** à part qui contiendra tous les *exemples* et *exercices* de ce cours.

On appelle le fichier contenant le programme un **fichier source**. Ce fichier ne peut pas être éxecuter directement par la machine. Il faut tout d'abord le traduire dans un language que l'ordinateur peut comprendre (une suite de 0 et de 1). Pour ça, on utilise un ***compilateur***.

## La compilation en C

Un compilateur va traduire le code écrit en une suite d'instructions compréhensible par la machine. C'est un processus en plusieurs étapes que nous allons détailler dans la partie suivante.

Plusieurs compilateurs existent, les 2 principaux étant **gcc** et **clang**. Nous allons ici utiliser gcc (déjà présent sur l'ordinateur normalement). 

La compilation d'un programme se déroule en 2 étapes:

- *La compilation* : le fichier texte est traduit en assembleur, une suite d’instructions associées aux fonctionnalités du processeur (faire une addition, etc.) Ce code assembleur est écrit dans en un **fichier objet**, compréhensible par le processeur.

- *L’édition de liens* : afin d’utiliser des librairies de fonctions déjà écrites, un programme est séparé en plusieurs fichiers source. Une fois le code source assemblé, il faut lier entre eux les fichiers objets. L’édition de liens produit un **fichier exécutable**.

En ouvrant un terminal (sous *ubuntu*: clic droit -> "ouvrir dans un terminal") au niveau de ce fichier, la compilation s'effectue avec:

```gcc -c hello.c -o hello.o```

```gcc``` est le programme permettant de compiler, ```-c``` est un paramètre indiquant que l'on veut seulement compiler (pas d'édition des liens). ```hello.c``` est le chemin du fichier source. ```-o hello.o``` est un paramètre indiquant le nom du fichier objet.

Un fichier objet "hello.o" est créé dans le même dossier.

L'édition des liens s'effectue avec:

```gcc -o hello hello.o```

```-o hello``` est un paramètre indiquant le nom du fichier éxecutable.```hello.o``` est le chemin du fichier objet.
Un fichier exécutable "hello" est créé dans le même dossier.

Enfin, on lance le programme avec:

```./hello```

Ce qui devrait afficher la phrase "Hello World!" dans le terminal.

### *Remarque:*

Il est possible de faire la compilation puis l'édition des liens en même temps en utilisant la commande:

```gcc hello.c -o hello```

Dans ce cas, le fichier objet ```hello.o``` est implicitement créé.

### Utilisation d'un IDE

Il est tout à fait possible de coder en écrivant tous ses programmes à l'aide d'un éditeur de texte, puis de compiler en ligne de commande comme nous venons de le faire. 

Cependant, il est souvent plus pratique d'utiliser ce que l'on appelle un IDE (Environnement de Développement). Ces derniers offrent de nombreuses fonctionnalités permettant de simplifier la tâche du programmeur (détection d'erreur, complétion de code, compilation automatique...).

Dans le cadre de ce cours, vous avez le choix entre deux méthodes.

- Soits installer un IDE (celui que vous souhaiter, mais il y a dans ce cours un tutoriel pour installer l'IDE **Geany** qui est très simple d'utilisation et bien pour commencer).

- Soit compiler les codes directement depuis le terminal en utilisant GCC.

#### Installation IDE Geany

Sous Linux, on peut l'installer en ouvrant un terminal, puis on écrit:

```sudo apt-get install geany```

On peut ensuite l'ouvrir en allant chercher geany dans les applications, ou en tapant dans le terminal:

```geany```

Et voilà ! Merci Linux. On peut désormais écrire un programme.

## Syntaxe language C

Un language de programmation suit toujours ce que l'on apelle une **syntaxe**. Ce sont des mots clés que le compilateur va pouvoir traduire en un éxecutable.


```c
#include <stdio.h>

int main() {
    printf("Hello World!");
}
```

    Hello World!

On peut déjà voir un certain nombre de ces mots-clés:

```C
#include <stdio.h>
```

permet d'inclure une **bibliothèque**. Cette dernière contient un certain nombre de **fonctions**. Nous en reparlerons plus en détail dans un autre chapitre, mais une fonction est tout simplement un bout de code permettant de réaliser des tâches diverses.

Ici, la bibliothèque <stdio.h> permet entre autre d'utiliser la fonction ```printf```, qui affiche un texte dans un terminal.

```C
int main() { }
```

Définit la **fonction principale**, qui est la base de tout programme en C. C'est à l'intérieur de cette fonction (entre les ```{ }```) que l'on va écrire nos programmes.

```C
printf("Hello World!);
```

permet d'afficher le texte "Hello World!" dans le terminal.

On remarque aussi que toute ligne d'**instructions** se termine par un ```;```. **C'est obligatoire en C**. Le compilateur refusera de fonctionner sans.

## Variables et Types

Une variable correspond tout simplement à un emplacement mémoire ou l'on va stocker différents type d'information.
Par exemple:

```C
int a;
a = 10;
```

Définis une variable nommée ```a```, de type ```int```, auquel on assigne la valeur ```10```.

Le type d'une variable définit quel genre d'information une variable va pouvoir stocker. Les 3 plus importants sont:

- ```int```: **integer** pour stocker des nombres entiers positifs et négatifs (codé sur 16 bits [-32 768 a +32 767] ou 32 bits [-2 147 483 648 a +2 147 483 647] selon l'architecture du PC).
- ```float```: **float** pour stocker des nombres réels positifs et négatifs (codé sur 32 bits).
- ```char```: **character** pour stocker un charactères ASCII (les lettres de l'alphabet plus d'autres symboles).

Mais il existe des variantes permettant de stocker de plus ou moins grandes valeurs.

- ```short```, ```int```, ```long```, ```long long```: pour stocker des entiers de plus en plus grand.
- ```float```, ```double```, ```long double```: pour stocker des réels de plus en plus grand.

Enfin, il existe le mot-clé ```unsigned``` qui force la variable a stocké des valeurs positives.

```C
unsigned int a;
```

Dans ce cas, la variable ```a``` ne pourra stocker que des entiers positifs. C'est une option intéressante dans le cas ou l'on sait que notre variable ne peut pas contenir des valeurs négatives (par exemple pour **l'age** d'une personne).

### *Remarque:*

On peut changer le type (**cast** en anglais) d'une variable avec:

```c
int a = 5; // on définit un entier a
a = (float) a; // transforme a en un réel
```

## Opérations sur les variables

Stocker des variables est bien, mais on souhaite aussi pouvoir effectuer des opérations dessus. Il existe 5 opérateurs de base:
- ```+``` addition
- ```-``` soustraction
- ```*``` multiplication
- ```/``` division (euclidienne si le type de la variable est un entier, tel que ```int```). 
- ```%``` modulo (le reste de la division euclidienne).

Voici des exemples d'utilisation:


```c
#include <stdio.h>

int main() {
    int a;
    a = 2 + 3;
    printf("a = %d\n", a); // permet simplement d'afficher la valeur de la variable
    
    a = a * 2;
    printf("a = %d\n", a);
    
    int b = 5;
    a = a / b;
    printf("a = %d\n", a);
}
```

    a = 5
    a = 10
    a = 2


##  <span style="color:red">Exercice 1</span>

**Exercice**:
- Calculer le **quotient** et le **reste** de la division euclidienne de ```a``` par ```b```.


```c
#include <stdio.h>

int main() {
    int a = 5;
    int b = 2;
    int quotient;
    int reste;
    
    /* ECRIRE LE CODE ICI */
    quotient = a / b;
    reste = a % b;
    /**/
    
    printf("quotient = %d, reste = %d", quotient, reste);
}
```

    quotient = 2, reste = 1

### *Remarque:*

Soit la variable entière ```int a```:

Lorsque l'on souhaite modifier cette variable directement (tel que lui rajouter 2), il est possible de simplifier l'équation:

```C
a = a + 2;
```

par:

```C
a += 2;
```

Les 5 opérations suivantes:
- ```+=```
- ```-=```
- ```*=```
- ```/=```
- ```%=```

Permettent donc d'éviter de répéter le nom de la variable pour les 5 opérations de bases décrites précédemment.

Il existe aussi une syntaxe particulière pour l'opération **ajouter/enlever 1** à une variable. Ainsi:

```C
a++;
a--;
```

équivaut à:

```C
a = a + 1;
a = a - 1;
```

##  <span style="color:red">Exercice 2</span>

Nous allons dans cet exercice essayer de comprendre les limites des variables. Un ordinateur ne peut pas assigner un espace mémoire infini à une variable. Aussi, les variables sont limités dans la taille des valeurs qu'elle peuvent contenir.

**Exercice**:
- Définir une variable nommé ```a``` de type ```int``` et lui assigne la valeur 2 147 483 647.
- Ajouter ```1``` à cette variable.


```c
#include <stdio.h>

int main() {
    
    /* ECRIRE LE CODE ICI */
    int a = 2147483647;
    /**/
    
    printf("a = %d\n", a);
    
    /* ECRIRE LE CODE ICI */
    a++;
    /**/
    
    printf("a = %d\n", a); 
}
```

    a = 2147483647
    a = -2147483648


Que se passe t-il ? On apelle cela un **overflow**. La valeur entière maximale que peut contenir un ```int``` est +2 147 483 647. Lorsque l'on dépasse cette valeur, le compilateur va faire le choix d'aller dans les négatifs plutôt que de retourner une erreur.

Les variables d'un ordinateur se comporte donc de la même manière que pour les valeurs sur un cercle par exemple.

##  <span style="color:red">Exercice 3</span>

**Exercice**:

- Permuter le contenu de deux variables entières ```a``` et ```b``` en passant par une troisième variable.


```c
# include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    
    printf("avant permutation: a = %d, b = %d\n", a, b);
    
    /* ECRIRE LE CODE ICI */
    int temp = a;
    a = b;
    b = temp;
    /**/
    
    printf("apres permutation: a = %d, b = %d\n", a, b);
}
```

    avant permutation: a = 10, b = 20
    apres permutation: a = 20, b = 10


## Entrée utilisateur

Nous avons déjà vu et utilisé la fonction **```printf```** qui permet d'afficher du contenu sur un terminal. Cette fonction a une syntaxe bien particulière afin d'afficher tout type de variables:

- ```%d``` ou ```%i``` affiche une variable de type ```int```
- ```%f``` affiche une variable de type ```float```
- ```%c``` affiche une variable de type ```char```

La fonction accepte aussi les chaînes de caractères (texte entre ```""```) afin d'afficher du texte. On peut faire un retour à la ligne avec le caractère spécial ```\n```.

On peut aussi afficher des variables dans d'autres bases, tel que l'hexadécimal (```%x```) ou l'octal (```%o```)

Enfin, pour les nombres réels, il est possible de choisir le nombre de chiffres après la virgule à afficher avec ```%0.3f``` (3 chiffres après la virgule).


```c
#include <stdio.h>

int main() {
    int entier = 45;
    float reel = 2.78134864624;
    char caractere = 'c';
    
    printf("l'entier vaut: %d, ", entier);
    printf("le reel vaut: %f, ", reel);
    printf("le caractere vaut: %c.", caractere);
    
    printf("\n\nl'entier vaut: %d\n", entier); // meme chose avec sauts de ligne
    printf("le reel vaut: %f\n", reel);
    printf("le caractere vaut: %c\n\n", caractere);
    
    printf("l'entier vaut: %x\n", entier); // hexadecimal
    printf("l'entier vaut: %o\n\n", entier); // octal
    
    printf("le reel avec 2 decimales: %0.2f\n", reel); // nombre de decimales
}
```

    l'entier vaut: 45, le reel vaut: 2.781349, le caractere vaut: c.
    
    l'entier vaut: 45
    le reel vaut: 2.781349
    le caractere vaut: c
    
    l'entier vaut: 2d
    l'entier vaut: 55
    
    le reel avec 2 decimales: 2.78


De la même manière qu'il est possible d'afficher à l'écran, on peut aussi lire des informations entrées par l'utilisateur. On utilise pour cela la fonction **```scanf```** présente dans la librairie ```stdio.h```.

Cette fonction utilise la même syntaxe que ```printf```. On peut donc lire un entier dans la variable ```a```:

```scanf("%d", &a);```

Il ne faut pas oublier de rajouter le ```&``` avant le nom de la variable, nous verrons pourquoi plus loin dans ce cours.


```c
#include <stdio.h>

int main() {
    int entier;
    scanf("%d", &entier);
    
    printf("entier = %d", entier);
}
```

    15
    entier = 15

##  <span style="color:red">Exercice 4</span>

**Exercice**:

- Lire en entrée 3 entiers et calculer leur **moyenne**. Afficher le résultat avec une précision de **2 chiffres** après la virgule.

Il faut penser à utiliser la division réelle plutôt que la division euclidienne en utilisant un changement de type.


```c
#include <stdio.h>

int main() {
    /* ECRIRE LE CODE ICI */
    int a, b, c;
    float moy;

    printf("Donnez 3 entiers:\n");
    scanf("%d%d%d", &a, &b, &c);

    moy = (float) (a + b + c) / 3;

    printf("La moyenne de ces trois entiers est: %.2f\n", moy);
    /**/
}
```

    Donnez 3 entiers:
    10 5 2
    La moyenne de ces trois entiers est: 5.67


##  <span style="color:red">Exercice 5</span>

**Exercice**:

- Lire 2 réels ```r1``` et ```r2``` qui représentent les **rayons** de 2 **cercles concentriques**, et renvoie ensuite l'**aire** de la surface comprise entre les 2 cercles.

Attention: ```r1``` peut être supérieur ou inférieur à ```r2```.

<img src="../ressources/cercle.jpg" alt="cercle" width="150"/>

La librairie ```<math.h>``` contient de nombreuses fonctions mathématiques, dont ```fabs``` qui permet de calculer la valeur absolue d'une variable.

```C
float a = fabs(-5); // a = 5.0
```


```c
#include <stdio.h>
#include <math.h>

int main() {
    /* ECRIRE LE CODE ICI */
    float r1, r2, aire;

    printf("Donnez les rayons des deux cercles:\n");
    scanf("%f%f", &r1, &r2);

    aire = fabs(3.14 * r1 * r1 - 3.14 * r2 * r2);

    printf("L'aire de la surface entre les deux cercles est: %.4f\n", aire);
    /**/
}
```

    Donnez les rayons des deux cercles:
    10.40 12.90
    L'aire de la surface entre les deux cercles est: 182.9050


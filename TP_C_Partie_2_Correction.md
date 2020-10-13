# <span style="color:green">Cours de Programmation C</span>

## <span style="color:blue">Partie 2: *Conditions, Caractères et Boucles*</span>


## Conditions

Il est souvent nécessaire en programmation de n'éxecuter un bout de code que si une **condition** est **vérifiée**. Afin de vérifier une condition, on utilise le mot-clé ```if```.

Par exemple, pour tester si la valeur d'une variable ```a``` est égale à `10`, on écrit: 
```C
if (a == 10) {
    /* code éxécuté si a vaut 10 */
}
```

Le code entre ```{}``` ne sera éxecuté que si a vaut ```10```.

On notera le ```==```, qu'il ne faut pas confondre avec le ```=``` d'affectation. Il existe 6 opérateurs de comparaison en C:

- ```==```: égal
- ```!=```: différent
- ```>```: strictement supérieur
- ```>=```: supérieur ou égal
- ```<```: strictement inférieur
- ```<=```: inférieur ou égal

On peut comparer tout type de variables entre elles, *entiers*, *réels*, *caractères*... Il faut être prudent avec les réels, car la moindre différence dans les décimales induit une **non égalité**.

Il est aussi possible d'exécuter du code lorsque la condition est fausse. On utilise alors le mot clé ```else```:

```C
if (a == 10) {
    /* code éxécuté si a vaut 10 */
}
else {
    /* code éxécuté si a différent de 10 */
}
```

Enfin, il existe un dernier mot clé ```else if```, qui permet de tester plusieurs conditions à la suite:

```C
if (a > 10) {
    /* code éxécuté si a supérieur à 10 */
}
else if (a > 5) {
    /* code éxécuté si a supérieur à 5 mais inférieur à 10 */
}
else {
    /* code éxécuté si a inférieur à 5 */
}
```

**Attention**, on aurait aussi pu écrire le code de cette manière:

```C
if (a > 10) {
    /* code éxécuté si a supérieur 10 */
}
if (a > 5) {
    /* code éxécuté si a supérieur à 5 */
}
else {
    /* code éxécuté si a inférieur à 5 */
}
```

Cependant, dans ce cas, lorsque a est supérieur à `10`, deux des conditions seront exécutés, le premier et le deuxième ```if```, contrairement au cas précédent ou seul le premier `if` était exécuté.

Par ailleurs, le mot-clé ```else``` réfère toujours au `if`/`else if` qui le précède. Il faut donc bien utiliser ```else if``` si l'on ne souhaite être sélectif dans nos conditions.

##  <span style="color:red">Exercice 1</span>

**Exercice**:

- Afficher si un entier est pair ou impair.


```c
#include <stdio.h>

int main() {
    int a;

    printf("Donnez un entier:\n");
    scanf("%d", &a);
    printf("%d", a = 8);
    
    /* ECRIRE CODE ICI */
    if(a % 2 == 1) {
       printf("%d est impair\n", a);
    } else {
       printf("%d est pair\n", a);
    }
    /**/
}
```

    Donnez un entier:
    32765 est impair


##  <span style="color:red">Exercice 2</span>

**Exercice**:

- Comparer deux entiers a et b, et afficher selon le cas l'un des messages suivants: ```a == b```, ```a > b``` ou ```a < b```.


```c
#include <stdio.h>

int main() {
    int a, b;

    printf("Donnez deux entiers:\n");
    scanf("%d%d", &a, &b);
    
    /* ECRIRE CODE ICI */
    if(a == b) {
       printf("a = b\n");
    } else if (a > b) {
       printf("a > b\n");
    } else {
       printf("a < b\n");
    }
    /**/
}
```

    Donnez deux entiers:
    a < b


## Opérateurs logiques

Il est parfois nécessaire de tester plusieurs conditions à l'intérieur d'un même ```if```. Dans ce cas, on utilise les **opérateurs logiques**.

Un opérateur logique est un opérateur booléen (inventé au départ pour faire des calculs avec des nombres binaires). Il existe trois opérateurs primaires, le **NON (NOT)**, **OU (OR)** et **ET (AND)** logiques. Ces opérateurs sont implémentés dans le language C sous la forme:

- ```!```: non logique
- ```||```: ou logique
- ```&&```: et logique

ils permettent de combiner plusieurs coditions ensemble:

```C
if (a >= 10 && a < 20) {
    /* code éxécuté si a compris entre 10 inclus et 20 exclus */
}
```

Si l'on souhaite combiner plus de 2 conditions, il faut parfois utiliser des ```()```. Les conditions entre parenthèses sont vérifiées en **premier**. Par ailleurs, le ```!``` (not) logique est prioritaire sur le ```&&``` (and) qui est lui même prioritaire sur le ```||``` (or), similaire à la multiplication prioritaire sur l'addition.

ainsi:

```C
if ((a > 10 && a < 20) || (b > 30 && b < 40)) {
    /* code éxécuté si a compris entre 10 et 20 exclus ou b compris entre 30 et 40 exclus */
}
```

équivaut à:

```C
if (a > 10 && a < 20 || b > 30 && b < 40) {
    /* code éxécuté si a compris entre 10 et 20 exclus ou b compris entre 30 et 40 exclus */
}
```

mais:

```C
if ((a > 20 || a < 10) && (b > 40 || b < 30)) {
    /* code éxécuté si a supérieur à 20 ou inférieur à 10 et b supérieur à 40 ou inférieur à 30 */
}
```

est totalement différent de:

```C
if (a > 20 || a < 10 && b > 40 || b < 30) {
    /* code éxécuté si a supérieur à 20 ou a inférieur à 10 et b supérieur à 40 ou b inférieur à 30 */
}
```

Le ```!``` logique est peu utilisé. Il permet d'inverser une condition:

```C
if (!(a == 10))
```

équivaut à:
```C
if (a != 10)
```

##  <span style="color:red">Exercice 3</span>

**Exercice**:

- Lire trois entiers puis les afficher dans un ordre croissant.


```c
#include <stdio.h>

int main() {
    int a, b, c;

    printf("Donnez trois entiers:\n");
    scanf("%d%d%d", &a, &b, &c);
    
    /* ECRIRE CODE ICI */
    if(a >= b && a >= c) {
        if (b >= c) {
            printf("a = %d, b = %d, c = %d\n", a, b, c);
        } else {
            printf("a = %d, c = %d, b = %d\n", a, c, b);
        }
    } else if (b >= a && b >= c) {
        if (a >= c) {
            printf("b = %d, a = %d, c = %d\n", b, a, c);
        } else {
            printf("b = %d, c = %d, a = %d\n", b, c, a);
        }
    } else {
        if (a >= b) {
            printf("c = %d, a = %d, b = %d\n", c, a, b);
        } else {
            printf("c = %d, b = %d, a = %d\n", c, b, a);
        }
    }
    /**/
}
```

    Donnez trois entiers:
    a = 1356284577, b = 941663392, c = 32766


## Gestion des caractères

Un caractère est un symbole représenant une lettre (majuscule ou minuscule), un chiffre, un signe de  ponctuation ou un caractère spécial. On indique un caractère en le mettant entre `''`. Mais fondamentalement, une machine ne fonctionne qu'avec des nombres. Un caractère est donc toujours codé par un nombre, faisant référence à une table de conversion. Le C utilise par défault la **table ASCII** pour convertir un nombre en caratère.

![alt text](../ressources/ASCII.png)

Un caractère en C est donc similaire à un entier. Il est possible d'effectuer les mêmes opérations que pour des nombres.


```c
#include <stdio.h>

int main() {
    char caractere = 'a';
    
    printf("%c = %d\n", caractere, caractere);
    
    caractere++; // on peut effectuer des operations sur les caracteres
    printf("a + 1 = %c = %d\n", caractere, caractere);
    
    if ('a' > 'b') { // On peut utiliser des conditions sur les caracteres
        printf("a est plus grand que b");
    } else {
        printf("b est plus grand que a");
    }
}
```

    a = 97
    a + 1 = b = 98
    b est plus grand que a

**Attention**: Les caractères ne peuvent pas dépasser 127, qui est la valeur maximale dans la table ASCII

##  <span style="color:red">Exercice 4</span>

**Exercice**:

- Lire un caractère et déterminer s'il fait partie de l'alphabet ou non. Si oui, dire s’il est en minuscule ou en majuscule.


```c
#include <stdio.h>

int main() {
    char cara;

    printf("Entrez un caractere:\n");
    scanf("%c", &cara);
    
    /* ECRIRE CODE ICI */
    if(cara >= 'a' && cara <= 'z') {
        printf("%c est dans l'alphabet\n", cara);
        printf("%c est une minuscule\n", cara);
    } else if (cara >= 'A' && cara <= 'Z') {
        printf("%c est dans l'alphabet\n", cara);
        printf("%c est une majuscule\n", cara);
    } else {
        printf("%c n'est pas dans l'alphabet", cara);
    }
    /**/
}
```

    Entrez un caractere:
    R est dans l'alphabet
    R est une majuscule


## Boucles de contrôles

Il est souvent nécessaire dans un programme d'**exécuter une action de manière répétée**, ou **tant qu'une condition n'est pas vérifiée**. C'est dans ce cadre qu'intervienne les boucles de contrôles. Il existe 2 types de boucles: 
- ```for```: pour itérer un nombre précis de fois.
- ```while```: pour itérer jusqu'à ce qu'une condition soit fausse

la syntaxe des boucles est assez particulière:

```C
for (int i = 0; i < 10; i++) {
    
}
```

signifie que l'on va itérer ```10``` fois:

```C
int i = 0 // On initialise une variable i à 0
```

```C
i < 10 // on arrête d'itérer quand i est supérieur ou égal à 10
```

```C
i++ // On ajoute 1 à i à chaque tour de boucle
```



```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 4; i++) {
        printf("i = %d\n", i);
    }
}
```

    i = 0
    i = 1
    i = 2
    i = 3


Le ```for``` n'est à utiliser que lorsque l'on **connait exactement le nombre d'itération voulue**. Il est possible de modifier les paramètres entre ```()``` pour changer le comportement de la boucle:


```c
#include <stdio.h>

int main() {
    for (int i = 1; i < 8; i = i+2) { // on initialise i à 1, et on lui ajoute 2 à chaque tour de boucle
        printf("i = %d\n", i);
    }
    printf("\n");
    for (int j = 4; j > 0; j--) { // on initialise j à 4, et on lui enleve 1 à chaque tour de boucle
        printf("j = %d\n", j);
    }
}
```

    i = 1
    i = 3
    i = 5
    i = 7
    
    j = 4
    j = 3
    j = 2
    j = 1


Lorsque l'on **ne connait pas le nombre d'itérations voulues**, il faut dans ce cas utiliser ```while```:

```C
while (a != 10) {
    
}
```

signifie que l'on va itérer tant que a est différent de ```10```.


```c
#include <stdio.h>

int main() {
    int a = 0;
    while (a != 10) { // on itère tant que l'utilisateur rentre une valeur différente de 10
        printf("Rentrer une valeur\n");
        scanf("%d", &a);
    }
}
```

    Rentrer une valeur
    Rentrer une valeur
    Rentrer une valeur
    Rentrer une valeur


##  <span style="color:red">Exercice 5</span>

**Exercice**:

- Lire un entier puis déterminer s'il est premier ou non.

On rappelle qu'un entier est dit premier s'il a exactement deux diviseurs différents; 1 et lui-même.
Ex: 2, 3, 7, 17, 101 sont tous premiers, et 4, 10, 27 ne le sont pas.


```c
#include <stdio.h>

int main() {
    int a;
    printf("Rentrer une valeur\n");
    scanf("%d", &a);
    
    /* ECRIRE CODE ICI */
    int premier = 1;
    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            premier = 0;
        }
    }
    if (premier) {
        printf("%d est premier.\n", a);
    } else {
        printf("%d n'est pas premier.\n", a);
    }
    /**/
}
```

    Rentrer une valeur
    2141977733 n'est pas premier.


##  <span style="color:red">Exercice 6</span>

**Exercice**:

- Calculer le nième terme de la suite de Fibonacci, définie comme suit: ```Un = Un-1 + Un-2``` avec ```U1 = U0 = 1```.


```c
#include <stdio.h>

int main() {
    int n;
    printf("Rentrer un entier\n");
    scanf("%d", &n);
    n = 35;
    
    /* ECRIRE CODE ICI */
    int Un, UnMinus1 = 1, UnMinus2 = 1;
    
    if (n < 2) {
        Un = 1;
    } else {
        for (int i = 2; i <= n; i++) {
            Un = UnMinus1 + UnMinus2;
            UnMinus2 = UnMinus1;
            UnMinus1 = Un;
        }
    }

    printf("le %dieme terme de la suite de Fibonacci = %d", n, Un);
    /**/
}
```

    Rentrer un entier
    le 35ieme terme de la suite de Fibonacci = 12149

## Directive de contrôle

Il existe 2 directives en C permettant d'altérer le comportement d'une boucle:
- ```break```: permet de forcer à sortir d'une boucle même si la condition de sortie n'est pas encore vérifiée.

```C
int n = 0;
while (1) { // boucle infinie
    n++;
    if (n == 10) {
        break; // on sort de la boucle après 10 itérations
    }
}
```

- ```continue```: permet de retourner en haut de la boucle sans éxecuter les instructions suivant ce mot clé.

```C
int n = 0;
while (n < 10) {
    n++;

    if (n % 2 == 1) { // si n est impair
        continue; // on retourne au début de l'instruction while
    }

    printf("The number %d is even.\n", n); // le printf n'est exécuté que si n est pair
}

```

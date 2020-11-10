
# <span style="color:green">Cours de Programmation C</span>

## <span style="color:blue">Partie 4: *Fonctions et Structures*</span>

## Déclaration d'une fonction

Une fonction est un regroupement de code répétable destiné à effectuer une action précise. Une fonction en C peut prendre **plusieurs entrées** mais possède **une seule sortie**. Une fonction en code est assez similaire a une fonction mathématique en un sens. Prenons par exemple:

```C
int addition(int a, int b) {
    return a + b;
}
```

Cette fonction permet de calculer l'addition entre 2 variables `a` et `b`. Elle suit une syntaxe bien précise:

- Elle commence par le **type de sortie** de la fonction (ici `int`).
- Vient ensuite le **nom de la fonction**. Il est important de choisir des noms explicites afin que l'on puisse facilement comprendre l'action effectuée par la fonction.
- Entre les `()`, on définit les **variables d'entrée**, en précisant bien leurs **types**. Il n'y a pas de lmimites au nombre de variables en entrées.
- Enfin, le mot-clé `return` permet de **sortir de la fonction en renvoyant une valeur**. Le type de la valeur en sortie doit correspondre au type précisé au début de la fonction.

### *Remarque:*

Le mot-clé `return` arrête la fonction même s'il reste des instructions en dessous. Cela peut être utilisé afin de sortir de la fonction prématurément lorsqu'un condition est vérifiée:

```C
int division(int a, int b) {
    if (b == 0) { // division non défini dans ce cas
        return 0; // on sort de la fonction en renvoyant 0
    }
    return a / b; // si b différent de 0, on renvoi le résultat de la division
}
```

Dans l'exemple ci dessus, un `else` n'est pas nécessaire car le `return 0;` sort de la fonction sans exécuter les lignes suivantes.

## Utilisation d'une fonction

Une fois la fonction déclarée (généralement au dessus du `main`), il est possible de l'utiliser dans notre programme. Une fonction peut être utilisée dans le `main` mais aussi à l'intérieur d'une autre fonction.


```c
#include <stdio.h>

float carre(float x) {
    return x * x;
}

int main() {
    float x = 6;
    float x2;
    
    x2 = carre(x); // on appelle la fonction carre et stocke le resultat dans x2
    printf("x = %f, x au carre = %f", x, x2);
}
```

    x = 6.000000, x au carre = 36.000000

### *Remarque:*

- Nous avons déjà utilisé des fonctions implictement dans les cours précédents. Les bibliothèques tels que `stdio.h`, `math.h` et `string.h`... contiennent en fait des **déclarations** de nombreuses fonctions en lien avec un sujet en particulier.

`printf`, `scanf`, `fabs` et `strlen` sont des exemples de fonctions que nous avons utilisé.

Définir ses propres fonctions est très utile. Cela permet de **mieux organiser** son programme et d'**éviter de répéter du code** dans certaines situations... Au fur est à mesure qu'un programme grandit, on crée de nouvelles fonctions permettant de réaliser des nouvelles actions bien particulières. Cela permet de garder un code cohérent, et de ne pas se perdre dans des codes trop longs.

- Le `main` que nous utilisons depuis le début n'est rien d'autre qu'une fonction un peu spéciale. D'ailleurs, une bonne pratique est d'utiliser `return 0` à la fin du `main` pour annoncer que le programme s'est bien déroulé. (Nous le ferons désormais).

## Portée d'une variable

Avec l'introduction des fonctions, il faut bien faire attention aux variables que l'on déclare et à leurs **portée** (*scope* en anglais).


```c
#include <stdio.h>

int a;

float moyenneTableau(int tailleTab, int tab[]) {
    float moy;
    for (int i = 0; i < tailleTab; i++) {
        moy += tab[i];
    }
    moy /= tailleTab;
    return moy;
}

int main() {
    int tableau[] = {0, 1, 2};
    float moyenne;
    
    moyenne = moyenneTableau(3, tableau);
    
    printf("moyenne = %f", moyenne);
    return 0;
}
```

    moyenne = 1.000000

Ci dessus, On a déclaré plusieurs variables de portées différentes.

- La variable `i` a une portée de **bloc**, c'est à dire qu'elle commence à l'ouverture d'un bloc, définit par `{`, et se termine à la fermeture de ce bloc, définit par `}`. La variable `i` ,'est donc utilisable **qu'à l'intérieur** de la boucle `for`, mais pas ailleurs.

- Les variables `tailleTab`, `tab` et `moy` ont une portée de **fonction**. Elles sont créés lorsque la fonction est appellée, puis détruites lorsque l'on sort de la fonction.

- Les variables `tableau` et `moyenne` ont aussi une portée de **fonction**. Elles seront détruites à la fin du `main`.

- La variable `a` a une portée **globale**. Elle peut être utilisée n'importe ou dans le programme. On la déclare en dehors d'une fonction. Il faut si possible **éviter** d'utiliser ces variables car elles compliquent la **comphréension** du code.

**Attention**: Modifier une variable de portée de **fonction** ne sera effectif que dans la fonction:


```c
#include <stdio.h>

void modifierVar(int var) {
    var++;
}

int main() {
    int var = 1;
    
    printf("var = %d\n", var);
    modifierVar(var);
    printf("var = %d\n", var);
    return 0;
}
```

    var = 1
    var = 1


Ci dessus, il existe 2 variables `var`, qui ont le **même nom** mais restent des **entitées différentes**. La variable `var` déclarée dans le `main`, et celle déclarée dans la fonction `modifierVar`. Ajouter 1 à la variable de la fonction `modifierVar` n'a aucun effet sur celle du `main`.

 On appelle cela un **passage par valeur**, ce qui signifie que la variable en entrée est **copiée** dans la fontion et n'a donc plus aucun lien avec cette dernière. 

Nous verrons plus tard qu'il est possible d'effectuer un **passage par pointeur**, qui lui permet de garder le lien entre les variables, sans effectuer de copie.

##  <span style="color:red">Exercice 1</span>

**Exercice**:

- Déterminer le max de quatre entiers à l'aide d'une fonction max_4, et qui doit utiliser une autre fonction max_2 qui trouve le max de deux entiers.


```c
#include <stdio.h>

/* ECRIRE LE CODE ICI */

int main() {
    int a, b, c, d, max;
    printf("Entrer 4 entiers\n");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d %d %d %d\n", a = 7, b = 26, c = 15, d = 3);
    
    /* ECRIRE LE CODE ICI */

    printf("maximum (%d, %d, %d, %d) = %d\n", a, b, c, d, max);
}
```

    Entrer 4 entiers
    7 26 15 3
    maximum (7, 26, 15, 3) = 26


## Récursivité

En C, une fonction peut s'apeller elle même. C'est à dire qu'il est possible d'**utiliser une fonction à l'intérieur de la définition de cette même fonction**. Cela va entrainer une chaine d'appel de la fonction, qu'il est nécessaire d'arrêter à l'aide d'une **condition limite** (autrement le programme va tourner à l'infini).

La récursivité est une pratique permettant de résoudre certains problèmes mathématiques qui seraient difficiles voir impossible à résoudre autrement.


```c
#include <stdio.h>

int factoriel(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factoriel(n-1);
    }
}

int main() {
    int n = 5;
    
    printf("5! = %d", factoriel(n));
    return 0;
}
```

    5! = 120

La fonction `factoriel` est ici une fonction récursive (*rappel*: 5 factoriel `5! = 5 * 4 * 3 * 2 * 1 = 120`) . A chaque itération, elle se rappelle elle même en décrémentant `n` de 1. La fonction ne retourne un résultat que lorsque un des appels récursif rentre dans la condition limite définit dans le `if`.

La **condition limite** est le moment ou il n'est plus nécessaire de calculer d'autres termes de la fonction. Or lorsque `n` vaut `0`, on ne peut plus le décrémenter et on retourne donc la définition du factoriel de 0: `0! = 1`.

##  <span style="color:red">Exercice 2 (Facultatif)</span>

**Exercice**:

- Créer une fonction **récursive** `fibonacci` qui calcule le nième terme de la suite de Fibonacci.

Rappel: La suite de Fibonacci est définie comme: ```Un = Un-1 + Un-2``` avec ```U1 = U0 = 1```.

**Attention:** Il y a 2 conditions limites (`U1` et `U0`).


```c
#include <stdio.h>

/* ECRIRE LE CODE ICI */

int main() {
    int n;
    printf("Rentrer un nombre\n");
    scanf("%d", &n);
    
    printf("fibonacci(%d) = %d", n, fibonacci(n));
    return 0;
}
```

    Rentrer un nombre
    8
    fibonacci(8) = 21

## Structures

Une **structure** est une variable un peu particulière qui peut contenir plusieurs autres variables. Elles sont souvent utilisées afin de regrouper des informations similaires ensemble. Elles ajoutent de la structure au code (d'où leur nom).

Le C n'est pas un langage dit **Objet**, cependant une structure permet de s'approcher en partie de ce **paradigme de programmation**. Par exemple:

```C
struct Point2D {
    float x;
    float y;
}; // ne pas oublier le point virgule
```

permet de définir une structure s'apparentant à un point en 2 dimensions. Un point en géométrie est défini par ses coordonnées (*x* et *y* en 2D). Créer la structure `Point2D` permet de rassembler les composantes d'un point dans **une seule variable**, ce qui simplifie la compréhension et permet de mieux structurer le code.

### Utilisation

Une fois la structure définit, on peut l'utiliser comme n'importe quel type dans un programme. Il faut juste rajouter le mot-clé `struct` devant le nom de la structure.

```C
    struct Point2D point;
```

Une fois la variable déclarée, on accède aux variables intérieurs à la structure avec un `.`:

```C
    point.x = 5;
    point.y = 7;
```

### *Remarques:*

- On peut initialiser une structure directement à la déclaration de la même manière qu'un tableau:

```C
    struct Point2D point = {5, 7};
```

- On peut éviter d'avoir à utiliser le mot-clé `struct` à chaque fois que l'on déclare une structure en utilisant un alias (`typedef`). 

Un alias permet d'associer des mot-clés afin de les raccourcirs. Ainsi, si on écrit:

```C
typedef struct Point2D Point2D;
```

on associe `struct Point2D` à `Point2D`. Donc lorsque l'on écrit `Point2D`, on écrit en fait réellement `struct Point2D`. On peut désormais utiliser la structure de la manière suivante:

```C
    Point2D point = {5, 7};
```

- Une structure peut contenir n'importe quel type de variables, même des tableaux, des chaînes de caractères ou d'autres structures.


```c
#include <stdio.h>

typedef struct Point2D Point2D;
struct Point2D {
    float x;
    float y;
};

typedef struct Personne Personne;
struct Personne {
    char prenom[100];
    int age;
    Point2D adresse; // variable adresse de type point2D (peut contenir une coordonnée GPS par exemple)
};

int main() {
    struct Personne moi = {"Thomas", 24}; // on declare le nom et l'age à l'initialisation de la structure
    moi.adresse.x = 45.7772; // puis on rentre l'adresse en accedant a la structure Point2D
    moi.adresse.y = 3.0870;
    
    printf("Bonjour, je m'appelle %s, j'ai %d ans et je vis près de (%f °N, %f °E).", moi.prenom, moi.age, moi.adresse.x, moi.adresse.y);
    return 0;
}
```

    Bonjour, je m'appelle Thomas, j'ai 24 ans et je vis près de (45.777199 °N, 3.087000 °E).

##  <span style="color:red">Exercice 3</span>

**Exercice**:

- Créer une structure `Point3D` qui définit un point en **3 dimensions**, puis écrire une fonction `distance3D` qui donne la distance euclidienne entre 2 points.

Rappel: La distance euclidienne d'un point en 3 dimension est `racine((x2 - x1)² + (y2 - y1)² + (z2 - z1)²)`.

### Remarque:

- Il est nécessaire d'utiliser les fonctions `sqrt(float x)` et `pow(float x, float power)` pour calculer la distance euclidienne, présentes dans la librairie `math.h`.

- Pour utiliser la librairie `math.h`, il faut compiler en rajoutant l'option `-lm` (qui permet de **lier** la librairie au programme):

ex: `gcc ex3.c -o exo3 -lm`


```c
#include <stdio.h>
#include <math.h> // permet d'utiliser sqrt et pow

/* ECRIRE LE CODE ICI */

int main() {
    Point3D point1 = {10, 5, 7}, point2 = {5, 14, 9};
    
    printf("La distance entre les points est de %f", distance3D(point1, point2));
    return 0;
}
```

    La distance entre les points est de 10.488088

##  <span style="color:red">Exercice 4</span>

**Exercice**:

- Définir une structure `Etudiant` où un étudiant est représenté par son nom, son prénom et une note. Lit ensuite un tableau d'étudiants entrée par l'utilisateur et affiche les noms de tous les étudiants ayant une note supérieure ou égale à 10 sur 20.

**Attention**: On utilisera `scanf("%s", etudiants[i].nom)` et `scanf("%s", etudiants[i].prenom)` sans `&` pour rentrer le nom et prénom d'un étudiant. C'est une spécificité liée au `scanf` et au chaînes de caractères/tableaux. 


```c
#include <stdio.h>

/* ECRIRE LE CODE ICI */

int main() {
    Etudiant etudiants[100];
    int n;
    
    printf("Entrer le nombre d'etudiants\n");
    scanf("%d", &n);
    
    /* ECRIRE LE CODE ICI */
    
    return 0;
}
```

    Entrer le nombre d'etudiants
    4
    Entrer le nom, prenom et note de l'etudiant
    Djadja Henry 3
    Entrer le nom, prenom et note de l'etudiant
    De la Rue Marjorie 6
    Entrer le nom, prenom et note de l'etudiant
    Vald Timothe 17
    Entrer le nom, prenom et note de l'etudiant
    Conombre Cecile 15
    Vald Timothe a eu 17
    Conombre Cecile a eu 15


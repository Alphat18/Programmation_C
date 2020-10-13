# <span style="color:green">Cours de Programmation C</span>

## <span style="color:blue">Partie 5: *Pointeurs*</span>

## Adresse mémoire

Il est important de bien comprendre la manière dont les valeurs sont stockés en C. Nous l'avons dit, une **variable** est un **espace mémoire** pour stocker une **valeur**. Chaque espace mémoire est lui même réferencé dans la machine par une **adresse**. Prenons l'exemple d'une variable:

```C
int var = 10;
```

![adresse](./adress1.png)

On assigne la valeur `10` à la variable `var`. Cependant, pour que la machine comprenne ou est stocké cette valeur, il est nécessaire d'utiliser un système d'**adressage**. Dans notre exemple sur la figure, l'adresse de la variable `var` est `177450`. En réalité, c'est souvent des grands nombres choisit aléatoirement par la machine lors de la création de la variable.

Il est possible d'accéder à l'adresse d'une variable avec le symbole `&`.


```c
#include <stdio.h>

int main() {
    int var = 145;
    
    printf("l'adresse de la variable var est: %p", &var); // on utilise "%p" et &var pour accéder à l'adresse
}
```

    l'adresse de la variable var est: 0x7fff3966bcf4

Les adresses des variables sont souvent affichés en **héxadécimal**. L'adresse ci-dessus, `0x7fff3966bcf4` vaut en fait: `140 734 156 422 388` en décimal (c'est beaucoup !). On utilise l'héxadécimal pour réduire la taille à l'affichage d'une adresse. 

Dans les fait, il n'est pas nécessaire de connaitre l'adresse d'une variable, la machine s'occupe de tout pour nous. D'ailleurs, l'adresse changera à chaque exécution d'un programme.

Cependant, accéder à l'adresse d'une variable s'avère utile dans certains cas. Nous avons déjà vu l'utilisation des adresses pour le `scanf`.

```C
scanf("%d", &var);
```

Le `scanf` utilise l'adresse pour venir assigner une valeur à une variable. Nous allons comprendre pourquoi dans ce chapitre.

## Pointeurs

Un pointeur est une *variable* qui va **contenir l'adresse d'une autre variable**. On les déclare avec le symbole `*`.

```C
int *pointeur;
```

Ici, `pointeur` est une variable qui peut contenir l'adresse d'un autre variable de type `int`. Les pointeurs ont de nombreuses utilités en C, que nous allons décrire un peu plus tards. Afin d'assigner une adresse à un pointeur, on utilise:

```C
pointeur = &var;
```

Ceci est cohérent avec ce que nous avons décrit plus haut. On accède à l'adresse de la variable var avec `&`, puis on l'assigne au pointeur.

![pointeur](./adress2.png)

On voit sur l'image que le pointeur stocke l'adresse de la variable `var`. En faisant cela, il devient possible d'accéder à la **valeur** de `var` à partir du pointeur, cette fois en utilisant le symbole `*`:


```c
#include <stdio.h>

int main() {
    int var = 10;
    int *pointeur;
    pointeur = &var;
    
    printf("Valeur de var: %d\n", var);
    printf("Adresse de var: %p\n\n", &var);
    
    printf("Valeur de var en passant par pointeur: %d\n", *pointeur);
    printf("Adresse de var en passant par pointeur: %p\n\n", pointeur);
    
    printf("Adresse de pointeur: %p", &pointeur);
}
```

    Valeur de var: 10
    Adresse de var: 0x7fff0a5f1e9c
    
    Valeur de var en passant par pointeur: 10
    Adresse de var en passant par pointeur: 0x7fff0a5f1e9c
    
    Adresse de pointeur: 0x7fff0a5f1ea0

Cela peut paraitre assez compliqué au départ. Les pointeurs rajoutent un certains nombre de notions très spécifiques. Mais il est important de bien comprendre ce qu'il se passe lorsque l'on manipule des pointeurs, afin de ne pas se perdre avec les notations (`&`, `*`, ...).

![pointeur](./adress3.png)

L'image ci-dessus résume les notations est ce à quoi elles correspondent, n'hésitez pas à vous y référer.

On comprends que:
- `&` désigne toujours l'adresse de la variable.
- `*` n'est utilisé qu'avec les pointeurs, et permet d'accéder à la **valeur** de la variable *pointée* par le pointeur.
- Lorsque l'on n'utilise pas de symboles, il faut bien vérifier quel type de variable on manipule. Pour une **variable normale**, on accède à la **valeur**, pour un **pointeur**, on accède à l'**adresse** de la variable pointée.

## Utilisation des pointeurs

Vous vous demander sans doute pourquoi compliquer autant les choses en utilisant les pointeurs ? Et bien ces derniers sont très utilisé en programmation C. Leur utilité principale est la capacité de **modifier** la valeur d'une variable sans jamais apeller cette dernière. Par exemple:


```c
#include <stdio.h>

int main() {
    int var = 10;
    
    printf("var = %d\n", var);
    
    int *pointeur = &var; // on fait pointer pointeur sur var
    *pointeur = 15; // on modifie la valeur de var
    
    printf("var = %d\n", var);
}
```

    var = 10
    var = 15


Ce code permet de modifier la valeur de `var` sans jamais faire appel à `var` (on aurait d'habitude écrit: `var = 15;`).

Les pointeurs sont très utilisés en C. Nous allons voir quelques uns de leeurs avantages principaux.

##  <span style="color:red">Exercice 1</span>

**Exercice**:

- Utiliser la notion de pointeur pour lire deux entiers et calculer leur somme.

*Attention*:
- Un pointeur ne peut être utilisé que s'il est d'abord initialisé en pointant sur l'adresse d'une variable.
- Bien réfléchir à la manière de lire la valeur d'un pointeur avec `scanf`.


```c
#include <stdio.h>

int main() {
    /* ECRIRE LE CODE ICI */

    return 0;
}
```

    Entrer deux entiers:
    10 5
    somme = 10 + 5 = 15

## Passage par référence

Nous avons vu dans le chapitre précédent le passage par **valeur** dans les **fonctions**. Cela consiste à copier la valeur dans une variable qui sera détruite à la fin de la fonction:

```C
void plusUn(int a) { // a est passé par valeur, il est donc copié à l'appel de la fonction
    a += 1;
}
```

Cette fonction ne sert donc à rien, puisque la modification effectuée sur `a` ne sera effective que **dans la fonction**.

Il est aussi possible de passer la variable par **référence** (qui est au fond un passage par *adresse*), pour lequel la variable n'est pas copiée. Pour cela, on utilise en fait un **pointeur** sur la variable.

```C
void plusUn(int *a) { // a est passé par référence, il n'est pas copié à l'appel de la fonction
    *a += 1; // il faut penser à utiliser *
}
```

Dans ce cas, la modification de `a` sera aussi effective en dehors de la fonction (C'est une technique qui permet en quelque sorte d'augmenter la **portée** de la variable).


```c
#include <stdio.h>

void plusUnValeur(int a) {
    a += 1;
}

void plusUnReference(int *a) {
    *a += 1;
}

int main() {
    int a = 10;

    plusUnValeur(a); // fonction inutile
    printf("a = %d\n", a);
    
    plusUnReference(&a); // ajoute 1 à a, il faut penser à utiliser &
    printf("a = %d\n", a);
    return 0; 
}
```

    a = 10
    a = 11


**Attention**: Lorsqu'une fonction déclare une variable par référence, il faut penser à passer l'**adresse** de la variable dans la fonction (avec `&`), afin que le pointeur puisse fonctionner correctement.

### *Remarque:*

- On comprends désormais l'écriture un peu particulière du `scanf`. Ce dernier utilise en fait un passage par référence afin que la variable qu'on lui donne soit effectivement modifiée.

### Fonction à sorties multiples

Nous avons dit précédement qu'une fonction ne pouvait pas `return` plus d'une variable. Cependant, grâce aux passages par références, il est possible de contourner cette limitation.

```C
void permuter(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

Cette fonction permet d'échanger les valeurs de 2 variables. Elle nécessite 2 sorties (`a` et `b`), il faut donc penser à utiliser un passage par référence.

##  <span style="color:red">Exercice 2</span>

**Exercice**:

- Ecrire une fonction `divisionEntiere` qui prend deux entiers, calul la divisions entière entre eux et retourne 2 variables en sortie, le *quotient* et le *reste*.


```c
#include <stdio.h>


/* ECRIRE LE CODE ICI */

int main() {
    int a, b, quotient, reste;
    
    printf("Entrer deux entiers\n");
    scanf("%d%d", &a, &b);
    
    /* ECRIRE LE CODE ICI */
    
    printf("%d/%d: quotient = %d, reste = %d", a, b, quotient, reste);
    return 0;
}
```

    Entrer deux entiers
    10 3
    10/3: quotient = 3, reste = 1

## Tableaux et pointeurs

Les cases d'un tableaux sont mises les unes à la suite des autres dans la mémoire de la machine. Cela signifie que les **adresses** des cases du tableau se suivent.

Lorsque l'on définit un tableau:

```C
int tab[5];
```

Le nom du tableau (`tab`) est en fait un **pointeur**. Ce dernier pointe sur l'adresse de la première cellule du tableau.


```c
#include <stdio.h>

int main() {
    int tab[5] = {5, 6, 7, 8, 9};
    
    printf("%d\n", tab[0]); // affiche la valeur de la première case du tableau
    printf("%d\n", *tab); // equivaut à la ligne du dessus
}
```

    5
    5


La nature de pointeur d'un tableau signifie qu'il sera toujours passé par **référence**, et donc que les modifications apportées à un tableau dans une fonction seront aussi effectives en dehors de la fonction. 


```c
#include <stdio.h>

void modifierTableau(int tab[]) {
    tab[0] = 8; // on modifie la premiere case du tableau
}

int main() {
    int tab[3] = {1, 2, 3};
    
    printf("Avant fonction\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", tab[i]);
    }
    
    modifierTableau(tab);
    
    printf("\nApres fonction\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", tab[i]);
    }
    return 0;
}
```

    Avant fonction
    1 2 3 
    Apres fonction
    8 2 3 

##  <span style="color:red">Exercice 3</span>

**Exercice**:

- Définir et utilise une fonction `inserer`, qui insère un entier dans un tableau.

- La fontion prend en entier un tableau, la taille de ce tableau qu'elle devra mettre à jours, la position d'insertion et la valeur à insérer.

**Attention:** Lorsque l'on insère, il faut penser à décaler tout les éléments au dessus de la position à insérer.


```c
#include <stdio.h>

void afficherTableau(int n, int tab[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

/* ECRIRE LE CODE ICI */

int main() {
    int tab[100] = {1, 2, 3, 4, 5};
    int n = 5;
    
    afficherTableau(n, tab);
    
    int pos, val;
    printf("Entrer une position d'insertion\n");
    scanf("%d", &pos);
    printf("%d\n", pos = 3);
    printf("Entrer une valeur à insérer\n");
    scanf("%d", &val);
    printf("%d\n", val = 15);
    
    /* ECRIRE LE CODE ICI */
    
    afficherTableau(n, tab);
    return 0;
}
```

    1 2 3 4 5 
    Entrer une position d'insertion
    3
    Entrer une valeur à insérer
    15
    1 2 15 3 4 5 


## Pointeurs et structures

Il est possible d'utiliser un pointeur sur tout type de variables, même sur des **structures** crées par l'utilisateur. Cela présente un certains nombre d'avantages:

- Si l'on souhaite modifier les **attributs** d'une structures dans une fonction, un passage par référence (et donc l'utilisation d'un pointeur) est nécessaire.
- Une structure peut être constituée de nombreuses variables, et donc prendre une place importante en mémoire. Aussi, copier une structure peut avoir un coût important en place et en temps de copie. L'utilisation d'un pointeur permet d'éviter cette copie.


```c
#include <stdio.h>

typedef struct Point2D Point2D;
struct Point2D {
    int x;
    int y;
};

int main() {
    Point2D point = {2, 5}; // on déclare un point
    
    printf("Point: x = %d, y = %d\n", point.x, point.y);
    
    Point2D *pointeur = &point; // pointeur sur la structure
    (*pointeur).x = 7; // on change la valeur de x
    
    printf("Point: x = %d, y = %d\n", point.x, point.y);
}
```

    Point: x = 2, y = 5
    Point: x = 7, y = 5


On remarque dans l'exemple ci-dessus l'utilisation de `()` pour le pointeur.

Ecrire:

```C
*pointeur.x = 7; // faux
```

ne fonctionne pas, car `*` référerait alors à la variable `x`, or celle-ci n'est pas un pointeur. Il faut donc préciser le placement de l'asterix en utilisant:

```C
*(pointeur).x = 7;
```

Cette notation peut devenir complexe lorsque l'on manipule des structures contenant d'autres structures, c'est pourquoi il existe une notation alternative que les développeurs utilisent régulièrements:

```C
pointeur->x = 7; // equivalent à l'expression au dessus
```

##  <span style="color:red">Exercice 4</span>

**Exercice**:

- Créer une structure `Personne` contenant le nom et l'age d'une personne, et une fonction `anniversaire` qui augmente l'age d'une personne de 1.


```c
#include <stdio.h>
#include <string.h> // donne acces a strcpy

/* ECRIRE LE CODE ICI */

int main() {
  Person john;
  strcpy(john.prenom, "John"); // permet d'assigner une chaine de caractere
  john.age = 27;

  printf("%s a %d ans.\n", john.prenom, john.age);
    
  /* ECRIRE LE CODE ICI */

  printf("Bon Anniversaire! %s a désormais %d ans.\n", john.prenom, john.age);

  return 0;
}
```

    John a 27 ans.
    Bon Anniversaire! John a désormais 28 ans.


## Exercices Complémentaires

##  <span style="color:red">Exercice 5</span>

**Exercice**:

- Définir et utiliser une fonction `trier` qui trie, dans un ordre croissant, les éléments d'un tableau d'entiers.

##  <span style="color:red">Exercice 6</span>

**Exercice**:

- Créer une structure `ListeChainee` permettant d'utiliser des listes chainées comme structures de données.

Une liste chainée est assez similaire à un tableau, chaque élément de la liste est liée (penser aux pointeurs) à l'élément suivant.
De plus chaque élément peut contenir une valeur.

Puis, créer des fonctions permettant:
- d'afficher la liste
- d'ajouter un élément à la fin de la liste
- de retirer un élément à la fin de la liste
- d'insérer un élément dans la liste
- de retirer un élément de la liste

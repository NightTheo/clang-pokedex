# clang-pokedex #

## Use cases ##

### Create ###

#### 1. Voir pikachu #### 

1.1. Pour la première fois

Contexte : mon pokedex est vide, je n'est jamais vu ni capturé de pokemon. 
Nous sommes le 27 mai 2022.

```bash
$ i saw pikachu
```
Le pokemon Pikachu est ajouté à mon Pokedex eet la date de première découverte vaut la date d'aujourd'hui
Mon pokedex possède maintenant 1 pokemon :
- Pikachu
  - Type electrique
  - Découvert la 1ère fois le 27 mai 2022
  - Jamais capturé
  

1.2. Pour la deuxième fois

Contexte : mon pokedex a 1 pokemon: Pikachu qui a déjà été vu le 27 mai 2022.
Nous sommes le 29 mai 2022.

```bash
$ i saw pikachu
```
Rien n'est modifié car la date de première capture est déjà renseignée
mon pokedex n'a pas changé:

- Pikachu
  - Type electrique
  - Découvert la 1ère fois le 27 mai 2022
  - Jamais capturé
  


#### 2. Capturer salameche ####

2.1. Pour la première fois

Contexte : mon pokedex est vide, je n'est jamais vu ni capturé de pokemon.
Nous sommes le 27 mai 2022.

```bash
$ i captured salameche
```

Le Pokemon Salameche est ajouté a mon Pokedex, le nombre de capture est de 1, 
sa date de 1ère découverte et de 1ère capture vaut la date d'aujourd'hui.
Mon pokedex possède maintenant 1 pokemon :

- Salameche
  - Type feu
  - en possède **1**
  - Découvert la 1ère fois le 27 mai 2022
  - capturé la première fois le 27 mai 2022

2.2. Pour la deuxième fois

Contexte : mon pokedex a 1 pokemon: Salameche qui a déjà été capturé le 27 mai 2022.
Nous sommes le 29 mai 2022.

```bash
$ i captured salameche
```

Le nombre de Salameche que je possède est incrémenté de 1, il vaut maintenant 2.
Mon pokedex possède 1 pokemon :

- Salameche
  - Type feu
  - en possède **2**
  - Découvert la 1ère fois le 27 mai 2022
  - capturé la première fois le 27 mai 2022


2.3. Qui n'avait été que vu

Contexte : mon pokedex a 1 pokemon: Salameche qui a déjà été vu le 27 mai 2022.
Nous sommes le 29 mai 2022.
pokedex:
- Salameche
  - Type feu
  - Découvert la 1ère fois le 27 mai 2022
  - Jamais capturé

```bash
$ i captured salameche
```

Le nombre de Salameche que je possède est incrémenté de 1, il vaut maintenant 2.
Mon pokedex possède 1 pokemon :

- Salameche
  - Type feu
  - en possède **1**
  - Découvert la 1ère fois le 27 mai 2022
  - capturé la première fois le 29 mai 2022

### Read ###

#### 3. Afficher tout le Pokedex #### 

3.1. Afficher tout le Pokedex

Contexte : mon pokedex contient 3 Pokemons: 
- Pikachu qui a été vu le 27 mai 2022.
- 3 Salameche, le 1er a été capturé le 28 mai 2022.
- 1 Roucool qui a été vu le 27 mai 2022 et capturé de 29 mai 2022.

```bash
$ display pokedex
```

doit afficher :

```
> stdout

Pikachu x0
    Type Electrique
    Découvert la 1ère fois le 27 mai 2022
    Jamais capturé
---
Salameche x3
    Type Feu
    Découvert la 1ère fois le 28 mai 2022
    Capturé la première fois le 28 mai 2022
---
Roucoule x1
    Type Vent
    Découvert la 1ère fois le 27 mai 2022
    Capturé la première fois le 29 mai 2022
```
`NB: Il n'y a pas d'ordre de préférence dans l'affichage`

3.2. Filtrer sur les pokemons que nous possédons

Contexte : mon pokedex contient 3 Pokemons: 
- Pikachu qui a été vu le 27 mai 2022.
- 3 Salameche, le 1er a été capturé le 28 mai 2022.
- 1 Roucool qui a été vu le 27 mai 2022 et capturé de 29 mai 2022.

```bash
$ display pokedex captured
```

doit afficher le pokedex sans pikachu qui n'a pas été capturé :
```
> stdout

Salameche x3
    Type Feu
    Découvert la 1ère fois le 28 mai 2022
    Capturé la première fois le 28 mai 2022
---
Roucoule x1
    Type Vent
    Découvert la 1ère fois le 27 mai 2022
    Capturé la première fois le 29 mai 2022
```

#### 4. Afficher un Pokemon dans le Pokedex #### 

4.1. Le Pokemon est dans mon Pokedex

Contexte : mon pokedex contient 3 Pokemons: 
- Pikachu qui a été vu le 27 mai 2022.
- 3 Salameche, le 1er a été capturé le 28 mai 2022.
- 1 Roucool qui a été vu le 27 mai 2022 et capturé de 29 mai 2022.

```bash
$ search salameche
```

Salameche est dans mon Pokedex donc je l'affiche :
```
> stdout

Salameche x3
    Type Feu
    Découvert la 1ère fois le 28 mai 2022
    Capturé la première fois le 28 mai 2022
```
`NB: La case de la recherche est ignorée`

---
4.2. Le Pokemon n'est pas dans mon Pokedex

Contexte : mon pokedex contient 3 Pokemons: 
- Pikachu qui a été vu le 27 mai 2022.
- 3 Salameche, le 1er a été capturé le 28 mai 2022.
- 1 Roucool qui a été vu le 27 mai 2022 et capturé de 29 mai 2022.

```bash
$ search mewtwo
```

Mewto n'est pas dans mon Pokedex donc j'affiche le message :
```
> stdout

'Mewto' n'est pas dans le Pokedex.
```
`NB: Le nom est en Title case`
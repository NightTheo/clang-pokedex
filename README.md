# clang-pokedex #

## TODO ##

- Renommer pokemon.h en pokemon_datasheet
- Avoir un builder pour ce PokemonDatasheet
  - Parce que Les deux dates possiblement nulles

Idées d'amélioration
- Faire des UseCases en CQS
- Avoir un adapter générique
- Types dans agréggat : PokemonName, FirstSeenDate, FistCaptureDate
- Avoir un module de langue pour ne plus avoir de français dans l'adapter

## Use cases ##

### Create ###

#### 1. Voir un Pokemon #### 

##### 1.1. Pour la première fois #####

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
  

##### 1.2. Pour la deuxième fois #####

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


##### 1.3. Voir un pokemon qui n'existe pas #####

Contexte : mon pokedex est vide, je n'est jamais vu ni capturé de pokemon. 

```bash
$ i saw not_a_pokemon
```

Le message d'erreur :
```bash
'Not_a_pokemon' n'est pas un Pokemon connu du Pokedex.
```
`NB: Le nom est en Title case`


#### 2. Capturer un Pokemon ####

##### 2.1. Pour la première fois #####

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

##### 2.2. Pour la deuxième fois #####

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


##### 2.3. Qui n'avait été que vu #####

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

##### 3.1. Afficher tout le Pokedex #####

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
    Type Vol
    Découvert la 1ère fois le 27 mai 2022
    Capturé la première fois le 29 mai 2022
```
`NB: Il n'y a pas d'ordre de préférence dans l'affichage`

##### 3.2. Filtrer sur les pokemons que je possède #####

Contexte : mon Pokedex contient 3 Pokemons: 
- Pikachu qui a été vu le 27 mai 2022.
- 3 Salameche, le 1er a été capturé le 28 mai 2022.
- 1 Roucool qui a été vu le 27 mai 2022 et capturé de 29 mai 2022.

```bash
$ display pokedex captured
```

doit afficher le Pokedex sans pikachu qui n'a pas été capturé :
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

#### 4. Chercher un Pokemon dans mon Pokedex #### 

##### 4.1. Le Pokemon est dans mon Pokedex #####

Contexte : mon Pokedex contient 3 Pokemons: 
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
    Découvert la première fois le 28 mai 2022
    Capturé la première fois le 28 mai 2022
```
`NB: La case de la recherche est ignorée`

##### 4.2. Le Pokemon n'est pas dans mon Pokedex #####

Contexte : mon Pokedex contient 3 Pokemons: 
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

### Update ###

#### 5. Modifier le nom d'un Pokemon #### 

##### 5.1. Mauvaises entrées #####

##### 5.1.1. Le Pokemon n'existe pas #####

Contexte : mon Pokedex contient 1 Pokemon: Rattata

```bash
$ rename rattata to not_a_pokemon
```

Affiche le message d'erreur :
```
> stdout

'Not_a_pokemon' n'est pas un Pokemon connu du Pokedex.
```

##### 5.1.2. Le Pokemon à renommer n'est pas dans mon pokedex #####

Contexte : mon Pokedex est vide, je n'est jamais vu ni capturé de pokemon. 

```bash
$ rename rattata to pikachu
```

Affiche le message d'erreur :
```
> stdout

'Rattata' n'est pas dans votre Pokedex.
```

##### 5.2. **SANS** collision #####

Contexte : mon Pokedex contient 1 Pokemon: Rattata

Pokedex:
- Rattata
  - Type Normal
  - en possède 2
  - Découvert la 1ère fois le 27 mai 2022
  - capturé la première fois le 27 mai 2022

```bash
$ rename rattata to pikachu
```

Rattata change pour Pikachu, mon Pokedex devient :
- **Pikachu**
  - Type electrique
  - en possède 2
  - Découvert la 1ère fois le 27 mai 2022
  - capturé la première fois le 27 mai 2022

##### 5.2. **AVEC** collision #####

`Lorsqu'il y a une collision, c'est que le nouveau nom correspond à un Pokemon 
qui est déjà présent dans le Pokedex.`

Il faut alors prendre en compte le nombre de Pokemons possédés : au final pour le nouveau nom, **le nouveau nombre de Pokemons possédés
vaut la somme des deux anciens.**

Il faut aussi prendre en compte les dates de 1ère découverte et de 1ère capture. 
**On prend les plus anciennes.**


##### 5.2.1. entre deux Pokemons capturés #####

Contexte : je possède 3 Pikachu et 2 Rattata.

```bash
$ rename rattata to pikachu
```

Je possède alors 5 Pikachu.

##### 5.2.2. entre un Pokemon capturé et un vu #####

Contexte : je possède 3 Pikachu et Rattata a été vu.

```bash
$ rename rattata to pikachu
```

Je possède alors 3 Pikachu.

##### 5.2.3. Le Pokemon à renommer est plus récent #####

Contexte : Je possède 2 Pikachu capturés le 1er janvier 2021 
et 3 Rattata capturés le 2 février 2022.

Rattata a été capturé 1 an et 1 mois **après** Pikachu.

```bash
$ rename rattata to pikachu
```

Les dates de 1ère capture et de 1ère découverte les plus anciennes sont le 1er janvier 2021.
Pikachu possède alors pour ces deux dates le **1er janvier 2021**.

##### 5.2.4. Le Pokemon à renommer est plus ancien #####

Contexte : Je possède 2 Pikachu capturés le 2 février 2022
et 3 Rattata capturés le 1er janvier 2021.

Rattata a été capturé 1 an et 1 mois **avant** Pikachu.

```bash
$ rename rattata to pikachu
```

Les dates de 1ère capture et de 1ère découverte les plus anciennes sont le 1er janvier 2021.
Pikachu possède alors pour ces deux dates le **1er janvier 2021**.


##### 5.2.5. Le Pokemon à renommer a été découvert en 1er mais capturé après l'autre Pokemon #####

Pokedex :

- Rattata
  - Découvert la 1ère fois le 1 janvier 2021
  - capturé la première fois le 3 mars 2023

- Pikachu
  - Découvert la 1ère fois le 2 février 2022
  - capturé la première fois le 2 février 2022

```bash
$ rename rattata to pikachu
```

Le Pokedex vaut donc :
- Pikachu
  - Découvert la 1ère fois le 1 janvier 2021
  - capturé la première fois le 2 février 2022

##### 5.3 Renommer un pokemon en lui même #####

Contexte : Je possède 2 Pikachu

```bash
$ rename pikachu to pikachu
```

Je dois encore posséder 2 pikachu. Rien a changé.


### DELETE ###

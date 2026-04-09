<h1 align="center"> TP1 - File par tableau circulaire</h1>

<p align="center"><strong> Hoarau Lindsay</strong> CPI2 - IT</p>

---
<p> Date : 08.04.2026 </p>

### Contexte
 L’**objectif** de ce sujet est de concevoir une librairie nommée MessStacker permettant de gérer une file (une pile FIFO) de messages. Des producteurs (les expéditeurs) alimentent la file en « postant » des messages. Et des consommateurs (les receveurs) analysent le contenu de ces messages un par un, puis demandent de passer au message suivant. Cette librairie expose pour cela un ensemble de fonction qui vont permettre la gestion du stockage des messages reçus, en attendant qu’ils soient consultés puis retirés du stock. Les messages considérés ici sont constitués d’un bloc d’octet data, associé à une commande cmd (un nombre). Pour garantir l’intégrité de l’information, le message sera associé à un checksum (code de contrôle) qui sera calculé sur l’ensemble cmd+data. Ce checksum pourra ainsi être utilisé à tout moment pour vérifier que le message n’a pas été altéré au cours de la chaine de transmission (en particulier s’il est amené à transiter sur le réseau). La particularité de l’implémentation que nous allons réaliser dans ce sujet, est que la file de message est matérialisée par un tableau circulaire.

---
### Sommaire
- [Contexte](#contexte)
- [Arborescence](#arborescence)
- [Git](#git)
- [API](#api-de-la-librairie)
---

### Arborescence
```
./
    build/  
        messStacker.o 
        test
        test.o 

    src/  
        messStacker.c
        messStacker.h

    test/ 
        test.c

    makefile
    README.md
```

**build/** fichier.o et exécutable   
**src/**   librairie messStacker   
**test/**  fichier test   

--- 

### Git

Dépôt git disponible à l'adresse suivante : [TP1 - File par tableau circulaire](https://github.com/hoarau-lindsay/eval_messStacker.git)

---


### API de la librairie 

#### haveMessage

**Description : Indique si la file contient au moins un message**  
**Paramètre** : aucun  
**Retourne** :   
    - true : si la file contient un message   
    - false : si la file ne contient aucun message (messCount = 0)  



    
    
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
- [Fonctions](#fonctions)
---
### Fonctions
- [haveMesssage](#havemessage)
- [checksumMessage](#checksummessage)
- [sendMessage](#sendmessage)
- [curMessageCmd](#curmessagecmd)
- [curMessageSize](#curmessagesize)
- [curMessagechecksum](#curmessagechecksum)
- [curMessageData](#curmessagedata)
- [nextMessage](#nextmessage)

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

#### checksumMessage
 **Description : Code de contrôle pour garantir l'intégrité de l'information. Calcul la somme de l'ensemble commande + un bloc d'octet data**   
**Paramètres :**  
    cmd : commande (un nombre)  
    data : tableau d'octet   
    size : nombre d'octet à considérer pour le contenu dans le tableau data   
**Retourne :**   
    somme : somme de l'ensemble cmd + data   


#### sendMessage
**Description : Ajout d'un message dans la file de messages (stackMess)**   
**Paramètres :**  
    cmd : commande (un nombre)  
    data : tableau d'octet   
    size : nombre d'octet à considérer pour le contenu dans le tableau data   
**Retourne :**  
    - true : si le message a été ajouté   
    - false : si la file est pleine (message non ajouté)   
    
#### curMessageCmd
**Description : Valeur de la commande du message courant dans la file**     
**Paramètre :** aucun     
**Retourne :**    
    - stackMess[curPos].cmd : la valeur de cmd du mesage courant   
    - 0 si la file est vide    

#### curMessageSize  
**Description : Valeur de la taille du message courant**  
**Paramètre :** aucun   
**Retourne :**   
    - stackMess[curPos].size : valeur size du message courant   
     - 0 si la file est vide 

#### curMessageChecksum
**Description code contrôle garantissant l'intégrité du message**  
**Paramètre** : aucun   
**Retourne:**  
    - stackMess[curPos].checksum : valeur checksum du message courant   
    - 0 si la file est vide   

#### curMessageData
**Description : Copie donnée (data) du message courant dans un buffer**   
**Paramètres :** 
    buff : tableau dans lequel seront copiées les données du message courant    
    lenghtMax : taille maximale du tableau buff   
**Retourne :**     
    - true : si la copie réussi    
    - false : si aucun nmessage est présent dans la file ou si la taille maximale du tableau buff est inférieur à la taille du message courant   

#### nextMessage
**Description : Passage au message suivant dans la file**  
**Paramètre** : aucun   
**Retourne :**
    - true : si passage au message suivant
    - false : si la file est vide 

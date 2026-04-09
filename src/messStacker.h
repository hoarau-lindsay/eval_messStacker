#ifndef MESS_STACKER
#define MESS_STACKER


/* Définition des constantes */

#define MESS_STACKER_VERSION "v0.0.01"
#define SIZE_MAX_DATA 57

char* getMessStackerVersion();

typedef struct message{
    uint8_t cmd;                 //commande (un nombre)
    char data[SIZE_MAX_DATA];    //tableau d'octet de taille SIZE_MAX_DATA
    uint8_t size;                //nombre d'octets 
    uint8_t checksum;            //checksum 
} Message;


#endif
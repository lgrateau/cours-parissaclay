/* SERVEUR. Lancer ce programme en premier (pas d'arguments). */

#include <stdio.h>                  /* fichiers d'en-tête classiques */
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/socket.h>             /* fichiers d'en-tête "réseau" */
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT_SERVEUR 5015           /* Numéro de port pour le serveur */
#define MAX_CLIENTS   128           /* Nombre maximum de clients */
#define BUFFER_SIZE  1024           /* Taille maximum des messages */

int main(int argc, char *argv[]) {


int main(int argc, char *argv[]) {
   fd_set fds_master, fds_tmp;
  int max_fd = 0;
  int secoute;
  int sservice, ss;
  char message[BUFFER_SIZE] = {0}; struct sockaddr_in saddr = {0}; int lus, ecrits;
  /* 1. On déroute les signaux */
  signal(SIGPIPE,SIG_IGN);

  /* 2. On crée la socket d'écoute. */
  if ((secoute = socket(AF_INET,SOCK_STREAM,0)) == 1) { // Same as Client. Can be copy/paste
    perror("Problème création socket");
    exit(1);
  }
  /* 3. On prépare l'adresse du serveur. */
  saddr.sin_family = // *****TOBECOMPLETE** See cours page 8
  saddr.sin_addr.s_addr = // *****TOBECOMPLETE** See cours page 8
  saddr.sin_port = // *****TOBECOMPLETE** u See cours page 8

  /* 4. On attache la socket a l'adresse du serveur. */
  if (bind(secoute,(struct sockaddr *)&saddr,sizeof(saddr)) == 1) { 
      perror("Problème bind");
      exit(1);
  }
  /* 5. Enregistrement auprès du système. */
  if (listen(****TOBECOMPLETED****) == 1) { 
    perror("Problème listen"); exit(1);
  }

  FD_ZERO(&fds_master); 
  FD_SET(secoute,&fds_master);
  max_fd = secoute;
  while (1) {
    printf("Serveur en attente de nouveaux clients ou messages.\n");
    fds_tmp = fds_master;
    select(max_fd+1,&fds_tmp,NULL,NULL,NULL);

    /* 6. Si on a reçu une demande sur la socket d'écoute... */
    if (FD_ISSET(secoute,&fds_tmp)) { 
      // *****TOBECOMPLETE** use accept function
    } 
    /* 7. Si on a reçu des données sur une socket de service... */
    for (sservice = 0; sservice <= max_fd; sservice++) {
      if (sservice == secoute) continue;
      if (!FD_ISSET(sservice,&fds_tmp)) continue;
      // *****TOBECOMPLETE** use read function
      lus=.....
      if (lus == 0) { // Client Termine
      // *****TOBECOMPLETE**  close all the resources.
      }   

      /* On fait la diffusion */
      printf("Reçu message : %s\n",message); 
      for (ss = 0; ss <= max_fd; ss++) {
        if (ss == secoute) continue;
        if (ss == sservice) continue; /* To avoid Echo */ 
        if (!FD_ISSET(ss,&fds_master)) continue;
        // *****TOBECOMPLETE**  use write function 
  
      }
    }
  }
  /* 8. On termine et libère les ressources. */
        // *****TOBECOMPLETE**  use close function 
  return 0;
}

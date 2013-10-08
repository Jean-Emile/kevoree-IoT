#include <sys/types.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#include "maven.h"

int Sock_Serv, Sock_Com, Ret_Read, Taille;


struct sockaddr distant;
int distant_len = sizeof distant;
struct sockaddr_in6 server;
struct sigaction act;
char Buf[1024];


int init_server(int port){

	/* Cr�ation de la socket d'�coute */
	if ((Sock_Serv = socket (PF_INET6, SOCK_STREAM, 0)) < 0)
	{
		perror ("Ouverture du socket en mode connecte\n");
		return -1;
	}

	/* Attachement de la socket d'�coute � une adresse sur le serveur */
	server.sin6_family = AF_INET6;
	memcpy ((void *)&server.sin6_addr, (void*)&in6addr_any, sizeof in6addr_any);
	server.sin6_port = htons (port);

	Taille = sizeof (server);

	if (bind (Sock_Serv, (struct sockaddr *) &server, Taille) < 0)
	{
		perror ("Serveur : erreur sur bind ");
		return -1;
	}

	/* Message de bienvenue. */
	printf ("[%05d] Server listenning on port %d.\n",(int) getpid (),  ntohs (server.sin6_port));


	listen (Sock_Serv, 5);

	while (1)
	{
		if ((Sock_Com = accept (Sock_Serv, &distant, &distant_len)) == -1)
		{
			fprintf (stderr, "[%05d] ", (int) getpid ());
			perror ("Erreur sur accept.");
			continue;
		}

		if (fork () == 0)
		{
			char buffer[64];
			char options[64];
			char data[32] ;
			int request;
			if ((Ret_Read = read (Sock_Com, buffer, sizeof (buffer))) < 0){
				fprintf (stderr, "[%05d] ", (int) getpid ());
				perror ("Erreur lecture message");
			}


			sscanf(buffer,"[%d][%s]\r\n",&request,options);

			printf("REQUEST = %d\n",request);

			switch(request){

			case 100:

				sprintf(data,"powet \r\n");

				if (write (Sock_Com, data, strlen (data)) < 0) {
					fprintf (stderr, "[%05d] ", getpid ());
					perror ("Erreur d'ecriture vers le serveur");
				}
				printf("sending %s \n",data);
				printf("Closing");
				close (Sock_Com);
	
				break;
			}



		}
		else
		{

		}
	}


}
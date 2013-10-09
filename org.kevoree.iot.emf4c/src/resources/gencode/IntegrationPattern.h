#ifndef H_IntegrationPattern
#define H_IntegrationPattern
 #include <stdlib.h>
 #include <stdio.h>
#include "ExtraFonctionalProperty.h"
#include "PortTypeRef.h"

typedef struct _IntegrationPattern { 
	char * name;
	int count_extraFonctionalProperties;
	struct ExtraFonctionalProperty **extraFonctionalProperties;
	int count_portTypes;
	struct PortTypeRef **portTypes;
} IntegrationPattern ;

#endif
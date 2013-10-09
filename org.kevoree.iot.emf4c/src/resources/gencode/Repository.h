#ifndef H_Repository
#define H_Repository
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"

typedef struct _Repository { 
	char * url;
	int count_units;
	struct DeployUnit **units;
} Repository ;

#endif
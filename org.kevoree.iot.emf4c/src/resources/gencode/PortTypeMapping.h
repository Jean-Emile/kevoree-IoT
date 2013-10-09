#ifndef H_PortTypeMapping
#define H_PortTypeMapping
 #include <stdlib.h>
 #include <stdio.h>

typedef struct _PortTypeMapping { 
	char * beanMethodName;
	char * serviceMethodName;
	char * paramTypes;
} PortTypeMapping ;

#endif
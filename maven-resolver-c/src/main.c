
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define buildLatestTag  "<latest>"
#define buildEndLatestTag  "</latest>"

#define buildReleaseTag  "<release>"
#define buildEndreleaseTag  "</release>"

#define buildMavenTag  "<buildNumber>"
#define buildEndMavenTag  "</buildNumber>"

#define timestampMavenTag  "<timestamp>"
#define timestampEndMavenTag  "</timestamp>"

#define lastUpdatedMavenTag  "<lastUpdated>"
#define lastUpdatedEndMavenTag  "</lastUpdated>"

#define snapshotVersionClassifierMavenTag  "<classifier>"
#define snapshotVersionClassifierEndMavenTag  "</classifier>"

#define snapshotVersionExtensionMavenTag  "<extension>"
#define snapshotVersionExtensionEndMavenTag  "</extension>"

#define snapshotVersionValueMavenTag  "<value>"
#define snapshotVersionValueEndMavenTag  "</value>"

#define snapshotVersionUpdatedMavenTag  "<updated>"
#define snapshotVersionUpdatedEndMavenTag  "</updated>"

#define metaFile "maven-metadata.xml"
#define localmetaFile  "maven-metadata-local.xml"

#define DEBUG 1

#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#define M2_PATH "/home/jed/.m2"

#define PATH_SEPARATOR "/" 

typedef struct _MavenArtefact{
	char *name;
	char *group;
	char *version;
	char *extension;
}MavenArtefact;


typedef struct _MavenVersionResult{
	char *value;
	char *lastUpdate;
	char *url_origin;
	short notDeployed ;
} MavenVersionResult;




char* foundRelevantVersion(MavenArtefact artefact,const char *basePath, boolean localDeploy) {
	char *askedVersion = str_tolower(artefact.version);
	boolean release = false;
	boolean lastest = false;

	if (strcmp(askedVersion,"release") == 0) {
		release = true;
	}

	if (strcmp(askedVersion,"latest") == 0) {
		lastest = true;
	}
	if (!release && !lastest) {
		return NULL;
	}
	
	char builder[2048]; // todo look the good size
	char sep = '/';
	memset(&builder,sizeof(builder),0);

	strcat(builder,basePath);

	if (startsWith(basePath,"http") == true) {
		sep = '/';
	}

	if (startsWith(basePath,&sep) == true) {
		strcat(builder,&sep);
	}

	if (startsWith(basePath,"http") == true) {
		strcat(builder,str_replace(artefact.group,".","/"));
	} else {

		strcat(builder,str_replace(artefact.group,".",PATH_SEPARATOR));
	}

	strcat(builder,&sep);
	strcat(builder,artefact.name);
	strcat(builder,&sep);
	strcat(builder,artefact.version);
	strcat(builder,&sep);

	if (localDeploy == true) {
		strcat(builder,localmetaFile);
	} else {
		strcat(builder,metaFile);
	}
	PRINTF("builder %s \n",builder);
	
return NULL;
}

MavenVersionResult* resolveVersion(MavenArtefact artefact,const char *basePath,boolean localDeploy){

	MavenVersionResult *result = (MavenVersionResult*)malloc(sizeof(MavenVersionResult));

	char builder[4096]; // todo look the good size
	char sep = '/';
	memset(&builder,sizeof(builder),0);

	strcat(builder,basePath);

	if (startsWith(basePath,"http") == true) {
		sep = '/';
	}

	if (startsWith(basePath,&sep) == true) {
		strcat(builder,&sep);
	}

	if (startsWith(basePath,"http") == true) {
		strcat(builder,str_replace(artefact.group,".","/"));
	} else {

		strcat(builder,str_replace(artefact.group,".",PATH_SEPARATOR));
	}

	strcat(builder,&sep);
	strcat(builder,artefact.name);
	strcat(builder,&sep);
	strcat(builder,artefact.version);
	strcat(builder,&sep);

	if (localDeploy == true) {
		strcat(builder,localmetaFile);
	} else {
		strcat(builder,metaFile);
	}
	PRINTF("builder %s \n",builder);

	return result;
}

FILE * resolve(char *group,char *name,char *versionAsked,char *extension, char  *urls){
	MavenArtefact artefact;
	PRINTF("resolve group %s %s %s %s \n",group,name,versionAsked,extension);
	artefact.group = str_tolower(group);
	artefact.name= str_tolower(name);
	artefact.version = str_tolower(versionAsked);
	artefact.extension = str_tolower(extension);


	if((strcmp(artefact.version,"release") == 0) || (strcmp(artefact.version,"release") == 0) ){
		//char *vremoteSaved = 
		//std::string vremoteSaved = versionResolver->foundRelevantVersion(artefact, basePath, false);
		char *vremoteSaved = foundRelevantVersion(artefact, M2_PATH, false);

	}


	return NULL;	
}

int main(void){

	char * urls = {"http://oss.sonatype.org/content/groups/public", };

	resolve("org.kevoree","org.kevoree.core","RELEASE","jar", urls);

	return 0;
}
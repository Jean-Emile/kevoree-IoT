
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "download.h"

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
#define N_URLS 1 

#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#define M2_PATH "/home/jed/.m2/repository/"
#define LENGHT_URL 1024 // todo look the good size

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
	char *askedVersion = artefact.version;
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

	char builder[LENGHT_URL]; // todo look the good size
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
	strcat(builder,PATH_SEPARATOR);
	strcat(builder,artefact.name);
	strcat(builder,PATH_SEPARATOR);
	strcat(builder,artefact.version);
	strcat(builder,PATH_SEPARATOR);

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

	char builder[LENGHT_URL]; // todo look the good size
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

	// TODO NEXT

	return result;
}



char *hash_resolve (char *buffer)
{
	static char tBuf[4];
	long index;
	unsigned int checksum;
	for (index = 0L, checksum = 0; index < strlen (buffer);
	checksum += (unsigned int) buffer[index++]);
	sprintf (tBuf, "%03d", (unsigned int) (checksum % 256));
	return (tBuf);
}

FILE * resolve(char *group,char *name,char *versionAsked,char *extension, URL  urls[]){
	MavenArtefact artefact;
	PRINTF("resolve group %s %s %s %s \n",group,name,versionAsked,extension);
	artefact.group = group;
	artefact.name= name;
	artefact.version = versionAsked;
	artefact.extension = extension;
	char builder[LENGHT_URL];

	if((strcmp(artefact.version,"release") == 0) || (strcmp(artefact.version,"latest") == 0) ){
		//char *vremoteSaved = 
		//std::string vremoteSaved = versionResolver->foundRelevantVersion(artefact, basePath, false);
		char *vremoteSaved = foundRelevantVersion(artefact, M2_PATH, false);

	}else {


		strcat(builder,M2_PATH);
		strcat(builder,str_replace(artefact.group,".",PATH_SEPARATOR));
		strcat(builder,PATH_SEPARATOR);
		strcat(builder,artefact.name);
		strcat(builder,PATH_SEPARATOR);
		strcat(builder,artefact.version);

		// build url
		strcat(builder,PATH_SEPARATOR);
		strcat(builder,artefact.name);
		strcat(builder,"-");
		strcat(builder,artefact.version);
		strcat(builder,".");
		strcat(builder,artefact.extension);

		char *hash = hash_resolve(builder);
		PRINTF("builder %s -> hash %s \n",builder,hash);
		// check local file system 
		if(file_exists(hash)){
			// load local
		}else {
			memset(&builder,0,sizeof(builder));
			int i;
			for(i=0;i<N_URLS;i++){

				strcat(builder,PATH_SEPARATOR);
				strcat(builder,str_replace(artefact.group,".",PATH_SEPARATOR));
				strcat(builder,PATH_SEPARATOR);
				strcat(builder,artefact.name);
				strcat(builder,PATH_SEPARATOR);
				strcat(builder,artefact.version);

				// build url
				strcat(builder,PATH_SEPARATOR);
				strcat(builder,artefact.name);
				strcat(builder,"-");
				strcat(builder,artefact.version);
				strcat(builder,".");
				strcat(builder,artefact.extension);
				printf("%s \n",builder);
				download(urls[i],builder);
			}
	
			// download 

			// copy in file system
		}

		// check remote 

	}


	return NULL;	
}

int main(void){

	

	URL s[N_URLS];
	s[0].host = "oss.sonatype.org";
	s[0].query = "/content/groups/public";

	resolve("org.kevoree","org.kevoree.core","2.0.12","jar", s);

	return 0;
}
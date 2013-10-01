#include "MavenVersionResolver.h"

MavenVersionResolver::MavenVersionResolver()
{
}

MavenVersionResolver::~MavenVersionResolver()
{
}




MavenVersionResult* MavenVersionResolver::resolveVersion(MavenArtefact artefact, std::string basePath, bool localDeploy){
	MavenVersionResult *result = new MavenVersionResult();
	std::string builder;
	builder.append(basePath);

	


	return result;	
}
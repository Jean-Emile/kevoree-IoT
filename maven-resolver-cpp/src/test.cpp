

#include "MavenResolver.h"


int main(int argc, char **argv) {
	
	MavenResolver *resolver = new MavenResolver();
	
	
	std::vector<std::string> urls;
	urls.push_back("http://oss.sonatype.org/content/groups/public");
	
	
	
	FILE *result = resolver->resolve("org.kevoree","org.kevoree.core","RELEASE","jar", urls);
	
	
	
}
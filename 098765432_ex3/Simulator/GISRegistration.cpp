#include "../Common/GISRegistration.h"

GISRegistration::GISRegistration(std::function<std::unique_ptr<AbstractGIS>()> factory) {
	// For demo only - You actually want to store this funs somewere for later use
	// You certainly don't want to load a map file here  
	auto gis = factory();
	gis->loadMapFile("non existant file"); 
}

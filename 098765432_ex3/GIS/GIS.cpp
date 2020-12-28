#include "GIS.h"
#include "Way.h"
#include "../Common/GISRegistration.h"
#include <iostream> // For demo only

REGISTER_GIS(GIS_098765432) // Registering the GIS

std::vector<EntityId> GIS_098765432::loadMapFile(const std::string& filename) {;
	// This is a stub
	std::cout << "I, GIS_098765432, was requested to open: " << filename << ". I can't do anything with it yet...\n";
	std::vector<EntityId> empty_vector{};
	return empty_vector;	
}

std::vector<EntityId> GIS_098765432::getWaysByJunction(const EntityId& junctionId) const {
	// This is a stub
	(void)junctionId;
	std::vector<EntityId> returned{EntityId{"W1"}, EntityId{"W2"}};
	return returned;
}

std::tuple<Coordinates, EntityId, std::size_t>GIS_098765432::getWayClosestPoint(const Coordinates& c) const {
	// This is a stub
	std::tuple<Coordinates, EntityId, std::size_t> returned = std::make_tuple(Coordinates{Longitude{0},Latitude{0}}, EntityId{"other"}, (std::size_t) 5);
	(void)c;
	return returned;
}

std::tuple<Coordinates, EntityId, std::size_t>GIS_098765432::getWayClosestPoint(const Coordinates& c, const Restrictions& res) const {
	// This is a stub
	std::tuple<Coordinates, EntityId, std::size_t> returned = std::make_tuple(Coordinates{Longitude{0},Latitude{0}}, EntityId{"other"}, (std::size_t) 5);
	(void)c;
	(void)res;
	return returned;
}

const AbstractWay& GIS_098765432::getWay(const EntityId& wayId) const {
	// This is a stub
	(void)wayId;
	static Way dummy_way{};
	return dummy_way;
}

#include "GIS.h"
#include "Way.h"
#include "../Common/GISRegistration.h"
#include <iostream> // For demo only

REGISTER_GIS(GIS_098765432) // Registering the GIS

std::vector<EntityId> GIS_098765432::loadMapFile(const std::string& filename) {;
	// This is a stub
	std::cout << "I, GIS_098765432, was requested to open: " << filename << ". I can't do anything with it yet...\n";
	return {};	
}

std::vector<EntityId> GIS_098765432::getWaysByJunction(const EntityId&) const {
	// This is a stub
	return {EntityId{"W1"}, EntityId{"W2"}};
}

std::tuple<Coordinates, EntityId, std::size_t>GIS_098765432::getWayClosestPoint(const Coordinates&) const {
	// This is a stub
	return std::make_tuple(Coordinates{Longitude{0},Latitude{0}}, EntityId{"other"}, (std::size_t) 5);
}

std::tuple<Coordinates, EntityId, std::size_t>GIS_098765432::getWayClosestPoint(const Coordinates& c, const Restrictions&) const {
	// This is a stub
	return std::make_tuple(c, EntityId{"other"}, (std::size_t) 5);
}

const AbstractWay& GIS_098765432::getWay(const EntityId&) const {
	// This is a stub
	static Way dummy_way{};
	return dummy_way;
}

/* Ex1 Functionality */ 

std::size_t GIS_098765432::clear() { 
	std::size_t size = 8;
	return size;
}

std::size_t GIS_098765432::saveMapFile(const std::string&) const {
	return 8;
}

std::vector<EntityId> GIS_098765432::getEntities(const std::string& search_name) const {
	std::vector<EntityId> res;
	if (search_name == "Washington Square Park") {
		res.emplace_back(EntityId("P1001"));
	}

	return res;
}

std::vector<EntityId> GIS_098765432::getEntities(const std::string&, const Coordinates&, Meters) const {
	std::vector<EntityId> res;
	res.emplace_back(EntityId("W2"));
	return res;
}

std::optional<Coordinates> GIS_098765432::getEntityClosestPoint(const EntityId&, const Coordinates& c) const {
	return {c};
}

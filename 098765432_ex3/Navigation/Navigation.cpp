#include "Navigation.h"
#include "../Common/NavigationRegistration.h"
#include "../Common/AbstractGIS.h"
#include <tuple>
#include <memory>
#include <iostream> // For demo only

REGISTER_NAVIGATION(Navigation_098765432)

/**
 * @brief Get the Routes object
 * 
 * @param start 
 * @param end 
 * @return Routes 
 */
std::unique_ptr<AbstractRoutes> Navigation_098765432::getRoutes(const Coordinates& start, const Coordinates& end) const {
    // For demo only
    std::cout << "Navigation_098765432 is Getting routes...\n";
    auto start_point = gis.getWayClosestPoint(start);
    gis.getWayClosestPoint(end);
    auto start_coordinates = std::get<AbstractGIS::ClosestPoint::Coord>(start_point);
    auto start_way_id = std::get<AbstractGIS::ClosestPoint::WayId>(start_point);
    auto start_segment_index = std::get<AbstractGIS::ClosestPoint::SegmentIndex>(start_point);
    const auto& start_way = gis.getWay(start_way_id);
    [[maybe_unused]] 
    std::pair<Meters, Meters> start_way_partition = start_way.getSegmentPartsOnWay(start_segment_index, start_coordinates);
    return std::make_unique<Routes>(); 
}



#include "Way.h"

/**
 * @brief Get the Junctions object
 * 
 * @return std::pair<EntityId, EntityId> - <from_junction, to_junction>
 */
std::pair<EntityId, EntityId> Way::getJunctions() const {
    // A stub
    return std::make_pair(EntityId{"x"}, EntityId{"y"});
}

/**
 * @brief Get the Length of Way
 *        might be lazily calculated (with a mutable field)
 * 
 * @return Meters 
 */
Meters Way::getLength() const {
    // A stub
    return Meters{100};
} 

/**
 * @brief 
 * 
 * @return true - Way is Bidirectional
 * @return false - Way is Unidirectional
 */
bool Way::isBidirectional() const {
    // A stub
    return false; 
}

/**
 * @brief Get the Speed Limit set on Way 
 * 
 * @return int 
 */
int Way::getSpeedLimit() const {
    // A stub
    return 45;
}

/**
 * @brief 
 * 
 * @return true - Way is an Highway 
 * @return false - Way is not an Highway
 */
bool Way::isHighway() const {
    // A stub
    return false;
}

/**
 * @brief 
 * 
 * @return true - Way is a Toll Road 
 * @return false - Way is not a Toll Road
 */
bool Way::isToll() const {
    // A stub
    return false;
}

/**
 * @brief Get the Segment Parts On Way object
 * 
 * @param segment 
 * @param c 
 * @return std::pair<Meters, Meters> - {from-junction->point, point->to-junction}
 */
std::pair<Meters, Meters> Way::getSegmentPartsOnWay(std::size_t, const Coordinates&) const {
    // A stub
    return std::make_pair(Meters{10}, Meters{90});
}

/**
 * @brief Get the From Junction Coordinates object
 * 
 * @return const Coordinates& 
 */
const Coordinates& Way::getFromJunctionCoordinates() const {
    // A stub
    static Coordinates from_coordinates{Longitude{0.0}, Latitude{0.0}};
    return from_coordinates;
}

/**
 * @brief Get the To Junction Coordinates object
 * 
 * @return const Coordinates& 
 */
const Coordinates& Way::getToJunctionCoordinates() const {
    // A stub
    static Coordinates to_coordinates{Longitude{0.0}, Latitude{0.0}};
    return to_coordinates;
}

/**
 * @brief Get the EntityId of Way object
 *
 * @return const EntityId& - Way's id
 */
const EntityId& Way::getId() const { 
    // A stub
    static EntityId dummy_id{"DUMMY_WAY1000"};
    return dummy_id;
}

#include <cstdio>
#include "gtest/gtest.h"

#include "mocks.h"

// Ex1
#include "../GIS/GISProvider.h"
#include "../Common/CoordinatesMath.h"

// Ex2
#include "../Navigation/NavigationProvider.h"
//#include "../Common/NavigationGIS.h"
#include "../Simulator/NavigationValidator.h"

// Testing Ex2 Functionality

TEST(GISEx2, NavigationTest) {
    	auto gis = GISProvider::getGIS();
	std::string input_file{"ex2_map1.json"};
	auto loaded_entities = gis.loadMapFile(input_file);
	EXPECT_EQ(loaded_entities, getInputFileEntities(input_file));

	NavigationGIS navigation_gis{gis};
	auto navigation = NavigationProvider::getNavigation(navigation_gis);
	
	Coordinates start{ex2_map1_P1}; // Note: this point is not on a way (could be on way in other cases)
	Coordinates end{ex2_map1_P2}; // Note: this point is not on a way (could be on way in other cases)
	auto routes = navigation.getRoutes(start, end);
	EXPECT_TRUE(routes->isValid());

	const AbstractRoute& shortest_distance_route = routes->shortestDistance();
	const AbstractRoute& shortest_time_route = routes->shortestTime();

	EXPECT_EQ(shortest_distance_route.getWays(), ex2_map1_best_route_ways);
	EXPECT_EQ(shortest_time_route.getWays(), ex2_map1_best_route_ways);

    	Coordinates expected_route_start_point = CoordinatesMath::closestPointOnSegment(start, ex2_map1_W1.from, ex2_map1_W1.to);
    	Coordinates expected_route_end_point = CoordinatesMath::closestPointOnSegment(end, ex2_map1_W5.from, ex2_map1_W5.to);

	// Note: route start point is on W1 - different from start
	// A start point of Route is always on a way!
	EXPECT_EQ(shortest_distance_route.getWayStartPoint(), expected_route_start_point); 
	EXPECT_EQ(shortest_time_route.getWayStartPoint(), expected_route_start_point); 

	// Note: route end point is on W5 - different from end
	// A end point of Route is always on a way!
	EXPECT_EQ(shortest_distance_route.getWayEndPoint(), expected_route_end_point); 
	EXPECT_EQ(shortest_time_route.getWayEndPoint(), expected_route_end_point); 

	NavigationValidator navigation_validator{gis}; 

	// Note: we are validating the route with start and end point that are not on ways (could be on way in other cases)
	EXPECT_TRUE(navigation_validator.validateRoute(start, end, shortest_distance_route));
	EXPECT_TRUE(navigation_validator.validateRoute(start, end, shortest_time_route));
}

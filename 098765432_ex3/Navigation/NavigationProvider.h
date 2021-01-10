#pragma once

#include "Navigation.h"

class NavigationProvider {
public:
        static auto getNavigation(const NavigationGIS& navigation_gis) {
                return Navigation_098765432{navigation_gis};
        }
};

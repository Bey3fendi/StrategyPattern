#pragma once
#include "StrategyPattern.h"

class StrategyFactory {
public:
	std::shared_ptr<INavigation> create(NavigatorType navigator) {
		std::shared_ptr<INavigation> selected_way;
		switch (navigator)
		{
		case kBicycle:
			selected_way = std::make_shared<Bicycle>();
			break;
		case kBus:
			selected_way = std::make_shared<Bus>();
			break;
		case kCar:
			selected_way = std::make_shared<Car>();
			break;
		default:
			break;
		}
		return selected_way;
	}

};
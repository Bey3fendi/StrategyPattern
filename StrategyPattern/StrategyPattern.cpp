#include <iostream>
#include "factory.h"
#include "StrategyPattern.h"

void ClientCode(INavigation& navigation) {
    navigation.differentTypesOfNavigator();
}

int main()
{
    std::unique_ptr<StrategyFactory> factory = std::make_unique<StrategyFactory>();
    ClientCode(*(factory->create(NavigatorType::kBicycle)));
}
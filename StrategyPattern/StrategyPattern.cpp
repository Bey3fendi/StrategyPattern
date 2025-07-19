#include <iostream>
#include "factory.h"
#include "StrategyPattern.h"

void ClientCode(INavigation& navigation) {
    navigation.differentTypesOfNavigator();
}

int main()
{
    std::unique_ptr<StrategyFactory> factory = std::make_unique<StrategyFactory>();
    ClientCode(*(factory->create(NavigatorType::kBicycle))); // one of the way is create a factory class for manage the creation of neccesary strategy object
    
    //second way is create and use a context class which set and get neccesary strategies with a method in runtime and call the core logic in it via the selected strategy core logic in it
    std::unique_ptr<context> set_strategy = std::make_unique<context>(std::make_unique<Car>()); // we set the strategy to the car
    set_strategy->doSomeBusinessLogic(); // it will call the bicycle one because we give reference of bicycle object.

    //now change the strategy with set method ->
    set_strategy->SetStrategy(std::make_unique<Bus>());
    set_strategy->doSomeBusinessLogic();

    //or use a factory class like above for control it from one main section.
}
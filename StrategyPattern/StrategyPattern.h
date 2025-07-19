#pragma once
#include <iostream>

enum NavigatorType {
    kBicycle,
    kBus,
    kCar
};

class INavigation {
public:
    virtual ~INavigation() {};

    virtual void differentTypesOfNavigator() = 0;
};

class Bicycle : public INavigation {
public:
    void differentTypesOfNavigator() override {
        std::cout << "show shortest way to selected destination via bicycle!!";
    }
};

class Bus : public INavigation {
public:
    void differentTypesOfNavigator() override {
        std::cout << "show shortest way to selected destination via bus!!";
    }
};

class Car : public INavigation {
public:
    void differentTypesOfNavigator() override {
        std::cout << "show shortest way to selected destination via car!!";
    }
};
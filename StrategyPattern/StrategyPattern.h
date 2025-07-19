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

class context {
public:
    context(std::unique_ptr<INavigation> navigation) : navigation_(std::move(navigation)) {

    }

    void SetStrategy(std::unique_ptr<INavigation> navigation) {
        navigation_ = std::move(navigation);
    }

    std::unique_ptr<INavigation> GetStrategy() {
        return std::move(navigation_);
    }

    void doSomeBusinessLogic() const
    {
        if (navigation_) {
            std::cout << "find a shortest way to go with the strategy (not sure how it'll do it)\n";
            navigation_->differentTypesOfNavigator();
        }
        else {
            std::cout << "Context: Strategy isn't set\n";
        }
    }

private:
    std::unique_ptr<INavigation> navigation_;
};

class Bicycle : public INavigation {
public:
    void differentTypesOfNavigator() override {
        std::cout << "show shortest way to selected destination via bicycle!!\n";
    }
};

class Bus : public INavigation {
public:
    void differentTypesOfNavigator() override {
        std::cout << "show shortest way to selected destination via bus!!\n";
    }
};

class Car : public INavigation {
public:
    void differentTypesOfNavigator() override {
        std::cout << "show shortest way to selected destination via car!!\n";
    }
};
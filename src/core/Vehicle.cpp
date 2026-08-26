#include "../../include/core/Vehicle.h"

#include <iostream>
#include <algorithm>

void Vehicle::addECU(std::shared_ptr<IECU> ecu)
{
    if (ecu)
        ecus.push_back(ecu);
}

void Vehicle::removeECU(const std::string& name)
{
    ecus.erase(
        std::remove_if(
            ecus.begin(),
            ecus.end(),
            [&](const std::shared_ptr<IECU>& ecu)
            {
                return ecu->getName() == name;
            }),
        ecus.end());
}

std::shared_ptr<IECU> Vehicle::findECU(const std::string& name)
{
    for (auto& ecu : ecus)
    {
        if (ecu->getName() == name)
            return ecu;
    }

    return nullptr;
}

void Vehicle::initialize()
{
    for (auto& ecu : ecus)
        ecu->initialize();
}

void Vehicle::update()
{
    for (auto& ecu : ecus)
        ecu->update();
}

void Vehicle::shutdown()
{
    for (auto& ecu : ecus)
        ecu->shutdown();
}

void Vehicle::printStatus() const
{
    std::cout << "\n============================\n";
    std::cout << "      VEHICLE STATUS\n";
    std::cout << "============================\n";

    for (const auto& ecu : ecus)
        ecu->printStatus();
}
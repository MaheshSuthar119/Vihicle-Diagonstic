#pragma once

#include "../interfaces/IECU.h"

#include <memory>
#include <vector>
#include <string>

class Vehicle
{
private:
    std::vector<std::shared_ptr<IECU>> ecus;

public:
    void addECU(std::shared_ptr<IECU> ecu);

    void removeECU(const std::string& name);

    std::shared_ptr<IECU> findECU(const std::string& name);

    void initialize();

    void update();

    void shutdown();

    void printStatus() const;
};
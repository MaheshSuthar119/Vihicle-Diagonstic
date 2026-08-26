#pragma once

#include "Vehicle.h"

class SimulationManager
{
private:
    Vehicle vehicle;
    bool running;

public:
    SimulationManager();

    void initialize();
    void run(int ticks);
    void shutdown();

    Vehicle& getVehicle();
};
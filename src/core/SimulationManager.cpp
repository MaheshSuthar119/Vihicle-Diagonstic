#include "../../include/core/SimulationManager.h"

#include <thread>
#include <chrono>

SimulationManager::SimulationManager()
    : running(false)
{
}

void SimulationManager::initialize()
{
    vehicle.initialize();
}

void SimulationManager::run(int ticks)
{
    running = true;

    for (int i = 0; i < ticks && running; ++i)
    {
        vehicle.update();

        vehicle.printStatus();

        std::this_thread::sleep_for(
            std::chrono::seconds(1));
    }
}

void SimulationManager::shutdown()
{
    running = false;

    vehicle.shutdown();
}

Vehicle& SimulationManager::getVehicle()
{
    return vehicle;
}
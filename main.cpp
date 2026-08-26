#include "include/core/SimulationManager.h"

#include "include/ecu/EngineECU.h"
#include "include/ecu/BatteryECU.h"
#include "include/ecu/BrakeECU.h"

#include <iostream>
#include <memory>

int main()
{
    std::cout << "Vehicle Diagnostics & ECU Simulator\n";

    SimulationManager simulation;

    auto engine = std::make_shared<EngineECU>();
    auto battery = std::make_shared<BatteryECU>();
    auto brake = std::make_shared<BrakeECU>();

    simulation.getVehicle().addECU(engine);
    simulation.getVehicle().addECU(battery);
    simulation.getVehicle().addECU(brake);

    engine->startEngine();

    simulation.initialize();

    simulation.run(10);

    simulation.shutdown();

    return 0;
}
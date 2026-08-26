#include "../../include/ecu/EngineECU.h"

#include <iostream>

EngineECU::EngineECU()
    : engineRunning(false),
      rpm(0),
      temperature(25.0),
      oilPressure(0.0)
{
}

void EngineECU::initialize()
{
    engineRunning = false;
    rpm = 0;
    temperature = 25.0;
    oilPressure = 0.0;
}

void EngineECU::update()
{
    if (!engineRunning)
        return;

    if (rpm < 800)
        rpm = 800;

    temperature += 0.5;

    oilPressure = 2.5;
}

void EngineECU::shutdown()
{
    engineRunning = false;
    rpm = 0;
}

void EngineECU::printStatus() const
{
    std::cout << "\n--- Engine ECU ---\n";
    std::cout << "Running     : "
              << (engineRunning ? "YES" : "NO") << '\n';

    std::cout << "RPM         : " << rpm << '\n';
    std::cout << "Temperature : " << temperature << " C\n";
    std::cout << "Oil Pressure: " << oilPressure << " bar\n";
}

std::string EngineECU::getName() const
{
    return "Engine ECU";
}

void EngineECU::startEngine()
{
    engineRunning = true;
    rpm = 800;
    oilPressure = 2.5;
}

void EngineECU::stopEngine()
{
    engineRunning = false;
    rpm = 0;
    oilPressure = 0.0;
}

void EngineECU::increaseRPM()
{
    if (engineRunning)
        rpm += 500;
}

void EngineECU::decreaseRPM()
{
    if (engineRunning && rpm >= 500)
        rpm -= 500;
}

void EngineECU::setRPM(int value)
{
    if (value >= 0)
        rpm = value;
}

int EngineECU::getRPM() const
{
    return rpm;
}

double EngineECU::getTemperature() const
{
    return temperature;
}

double EngineECU::getOilPressure() const
{
    return oilPressure;
}
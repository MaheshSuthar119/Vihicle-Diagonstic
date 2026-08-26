#include "../../include/ecu/BrakeECU.h"

#include <iostream>

BrakeECU::BrakeECU()
    : brakeApplied(false),
      pressure(0.0)
{
}

void BrakeECU::initialize()
{
    brakeApplied = false;
    pressure = 0.0;
}

void BrakeECU::update()
{
    if (brakeApplied)
        pressure = 50.0;
    else
        pressure = 0.0;
}

void BrakeECU::shutdown()
{
    brakeApplied = false;
    pressure = 0.0;
}

void BrakeECU::printStatus() const
{
    std::cout << "\n--- Brake ECU ---\n";
    std::cout << "Brake    : "
              << (brakeApplied ? "APPLIED" : "RELEASED")
              << '\n';

    std::cout << "Pressure : " << pressure << " bar\n";
}

std::string BrakeECU::getName() const
{
    return "Brake ECU";
}

void BrakeECU::applyBrake()
{
    brakeApplied = true;
}

void BrakeECU::releaseBrake()
{
    brakeApplied = false;
}

double BrakeECU::getPressure() const
{
    return pressure;
}

bool BrakeECU::isBrakeApplied() const
{
    return brakeApplied;
}
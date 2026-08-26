#include "../../include/ecu/BatteryECU.h"

#include <iostream>

BatteryECU::BatteryECU()
    : voltage(12.6),
      current(0.0),
      stateOfCharge(100.0)
{
}

void BatteryECU::initialize()
{
    voltage = 12.6;
    current = 0.0;
    stateOfCharge = 100.0;
}

void BatteryECU::update()
{
    if (stateOfCharge > 0)
    {
        stateOfCharge -= 0.1;
        voltage -= 0.001;
    }
}

void BatteryECU::shutdown()
{
    current = 0.0;
}

void BatteryECU::printStatus() const
{
    std::cout << "\n--- Battery ECU ---\n";
    std::cout << "Voltage : " << voltage << " V\n";
    std::cout << "Current : " << current << " A\n";
    std::cout << "SOC     : " << stateOfCharge << " %\n";
}

std::string BatteryECU::getName() const
{
    return "Battery ECU";
}

void BatteryECU::charge()
{
    if (stateOfCharge < 100.0)
        stateOfCharge += 1.0;
}

void BatteryECU::discharge()
{
    if (stateOfCharge > 0.0)
        stateOfCharge -= 1.0;
}

double BatteryECU::getVoltage() const
{
    return voltage;
}

double BatteryECU::getCurrent() const
{
    return current;
}

double BatteryECU::getStateOfCharge() const
{
    return stateOfCharge;
}
#pragma once

#include "../interfaces/IECU.h"
#include <string>

class BatteryECU : public IECU
{
private:
    double voltage;
    double current;
    double stateOfCharge;

public:
    BatteryECU();

    void initialize() override;
    void update() override;
    void shutdown() override;
    void printStatus() const override;

    std::string getName() const override;

    void charge();
    void discharge();

    double getVoltage() const;
    double getCurrent() const;
    double getStateOfCharge() const;
};
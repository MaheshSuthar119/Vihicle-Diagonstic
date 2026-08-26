#pragma once

#include "../interfaces/IECU.h"
#include <string>

class BrakeECU : public IECU
{
private:
    bool brakeApplied;
    double pressure;

public:
    BrakeECU();

    void initialize() override;
    void update() override;
    void shutdown() override;
    void printStatus() const override;

    std::string getName() const override;

    void applyBrake();
    void releaseBrake();

    double getPressure() const;
    bool isBrakeApplied() const;
};
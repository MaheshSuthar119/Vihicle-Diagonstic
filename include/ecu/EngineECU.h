#pragma once

#include "../interfaces/IECU.h"
#include <string>

class EngineECU : public IECU
{
private:
    bool engineRunning;
    int rpm;
    double temperature;
    double oilPressure;

public:
    EngineECU();

    void initialize() override;
    void update() override;
    void shutdown() override;
    void printStatus() const override;

    std::string getName() const override;

    void startEngine();
    void stopEngine();

    void increaseRPM();
    void decreaseRPM();

    void setRPM(int value);

    int getRPM() const;
    double getTemperature() const;
    double getOilPressure() const;
};
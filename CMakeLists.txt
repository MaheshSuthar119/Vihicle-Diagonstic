cmake_minimum_required(VERSION 3.20)

project(VehicleDiagnostics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(VehicleDiagnostics

    main.cpp

    src/ecu/EngineECU.cpp
    src/ecu/BatteryECU.cpp
    src/ecu/BrakeECU.cpp

    src/core/Vehicle.cpp
    src/core/SimulationManager.cpp
)

target_include_directories(
    VehicleDiagnostics
    PRIVATE
    include
)
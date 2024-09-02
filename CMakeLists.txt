# lib/TMCStepper/CMakeLists.txt

# Minimum CMake version required
cmake_minimum_required(VERSION 3.13)

# Define the TMCStepper library, including only the TMC2209-related files
add_library(TMCStepper STATIC
    src/source/TMC2208Stepper.cpp
    src/source/TMC2209Stepper.cpp
    src/source/TMCStepper.cpp
    
    src/source/CHOPCONF.cpp
    src/source/COOLCONF.cpp
    src/source/DRV_STATUS.cpp
    src/source/GCONF.cpp
    src/source/IHOLD_IRUN.cpp
    src/source/PWMCONF.cpp
    src/source/SERIAL_SWITCH.cpp
)

# Include directories for the TMCStepper library
target_include_directories(TMCStepper PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src  # Include the directory where TMCStepper.h is located
)

# Link any required libraries for TMCStepper, if necessary
target_link_libraries(TMCStepper PUBLIC
    pico_stdlib      # Standard Pico SDK libraries
    hardware_uart    # UART communication
    hardware_gpio    # GPIO control
)

cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
project(
  adc
  VERSION 0.1
  LANGUAGES C)
set(CMAKE_C_COMPILER avr-gcc)
set(MCU_TARGET atmega328p)
set(CPU_FREQUENCY 1000000)
set(CMAKE_C_FLAGS "-Wall -mmcu=${MCU_TARGET}")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-Map,${PROJECT_NAME}.map")

add_compile_options(-DF_CPU=${CPU_FREQUENCY}UL)

add_subdirectory(src)

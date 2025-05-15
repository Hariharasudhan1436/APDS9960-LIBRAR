cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(apds9960_project)

pico_sdk_init()

add_executable(apds9960
    main.cpp
    apds9960.cpp
)

target_link_libraries(apds9960 pico_stdlib hardware_i2c)
pico_add_extra_outputs(apds9960)

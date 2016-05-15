cmake_minimum_required(VERSION 3.2)
project(arduino_flotilla_dummy)

include(CMakeListsPrivate.txt)

add_definitions(-DF_CPU=8000000L)
add_definitions(-DARDUINO_ARCH_AVR)
add_definitions(-DAVR_PROMICRO8)
add_definitions(-DUSB_VID=0x1B4F)
add_definitions(-DUSB_PID=0x9203)
add_definitions(-DUSB_PRODUCT="SparkFun Pro Micro")
add_definitions(-DUSB_MANUFACTURER="SparkFun")
add_definitions(-DARDUINO=10608)
add_definitions(-DPLATFORMIO=020901)
add_definitions(-D__AVR_ATmega32U4__)

add_custom_target(
    PLATFORMIO_BUILD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOAD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_CLEAN ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target clean
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_PROGRAM ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target program
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOADFS ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target uploadfs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPDATE_ALL ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion update
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(arduino_flotilla_dummy
    src/main.cpp
    src/handleupdate.cpp
    src/handlecommand.cpp
        src/pushbutton.h src/led.h src/pushbutton.cpp)

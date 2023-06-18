cmake_minimum_required(VERSION 3.0.0)
project(SCARA_APPLICATIONLAYER VERSION 0.1.0)

set(UNIT_TESTING TRUE)

if(UNIT_TESTING)
    add_compile_definitions(STUB_ONESHOTTIMER STUB_GPIO)
endif()


add_subdirectory(Common)
add_subdirectory(FirmwareInterface)
add_subdirectory(HwAbstraction)


if(UNIT_TESTING)
    add_subdirectory(Test)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

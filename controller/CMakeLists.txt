add_library(cnc_controller_data INTERFACE)
target_include_directories(cnc_controller_data INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(stepper_motor_driver INTERFACE)
target_include_directories(stepper_motor_driver INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(stepper_motor_driver INTERFACE cnc_controller_data)

add_library(cnc_controller INTERFACE)
target_include_directories(cnc_controller INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(cnc_controller INTERFACE cnc_controller_data stepper_motor_driver)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(cnc_controller_uts ${CMAKE_CURRENT_SOURCE_DIR}/src/cnc_controller_uts.cpp)
target_link_libraries(cnc_controller_uts PRIVATE gtest gtest_main cnc_controller)
add_test(NAME cnc_controller_uts COMMAND cnc_controller_uts_run)
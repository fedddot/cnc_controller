#include <gtest/gtest.h>
#include <stdexcept>
#include <thread>
#include <chrono>

#include "cnc_controller.hpp"
#include "cnc_controller_data.hpp"
#include "stepper_motor_driver.hpp"

using namespace cnc_controller;

class MockStepperMotorDriver : public StepperMotorDriver {
public:
    void step(const Direction& direction) override {
        throw std::runtime_error("not implemented");
    }
};

TEST(cnc_controller_uts, move_sanity) {
    // GIVEN
    const auto linear_movement_vector = Vector(100, 200, 300);
    const auto duration = 1000;
    const auto linear_movement = LinearMovement{linear_movement_vector, duration};
    const auto steps_per_length = 100;
    // WHEN
    auto controller = CncController(
        steps_per_length,
        [](const Axis& axis) -> StepperMotorDriver * { 
            return new MockStepperMotorDriver();
        },
        [](const int& delay_ms) {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
        }
    );

    // THEN
    ASSERT_NO_THROW(controller.move(linear_movement));
}
#include <gtest/gtest.h>
#include <stdexcept>

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
    const auto linear_movement_vector = Vector<int>{100, 200, 300};
    const auto duration = 1000;
    const auto linear_movement = LinearMovement<int, int>{linear_movement_vector, duration};
    const auto steps_per_length = 100;
    // WHEN
    auto controller = CncController<int, int>(steps_per_length);

    // THEN
    ASSERT_NO_THROW(controller.move(linear_movement));
}
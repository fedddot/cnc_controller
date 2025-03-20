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

    // WHEN
    auto controller = CncController<int, int>();

    // THEN
    ASSERT_NO_THROW(controller.move(linear_movement));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
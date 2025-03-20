#include <gtest/gtest.h>
#include "cnc_controller.hpp"
#include "cnc_controller_data.hpp"

using namespace cnc_controller;

class MockStepperMotorDriver : public StepperMotorDriver<int> {
public:
    void step(const int& steps) override {
        steps_ = steps;
    }

    void setDirection(const Direction& direction) override {
        direction_ = direction;
    }

    int steps_ = 0;
    Direction direction_ = Direction::CW;
};

TEST(CncControllerTest, MoveTest) {
    MockStepperMotorDriver motorDriver;
    CncController<int, int> controller;

    LinearMovement<int, int> movement{100, 200};
    controller.move(movement);

    EXPECT_EQ(motorDriver.steps_, 100);
    EXPECT_EQ(motorDriver.direction_, Direction::CW);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
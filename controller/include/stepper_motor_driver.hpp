#ifndef STEPPER_MOTOR_DRIVER_HPP
#define STEPPER_MOTOR_DRIVER_HPP

#include "cnc_controller_data.hpp"

namespace cnc_controller {
    class StepperMotorDriver {
    public:
        virtual ~StepperMotorDriver() noexcept = default;
        virtual void step(const Direction& direction) = 0;
    };
}

#endif // STEPPER_MOTOR_DRIVER_HPP
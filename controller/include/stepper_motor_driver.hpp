#ifndef STEPPER_MOTOR_DRIVER_HPP
#define STEPPER_MOTOR_DRIVER_HPP

#include "cnc_controller_data.hpp"

namespace cnc_controller {
    template <typename Tstep>
    class StepperMotorDriver {
    public:
        StepperMotorDriver() = default;
        StepperMotorDriver(const StepperMotorDriver&) = delete;
        StepperMotorDriver& operator=(const StepperMotorDriver&) = delete;
        virtual ~StepperMotorDriver() noexcept = default;

        virtual void step(const Tstep& steps) = 0;
        virtual void setDirection(const Direction& direction) = 0;
    };
}

#endif // STEPPER_MOTOR_DRIVER_HPP
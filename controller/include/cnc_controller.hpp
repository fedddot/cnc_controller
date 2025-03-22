#ifndef	CNC_CONTROLLER_HPP
#define	CNC_CONTROLLER_HPP

#include <functional>
#include <map>
#include <memory>
#include <stdexcept>

#include "cnc_controller_data.hpp"
#include "stepper_motor_driver.hpp"

namespace cnc_controller {
	class CncController {
	public:
		using StepperMotorDriverCreator = std::function<StepperMotorDriver *(const Axis&)>;
		using DelayFunction = std::function<void(const unsigned int& delay_ms)>;

		CncController(
			const unsigned int steps_per_mm,
			const StepperMotorDriverCreator& stepper_motor_driver_creator,
			const DelayFunction& delay_function
		);
		CncController(const CncController&) = delete;
		CncController& operator=(const CncController&) = delete;
		~CncController() noexcept = default;

		void move(const LinearMovement& movement);
	private:
		unsigned int m_steps_per_mm;
		DelayFunction m_delay_function;
		std::map<Axis, std::unique_ptr<StepperMotorDriver>> m_stepper_motor_drivers;
	};

	inline CncController::CncController(
		const unsigned int steps_per_mm,
		const StepperMotorDriverCreator& stepper_motor_driver_creator,
		const DelayFunction& delay_function
	) : m_steps_per_mm(steps_per_mm), m_delay_function(delay_function) {
		if (!steps_per_mm) {
			throw std::invalid_argument("steps_per_mm must be a positive integer");
		}
		if (!delay_function) {
			throw std::invalid_argument("delay_function must be callable");
		}
		if (!stepper_motor_driver_creator) {
			throw std::invalid_argument("stepper_motor_driver_creator must be callable");
		}
		for (const auto axis : {Axis::X, Axis::Y, Axis::Z}) {
			m_stepper_motor_drivers[axis] = std::unique_ptr<StepperMotorDriver>(stepper_motor_driver_creator(axis));
		}
	}

	inline void CncController::move(const LinearMovement& movement) {
		// throw std::runtime_error("not implemented");
	}	
}

#endif // CNC_CONTROLLER_HPP
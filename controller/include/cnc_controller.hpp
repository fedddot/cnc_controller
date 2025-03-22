#ifndef	CNC_CONTROLLER_HPP
#define	CNC_CONTROLLER_HPP

#include <functional>
#include <map>
#include <memory>
#include <stdexcept>

#include "cnc_controller_data.hpp"
#include "stepper_motor_driver.hpp"

namespace cnc_controller {
	template <typename Tlength, typename Tduration>
	class CncController {
	public:
		using StepperMotorDriverCreator = std::function<StepperMotorDriver *(const Axis&)>;
		using DelayFunction = std::function<void(const Tduration&)>;

		CncController(
			const unsigned int steps_per_length,
			const StepperMotorDriverCreator& stepper_motor_driver_creator,
			const DelayFunction& delay_function
		);
		CncController(const CncController&) = delete;
		CncController& operator=(const CncController&) = delete;
		~CncController() noexcept = default;

		void move(const LinearMovement<Tlength, Tduration>& movement);
	private:
		unsigned int m_steps_per_length;
		DelayFunction m_delay_function;
		std::map<Axis, std::unique_ptr<StepperMotorDriver>> m_stepper_motor_drivers;
	};

	template <typename Tlength, typename Tduration>
	inline CncController<Tlength, Tduration>::CncController(
		const unsigned int steps_per_length,
		const StepperMotorDriverCreator& stepper_motor_driver_creator,
		const DelayFunction& delay_function
	) : m_steps_per_length(steps_per_length), m_delay_function(delay_function) {
		if (!steps_per_length) {
			throw std::invalid_argument("steps_per_length must be a positive integer");
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

	template <typename Tlength, typename Tduration>
	inline void CncController<Tlength, Tduration>::move(const LinearMovement<Tlength, Tduration>& movement) {
		// throw std::runtime_error("not implemented");
	}	
}

#endif // CNC_CONTROLLER_HPP
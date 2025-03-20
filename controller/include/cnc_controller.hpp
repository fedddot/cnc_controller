#ifndef	CNC_CONTROLLER_HPP
#define	CNC_CONTROLLER_HPP

#include <stdexcept>

#include "cnc_controller_data.hpp"

namespace cnc_controller {
	template <typename Tlength, typename Tduration>
	class CncController {
	public:
		CncController(const unsigned int steps_per_length);
		CncController(const CncController&) = delete;
		CncController& operator=(const CncController&) = delete;
		~CncController() noexcept = default;

		void move(const LinearMovement<Tlength, Tduration>& movement);
	private:
		unsigned int m_steps_per_length;
	};

	template <typename Tlength, typename Tduration>
	inline CncController<Tlength, Tduration>::CncController(const unsigned int steps_per_length) : m_steps_per_length(steps_per_length) {
		if (!steps_per_length) {
			throw std::invalid_argument("steps_per_length must be a positive integer");
		}
	}

	template <typename Tlength, typename Tduration>
	inline void CncController<Tlength, Tduration>::move(const LinearMovement<Tlength, Tduration>& movement) {
		throw std::runtime_error("not implemented");
	}	
}

#endif // CNC_CONTROLLER_HPP
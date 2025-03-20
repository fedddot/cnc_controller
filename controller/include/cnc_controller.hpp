#ifndef	CNC_CONTROLLER_HPP
#define	CNC_CONTROLLER_HPP

#include <stdexcept>

#include "cnc_controller_data.hpp"

namespace cnc_controller {
	template <typename Tlength, typename Tduration>
	class CncController {
	public:
		CncController();
		CncController(const CncController&) = delete;
		CncController& operator=(const CncController&) = delete;
		~CncController() noexcept = default;

		void move(const LinearMovement<Tlength, Tduration>& movement);
	private:
		
	};

	template <typename Tlength, typename Tduration>
	inline CncController<Tlength, Tduration>::CncController() {
		
	}

	template <typename Tlength, typename Tduration>
	inline void CncController<Tlength, Tduration>::move(const LinearMovement<Tlength, Tduration>& movement) {
		throw std::runtime_error("not implemented");
	}	
}

#endif // CNC_CONTROLLER_HPP
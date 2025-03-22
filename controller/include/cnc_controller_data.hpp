#ifndef	CNC_CONTROLLER_DATA_HPP
#define	CNC_CONTROLLER_DATA_HPP

namespace cnc_controller {
	template <typename Tlength>
	struct Vector {
		Tlength x;
		Tlength y;
		Tlength z;
	};

	template <typename Tlength, typename Tduration>
	struct LinearMovement {
		Vector<Tlength> destination;
		Tduration duration;
	};

    enum class Direction: int {
        CW,
        CCW
    };

	enum class Axis: int {
		X = 0,
		Y,
		Z
	};
}

#endif // CNC_CONTROLLER_DATA_HPP
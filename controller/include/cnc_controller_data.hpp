#ifndef	CNC_CONTROLLER_DATA_HPP
#define	CNC_CONTROLLER_DATA_HPP

#include <map>

namespace cnc_controller {
	enum class Axis: int {
		X = 0,
		Y,
		Z
	};

	class Vector {
	public:
		Vector(const double& x, const double& y, const double& z): m_components({{Axis::X, x}, {Axis::Y, y}, {Axis::Z, z}}) {

		}
		Vector(const Vector&) = default;
		Vector& operator=(const Vector&) = default;
		~Vector() noexcept = default;
		double get(const Axis& axis) const {
			return m_components.at(axis);
		}
	private:
		std::map<Axis, double> m_components;
	};

	struct LinearMovement {
		Vector destination;
		unsigned int duration_ms;
	};

    enum class Direction: int {
        CW,
        CCW
    };
}

#endif // CNC_CONTROLLER_DATA_HPP
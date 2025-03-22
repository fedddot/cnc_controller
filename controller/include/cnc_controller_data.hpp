#ifndef	CNC_CONTROLLER_DATA_HPP
#define	CNC_CONTROLLER_DATA_HPP

#include <map>
namespace cnc_controller {
	enum class Axis: int {
		X = 0,
		Y,
		Z
	};

	template <typename Tlength>
	class Vector {
	public:
		Vector(const Tlength& x, const Tlength& y, const Tlength& z): m_components({{Axis::X, x}, {Axis::Y, y}, {Axis::Z, z}}) {

		}
		Vector(const Vector&) = default;
		Vector& operator=(const Vector&) = default;
		~Vector() noexcept = default;
		Tlength get(const Axis& axis) const {
			return m_components.at(axis);
		}
	private:
		std::map<Axis, Tlength> m_components;
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
}

#endif // CNC_CONTROLLER_DATA_HPP
#include <iostream>

class Parallelogram {
private:
	// поля
	float m_base;
	float m_height;
	float m_side;

public:
	Parallelogram(float base, float height, float side) {
		setB(base);
		setH(height);
		setS(side);
	}


	void setB(float base) {
		if (base < 0)
			std::cout << "Negative base" << std::endl;
		m_base = base;
	}

	void setH(float height) {
		if (height < 0)
			std::cout << "Negative height" << std::endl;
		m_height = height;
	}

	void setS(float side) {
		if (side < 0)
			std::cout << "Negative side" << std::endl;
		m_side = side;
	}

	float Perimeter(){
		return 2 * (m_base + m_side);
	}


	~Parallelogram() = default;

};

int main() {
	float base, height, side;

	std::cin >> base;
	std::cin >> height;
	std::cin >> side;

	Parallelogram p(base, height, side);

	std::cout << "Площадь: " << p.Square() << std::endl;
	std::cout << "Периметр: " << p.Perimeter() << std::endl;

	return 0;
}

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

	float getB() {
		return m_base;
	}

	float getH() {
		return m_height;
	}

	float getS() {
		return m_side;
	}

	float Square(){
		return m_base * m_height;
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

	std::cout << "Основание: " << p.getB() << std::endl;
	std::cout << "Высота: " << p.getH() << std::endl;
	std::cout << "Сторона: " << p.getS() << std::endl;
	std::cout << "Площадь: " << p.Square() << std::endl;
	std::cout << "Периметр: " << p.Perimeter() << std::endl;

	return 0;
}

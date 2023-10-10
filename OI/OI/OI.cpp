#include <iostream>

template <typename T>
class Vector2 {
public:
	struct Position {
		T x;
		T y;
		T z;
	};

	Position position;

	void echo_position() {
		std::cout << "x: " << position.x << ", y: " << position.y << ", z: " << position.z << std::endl;
	}
};

int main() {
	// TEMPLATE CLASS
	Vector2<float> vector2;
	vector2.position.x = 13.5;
	vector2.position.y = 7.25;
	vector2.position.z = 3.75;

	vector2.echo_position();

	// POINTERS
	int number = 256;
	int* pointer = &number;
	std::cout << pointer << " - " << *pointer << std::endl;

	// DYNAMIC POINTERS
	int* dynamic_int = new int;
	*dynamic_int = 16;
	std::cout << dynamic_int << " - " << *dynamic_int << std::endl;

	// TABLE POINTERS
	int tab[5] = { 0, 2, 4, 8, 16 };
	int* tab_pointer = tab;
	int element = tab_pointer[1];
	std::cout << tab_pointer << " - " << element << std::endl;

	return 0;
}

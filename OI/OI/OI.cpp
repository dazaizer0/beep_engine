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
		std::cout << std::endl;
	}
};

template <typename T>
class Container2 {
public:
	T a;
	T b;

	Container2(T value1, T value2) {
		a = value1;
		b = value2;
	}
};

int main() {
	// TEMPLATE CLASS
	Vector2<float> vector2;
	vector2.position.x = 13.5;
	vector2.position.y = 7.25;
	vector2.position.z = 3.75;

	vector2.echo_position();
	
	std::cout << &vector2 << std::endl;
	std::cout << sizeof(vector2) << std::endl;

	std::cout << sizeof(Container2<int>) << std::endl;
	std::cout << std::endl;

	Container2<int> Container2Table[3] = { Container2<int>(2, 4), Container2<int>(4, 8), Container2<int>(8, 16) };
	Container2<int>* Container2TablePointer = Container2Table;
	for (int i = 0; i < sizeof(Container2Table) / sizeof(Container2Table[0]); i++) {
		Container2<int> Container2Element = Container2TablePointer[i];

		std::cout << "> " << i + 1 << ":\n" << Container2TablePointer << " - " << Container2Element.a << std::endl;
		std::cout << Container2TablePointer << " - " << Container2Element.b << std::endl;
		std::cout << std::endl;
	}

	/*for (Container2<int> container : Container2Table) {
		std::cout << container.a << ", " << container.b << std::endl;
	}*/
	return 0;
}

/* > RESOURCES:
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
*/

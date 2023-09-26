#include <iostream>
#include <string>

class Main {
public:
	std::string program_name;

	Main(const std::string &program_name) : program_name(program_name) {}

	void echo_program_name() {
		std::cout << program_name << "/...";
	}
};

class Seco : public Main{
public:
	std::string next_program_name;
	Seco(const std::string &program_name, const std::string& next_program_name) : Main(program_name),  next_program_name(next_program_name) {}

	void echo_this_program_name() {
		std::cout << program_name << "/" << next_program_name << "/...";
	}
};

int main() {
	Seco program("main", "seco_program");
	program.echo_this_program_name();
	return 0;
}

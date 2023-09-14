#include "beep.h"


void PLAY(double frequency, int duration) {

    double period = 1.0 / frequency * 1000000; // T = 1 / f 

#ifdef _WIN32
    Beep(static_cast<int>(frequency), duration);
#else
    for (int i = 0; i < duration * 1000; i += period) {
        std::cout << "\a"; // play sound
        std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(period)));
    }
#endif
}

class SOUND {
public:

    SOUND() : frequency(0.0), duration(0) {} // default sound constructor
    SOUND(double f, int d) : frequency(f), duration(d) {}

    double getFrequency() const {
        return frequency;
    }

    int getDuration() const {
        return duration;
    }

private:

    double frequency;
    int duration;
};

void PLAY_SOUNDS(std::map<int, SOUND> SOUNDS) {

    for (const auto& sound : SOUNDS) {
        PLAY(sound.second.getFrequency(), sound.second.getDuration());
    }
}

void BEEP_MAP() { // beepengine option 1

    std::map<int, SOUND> SOUNDS;
    int length;

    std::string hello_message = "beep_map <- opt2";

    for (int i = 0; i < hello_message.length(); i++) {
        std::cout << hello_message[i];
        Sleep(25);
    }
    std::cout << std::endl;

    std::cout << "Length of sounds map: ";
    std::cin >> length;

    for (int i = 0; i < length; i++) {
        double frequency;
        int duration;

        std::cout << i << " > frequency (Hz): ";
        std::cin >> frequency;
        std::cout << i << " > duration (ms): ";
        std::cin >> duration;

        std::cout << length - i - 1 << " left" << std::endl;

        SOUND temp_sound(frequency, duration);
        SOUNDS[i] = temp_sound;
    }

    PLAY_SOUNDS(SOUNDS);
}

void BEEPBOARD() { // beepengine option 2

    int base_frequency = 300;
    std::string hello_message = "<- base_frequency, beepboard[play = [f, g, h, j, k], tone_controls[+, -], quit[/]] beepboard <- opt2";

    std::cout << base_frequency;
    for (int i = 0; i < hello_message.length(); i++) {
        std::cout << hello_message[i];
        Sleep(25);
    }
    std::cout << std::endl;

    char key;
    int counter = 0;
    while (true) {
        if (_kbhit()) {  // check if key have been pressed
            key = _getch();  // get key

            if (key == 'F' || key == 'f') {
                PLAY(base_frequency, 720);
                std::cout << "f, ";
            }

            if (key == 'G' || key == 'g') {
                PLAY(base_frequency + 150, 720);
                std::cout << "g, ";
            }

            if (key == 'H' || key == 'h') {
                PLAY(base_frequency + 300, 720);
                std::cout << "h, ";
            }

            if (key == 'J' || key == 'j') {
                PLAY(base_frequency + 450, 720);
                std::cout << "j, ";
            }

            if (key == 'K' || key == 'k') {
                PLAY(base_frequency + 550, 720);
                std::cout << "k, ";
            }

            if (key == '+') {
                if (base_frequency < 1000) {
                    base_frequency += 100;
                    std::cout << "i = up, bf = " << base_frequency << ", ";
                }
                else {
                    std::cout << "i = none, bf = " << base_frequency << ", ";
                }
            }

            if (key == '-') {
                if (base_frequency > 200) {
                    base_frequency -= 100;
                    std::cout << "o = down, bf = " << base_frequency << ", ";
                }
                else {
                    std::cout << "o = none, bf = " << base_frequency << ", ";
                }
            }

            if (key == '/') {
                break;
            }

            if (counter >= 12) {
                std::cout << std::endl;
                counter = 0;
            }

            counter += 1;
        }
    }
}

void CLEAR_TERMINAL() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


int main() {

    int option;
    std::string hello_message = "[1 - beep_map], [2 - beepboard]: ";

    for (int i = 0; i < hello_message.length(); i++) {
        std::cout << hello_message[i];
        Sleep(25);
    }
    std::cout << std::endl;
    std::cin >> option;

    switch (option) {
    case 1:
        CLEAR_TERMINAL();
        BEEP_MAP();
        break;
    case 2:
        CLEAR_TERMINAL();
        BEEPBOARD();
        break;
    default:
        break;
    }
    return 0;
}

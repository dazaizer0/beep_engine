#include "beep.h"


void PRINT(const std::string& message) {
    std::cout << message;
}

void PLAY(const double frequency, int duration) {
    const double period = 1.0 / frequency * 1000000; // T = 1 / f 

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
    SOUND(const double f, const int d) : frequency(f), duration(d) {}

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

void PLAY_SOUNDS(const std::map<int, SOUND>& SOUNDS) {
    for (const auto& sound : SOUNDS) {
        PLAY(sound.second.getFrequency(), sound.second.getDuration());
        std::cout << std::flush;
    }
}

void BEEP_MAP() { // beepengine option 1
    std::map<int, SOUND> SOUNDS;
    int length;

    const std::string hello_message = "beep_map <- opt2";

    for (const char i : hello_message) {
        std::cout << i;
        Sleep(25);
    }
    std::cout << std::endl;

    std::cout << "Length of sounds map: ";
    std::cin >> length;

    for (int i = 0; i < length; ++i) {
        double frequency;
        int duration;

        std::cout << i + 1 << " > frequency (Hz): ";
        std::cin >> frequency;
        std::cout << i + 1 << " > duration (ms): ";
        std::cin >> duration;

        std::cout << length - i - 1 << " left" << std::endl;

        const SOUND temp_sound(frequency, duration);
        SOUNDS[i] = temp_sound;
    }

    PLAY_SOUNDS(SOUNDS);
}

void ENTER(int base_frequency) {
    std::string message = "f, ";
    std::thread message_thread(PRINT, message);
    std::thread play_thread(PLAY, base_frequency, 720);
    message_thread.join();
    play_thread.join();
    std::cout << std::flush;
}

void BEEPBOARD() { // beepengine option 2
    int base_frequency = 300;
    std::string hello_message = " <- base_frequency, beepboard[play = [f, g, h, j, k], tone_controls[+, -], quit[/]: ";

    std::cout << base_frequency;
    for (char i : hello_message) {
        std::cout << i;
        std::cout << std::flush;
        Sleep(25);
    }
    std::cout << std::endl;

    char key;
    int counter = 0;
    while (true) {
        if (_kbhit()) {  // check if key have been pressed
            key = _getch();  // get key

            if (key == 'F' || key == 'f') {
                std::string message = "f, ";

                std::thread message_thread(PRINT, message);
                std::thread play_thread(PLAY, base_frequency, 720);
                message_thread.join();
                play_thread.join();

                std::cout << std::flush;
            }

            if (key == 'G' || key == 'g') {
                std::string message = "g, ";

                std::thread message_thread(PRINT, message);
                std::thread play_thread(PLAY, base_frequency + 150, 720);
                message_thread.join();
                play_thread.join();

                std::cout << std::flush;
            }

            if (key == 'H' || key == 'h') {
                std::string message = "h, ";

                std::thread message_thread(PRINT, message);
                std::thread play_thread(PLAY, base_frequency + 300, 720);
                message_thread.join();
                play_thread.join();

                std::cout << std::flush;
            }

            if (key == 'J' || key == 'j') {
                std::string message = "j, ";

                std::thread message_thread(PRINT, message);
                std::thread play_thread(PLAY, base_frequency + 450, 720);
                message_thread.join();
                play_thread.join();

                std::cout << std::flush;
            }

            if (key == 'K' || key == 'k') {
                std::string message = "k, ";

                std::thread message_thread(PRINT, message);
                std::thread play_thread(PLAY, base_frequency + 550, 720);
                message_thread.join();
                play_thread.join();

                std::cout << std::flush;
            }

            if (key == '+') {
                if (base_frequency < 1000) {
                    base_frequency += 100;
                    std::cout << "i = up, bf = " << base_frequency << ", ";
                    std::cout << std::flush;
                }
                else {
                    std::cout << "i = none, bf = " << base_frequency << ", ";
                    std::cout << std::flush;
                }
            }

            if (key == '-') {
                if (base_frequency > 200) {
                    base_frequency -= 100;
                    std::cout << "o = down, bf = " << base_frequency << ", ";
                    std::cout << std::flush;
                }
                else {
                    std::cout << "o = none, bf = " << base_frequency << ", ";
                    std::cout << std::flush;
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

void BEEP_ENGINE(const char key, int base_frequency, int &counter) {
    if (key == 'F' || key == 'f') {
        std::string message = "f, ";

        std::thread message_thread(PRINT, message);
        std::thread play_thread(PLAY, base_frequency, 720);
        message_thread.join();
        play_thread.join();

        std::cout << std::flush;
    }

    if (key == 'G' || key == 'g') {
        std::string message = "g, ";

        std::thread message_thread(PRINT, message);
        std::thread play_thread(PLAY, base_frequency + 150, 720);
        message_thread.join();
        play_thread.join();

        std::cout << std::flush;
    }

    if (key == 'H' || key == 'h') {
        std::string message = "h, ";

        std::thread message_thread(PRINT, message);
        std::thread play_thread(PLAY, base_frequency + 300, 720);
        message_thread.join();
        play_thread.join();

        std::cout << std::flush;
    }

    if (key == 'J' || key == 'j') {
        std::string message = "j, ";

        std::thread message_thread(PRINT, message);
        std::thread play_thread(PLAY, base_frequency + 450, 720);
        message_thread.join();
        play_thread.join();

        std::cout << std::flush;
    }

    if (key == 'K' || key == 'k') {
        std::string message = "k, ";

        std::thread message_thread(PRINT, message);
        std::thread play_thread(PLAY, base_frequency + 550, 720);
        message_thread.join();
        play_thread.join();

        std::cout << std::flush;
    }

    if (key == '+') {
        if (base_frequency < 1000) {
            base_frequency += 100;
            std::cout << "i = up, bf = " << base_frequency << ", ";
            std::cout << std::flush;
        }
        else {
            std::cout << "i = none, bf = " << base_frequency << ", ";
            std::cout << std::flush;
        }
    }

    if (key == '-') {
        if (base_frequency > 200) {
            base_frequency -= 100;
            std::cout << "o = down, bf = " << base_frequency << ", ";
            std::cout << std::flush;
        }
        else {
            std::cout << "o = none, bf = " << base_frequency << ", ";
            std::cout << std::flush;
        }
    }

    if (counter >= 12) {
        std::cout << std::endl;
        counter = 0;
    }

    counter += 1;
}

void CLEAR_TERMINAL() {
#ifdef _WIN32
    system("cls"); // thread-unsafe
#else
    system("clear");
#endif
}

int main() {
    int base_frequency = 300;
    int counter = 0;
    int option;
    const std::string hello_message = "[1 - beep_map], [2 - beepboard], [3 - beep_engine/beepboard2]: ";

    for (const char i : hello_message) {
        std::cout << i;
        Sleep(25);
    }
    std::cout << std::endl;
    std::cin >> option;

    switch (option) {
    case 1: // beepmap
        CLEAR_TERMINAL();
        BEEP_MAP();
        break;

    case 2: // beepboard
        CLEAR_TERMINAL();
        BEEPBOARD();
        std::cout << std::endl;
        break;

    case 3: // bee_engine
        CLEAR_TERMINAL();
        std::cout << "beep_engine is starting..." << std::endl;
        while (true) {
            if (_kbhit()) {
                // check if key have been pressed
                char key = _getch();  // get key
                if (key == '/') {
                    break;
                }

                std::thread beep(BEEP_ENGINE, key, base_frequency, counter);
                beep.join();
            }
        }
        break;

    default:
        break;
    }

    return 0;
}

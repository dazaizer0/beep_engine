#include <iostream>
#include <map>
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


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

    SOUND() : frequency(0.0), duration(0) {} // Konstruktor domyślny
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

int main() {

    std::map<int, SOUND> SOUNDS;
    int length;

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
    /*
    std::vector<std::thread> threads;
    for (const auto& sound : SOUNDS) {

        threads.push_back(std::thread([sound]() {

            PLAY(sound.second.getFrequency(), sound.second.getDuration());
            }));
    }

    for (auto& thread : threads) {

        thread.join();
    }
    */
    return 0;
}

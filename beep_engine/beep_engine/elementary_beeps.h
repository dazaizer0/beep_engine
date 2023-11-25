#include "beep_engine.h"


void PLAY(double frequency, int duration)
{
    double period = 1.0 / frequency * 1000000; // T = 1 / f 

#ifdef _WIN32
    Beep(static_cast<int>(frequency), duration);
#else
    for (int i = 0; i < duration * 1000; i += period)
    {
        std::cout << "\a"; // play sound
        std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(period)));
    }
#endif
}

class SOUND {
public:
    SOUND() : frequency(0.0), duration(0) {} // default sound constructor
    SOUND(double f, int d) : frequency(f), duration(d) {}

    double getFrequency() const
    {
        return frequency;
    }

    int getDuration() const
    {
        return duration;
    }

private:
    double frequency;
    int duration;
};

void PLAY_SOUNDS(std::map<int, SOUND> SOUNDS)
{
    for (const auto& sound : SOUNDS)
    {
        PLAY(sound.second.getFrequency(), sound.second.getDuration());
        std::cout << std::flush;
    }
}

void PRINT(const std::string message)
{
    std::cout << message;
}

void ENTER(int base_frequency)
{
    std::string message = "f, ";
    std::thread message_thread(PRINT, message);
    std::thread play_thread(PLAY, base_frequency, 720);

    message_thread.join();
    play_thread.join();

    std::cout << std::flush;
}

void CLEAR_TERMINAL()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
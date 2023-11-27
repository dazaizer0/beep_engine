#pragma once

#include <iostream>
#include <map>
#include <chrono>
#include <thread>
#include <conio.h>
#include <cstdlib>
#include <fstream>

#ifdef _WIN32
#include <Windows.h>
#include <windows.h>
#else
#include <unistd.h>
#endif

void PRINT(const std::string& message)
{
    std::cout << message;
}

void PLAY(const double frequency, int duration)
{
    const double period = 1.0 / frequency * 1000000; // T = 1 / f 

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
    SOUND(const double f, const int d) : frequency(f), duration(d) {}

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

void PLAY_SOUNDS(const std::map<int, SOUND> SOUNDS, int base_sleep_time)
{
    for (const auto& sound : SOUNDS)
    {
        PLAY(sound.second.getFrequency(), sound.second.getDuration());
        std::cout << std::flush;

        Sleep(base_sleep_time);
    }
}

void CLEAR_TERMINAL()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

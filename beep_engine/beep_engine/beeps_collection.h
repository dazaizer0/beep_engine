#include "beep_engine.h"
#include "elementary_beeps.h"


class BEEP {
public:
    BEEP() : frequency(0.0), duration(0) {} // default sound constructor
    BEEP(const double f, const int d) : frequency(f), duration(d) {}

    double getFrequency() const
    {
        return frequency;
    }

    int getDuration() const
    {
        return duration;
    }

public:
    double frequency;
    int duration;
};

class BEEP_COLLECTION {
public:
    static void PLAY_BEEP(BEEP beep, int base_frequency)
    {
        double period = 1.0 / (base_frequency + beep.frequency) * 1000000; // T = 1 / f 

#ifdef _WIN32
        Beep(static_cast<int>(base_frequency + beep.frequency), beep.duration);
#else
        for (int i = 0; i < beep.duration * 1000; i += period)
        {
            std::cout << "\a"; // play sound
            std::this_thread::sleep_for(std::chrono::microseconds(static_cast<int>(period)));
        }
#endif
    }

    const BEEP f = BEEP(50, 720);
    const BEEP g = BEEP(150, 720);
    const BEEP h = BEEP(250, 720);
    const BEEP j = BEEP(350, 720);
    const BEEP k = BEEP(550, 720);
};

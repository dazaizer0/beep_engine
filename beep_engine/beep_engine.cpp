#include "Headers/beep_libs.h"
#include "Headers/beep_funcs.h"
#include "Headers/beep_variables.h"
#include "Headers/beep.h"


int main(int argc, char* argv[])
{

// -------------------------------------------------------------------------------------------------------- INITIALIZATION
// -------------------------------------------------------------------------------------------------------- INITIALIZATION
// -------------------------------------------------------------------------------------------------------- INITIALIZATION

    // BEEP_DATA FILE
    std::ofstream file("beep_engine_data.txt");

    // BEEP MAP
    std::map<int, SOUND> SOUNDS;

    // BEEP LOGS
    std::string beepboard_log;
    std::string continuous;

    // BEEP OTHER VARIABLES
    int counter = 0;
    int option;
    int settings_option;
    int length;
    char key;

    // PROGRAM MESSAGE
    for (const char i : program_message)
    {
        std::cout << i;
        Sleep(25);
    }
    std::cout << std::endl;

    std::cout << "\nbase_frequency: " << base_frequency << ", " << "base_duration: " << base_duration << std::endl;
    std::cout << "base_frequency_change: " << frequency_change << ", " << "beeps frequency change: " << beeps_frequency_change << std::endl;

    std::cout << std::endl;

    // PROGRAM START
    if (beep_engie1 == "made by dazaizer0") 
    {
    MENU:
#ifdef _WIN32
        HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
#else
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define PINK    "\033[95m"
#endif

        std::cout << std::endl;

#ifdef _WIN32
        SetConsoleTextAttribute(h_console, 12);

        for (const char i : hello_message)
        {
            std::cout << i;
            Sleep(25);
        }

        SetConsoleTextAttribute(h_console, 7);
#else
        for (const char i : hello_message)
        {
            std::cout << RED << i;
            Sleep(25);
        }
#endif

        std::cout << std::endl;
        std::cout << "> ";
        std::cin >> option;

        switch (option)
        {

// -------------------------------------------------------------------------------------------------------- BEEPMAP
// -------------------------------------------------------------------------------------------------------- BEEPMAP
// -------------------------------------------------------------------------------------------------------- BEEPMAP

            // BEEPMAP
        case 1:
            std::cout << std::endl;

#ifdef _WIN32
            SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_BLUE);
            for (const char i : beepmap_hello_message)
            {
                std::cout << i;
                Sleep(25);
            }
            SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
            for (const char i : beepmap_hello_message)
            {
                std::cout << PINK << i;
                Sleep(25);
            }
#endif

            std::cout << std::endl;

            std::cout << ">  ";
            std::cin >> length;

            for (int i = 0; i < length; ++i)
            {
                double frequency;
                int duration;

                std::cout << i + 1 << " > frequency (Hz): ";
                std::cin >> frequency;
                std::cout << i + 1 << " > duration (ms): ";
                std::cin >> duration;

                std::cout << length - i - 1 << " left" << std::endl;

                SOUND temp_sound(frequency, duration);
                SOUNDS[i] = temp_sound;
            }

            PLAY_SOUNDS(SOUNDS, base_sleep_time);
            goto MENU;

// -------------------------------------------------------------------------------------------------------- BEEPBOARD
// -------------------------------------------------------------------------------------------------------- BEEPBOARD
// -------------------------------------------------------------------------------------------------------- BEEPBOARD

            // BEEPBOARD
        case 2:
#ifdef _WIN32
            SetConsoleTextAttribute(h_console, FOREGROUND_GREEN);
            for (const char i : beepboard_hello_message)
            {
                std::cout << i;
                Sleep(25);
            }
            SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
            for (const char i : beepboard_hello_message)
            {
                std::cout << GREEN << i;
                Sleep(25);
            }
#endif
            std::cout << std::endl;
            // PROGRAM
            std::cout << base_frequency;


            std::cout << std::endl;

            while (true)
            {
                if (_kbhit()) // check if key have been pressed
                {
                    key = _getch();  // get key

                    if (key == 'F' || key == 'f')
                    {
                        std::string message = "f, ";

                        std::thread message_thread(PRINT, message);
                        std::thread play_thread(PLAY, base_frequency, base_duration);
                        message_thread.join();
                        play_thread.join();

                        std::cout << std::flush;

                        beepboard_log = beepboard_log + "f";
                        Sleep(base_sleep_time);
                    }

                    if (key == 'G' || key == 'g')
                    {
                        std::string message = "g, ";

                        std::thread message_thread(PRINT, message);
                        std::thread play_thread(PLAY, base_frequency + beeps_frequency_change, base_duration);
                        message_thread.join();
                        play_thread.join();

                        std::cout << std::flush;

                        beepboard_log = beepboard_log + "g";
                        Sleep(base_sleep_time);
                    }

                    if (key == 'H' || key == 'h')
                    {
                        std::string message = "h, ";

                        std::thread message_thread(PRINT, message);
                        std::thread play_thread(PLAY, base_frequency + (beeps_frequency_change * 2), base_duration);
                        message_thread.join();
                        play_thread.join();

                        std::cout << std::flush;

                        beepboard_log = beepboard_log + "h";
                        Sleep(base_sleep_time);
                    }

                    if (key == 'J' || key == 'j')
                    {
                        std::string message = "j, ";

                        std::thread message_thread(PRINT, message);
                        std::thread play_thread(PLAY, base_frequency + (beeps_frequency_change * 3), base_duration);
                        message_thread.join();
                        play_thread.join();

                        std::cout << std::flush;

                        beepboard_log = beepboard_log + "j";
                        Sleep(base_sleep_time);
                    }

                    if (key == 'K' || key == 'k')
                    {
                        std::string message = "k, ";

                        std::thread message_thread(PRINT, message);
                        std::thread play_thread(PLAY, base_frequency + (beeps_frequency_change * 4), base_duration);
                        message_thread.join();
                        play_thread.join();

                        std::cout << std::flush;

                        beepboard_log = beepboard_log + "k";
                        Sleep(base_sleep_time);
                    }

                    if (key == '+')
                    {
                        if (base_frequency < 1000)
                        {
                            base_frequency += frequency_change;
                            std::cout << "i = up, bf = " << base_frequency << ", ";
                            std::cout << std::flush;

                            beepboard_log = beepboard_log + "+";
                        }
                        else
                        {
                            std::cout << "i = none, bf = " << base_frequency << ", ";
                            std::cout << std::flush;
                        }
                    }

                    if (key == '-')
                    {
                        if (base_frequency > 180)
                        {
                            base_frequency -= frequency_change;
                            std::cout << "o = down, bf = " << base_frequency << ", ";
                            std::cout << std::flush;

                            beepboard_log = beepboard_log + "-";
                        }
                        else
                        {
                            std::cout << "o = none, bf = " << base_frequency << ", ";
                            std::cout << std::flush;
                        }
                    }

                    if (key == '/')
                    {
                        break;
                    }

                    if (counter >= 12)
                    {
                        std::cout << std::endl;
                        counter = 0;
                    }
                    counter += 1;
                }
            }
            std::cout << std::endl;

            if (file.is_open())
            {
                std::string data_to_save = "beepboardlog " + beepboard_log;
                file << data_to_save << std::endl;
                file.close();

                std::cout << "data was successfully saved" << std::endl;
            }
            else
            {
                std::cerr << "data was not saved successfully" << std::endl;
            }

            file.close();

            beepboard_log = "";

            goto MENU;

// -------------------------------------------------------------------------------------------------------- BEEPLIST
// -------------------------------------------------------------------------------------------------------- BEEPLIST
// -------------------------------------------------------------------------------------------------------- BEEPLIST

            // BEEPLIST
        case 3:
            std::cout << std::endl;

#ifdef _WIN32
            SetConsoleTextAttribute(h_console, FOREGROUND_GREEN);
            for (const char i : beeplist_hello_message)
            {
                std::cout << i;
                Sleep(25);
            }
            SetConsoleTextAttribute(h_console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
            for (const char i : beeplist_hello_message)
            {
                std::cout << BLUE << i;
                Sleep(25);
            }
#endif
            std::cout << std::endl;

            // PROGRAM
            std::cout << "The last beeplist: " << continuous << std::endl;
            std::cout << "> ";
            std::cin >> continuous;

            if (continuous == "/")
            {
                break;
            }

            std::cout << "playing...";

            for (int i = 0; i < continuous.length(); i++)
            {
                if (continuous[i] == 'f' || continuous[i] == 'F')
                {
                    std::thread play_thread(PLAY, base_frequency, base_duration);
                    play_thread.join();

                    std::cout << std::flush;
                    Sleep(base_sleep_time);
                }

                if (continuous[i] == 'g' || continuous[i] == 'G')
                {
                    std::thread play_thread(PLAY, base_frequency + (beeps_frequency_change * 2), base_duration);
                    play_thread.join();

                    std::cout << std::flush;
                    Sleep(base_sleep_time);
                }

                if (continuous[i] == 'h' || continuous[i] == 'H')
                {
                    std::thread play_thread(PLAY, base_frequency + (beeps_frequency_change * 3), base_duration);
                    play_thread.join();

                    std::cout << std::flush;
                    Sleep(base_sleep_time);
                }

                if (continuous[i] == 'j' || continuous[i] == 'J')
                {
                    std::thread play_thread(PLAY, base_frequency + (beeps_frequency_change * 4), base_duration);
                    play_thread.join();

                    std::cout << std::flush;
                    Sleep(base_sleep_time);
                }

                if (continuous[i] == 'k' || continuous[i] == 'K')
                {
                    std::thread play_thread(PLAY, base_frequency + (beeps_frequency_change * 5), base_duration);
                    play_thread.join();

                    std::cout << std::flush;
                    Sleep(base_sleep_time);
                }

                if (continuous[i] == '+')
                {
                    if (base_frequency < 1000)
                    {
                        base_frequency += frequency_change;
                        std::cout << std::flush;
                    }
                    else
                    {
                        std::cout << std::flush;
                    }
                }

                if (continuous[i] == '-')
                {
                    if (base_frequency > 180)
                    {
                        base_frequency -= frequency_change;
                        std::cout << std::flush;
                    }
                    else
                    {
                        std::cout << std::flush;
                    }
                }
            }

            if (file.is_open())
            {
                std::string data_to_save = "continuous " + continuous;
                file << data_to_save << std::endl;
                file.close();

                std::cout << "data was successfully saved" << std::endl;
            }
            else
            {
                std::cerr << "data was not saved successfully" << std::endl;
            }

            goto MENU;

// -------------------------------------------------------------------------------------------------------- QUIT
// -------------------------------------------------------------------------------------------------------- QUIT
// -------------------------------------------------------------------------------------------------------- QUIT

        case 4:
            CLEAR_TERMINAL();
            std::cout << "Thank you for using beep_engine!" << std::endl;
            std::cout << beep_engie1 << std::endl;
            break;

// -------------------------------------------------------------------------------------------------------- CLEAR TERMINAL
// -------------------------------------------------------------------------------------------------------- CLEAR TERMINAL
// -------------------------------------------------------------------------------------------------------- CLEAR TERMINAL

        case 5:
            CLEAR_TERMINAL();
            goto MENU;

// -------------------------------------------------------------------------------------------------------- SETTINGS
// -------------------------------------------------------------------------------------------------------- SETTINGS
// -------------------------------------------------------------------------------------------------------- SETTINGS

            // SETTINGS
        case 6:
            std::cout << "---------------------------------SETTINGS---------------------------------" << std::endl;
            std::cout << "Here you can change base values like: pause between beeps or base duration" << std::endl;
            std::cout << "*[base sleep time - 1], *[base duration - 2], *[frequency change - 3], " << std::endl;
            std::cout << "*[beeps frequency change - 4], *[back to menu - 5] ----------------->: " << std::endl;
            std::cout << "> "; std::cin >> settings_option;

            switch (settings_option)
            {
                // CHANGE SLEEP TIME
            case 1:
                std::cout << "actual sleep time = " << base_sleep_time << std::endl;
                std::cout << "new sleep time > "; std::cin >> base_sleep_time;

                goto MENU;

                // CHANGE DURATION
            case 2:
                std::cout << "actual duration = " << base_duration << std::endl;
                std::cout << "new duration > "; std::cin >> base_duration;

                goto MENU;

                // FREQUENCY CHANGE
            case 3:
                std::cout << "actual frequency change = " << frequency_change << std::endl;
                std::cout << "new frequency change > "; std::cin >> frequency_change;

                goto MENU;

                // BEEPS FREQUENCY CHANGE
            case 4:
                std::cout << "actual beeps frequency change = " << beeps_frequency_change << std::endl;
                std::cout << "new beeps frequency change > "; std::cin >> beeps_frequency_change;

                goto MENU;

                // BACK TO THE MENU
            case 5:
                goto MENU;

            default:
                break;
            }
            goto MENU;

// -------------------------------------------------------------------------------------------------------- END
// -------------------------------------------------------------------------------------------------------- END
// -------------------------------------------------------------------------------------------------------- END

        default:
            std::cout << "|input error|" << std::endl;
            break;
        }
    }
    else
    {
        std::cout << "error in beep";
    }
    return 0;
}
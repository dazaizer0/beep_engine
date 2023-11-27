#include "beep_maker.h"


int main()
{
#pragma region VARIABLES
    const std::string beepboard_hello_message = "    <- base_frequency, This is beepboard[play = [f, g, h, j, k], tone_controls[+, -], quit[/]: ";
    const std::string hello_message = "[1 - beep_map], [2 - beepboard], [3 - beeplist], [4 - quit], [5 - clear], [6 - change base values]: ";
    const std::string program_message = "Welcome to beep_engine2023! The universal engine, created to generate beeps whatever platform you use: ";
    const std::string beepmap_hello_message = "This is beepmap please type the length of your beep map: ";
    const std::string beeplist_hello_message = "This is beeplist, [f, g, h, j, k], tone_controls[+, -], quit[/], [enter] to play:";
    std::string beepboard_log;
    std::string continuous;
    std::ofstream file("beep_engine_data.txt");
    int base_frequency = 300;
    int base_duration = 720;
    int base_sleep_time = 0;
    int counter = 0;
    char key;
    int option;
    int option2;
    std::map<int, SOUND> SOUNDS;
    int length;
#pragma endregion

    for (const char i : program_message)
    {
        std::cout << i;
        Sleep(25);
    }
    std::cout << std::endl;

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
    case 1: // beepmap
    BEEPMAP:
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
        // END

    case 2: // beepboard
    BEEPBOARD:
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
                    std::thread play_thread(PLAY, base_frequency + 150, base_duration);
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
                    std::thread play_thread(PLAY, base_frequency + 300, base_duration);
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
                    std::thread play_thread(PLAY, base_frequency + 450, base_duration);
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
                    std::thread play_thread(PLAY, base_frequency + 550, base_duration);
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
                        base_frequency += 100;
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
                    if (base_frequency > 200)
                    {
                        base_frequency -= 100;
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
        // END

    case 3:
    BEEPLIST:
        std::cout << std::endl;

#ifdef _WIN32
        SetConsoleTextAttribute(h_console, FOREGROUND_BLUE);
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
            if (continuous[i] == 'f')
            {
                std::thread play_thread(PLAY, base_frequency, base_duration);
                play_thread.join();

                std::cout << std::flush;
                Sleep(base_sleep_time);
            }

            if (continuous[i] == 'g')
            {
                std::thread play_thread(PLAY, base_frequency + 150, base_duration);
                play_thread.join();

                std::cout << std::flush;
                Sleep(base_sleep_time);
            }

            if (continuous[i] == 'h')
            {
                std::thread play_thread(PLAY, base_frequency + 300, base_duration);
                play_thread.join();

                std::cout << std::flush;
                Sleep(base_sleep_time);
            }

            if (continuous[i] == 'j')
            {
                std::thread play_thread(PLAY, base_frequency + 450, base_duration);
                play_thread.join();

                std::cout << std::flush;
                Sleep(base_sleep_time);
            }

            if (continuous[i] == 'k')
            {
                std::thread play_thread(PLAY, base_frequency + 550, base_duration);
                play_thread.join();

                std::cout << std::flush;
                Sleep(base_sleep_time);
            }

            if (continuous[i] == '+')
            {
                if (base_frequency < 1000)
                {
                    base_frequency += 100;
                    std::cout << std::flush;
                }
                else
                {
                    std::cout << std::flush;
                }
            }

            if (continuous[i] == '-')
            {
                if (base_frequency > 200)
                {
                    base_frequency -= 100;
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
        // END

    case 4: // CLEAR_TERMINAL
        CLEAR_TERMINAL();
        break;
        // END
    case 5: // change basic values
        CLEAR_TERMINAL();
        goto MENU;
        // END
    case 6: // change basic values
        std::cout << "Here you can change base values like: pause between beeps or base duration" << std::endl;
        std::cout << "[base sleep time - 1], [base duration - 2], [back to menu - 3]: " << std::endl;
        std::cout << "> ";
        std::cin >> option2;

        switch (option2)
        {
        case 1:
            std::cout << "actual sleep time = " << base_sleep_time << std::endl;
            std::cout << "new sleep time > ";
            std::cin >> base_sleep_time;
            goto MENU;

        case 2:
            std::cout << "actual duration = " << base_duration << std::endl;
            std::cout << "new duration > ";
            std::cin >> base_duration;
            goto MENU;

        case 3:
            goto MENU;

        }
        goto MENU;
        // END
    default:
        break;
    }
    return 0;
}
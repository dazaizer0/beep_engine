#include "beep_engine.h"
#include "elementary_beeps.h"


void BEEP_MAP()  // beepengine option 1
{
    std::map<int, SOUND> SOUNDS;
    int length;

    std::string hello_message = "beep_map <- opt2";

    for (int i = 0; i < hello_message.length(); ++i)
    {
        std::cout << hello_message[i];
        Sleep(25);
    }

    std::cout << std::endl;

    std::cout << "Length of sounds map: ";
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

    PLAY_SOUNDS(SOUNDS);
}

void BEEPBOARD(int base_frequency) // beepengine option 2
{
    std::string hello_message = " <- base_frequency, beepboard[play = [f, g, h, j, k], tone_controls[+, -], quit[/]: ";
    std::cout << base_frequency;

    for (int i = 0; i < hello_message.length(); ++i)
    {
        std::cout << hello_message[i];
        std::cout << std::flush;
        Sleep(25);
    }

    std::cout << std::endl;

    int counter = 0;
    char key;

    while (true)
    {
        if (_kbhit()) // check if key have been pressed
        {
            key = _getch();  // get key

            if (key == 'F' || key == 'f')
            {
                std::string message = "f, ";

                std::thread message_thread(PRINT, message);
                std::thread play_thread(PLAY, base_frequency, 720);
                message_thread.join();
                play_thread.join();

                std::cout << std::flush;
            }

            if (key == 'G' || key == 'g')
            {
                std::string message = "g, ";

                std::thread message_thread(PRINT, message);
                std::thread play_thread(PLAY, base_frequency + 150, 720);
                message_thread.join();
                play_thread.join();

                std::cout << std::flush;
            }

            if (key == 'H' || key == 'h')
            {
                std::string message = "h, ";

                std::thread message_thread(PRINT, message);
                std::thread play_thread(PLAY, base_frequency + 300, 720);
                message_thread.join();
                play_thread.join();

                std::cout << std::flush;
            }

            if (key == 'J' || key == 'j')
            {
                std::string message = "j, ";

                std::thread message_thread(PRINT, message);
                std::thread play_thread(PLAY, base_frequency + 450, 720);
                message_thread.join();
                play_thread.join();

                std::cout << std::flush;
            }

            if (key == 'K' || key == 'k')
            {
                std::string message = "k, ";

                std::thread message_thread(PRINT, message);
                std::thread play_thread(PLAY, base_frequency + 550, 720);
                message_thread.join();
                play_thread.join();

                std::cout << std::flush;
            }

            if (key == '+')
            {
                if (base_frequency < 1000)
                {
                    base_frequency += 100;
                    std::cout << "i = up, bf = " << base_frequency << ", ";
                    std::cout << std::flush;
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
}

void BEEPLIST(int base_frequency) // beepengine option 3
{
    std::string continuous;

    while (true)
    {
        std::cout << continuous << std::endl;
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
                std::thread play_thread(PLAY, base_frequency, 720);
                play_thread.join();

                std::cout << std::flush;
            }

            if (continuous[i] == 'g')
            {
                std::thread play_thread(PLAY, base_frequency + 150, 720);
                play_thread.join();

                std::cout << std::flush;
            }

            if (continuous[i] == 'h')
            {
                std::thread play_thread(PLAY, base_frequency + 300, 720);
                play_thread.join();

                std::cout << std::flush;
            }

            if (continuous[i] == 'j')
            {
                std::thread play_thread(PLAY, base_frequency + 450, 720);
                play_thread.join();

                std::cout << std::flush;
            }

            if (continuous[i] == 'k')
            {
                std::thread play_thread(PLAY, base_frequency + 550, 720);
                play_thread.join();

                std::cout << std::flush;
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
    }
}

int main()
{
    std::string continuous;
    int base_frequency = 300;
    int option;
    char key;

    std::string program_message = "Welcome to beep_engine2023!: ";
    for (int i = 0; i < program_message.length(); ++i)
    {
        std::cout << program_message[i];
        Sleep(25);
    }

    std::cout << std::endl;

    std::string hello_message = "[1 - beep_map], [2 - beepboard], [3 - beeplist]: ";
    for (int i = 0; i < hello_message.length(); ++i)
    {
        std::cout << hello_message[i];
        Sleep(25);
    }

    std::cout << std::endl;
    std::cin >> option;

    switch (option)
    {
    case 1: // beepmap
        CLEAR_TERMINAL();
        BEEP_MAP();
        break;

    case 2: // beepboard
        CLEAR_TERMINAL();
        BEEPBOARD(base_frequency);
        std::cout << std::endl;
        break;
    case 3:
        CLEAR_TERMINAL();
        BEEPLIST(base_frequency);
        std::cout << std::endl;
    default:
        break;
    }
    return 0;
}
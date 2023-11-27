#include "beep_libs.h"


const std::string beepboard_hello_message = "    <- base_frequency, This is beepboard[play = [f, g, h, j, k], tone_controls[+, -], quit[/]: ";
const std::string hello_message = "[1 - beep_map], [2 - beepboard], [3 - beeplist], [4 - quit], [5 - clear], [6 - change base values]: ";
const std::string program_message = "Welcome to beep_engine2023! The universal engine, created to generate beeps whatever platform you use: ";
const std::string beepmap_hello_message = "This is beepmap please type the length of your beep map: ";
const std::string beeplist_hello_message = "This is beeplist, [f, g, h, j, k], tone_controls[+, -], quit[/], [enter] to play:";

int base_frequency = 300;
int base_duration = 720;
int base_sleep_time = 0;
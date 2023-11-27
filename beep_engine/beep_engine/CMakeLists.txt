# CMakeList.txt: projekt CMake dla elementu beep_engine, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (beep_engine "beep_engine.cpp" "beep_libs.h" "beep_variables.h" "beep.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET beep_engine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.

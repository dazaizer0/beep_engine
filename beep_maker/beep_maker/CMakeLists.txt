# CMakeList.txt: projekt CMake dla elementu beep_maker, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (beep_maker "beep_maker.cpp" "beep_maker.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET beep_maker PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.

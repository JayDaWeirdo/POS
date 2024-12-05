cmake_minimum_required(VERSION 3.31.0)

# Set project name
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include Windows SDK headers
include_directories("C:/Program Files (x86)/Windows Kits/10/Include/10.0.18362.0/um")
include_directories("C:/Users/maske/Desktop/MyProject/include")

# Link Windows SDK libraries
link_directories("C:/Program Files (x86)/Windows Kits/10/Lib/10.0.18362.0/um/x64")

# Set the source files
add_executable(MyProject main.cpp)

# Link the Windows SDK libraries
target_link_libraries(MyProject PRIVATE
    kernel32.lib
    user32.lib
    gdi32.lib
    comdlg32.lib
    Winscard.lib  # Example: additional libraries if needed
)
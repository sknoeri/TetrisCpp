cmake_minimum_required(VERSION 3.13.4)

# Set the project name
project(TetrisCpp)

# Set include directories
set(INC_DIRECTORI
    inc/
)
# Set include files
set(INC_FILES
    inc/grid.h
)

# Set source directories
set(SRC_DIRECTORI
    src/
)
# Set source files
set(SRC_FILES
    src/grid.cpp
)


# Add the raylib library
add_subdirectory(external/raylib)

# Add the executable
add_executable(${PROJECT_NAME} main.cpp ${INC_FILES} ${SRC_FILES})

# Add include directories
target_include_directories(${PROJECT_NAME}
    PUBLIC
        inc/
)

# Link the raylib library to the executable
target_link_libraries(${PROJECT_NAME} raylib)
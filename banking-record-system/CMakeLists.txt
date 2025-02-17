# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(banking-record-system VERSION 1.0)

# This will download the nlohmann_json package and make it available to the project
include(FetchContent)

# Fetch the nlohmann_json package
FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
        DOWNLOAD_EXTRACT_TIMESTAMP true
)

# Make the nlohmann_json package available to the project
FetchContent_MakeAvailable(json)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files to the project
add_executable(banking-record-system
    src/main.cpp
    src/BankAccount.cpp
    src/Transaction.cpp
    src/BankManager.cpp
    src/FileHandler.cpp
)

set(DATA_DIR ${CMAKE_SOURCE_DIR}/data)  # Define the path for the data directory
file(MAKE_DIRECTORY ${DATA_DIR})  # Create data directory during build

# Add include directories for the target
target_include_directories(banking-record-system PRIVATE include)

# Specify the C++ standard for the target
target_compile_features(banking-record-system PRIVATE cxx_std_11)

# Optionally, add any other compile options or flags here
# For example, to enable warnings:
target_compile_options(banking-record-system PRIVATE -Wall -Wextra)

# Link the nlohmann_json library to the target
target_link_libraries(banking-record-system PRIVATE nlohmann_json::nlohmann_json)
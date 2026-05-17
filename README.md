# Daily Planner Simulator

A Qt-based desktop planner application written in C++.

## Features

- Add tasks using a text input
- Mark tasks as completed
- Delete tasks
- Styled Qt GUI with custom buttons, colors, and task status indicators

## Requirements

- Qt 6 (Qt Widgets)
- CMake 3.16+
- Apple Clang or another C++17-compatible compiler

## Build and Run (macOS)

```bash
cd /Users/suleman/Documents/projects/c++/final-project
cmake -S . -B build
cmake --build build -- -j 2
./build/final_project
```

## Project Structure

- `CMakeLists.txt` — CMake build configuration
- `main.cpp` — Qt application entry point
- `MainWindow.h` / `MainWindow.cpp` — main GUI code and styling
- `Planner.h` / `Planner.cpp` — task planner logic
- `Task.h` / `Task.cpp` — task data model
- `.gitignore` — ignore build files and editor metadata

## Notes

- The code is portable and can also be built on Windows or Linux with Qt installed.
- On macOS, Qt can be installed via Homebrew: `brew install qt`
- If using VS Code, configure CMake and the C/C++ extension to use the generated `build/compile_commands.json`.

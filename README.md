# Far Cry 4 Custom Client

A lightweight replacement executable for Far Cry 4. This custom launcher directly initializes the game engine (`FC64.DLL`) and includes a built-in loader for custom plugins.

## Features

* **Small Footprint:** Greatly reduced executable size (approximately 17KB) compared to the original game launcher.
* **No bloat in the code** There are less than 50 lines of code
* **Built-in Plugin Loader:** Automatically loads `.asi` plugins from the game directory
* Probably more features coming soon

## Installation

1. Navigate to your Far Cry 4 game directory.
2. Back up your original `FarCry4.exe`.
3. Drop the new custom `FarCry4.exe` into the directory. It must be in the same location as `FC64.DLL`.
4. If you are using them, place your `.asi` plugins in the game directory
6. Launch the game normally.

## Compiling from Source

This is a standard C++ project intended for Visual Studio.

1. Open the project in Visual Studio.
2. Ensure the build configuration is set to **Release** to minimize the compiled file size.
3. Build the solution.

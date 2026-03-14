#include <windows.h>

typedef bool (*RunGameFn)(HINSTANCE, const char*);

// Might expand this in the future, very basic rn
void LoadASIPlugins() {
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA("*.asi", &findData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {  // might be a bit buggy
                HMODULE hPlugin = LoadLibraryA(findData.cFileName);
            }
        } while (FindNextFileA(hFind, &findData));

        FindClose(hFind);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    LoadASIPlugins();

    //Load the engine DLL
    HMODULE hEngineDLL = LoadLibraryA("FC64.DLL");

    if (hEngineDLL == NULL) {
        MessageBoxA(NULL, "Failed to load FC64.DLL. Make sure the launcher is in the game directory.", "Launcher Error", MB_ICONERROR | MB_OK);
        return 1;
    }

    // Gets the RunGame export
    RunGameFn pRunGame = (RunGameFn)GetProcAddress(hEngineDLL, "?RunGame@@YA_NPEAUHINSTANCE__@@PEBD@Z");

    if (pRunGame == NULL) {
        MessageBoxA(NULL, "Could not find '?RunGame@@YA_NPEAUHINSTANCE__@@PEBD@Z' export in FC64.DLL.", "Launcher Error", MB_ICONERROR | MB_OK);
        FreeLibrary(hEngineDLL);
        return 1;
    }

    // Runs the game
    pRunGame(hInstance, lpCmdLine);

    //Cleanup
    FreeLibrary(hEngineDLL);

    return 0;
}
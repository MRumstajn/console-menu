#include <iostream>
#include <vector>
#include <windows.h>
#include "MenuRenderer.h"

using namespace std;

int longestMenuItemWidth;

HANDLE stdOutHandle;
DWORD count;
DWORD cellCount;
COORD homeCoords = {0, 0};
CONSOLE_SCREEN_BUFFER_INFO screenBuffer;

string generatePadding(int amount) {
    string padding;

    for (int i = 0; i < amount; i++) {
        padding.append(" ");
    }

    return padding;
}

string formatNonSelectedItem(string item, int maxItemWidth) {
    return "[  " + generatePadding((maxItemWidth - item.length())  / 2) + item + generatePadding((maxItemWidth - item.length()) / 2) + "  ]";
}

string formatSelectedItem(string item, int maxItemWidth) {
    return "-> " + generatePadding((maxItemWidth - item.length())  / 2) + item + generatePadding((maxItemWidth - item.length()) / 2) + " <-";
}

void renderMenu(vector<string> items, int selectedItemIndex, int maxItemWidth) {
    clearScreen();
    for (int i = 0; i < items.size(); i++) {
        string line;
        if (selectedItemIndex == i) {
            line = formatSelectedItem(items[i], maxItemWidth);
        } else {
            line = formatNonSelectedItem(items[i], maxItemWidth);
        }
        cout << line << endl;
    }
}

void clearScreen() {
    stdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (stdOutHandle == INVALID_HANDLE_VALUE) {
        return;
    }

    if (!GetConsoleScreenBufferInfo(stdOutHandle, &screenBuffer)) {
        return;
    }

    cellCount = screenBuffer.dwSize.X * screenBuffer.dwSize.Y;

    if (!FillConsoleOutputCharacter(stdOutHandle, (TCHAR) ' ', cellCount, homeCoords, &count
    )) {
        return;
    }

    if (!FillConsoleOutputAttribute(stdOutHandle, screenBuffer.wAttributes, cellCount, homeCoords, &count
    )) {
        return;
    }

  SetConsoleCursorPosition(stdOutHandle, homeCoords);
}
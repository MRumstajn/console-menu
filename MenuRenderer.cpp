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

string formatItemLine(string item, 
                            int maxItemWidth, 
                            struct MenuItemSelectionConfig &selectionConfig,
                            bool isItemSelected) {

    string itemWithPadding = generatePadding((maxItemWidth - item.length())  / 2) + item + generatePadding((maxItemWidth - item.length()) / 2);;

    return isItemSelected ? 
    selectionConfig.selectedSymbolLeft + " " + itemWithPadding + " " + selectionConfig.selectedSymbolRight : selectionConfig.defaultSymbolLeft + " " + itemWithPadding + " " + selectionConfig.defaultSymbolRight;
}

string centerLineWithPadding(string line, int consoleWidth) {
    int paddingAmount = consoleWidth - line.length();
    return generatePadding(paddingAmount / 2) + line + generatePadding(paddingAmount / 2);
}

int getConsoleWidth() {
    int width;

    if (stdout == INVALID_HANDLE_VALUE) {
        width = -1;
    }

    if (!GetConsoleScreenBufferInfo(stdOutHandle, &screenBuffer)) {
        width = -1;
    }

    width = screenBuffer.dwSize.X;
    return width;
}

MenuRenderer::MenuRenderer() {
    selectionConfig = new MenuItemSelectionConfig {
        "[ ",
        " ]",
        "-> ",
        " <-"
    };

    stdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (stdOutHandle == INVALID_HANDLE_VALUE) {
        cout << "Failed to get terminal window handle" << endl;
    }
}

MenuRenderer::~MenuRenderer() {
    CloseHandle(stdOutHandle);
    delete selectionConfig;
}

void MenuRenderer::renderMenu(vector<string> items, 
                                int selectedItemIndex, 
                                int maxItemWidth, 
                                MenuAlignment alignment) {
    clearScreen();
    for (int i = 0; i < items.size(); i++) {
        string line = formatItemLine(items[i], maxItemWidth, *selectionConfig, selectedItemIndex == i);

        if (alignment == MenuAlignment::CENTER) {
            int consoleWidth = getConsoleWidth();
            if (consoleWidth != -1) {
                line = centerLineWithPadding(line, consoleWidth);
            }
        }

         cout << line << endl;
    }
}

void MenuRenderer::clearScreen() {
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

void MenuRenderer::setSelectionConfig(MenuItemSelectionConfig *config) {
    delete this->selectionConfig;
    this->selectionConfig = config;
}
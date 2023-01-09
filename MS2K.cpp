#include <Windows.h>
#include <iostream>
#include <string>

//DEFINING ALL KEYS
#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x41
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x41
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A

int main() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(consoleHandle,
		FOREGROUND_BLUE | FOREGROUND_INTENSITY | (255 / 255) * FOREGROUND_BLUE);
	std::cout << "MS2K v1.0 - MuseSwipr to Key by Railgun" << std::endl;

	SetConsoleTextAttribute(consoleHandle,
		FOREGROUND_RED | FOREGROUND_INTENSITY | (255 / 255) |
		FOREGROUND_GREEN | FOREGROUND_INTENSITY | (255 / 255) |
		FOREGROUND_BLUE | FOREGROUND_INTENSITY | (255 / 255));
	std::cout << "#####################################" << std::endl;

	SetConsoleTextAttribute(consoleHandle,
		FOREGROUND_BLUE | FOREGROUND_INTENSITY | (255 / 255) * FOREGROUND_BLUE);
	std::cout << "Discord: Railgun#5065" << std::endl;

	SetConsoleTextAttribute(consoleHandle,
		FOREGROUND_RED | FOREGROUND_INTENSITY | (255 / 255) |
		FOREGROUND_GREEN | FOREGROUND_INTENSITY | (255 / 255) |
		FOREGROUND_BLUE | FOREGROUND_INTENSITY | (255 / 255));
	std::cout << "#####################################" << std::endl << std::endl;
	SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	int vk1 = 0;
	int vk2 = 0;
	int vk3 = 0;
	int vk4 = 0;
	bool key1 = false;
	bool key2 = false;
	bool key3 = false;
	bool key4 = false;
	bool up = false;
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	std::string keey1;
	std::string keey2;
	std::string keey3;
	std::string keey4;
	std::cout << "Enter 1st Key (A-Z only) for left side.";
	std::cin >> keey1;
	std::cout << "Enter 2nd Key (A-Z only) for left side.";
	std::cin >> keey2;
	std::cout << "Enter 1st Key (A-Z only) for right side.";
	std::cin >> keey3;
	std::cout << "Enter 2nd Key (A-Z only) for right side.";
	std::cin >> keey4;
	std::cout << "Your Key mapping is now " << keey1 << keey2 << keey3 << keey4 << " , to reset that, just restart the application." << std::endl;
	std::cout << "Your screen resolution of your main monitor (if u have multiple) is " << width << "x" << height << std::endl << "MuseSwipr should be runned on your main Monitor." << std::endl;

	switch (keey1[0]) {
	case 'a': vk1 = VK_A; break;
	case 'b': vk1 = VK_B; break;
	case 'c': vk1 = VK_C; break;
	case 'd': vk1 = VK_D; break;
	case 'e': vk1 = VK_E; break;
	case 'f': vk1 = VK_F; break;
	case 'g': vk1 = VK_G; break;
	case 'h': vk1 = VK_H; break;
	case 'i': vk1 = VK_I; break;
	case 'j': vk1 = VK_J; break;
	case 'k': vk1 = VK_K; break;
	case 'l': vk1 = VK_L; break;
	case 'm': vk1 = VK_M; break;
	case 'n': vk1 = VK_N; break;
	case 'o': vk1 = VK_O; break;
	case 'p': vk1 = VK_P; break;
	case 'q': vk1 = VK_Q; break;
	case 'r': vk1 = VK_R; break;
	case 's': vk1 = VK_S; break;
	case 't': vk1 = VK_T; break;
	case 'u': vk1 = VK_U; break;
	case 'V': vk1 = VK_V; break;
	case 'w': vk1 = VK_W; break;
	case 'x': vk1 = VK_X; break;
	case 'y': vk1 = VK_Y; break;
	case 'z': vk1 = VK_Z; break;
	}
	switch (keey2[0]) {
	case 'a': vk2 = VK_A; break;
	case 'b': vk2 = VK_B; break;
	case 'c': vk2 = VK_C; break;
	case 'd': vk2 = VK_D; break;
	case 'e': vk2 = VK_E; break;
	case 'f': vk2 = VK_F; break;
	case 'g': vk2 = VK_G; break;
	case 'h': vk2 = VK_H; break;
	case 'i': vk2 = VK_I; break;
	case 'j': vk2 = VK_J; break;
	case 'k': vk2 = VK_K; break;
	case 'l': vk2 = VK_L; break;
	case 'm': vk2 = VK_M; break;
	case 'n': vk2 = VK_N; break;
	case 'o': vk2 = VK_O; break;
	case 'p': vk2 = VK_P; break;
	case 'q': vk2 = VK_Q; break;
	case 'r': vk2 = VK_R; break;
	case 's': vk2 = VK_S; break;
	case 't': vk2 = VK_T; break;
	case 'u': vk2 = VK_U; break;
	case 'V': vk2 = VK_V; break;
	case 'w': vk2 = VK_W; break;
	case 'x': vk2 = VK_X; break;
	case 'y': vk2 = VK_Y; break;
	case 'z': vk2 = VK_Z; break;
	}
	switch (keey3[0]) {
	case 'a': vk3 = VK_A; break;
	case 'b': vk3 = VK_B; break;
	case 'c': vk3 = VK_C; break;
	case 'd': vk3 = VK_D; break;
	case 'e': vk3 = VK_E; break;
	case 'f': vk3 = VK_F; break;
	case 'g': vk3 = VK_G; break;
	case 'h': vk3 = VK_H; break;
	case 'i': vk3 = VK_I; break;
	case 'j': vk3 = VK_J; break;
	case 'k': vk3 = VK_K; break;
	case 'l': vk3 = VK_L; break;
	case 'm': vk3 = VK_M; break;
	case 'n': vk3 = VK_N; break;
	case 'o': vk3 = VK_O; break;
	case 'p': vk3 = VK_P; break;
	case 'q': vk3 = VK_Q; break;
	case 'r': vk3 = VK_R; break;
	case 's': vk3 = VK_S; break;
	case 't': vk3 = VK_T; break;
	case 'u': vk3 = VK_U; break;
	case 'V': vk3 = VK_V; break;
	case 'w': vk3 = VK_W; break;
	case 'x': vk3 = VK_X; break;
	case 'y': vk3 = VK_Y; break;
	case 'z': vk3 = VK_Z; break;
	}
	switch (keey4[0]) {
	case 'a': vk4 = VK_A; break;
	case 'b': vk4 = VK_B; break;
	case 'c': vk4 = VK_C; break;
	case 'd': vk4 = VK_D; break;
	case 'e': vk4 = VK_E; break;
	case 'f': vk4 = VK_F; break;
	case 'g': vk4 = VK_G; break;
	case 'h': vk4 = VK_H; break;
	case 'i': vk4 = VK_I; break;
	case 'j': vk4 = VK_J; break;
	case 'k': vk4 = VK_K; break;
	case 'l': vk4 = VK_L; break;
	case 'm': vk4 = VK_M; break;
	case 'n': vk4 = VK_N; break;
	case 'o': vk4 = VK_O; break;
	case 'p': vk4 = VK_P; break;
	case 'q': vk4 = VK_Q; break;
	case 'r': vk4 = VK_R; break;
	case 's': vk4 = VK_S; break;
	case 't': vk4 = VK_T; break;
	case 'u': vk4 = VK_U; break;
	case 'V': vk4 = VK_V; break;
	case 'w': vk4 = VK_W; break;
	case 'x': vk4 = VK_X; break;
	case 'y': vk4 = VK_Y; break;
	case 'z': vk4 = VK_Z; break;
	}

	while (true) {
		if (GetAsyncKeyState(vk1) & 0x8000) {
			// Print the message if it hasn't been printed yet
			if (!key1) {
				std::cout << "The 1st key was pressed" << std::endl;

				if (up == false) {
					SetCursorPos((width / 4 + ((width / 4) / 2)), height / 2);
					up = true;
				}
				else if (up == true) {
					SetCursorPos((width / 4 + ((width / 4) / 2)), (height / 2) + 150);
					up = false;
				}
				key1 = true;
			}
		}
		else {
			// Reset the flag when the key is no longer being held down
			key1 = false;
		}

		if (GetAsyncKeyState(vk2) & 0x8000) {
			// Print the message if it hasn't been printed yet
			if (!key2) {
				std::cout << "The 2nd key was pressed" << std::endl;
				if (up == false) {
					SetCursorPos((width / 4 + ((width / 4) / 2)), height / 2);
					up = true;
				}
				else if (up == true) {
					SetCursorPos((width / 4 + ((width / 4) / 2)), (height / 2) + 150);
					up = false;
				}
				key2 = true;
			}
		}
		else {
			// Reset the flag when the key is no longer being held down
			key2 = false;
		}

		if (GetAsyncKeyState(vk3) & 0x8000) {
			// Print the message if it hasn't been printed yet
			if (!key3) {
				std::cout << "The 3rd key was pressed" << std::endl;
				if (up == false) {
					SetCursorPos(((width / 4) * 2 + ((width / 4) / 2)), height / 2);
					up = true;
				}
				else if (up == true) {
					SetCursorPos(((width / 4) * 2 + ((width / 4) / 2)), (height / 2) + 150);
					up = false;
				}
				key3 = true;
			}
		}
		else {
			// Reset the flag when the key is no longer being held down
			key3 = false;
		}

		if (GetAsyncKeyState(vk4) & 0x8000) {
			// Print the message if it hasn't been printed yet
			if (!key4) {
				std::cout << "The 4th key was pressed" << std::endl;
				if (up == false) {
					SetCursorPos(((width / 4) * 2 + ((width / 4) / 2)), height / 2);
					up = true;
				}
				else if (up == true) {
					SetCursorPos(((width / 4) * 2 + ((width / 4) / 2)), (height / 2) + 150);
					up = false;
				}
				key4 = true;
			}
		}
		else {
			// Reset the flag when the key is no longer being held down
			key4 = false;
		}
		Sleep(1);
	}
	return 0;
}

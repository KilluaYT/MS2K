#include <Windows.h>
#include <iostream>

#define VK_D 0x44
#define VK_F 0x46
#define VK_K 0x4B
#define VK_L 0x4C

int main() {
	bool key1 = false;
	bool key2 = false;
	bool key3 = false;
	bool key4 = false;
	bool up = false;

	while (true) {
		if (GetAsyncKeyState(VK_D) & 0x8000) {
			// Print the message if it hasn't been printed yet
			if (!key1) {
				std::cout << "The 'D' key was pressed" << std::endl;

				if (up == false) {
					SetCursorPos(480 + (480 / 2), 1080 / 2);
					up = true;
				}
				else if (up == true) {
					SetCursorPos(480 + (480 / 2), (1080 / 2) + 150);
					up = false;
				}
				key1 = true;
			}
		}
		else {
			// Reset the flag when the key is no longer being held down
			key1 = false;
		}

		if (GetAsyncKeyState(VK_F) & 0x8000) {
			// Print the message if it hasn't been printed yet
			if (!key2) {
				std::cout << "The 'F' key was pressed" << std::endl;
				if (up == false) {
					SetCursorPos(480 + (480 / 2), 1080 / 2);
					up = true;
				}
				else if (up == true) {
					SetCursorPos(480 + (480 / 2), (1080 / 2) + 150);
					up = false;
				}
				key2 = true;
			}
		}
		else {
			// Reset the flag when the key is no longer being held down
			key2 = false;
		}

		if (GetAsyncKeyState(VK_L) & 0x8000) {
			// Print the message if it hasn't been printed yet
			if (!key3) {
				std::cout << "The 'L' key was pressed" << std::endl;
				if (up == false) {
					SetCursorPos(480*2 + (480 / 2), 1080 / 2);
					up = true;
				}
				else if (up == true) {
					SetCursorPos(480*2 + (480 / 2), (1080 / 2) + 150);
					up = false;
				}
				key3 = true;
			}
		}
		else {
			// Reset the flag when the key is no longer being held down
			key3 = false;
		}

		if (GetAsyncKeyState(VK_K) & 0x8000) {
			// Print the message if it hasn't been printed yet
			if (!key4) {
				std::cout << "The 'K' key was pressed" << std::endl;
				if (up == false) {
					SetCursorPos(480*2 + (480 / 2), 1080 / 2);
					up = true;
				}
				else if (up == true) {
					SetCursorPos(480*2 + (480 / 2), (1080 / 2) + 150);
					up = false;
				}
				key4 = true;
			}
		}
		else {
			// Reset the flag when the key is no longer being held down
			key4 = false;
		}
	}
	return 0;
}

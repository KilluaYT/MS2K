#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <queue>
#include <chrono>

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
//key press statement
bool key1 = false;
bool key2 = false;
bool key3 = false;
bool key4 = false;
bool up = false;
// getting screen resolution
int width = GetSystemMetrics(SM_CXSCREEN);
int height = GetSystemMetrics(SM_CYSCREEN);
int vk1 = 0;
int vk2 = 0;
int vk3 = 0;
int vk4 = 0;
int vk5 = 0;
int vk6 = 0;
int vk7 = 0;
int vk8 = 0;
//counter
int k1, k2, k3, k4 = 0;
int clicks = 0;
//defining functions
void key1T();
void key2T();
void key3T();
void key4T();
void counter();
void refresh();
void onClick();
const int MAX_SAMPLES = 10; // Number of samples to use for the moving average
std::queue<std::chrono::high_resolution_clock::time_point> click_times; // Queue to store the times of each click
double total_time = 0, cps = 0;
double roundedValue = 0;
std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
WORD wAttributes;
const double DECAY_RATE = 0.1;
HANDLE stdhandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO screenbufferinfo;
SHORT prevX, prevY;

int main() {
	// GET CURSOR POSITION
	GetConsoleScreenBufferInfo(stdhandle, &screenbufferinfo);

	WORD wAttributes = screenbufferinfo.wAttributes;
	click_times.push(now);

	wAttributes &= ~(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wAttributes |= RGB(5, 5, 5); // Custom RGB color
	SetConsoleTextAttribute(stdhandle, wAttributes);

	std::cout << "MS2K v1.1.0 - MuseSwipr to Key by Railgun" << std::endl;

	SetConsoleTextAttribute(stdhandle,
		FOREGROUND_RED | FOREGROUND_INTENSITY | (255 / 255) |
		FOREGROUND_GREEN | FOREGROUND_INTENSITY | (255 / 255) |
		FOREGROUND_BLUE | FOREGROUND_INTENSITY | (255 / 255));
	std::cout << "-----------------------------------" << std::endl;

	wAttributes = 0;
	wAttributes &= ~(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wAttributes |= RGB(3, 3, 3); // Custom RGB color
	SetConsoleTextAttribute(stdhandle, wAttributes);
	std::cout << "Discord: Railgun#5065" << std::endl;
	wAttributes = 0;
	SetConsoleTextAttribute(stdhandle,
		FOREGROUND_RED | FOREGROUND_INTENSITY | (255 / 255) |
		FOREGROUND_GREEN | FOREGROUND_INTENSITY | (255 / 255) |
		FOREGROUND_BLUE | FOREGROUND_INTENSITY | (255 / 255));
	std::cout << "-----------------------------------" << std::endl << std::endl;
	SetConsoleTextAttribute(stdhandle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

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
	std::cout << std::endl;
	std::cout << "Your Key mapping is now " << keey1 << keey2 << keey3 << keey4 << " , to reset that, just restart the application." << std::endl;
	std::cout << "Your screen resolution of your main monitor (if u have multiple) is " << width << "x" << height << std::endl << "MuseSwipr must be runned on your main Monitor." << std::endl << std::endl;

	switch (keey1[0]) {
	case 'a':
	case 'A':
		vk1 = VK_A;	break;
	case 'b':
	case 'B':
		vk1 = VK_B;	break;
	case 'c':
	case 'C':
		vk1 = VK_C; break;
	case 'd':
	case 'D':
		vk1 = VK_D; break;
	case 'e':
	case 'E':
		vk1 = VK_E; break;
	case 'f':
	case 'F':
		vk1 = VK_F; break;
	case 'g':
	case 'G':
		vk1 = VK_G; break;
	case 'h':
	case 'H':
		vk1 = VK_H; break;
	case 'i':
	case 'I':
		vk1 = VK_I; break;
	case 'j':
	case 'J':
		vk1 = VK_J; break;
	case 'k':
	case 'K':
		vk1 = VK_K; break;
	case 'l':
	case 'L':
		vk1 = VK_L; break;
	case 'm':
	case 'M':
		vk1 = VK_M; break;
	case 'n':
	case 'N':
		vk1 = VK_N; break;
	case 'o':
	case 'O':
		vk1 = VK_O; break;
	case 'p':
	case 'P':
		vk1 = VK_P; break;
	case 'q':
	case 'Q':
		vk1 = VK_Q; break;
	case 'r':
	case 'R':
		vk1 = VK_R; break;
	case 's':
	case 'S':
		vk1 = VK_S; break;
	case 't':
	case 'T':
		vk1 = VK_T; break;
	case 'u':
	case 'U':
		vk1 = VK_U; break;
	case 'v':
	case 'V':
		vk1 = VK_V; break;
	case 'w':
	case 'W':
		vk1 = VK_W; break;
	case 'x':
	case 'X':
		vk1 = VK_X; break;
	case 'y':
	case 'Y':
		vk1 = VK_Y; break;
	case 'z':
	case 'Z':
		vk1 = VK_Z; break;
	}
	switch (keey2[0]) {
	case 'a':
	case 'A':
		vk2 = VK_A;	break;
	case 'b':
	case 'B':
		vk2 = VK_B;	break;
	case 'c':
	case 'C':
		vk2 = VK_C; break;
	case 'd':
	case 'D':
		vk2 = VK_D; break;
	case 'e':
	case 'E':
		vk2 = VK_E; break;
	case 'f':
	case 'F':
		vk2 = VK_F; break;
	case 'g':
	case 'G':
		vk2 = VK_G; break;
	case 'h':
	case 'H':
		vk2 = VK_H; break;
	case 'i':
	case 'I':
		vk2 = VK_I; break;
	case 'j':
	case 'J':
		vk2 = VK_J; break;
	case 'k':
	case 'K':
		vk2 = VK_K; break;
	case 'l':
	case 'L':
		vk2 = VK_L; break;
	case 'm':
	case 'M':
		vk2 = VK_M; break;
	case 'n':
	case 'N':
		vk2 = VK_N; break;
	case 'o':
	case 'O':
		vk2 = VK_O; break;
	case 'p':
	case 'P':
		vk2 = VK_P; break;
	case 'q':
	case 'Q':
		vk2 = VK_Q; break;
	case 'r':
	case 'R':
		vk2 = VK_R; break;
	case 's':
	case 'S':
		vk2 = VK_S; break;
	case 't':
	case 'T':
		vk2 = VK_T; break;
	case 'u':
	case 'U':
		vk2 = VK_U; break;
	case 'v':
	case 'V':
		vk2 = VK_V; break;
	case 'w':
	case 'W':
		vk2 = VK_W; break;
	case 'x':
	case 'X':
		vk2 = VK_X; break;
	case 'y':
	case 'Y':
		vk2 = VK_Y; break;
	case 'z':
	case 'Z':
		vk2 = VK_Z; break;
	}
	switch (keey3[0]) {
	case 'a':
	case 'A':
		vk3 = VK_A;	break;
	case 'b':
	case 'B':
		vk3 = VK_B; break;
	case 'c':
	case 'C':
		vk3 = VK_C; break;
	case 'd':
	case 'D':
		vk3 = VK_D; break;
	case 'e':
	case 'E':
		vk3 = VK_E; break;
	case 'f':
	case 'F':
		vk3 = VK_F; break;
	case 'g':
	case 'G':
		vk3 = VK_G; break;
	case 'h':
	case 'H':
		vk3 = VK_H; break;
	case 'i':
	case 'I':
		vk3 = VK_I; break;
	case 'j':
	case 'J':
		vk3 = VK_J; break;
	case 'k':
	case 'K':
		vk3 = VK_K; break;
	case 'l':
	case 'L':
		vk3 = VK_L; break;
	case 'm':
	case 'M':
		vk3 = VK_M; break;
	case 'n':
	case 'N':
		vk3 = VK_N; break;
	case 'o':
	case 'O':
		vk3 = VK_O; break;
	case 'p':
	case 'P':
		vk3 = VK_P; break;
	case 'q':
	case 'Q':
		vk3 = VK_Q; break;
	case 'r':
	case 'R':
		vk3 = VK_R; break;
	case 's':
	case 'S':
		vk3 = VK_S; break;
	case 't':
	case 'T':
		vk3 = VK_T; break;
	case 'u':
	case 'U':
		vk3 = VK_U; break;
	case 'v':
	case 'V':
		vk3 = VK_V; break;
	case 'w':
	case 'W':
		vk3 = VK_W; break;
	case 'x':
	case 'X':
		vk3 = VK_X; break;
	case 'y':
	case 'Y':
		vk3 = VK_Y; break;
	case 'z':
	case 'Z':
		vk3 = VK_Z; break;
	}
	switch (keey4[0]) {
	case 'a':
	case 'A':
		vk4 = VK_A;	break;
	case 'b':
	case 'B':
		vk4 = VK_B;	break;
	case 'c':
	case 'C':
		vk4 = VK_C; break;
	case 'd':
	case 'D':
		vk4 = VK_D; break;
	case 'e':
	case 'E':
		vk4 = VK_E; break;
	case 'f':
	case 'F':
		vk4 = VK_F; break;
	case 'g':
	case 'G':
		vk4 = VK_G; break;
	case 'h':
	case 'H':
		vk4 = VK_H; break;
	case 'i':
	case 'I':
		vk4 = VK_I; break;
	case 'j':
	case 'J':
		vk4 = VK_J; break;
	case 'k':
	case 'K':
		vk4 = VK_K; break;
	case 'l':
	case 'L':
		vk4 = VK_L; break;
	case 'm':
	case 'M':
		vk4 = VK_M; break;
	case 'n':
	case 'N':
		vk4 = VK_N; break;
	case 'o':
	case 'O':
		vk4 = VK_O; break;
	case 'p':
	case 'P':
		vk4 = VK_P; break;
	case 'q':
	case 'Q':
		vk4 = VK_Q; break;
	case 'r':
	case 'R':
		vk4 = VK_R; break;
	case 's':
	case 'S':
		vk4 = VK_S; break;
	case 't':
	case 'T':
		vk4 = VK_T; break;
	case 'u':
	case 'U':
		vk4 = VK_U; break;
	case 'v':
	case 'V':
		vk4 = VK_V; break;
	case 'w':
	case 'W':
		vk4 = VK_W; break;
	case 'x':
	case 'X':
		vk4 = VK_X; break;
	case 'y':
	case 'Y':
		vk4 = VK_Y; break;
	case 'z':
	case 'Z':
		vk4 = VK_Z; break;
	}

	std::cout << "Initializing Multi Threading" << std::endl << std::endl;
	// A BIT OF SLEEP SO USER KNOWS PROGRAM IS STARTING AND CONSOLE WOULD BE CLEARED INSTANTLY AFTER THAT
	std::this_thread::sleep_for(std::chrono::milliseconds(2500));
	std::thread t6(refresh);
	std::thread t1(key1T);
	std::thread t2(key2T);
	std::thread t3(key3T);
	std::thread t4(key4T);
	std::thread t5(counter);
	system("cls"); // CLEAR CONSOLE

	prevX = screenbufferinfo.dwCursorPosition.X;
	prevY = screenbufferinfo.dwCursorPosition.Y;
	t6.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	return 0;
}

void key1T() {
	while (true) {
		if (GetAsyncKeyState(vk1) & 0x8000) {
			if (!key1) {
				k1++;
				onClick();
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
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
void key2T() {
	while (true) {
		if (GetAsyncKeyState(vk2) & 0x8000) {
			if (!key2) {
				k2++;
				onClick();

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
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
void key3T() {
	while (true) {
		if (GetAsyncKeyState(vk3) & 0x8000) {
			if (!key3) {
				k3++;

				onClick();

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
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
void key4T() {
	while (true) {
		if (GetAsyncKeyState(vk4) & 0x8000) {
			if (!key4) {
				k4++;
				onClick();

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
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
void counter() {
	while (true) {
		roundedValue = std::round(cps * 10) / 10;
		std::cout << "Key Count | K1: " << k1 << " | K2: " << k2 << " | K3: " << k3 << " | K4: " << k4 << std::endl;
		std::cout << "KPS: ";
		wAttributes = 0;
		wAttributes &= ~(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		if (roundedValue < 20) {
			wAttributes |= RGB(3, 3, 3);
			SetConsoleTextAttribute(stdhandle, wAttributes);
		}
		else {
			if (roundedValue < 30)
			{
				wAttributes |= RGB(2, 2, 2);
				SetConsoleTextAttribute(stdhandle, wAttributes);
			}
			else {
				SetConsoleTextAttribute(stdhandle, FOREGROUND_RED);
			}
		}

		std::cout << roundedValue << "         " << std::endl;
		SetConsoleTextAttribute(stdhandle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		SetConsoleCursorPosition(stdhandle, { prevX , prevY });

		//(&prevPos);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
void refresh() {
	while (true) {
		if (click_times.empty()) {
			cps = 0;
		}
		else {
			now = std::chrono::high_resolution_clock::now();
			auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - click_times.front()).count();
			cps = cps * (1 - (total_time * DECAY_RATE));
		}
		total_time = std::chrono::duration_cast<std::chrono::milliseconds>(now - click_times.front()).count();
		if (total_time > 0) {
			cps = click_times.size() / (total_time / 1000.0);
		}
		else {
			cps = 0;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void onClick() {
	now = std::chrono::high_resolution_clock::now();
	click_times.push(now);
	while (click_times.size() > MAX_SAMPLES) {
		click_times.pop();
	}
}
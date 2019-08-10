#pragma once
#ifndef BASE4CONSOLEGAMES_HPP
#define BASE4CONSOLEGAMES_HPP

/*
Table showing how ASCII characters are drawn on the screen

0 |     32 |    64 | @  96 | `  128 | Ç 160 | á 192 | └ 224 | Ó
1 | ☺   33 | !  65 | A  97 | a  129 | ü 161 | í 193 | ┴ 225 | ß
2 | ☻   34 | "  66 | B  98 | b  130 | é 162 | ó 194 | ┬ 226 | Ô
3 | ♥   35 | #  67 | C  99 | c  131 | â 163 | ú 195 | ├ 227 | Ò
4 | ♦   36 | $  68 | D  100 | d 132 | ä 164 | ñ 196 | ─ 228 | õ
5 | ♣   37 | %  69 | E  101 | e 133 | à 165 | Ñ 197 | ┼ 229 | Õ
6 | ♠   38 | &  70 | F  102 | f 134 | å 166 | ª 198 | ã 230 | µ
7 | •   39 | '  71 | G  103 | g 135 | ç 167 | º 199 | Ã 231 | þ
8 | ◘   40 | (  72 | H  104 | h 136 | ê 168 | ¿ 200 | ╚ 232 | Þ
9 | ○   41 | )  73 | I  105 | i 137 | ë 169 | ® 201 | ╔ 233 | Ú
10 | ◙	42 | *  74 | J  106 | j 138 | è 170 | ¬ 202 | ╩ 234 | Û
11 | ♂  43 | +  75 | K  107 | k 139 | ï 171 | ½ 203 | ╦ 235 | Ù
12 | ♀  44 | ,  76 | L  108 | l 140 | î 172 | ¼ 204 | ╠ 236 | ý
13 | ♪	45 | -  77 | M  109 | m 141 | ì 173 | ¡ 205 | ═ 237 | Ý
14 | ♫  46 | .  78 | N  110 | n 142 | Ä 174 | « 206 | ╬ 238 | ¯
15 | ☼  47 | /  79 | O  111 | o 143 | Å 175 | » 207 | ¤ 239 | ´
16 | ►  48 | 0  80 | P  112 | p 144 | É 176 | ░ 208 | ð 240 | ­­­­­­­­­­­­­­­­­-
17 | ◄  49 | 1  81 | Q  113 | q 145 | æ 177 | ▒ 209 | Ð 241 | ±
18 | ↕  50 | 2  82 | R  114 | r 146 | Æ 178 | ▓ 210 | Ê 242 | ‗
19 | ‼  51 | 3  83 | S  115 | s 147 | ô 179 | │ 211 | Ë 243 | ¾
20 | ¶  52 | 4  84 | T  116 | t 148 | ö 180 | ┤ 212 | È 244 | ¶
21 | §  53 | 5  85 | U  117 | u 149 | ò 181 | Á 213 | ı 245 | §
22 | ▬  54 | 6  86 | V  118 | v 150 | û 182 | Â 214 | Í 246 | ÷
23 | ↨  55 | 7  87 | W  119 | w 151 | ù 183 | À 215 | Î 247 | ¸
24 | ↑  56 | 8  88 | X  120 | x 152 | ÿ 184 | © 216 | Ï 248 | °
25 | ↓  57 | 9  89 | Y  121 | y 153 | Ö 185 | ╣ 217 | ┘ 249 | ¨
26 | →  58 | :  90 | Z  122 | z 154 | Ü 186 | ║ 218 | ┌ 250 | ·
27 | ←  59 | ;  91 | [  123 | { 155 | ø 187 | ╗ 219 | █ 251 | ¹
28 | ∟  60 | <  92 | \  124 | | 156 | £ 188 | ╝ 220 | ▄ 252 | ³
29 | ↔  61 | =  93 | ]  125 | } 157 | Ø 189 | ¢ 221 | ¦ 253 | ²
30 | ▲  62 | >  94 | ^  126 | ~ 158 | × 190 | ¥ 222 | Ì 254 | ■
31 | ▼  63 | ?  95 | _  127 | ⌂ 159 | ƒ 191 | ┐ 223 | ▀ 255 |  

*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/**
 ** Default SCREEN_WIDTH is 80.
 ** Default SCREEN_HEIGHT is 25.
 **/
#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 80
#endif // SCREEN_WIDTH

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 25
#endif // SCREEN_HEIGHT

#define F_BLACK			0x00
#define	F_BLUE			0x01
#define	F_GREEN 		0x02
#define F_AQUA			0x03
#define	F_RED			0x04
#define F_PURPLE		0x05
#define F_YELLOW		0x06
#define F_WHITE			0x07
#define	F_GREY			0x08
#define	F_LIGHTBLUE		0x09
#define	F_LIGHTGREEN	0x0A
#define	F_LIGHTAQUA		0x0B
#define	F_LIGHTRED		0x0C
#define	F_LIGHTPURPLE	0x0D
#define	F_LIGHTYELLOW	0x0E
#define	F_BRIGTHWHITE	0x0F

#define B_BLACK			0x00
#define	B_BLUE			0x10
#define	B_GREEN 		0x20
#define B_AQUA			0x30
#define	B_RED			0x40
#define B_PURPLE		0x50
#define B_YELLOW		0x60
#define B_WHITE			0x70
#define	B_GREY			0x80
#define	B_LIGHTBLUE		0x90
#define	B_LIGHTGREEN	0xA0
#define	B_LIGHTAQUA		0xB0
#define	B_LIGHTRED		0xC0
#define	B_LIGHTPURPLE	0xD0
#define	B_LIGHTYELLOW	0xE0
#define	B_BRIGTHWHITE	0xF0

#define KEY_BACKSPACE	0x08
#define KEY_ENTER		0x0D
#define KEY_ESCAPE		0x1B
#define KEY_ARROW_LEFT	0x25
#define KEY_ARROW_UP	0x26
#define KEY_ARROW_RIGHT	0x27
#define KEY_ARROW_DOWN	0x28
#define KEY_0			0x30
#define KEY_1			0x31
#define KEY_2			0x32
#define KEY_3			0x33
#define KEY_4			0x34
#define KEY_5			0x35
#define KEY_6			0x36
#define KEY_7			0x37
#define KEY_8			0x38
#define KEY_9			0x39
#define KEY_A			0x41
#define KEY_B			0x42
#define KEY_C			0x43
#define KEY_D			0x44
#define KEY_E			0x45
#define KEY_F			0x46
#define KEY_G			0x47
#define KEY_H			0x48
#define KEY_I			0x49
#define KEY_J			0x4A
#define KEY_K			0x4B
#define KEY_L			0x4C
#define KEY_M			0x4D
#define KEY_N			0x4E
#define KEY_O			0x4F
#define KEY_P			0x50
#define KEY_Q			0x51
#define KEY_R			0x52
#define KEY_S			0x53
#define KEY_T			0x54
#define KEY_U			0x55
#define KEY_V			0x56
#define KEY_W			0x57
#define KEY_X			0x58
#define KEY_Y			0x59
#define KEY_Z			0x5A
#define KEY_NUMPAD0		0x60
#define KEY_NUMPAD1		0x61
#define KEY_NUMPAD2		0x62
#define KEY_NUMPAD3		0x63
#define KEY_NUMPAD4		0x64
#define KEY_NUMPAD5		0x65
#define KEY_NUMPAD6		0x66
#define KEY_NUMPAD7		0x67
#define KEY_NUMPAD8		0x68
#define KEY_NUMPAD9		0x69

enum FrameType : unsigned short int {DOUBLE = 0, SINGLE = 1};

class Game
{
	protected:
		/**
		 ** 	Game constructor.
		 **		
		 ** 	Names are self-explanatory.
		 ** 	It's important to setup correctly the buffer,
		 ** 	initializing it with something.
		 **/
		Game()
		{
			consoleOutput	= (HANDLE) GetStdHandle(STD_OUTPUT_HANDLE);
			bufferSize		= {SCREEN_WIDTH,SCREEN_HEIGHT};
			bufferCoord		= {0, 0};
			region			= {0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1};
			
			ReadConsoleOutputA(consoleOutput, (CHAR_INFO *) buffer, bufferSize, bufferCoord, &region);

			BYTE values[256];
			GetKeyboardState(values);
			for (int i = 0; i < 256; ++i)
				keys[i] = values[i] & 0x0001;
		}

		/**
		 **	FillCell(SHORT x, SHORT y, CHAR c, WORD attr):
		 **	
		 **		Fill the selected cell (buffer[y][x]) with
		 ** 	an ASCII CHAR c and some ATTRIBUTES attr.
		 **/
		void FillCell(SHORT x, SHORT y, CHAR c, WORD attr)
		{
			buffer[y][x].Attributes		= attr;
			buffer[y][x].Char.AsciiChar	= c;
		}

		/**
		 **	DrawBuffer():
		 **	
		 **		Draw the buffer into the screen.
		 **	
		 ** 	Call it after have drawned something.
		 **/
		void DrawBuffer()
		{
			WriteConsoleOutputA(consoleOutput, (CHAR_INFO*) buffer, bufferSize, bufferCoord, &region);
		}

		/**
		 ** DrawBufferRegion(SHORT x, SHORT y, SHORT columns, SHORT rows):
		 **
		 **		Draw a region of the buffer into the screen.
		 **		The region is defined by the topleft corner
		 **		[x, y] coordinates and the number of rows
		 **		and columns.
		 **
		 ** 	Call it after have drawned something.
		 **/
		void DrawBufferRegion(SHORT x, SHORT y, SHORT columns, SHORT rows)
		{
			SMALL_RECT region = {x, y, x + columns - 1, y + rows - 1};
			WriteConsoleOutputA(consoleOutput, (CHAR_INFO*)buffer, bufferSize, {x, y}, &region);
		}
		
		/**
		 ** FillBuffer(CHAR c, WORD attr):
		 **	
		 ** 	Fill the entire buffer with an ASCII CHAR c
		 ** 	and some ATTRIBUTES attr.
		 **
		 ** 	ex. Use FillBuffer(' ', F_BLACK | B_BLACK)
		 ** 	to display black screen;
		 **/
		void FillBuffer(CHAR c, WORD attr)
		{
			CHAR_INFO ci;
			ci.Attributes		= attr;
			ci.Char.AsciiChar	= c;
			
			for(unsigned short y = 0; y < SCREEN_HEIGHT; ++y)
				for(unsigned short x = 0; x < SCREEN_WIDTH; ++x)
					buffer[y][x] = ci;
		}

		/**
		 ** IsKeyDown(int key):
		 **
		 ** 	Check is key is down.
		 **/
		bool IsKeyDown(int key)
		{
			return (GetAsyncKeyState(key) & 0x8000);
		}

		/**
		 ** IsKeyPressed(int key):
		 **
		 ** 	Check is key is pressed since
		 ** 	the last call.
		 **/
		bool IsKeyPressed(int key)
		{
			bool toggled	= keys[key];
			keys[key]		= GetKeyState(key) & 0x0001;

			return toggled != keys[key];
		}

		/**
		 ** DrawFrame(int x, int y, int w, int h, FrameType type, unsigned char attr):
		 ** 
		 **		Draw a simple frame using x & y
		 **		coordinates, w & h as width and height 
		 **		and attr to display it colored.
		 **		
		 **		ex.
		 **		FrameType::SINGLE	FrameType::DOUBLE
		 ** 	┌──┐				╔══╗
		 **		│  │				║  ║
		 **		└──┘				╚══╝
		 **/
		void DrawFrame(int x, int y, int w, int h, FrameType type, unsigned char attr)
		{
			--w; --h;
			static const char c[2][6] = {	{(char) 201, (char) 187, (char) 200, (char) 188, (char) 205, (char) 186},
											{(char) 218, (char) 191, (char) 192, (char) 217, (char) 196, (char) 179}};

			// Corners
			FillCell(x,			y, c[type][0], attr); // '╔' | '┌'
			FillCell(x + w,		y, c[type][1], attr); // '╗' | '┐'
			FillCell(x,		y + h, c[type][2], attr); // '╚' | '└'
			FillCell(x + w, y + h, c[type][3], attr); // '╝' | '┘'
			for (int i = x + 1; i < x + w; ++i)
			{
				FillCell(i,		y, c[type][4], attr); // '═' | '─'
				FillCell(i, y + h, c[type][4], attr); // '═' | '─'
			}
			for (int i = y + 1; i < y + h; ++i)
			{
				FillCell(x,		i, c[type][5], attr); // '║' | '│'
				FillCell(x + w,	i, c[type][5], attr); // '║' | '│'
			}
		}

		/**
		 ** DrawWords(int x, int y, const char* text, const int n, unsigned char attr):
		 **		
		 **		Draw some text into the screen using
		 **		x & y coordinates and the attr value
		 **		to display it colored.
		 ** 
		 **		Text is a const char array and n is
		 **		its size.
		 **		Pass NULL to draw the entire text.
		 **/
		void DrawWords(int x, int y, const char* text, size_t n, unsigned char attr)
		{
			if (n == NULL)	n = strlen(text);

			for (int i = 0; i < n; ++i)
				FillCell(x + i, y, text[i], attr);
		}

		/**
		 ** SetTitle(const char* title):
		 **	
		 **		Set console title.
		 **/
		void SetTitle(const char* title)
		{
			SetConsoleTitle(title);
		}

		/**
		 ** SetWindowSize(SHORT width, SHORT height, bool adjustBuffer):
		 **	
		 ** 	Set window size and if adjustBuffer flag is
		 ** 	setted to true, the buffer is resized too.
		 ** 
		 **/
		void SetWindowSize(SHORT width, SHORT height, bool adjustBuffer)
		{
			SMALL_RECT rect = {0, 0, width, height};
			if (adjustBuffer) SetConsoleScreenBufferSize(consoleOutput, {width, height});
			SetConsoleWindowInfo(consoleOutput, TRUE, &rect);
		}
		
		/**
		 ** ShowConsoleCursor(BOOL visible):
		 **	
		 ** 	Set cursor visibility.
		 **/
		void ShowConsoleCursor(BOOL visible)
		{
			CONSOLE_CURSOR_INFO cursorInfo;
			GetConsoleCursorInfo(consoleOutput, &cursorInfo);
			cursorInfo.bVisible = visible;
			SetConsoleCursorInfo(consoleOutput, &cursorInfo);
		}
		
		/**
		 ** Gotoxy(SHORT x, SHORT y):
		 ** 
		 ** 	Set cursor position at [x, y].
		 **/
		void Gotoxy(SHORT x, SHORT y)
		{
			SetConsoleCursorPosition(consoleOutput, {x, y});
		}
		
	private:
		HANDLE consoleOutput;
		COORD bufferSize, bufferCoord;
		SMALL_RECT region;
		CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
		bool keys[256];
};

#endif // BASE4CONSOLEGAMES_HPP

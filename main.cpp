#define SCREEN_HEIGHT	30
#define SCREEN_WIDTH	40

#define PLAYER_SPEED	3

#include "../Base4ConsoleGames.hpp"

#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <time.h>

#define TOTAL_LEVEL	10

int enemies_per_level[TOTAL_LEVEL] = {38, 38 * 2, 38 * 3, 38 * 4, 38 * 5, 38 * 6, 38 * 7, 38 * 8, 38 * 9, 38 * 10};

struct Player
{
	int x, y, power, fireRate, time, life, lifeMax, granade, shield;
	bool dead;
};
struct Enemy
{
	int x, y, power, fireRate, time, life;
	bool dead;
	char c;
	unsigned char attr;
};
struct Shoot
{
	int x, y, damage, speedx, speedy, time, deltaTime;
	bool dead;
	char c;
	unsigned char attr;
};
struct Upgrade
{
	int x, y;
	bool isPower, isFireRate, isLife, isHeal, isGranade, isShield, dead;
	char c;
	unsigned char attr;
};
struct Options
{
	bool isPlayerAlwaysShooting;
	unsigned char	boardAttributes, playerAttributes, wordAttributes, lifeAttributes, deadLifeAttributes,
					powerAttributes, backgroundAttributes, firerateAttributes, shieldAttributes, granadeAttributes;
};

class SpaceShooterGame : public Game
{
	public:
		SpaceShooterGame()
		{
			srand(time(NULL));

			o.isPlayerAlwaysShooting	= true;
			o.boardAttributes			= F_GREEN;
			o.playerAttributes			= F_LIGHTBLUE;
			o.lifeAttributes			= F_RED;
			o.deadLifeAttributes		= F_GREY;
			o.wordAttributes			= F_BRIGTHWHITE;
			o.powerAttributes			= F_LIGHTYELLOW;
			o.backgroundAttributes		= B_BLACK;
			o.firerateAttributes		= F_LIGHTRED;
			o.shieldAttributes			= F_BLUE;
			o.granadeAttributes			= F_GREY;

			isRunning = true;
		}

		void run()
		{
			onStart();
			mainLoop();
			onEnd();
		}

	private:
		void onStart()
		{
			ShowConsoleCursor(false);
			SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT, true);
		}

		void drawWelcome()
		{
			std::string s = "Press Enter to Start!";
			if (frame > 105) frame -= 105;
			int delta = frame / 5;
			for (int i = 0; i < 21; ++i)
			{
				if (delta == i)	FillCell(i + 10,  9, s[i], F_RED | B_WHITE);
				else			FillCell(i + 10, 10, s[i], F_RED | B_WHITE);
			}

			s = "Please disable the legacy console.";
			for (int i = 0; i < 34; ++i)
				FillCell(i + 2, 15, s[i], F_BRIGTHWHITE | o.backgroundAttributes);
		}

		void drawMenuAnimations()
		{
			static const int n = 20;
			static bool init = false;
			static std::vector<int> X(n, 0), Y(n, 0), time(n, 0), deltaTime(n, 0), speedX(n, 0), speedY(n, 0);
			static const std::vector<char> C(n, 30); // '▲'
			static std::vector<unsigned char> attr(n, F_WHITE);

			if (!init)
			{
				for (auto& x : X)			x = rand() % SCREEN_WIDTH;
				for (auto& y : Y)			y = rand() % SCREEN_HEIGHT;
				for (auto& s : speedY)		s = rand() % 2 == 0 ? -1 : 1;
				for (auto& s : speedX)		s = rand() % 2 == 0 ? -1 : 1;
				for (auto& a : attr)		a = rand() % 16;
				for (auto& t : time)		t = rand() % 10;
				for (auto& t : deltaTime)	t = rand() % 10 + 5;

				init = true;
			}

			for (int i = 0; i < n; ++i)
			{
				++time[i];
				if (time[i] >= deltaTime[i])
				{
					X[i] += speedX[i];
					Y[i] += speedY[i];

					time[i] -= deltaTime[i];

					if (X[i] <= 0 || Y[i] <= 0 || X[i] >= SCREEN_WIDTH || Y[i] >= SCREEN_HEIGHT)
					{
						X[i]			= rand() % SCREEN_WIDTH;
						Y[i]			= rand() % SCREEN_HEIGHT;
						speedX[i]		= rand() % 2 == 0 ? -1 : 1;
						speedY[i]		= rand() % 2 == 0 ? -1 : 1;
						attr[i]			= rand() % 16;
						time[i]			= rand() % 20;
						deltaTime[i]	= rand() % 20 + 10;
					}
				}
			}

			for (int i = 0; i < n; ++i)
				FillCell(X[i], Y[i], C[i], attr[i] | o.backgroundAttributes);
		}

		void drawEnemies(int toDraw)
		{
			int i = 0;
			while (toDraw > 0)
			{
				if (!enemies[i].dead)
				{
					FillCell(enemies[i].x, enemies[i].y, enemies[i].c, enemies[i].attr | o.backgroundAttributes);
					--toDraw;
				}
				++i;
			}
		}

		void drawBoard()
		{
			// Texts
			std::string s = "LEVEL " + std::to_string(level) + " SCORE " + std::to_string(points);
			for (int i = 0; i < s.size(); ++i)
				FillCell(i + 1, 1, s[i], o.wordAttributes | o.backgroundAttributes);
			
			// Special tags
			for (int i = 0; i < p.life; ++i)				FillCell(2 + i, 2,	  3, o.lifeAttributes | o.backgroundAttributes);		// Life '♥'
			for (int i = p.life; i < p.lifeMax; ++i)		FillCell(2 + i, 2,    3, o.deadLifeAttributes | o.backgroundAttributes);	// Life '♥'
			for (int i = 0; i < p.power; ++i)				FillCell(8 + i, 2,	  4, o.powerAttributes | o.backgroundAttributes);		// Power '♦'
			for (int i = 0; i < (20 - p.fireRate) / 2; ++i)	FillCell(14 + i, 2, 175, o.firerateAttributes | o.backgroundAttributes);	// FireRate '»'
			for (int i = 0; i < p.shield / 100; ++i)		FillCell(20 + i, 2, 157, o.shieldAttributes | o.backgroundAttributes);		// Shield 'Ø'
			for (int i = 0; i < p.granade; ++i)				FillCell(26 + i, 2, 184, o.granadeAttributes | o.backgroundAttributes);		// Granade '©'

			// Borders
			for (int i = 1; i < SCREEN_WIDTH - 1; ++i)
			{
				FillCell(i, 0,					205, o.boardAttributes | o.backgroundAttributes); // '═'
				FillCell(i, 3,					205, o.boardAttributes | o.backgroundAttributes); // '═'
				FillCell(i, SCREEN_HEIGHT - 1,	205, o.boardAttributes | o.backgroundAttributes); // '═'
			}
			FillCell(0, 0,					201, o.boardAttributes | o.backgroundAttributes); // '╔'
			FillCell(0, 1,					186, o.boardAttributes | o.backgroundAttributes); // '║'
			FillCell(0, 2,					186, o.boardAttributes | o.backgroundAttributes); // '║'
			FillCell(0, 3,					204, o.boardAttributes | o.backgroundAttributes); // '╠'
			FillCell(SCREEN_WIDTH - 1, 0,	187, o.boardAttributes | o.backgroundAttributes); // '╗'
			FillCell(SCREEN_WIDTH - 1, 1,	186, o.boardAttributes | o.backgroundAttributes); // '║'
			FillCell(SCREEN_WIDTH - 1, 2,	186, o.boardAttributes | o.backgroundAttributes); // '║'
			FillCell(SCREEN_WIDTH - 1, 3,	185, o.boardAttributes | o.backgroundAttributes); // '╣'
			for (int i = 4; i < SCREEN_HEIGHT - 1; ++i)
			{
				FillCell(0, i,					186, o.boardAttributes | o.backgroundAttributes); // '║'
				FillCell(SCREEN_WIDTH - 1, i,	186, o.boardAttributes | o.backgroundAttributes); // '║'
			}
			FillCell(0, SCREEN_HEIGHT - 1,					200, o.boardAttributes | o.backgroundAttributes); // '╚'
			FillCell(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1,	188, o.boardAttributes | o.backgroundAttributes); // '╝'
		}

		void drawPlayer()
		{
			FillCell(p.x, p.y,  30, o.playerAttributes | o.backgroundAttributes); // '▲'
		}

		void drawShoots()
		{
			for (auto& s : shoots)
				FillCell(s.x, s.y, s.c, s.attr | o.backgroundAttributes);
		}

		void drawUpgrades()
		{
			for (auto& u : upgrades)
				FillCell(u.x, u.y, u.c, u.attr | o.backgroundAttributes);
		}

		void playerShoot()
		{
			if (p.time >= p.fireRate)
			{
				p.time = 0;
				shoots.push_back({p.x, p.y - 1, p.power, 0, -1, 0, p.fireRate / 3 * 2, false, 24, F_LIGHTAQUA}); // '↑'
			}
		}

		void playerThrowGranade()
		{
			if (p.granade <= 0) return;

			for (auto& s : shoots)
				if (s.speedy > 0)
					s.dead = true;
			--p.granade;
		}

		void enemyDeath(Enemy e)
		{
			points += 10;

			int choice = rand() % 100;

			if (choice == 0)		upgrades.push_back({e.x, e.y, true, false, false, false, false, false, false, (char)   4, o.powerAttributes});		// Power '♦'
			else if (choice == 10)	upgrades.push_back({e.x, e.y, false, true, false, false, false, false, false, (char) 175, o.firerateAttributes});	// FireRate '»'
			else if (choice == 20)	upgrades.push_back({e.x, e.y, false, false, true, false, false, false, false, (char)   3, o.deadLifeAttributes });	// Life '♥'
			else if (choice == 30)	upgrades.push_back({e.x, e.y, false, false, false, true, false, false, false, (char)   3, o.lifeAttributes});		// Life '♥'
			else if (choice == 40)	upgrades.push_back({e.x, e.y, false, false, false, false, true, false, false, (char) 184, o.granadeAttributes });	// Granade '©'
			else if (choice == 50)	upgrades.push_back({e.x, e.y, false, false, false, false, false, true, false, (char) 157, o.shieldAttributes});		// Shield 'Ø'
		}

		void applyUpgrade(Upgrade& u)
		{
			if (u.isPower && p.power < 5)			++p.power;
			if (u.isGranade && p.granade < 3)		++p.granade;
			if (u.isHeal && p.life < p.lifeMax)		++p.life;
			if (u.isShield)							p.shield = 500;
			if (u.isLife && p.lifeMax < 5)			++p.lifeMax;
			if (u.isFireRate && p.fireRate > 10)	p.fireRate -= 2;

			u.dead = true;
		}

		void gameLogic()
		{
			// Player movement & shooting
			++p.time;
			if (p.shield > 0) --p.shield;
			
			if (frame % PLAYER_SPEED == 0)
			{
				if (IsKeyDown(KEY_A))		{ if (p.x > 1)					--p.x; }
				else if (IsKeyDown(KEY_D))	{ if (p.x < SCREEN_WIDTH - 2)	++p.x; }
			}
			if (o.isPlayerAlwaysShooting | IsKeyDown(KEY_BACKSPACE))	playerShoot();
			if (IsKeyDown(KEY_G))										playerThrowGranade();

			// Shoots movement & collision
			for (auto& s : shoots)
			{
				++s.time;

				// Shoot movement
				if (s.deltaTime <= s.time)
				{
					s.time -= s.deltaTime;
					s.y += s.speedy;
					s.x += s.speedx;
				}

				// Shoot out of screen
				if (s.x < 0 || s.y < 4 || s.x >= SCREEN_WIDTH || s.y >= SCREEN_HEIGHT)
				{
					s.dead = true;
					continue;
				}

				// Check for player collision
				if (p.x == s.x && p.y == s.y)
				{
					if (p.shield <= 0)
					{
						p.life -= s.damage;
						p.shield = 110;
					}

					s.dead = true;
				}

				// Check for enemies collision
				if (s.speedy > 0) continue;
				for (auto &e : enemies)
					if (!e.dead && !s.dead && e.x == s.x && e.y == s.y)
					{
						s.dead = true;
						e.life -= s.damage;
					}
			}

			// Enemy shoots
			for (auto &e : enemies)
			{
				if (e.life <= 0)
				{
					e.dead = true;
					continue;
				}
				++e.time;

				if (e.fireRate <= e.time)
				{
					bool canShoot = true;
					for (auto& s1 : shoots)
						if (s1.x == e.x && s1.y == e.y + 1)
						{
							canShoot = false;
							break;
						}

					if (canShoot)
					{
						e.time -= e.fireRate;
						shoots.push_back({ e.x, e.y + 1, e.power, 0, 1, 0, 10, false, 124, F_LIGHTYELLOW }); // '|'
					}
				}
			}

			// Upgrade movement & collision
			for (auto& u : upgrades)
			{
				if (u.dead) continue;

				if (frame % 15 == 0) ++u.y;
				if (p.x == u.x && p.y == u.y)	applyUpgrade(u);
				if (u.y >= SCREEN_HEIGHT)		u.dead = true;
			}

			// Check for player death
			if (p.life <= 0) p.dead = true;

			// Destroy dead enemies
			for (int i = enemies.size() - 1; i >= 0; --i)
				if (enemies[i].dead)
				{
					enemyDeath(enemies[i]);
					enemies.erase(enemies.begin() + i);
				}

			// Destroy dead shoots
			for (int i = shoots.size() - 1; i >= 0; --i)
				if (shoots[i].dead)
					shoots.erase(shoots.begin() + i);

			// Destroy dead upgrades
			for (int i = upgrades.size() - 1; i >= 0; --i)
				if (upgrades[i].dead)
					upgrades.erase(upgrades.begin() + i);
		}

		void setupLevel()
		{
			p.time = 0;
			shoots.clear();
			for (int i = 0; i < enemies_per_level[level - 1]; ++i)
			{
				Enemy enemy;
				enemy.x			= 1 + i % (SCREEN_WIDTH - 2);
				enemy.y			= 4 + i / (SCREEN_WIDTH - 2);
				enemy.life		= 1;
				enemy.power		= 1;
				enemy.fireRate	= 1000 + rand() % 500;
				enemy.time		= 500 + rand() % 500;
				enemy.dead		= false;
				int v = rand() % 4;
				if (v == 0)			enemy.c	= 228; // 'õ'
				else if (v == 1)	enemy.c	= 224; // 'Ó'
				else if (v == 2)	enemy.c = 226; // 'Ô'
				else if (v == 3)	enemy.c = 227; // 'Ò'
				enemy.attr		= F_RED;
				enemies.push_back(enemy);
			}
		}

		void restart()
		{
			level = 1;
			points = 0;
			frame = 0;

			p.x			= 12;
			p.y			= 25;
			p.power		= 1;
			p.fireRate	= 20;
			p.time		= 0;
			p.life		= 3;
			p.lifeMax	= 3;
			p.granade	= 1;
			p.dead		= false;
			p.shield	= 300;

			shoots.clear();
			enemies.clear();
			upgrades.clear();
		}

		void mainLoop()
		{
			while (isRunning)
			{
				restart();

				// MENU
				bool menu = true;
				while (isRunning && menu)
				{
					FillBuffer(' ', F_BLACK | o.backgroundAttributes);
					drawMenuAnimations();
					drawWelcome();
					DrawBuffer();
					if (IsKeyDown(KEY_ENTER)) menu = false;
					Sleep(10);
					++frame;
				}

				FillBuffer(' ', F_BLACK | o.backgroundAttributes);
				DrawBuffer();

				// PLAYING PHASE
				bool play = true;
				while (isRunning && play)
				{
					// DRAW ENEMIES
					frame = 0;
					setupLevel();
					while (frame < enemies_per_level[level - 1])
					{
						FillBuffer(' ', F_BLACK | o.backgroundAttributes);
						drawEnemies(frame);
						drawBoard();
						DrawBuffer();
						Sleep(10);
						++frame;
					};

					// START PLAYING
					while (!p.dead && enemies.size() > 0)
					{
						FillBuffer(' ', F_BLACK | o.backgroundAttributes);
						drawShoots();
						drawUpgrades();
						drawShoots();
						drawEnemies(enemies.size());
						drawPlayer();
						drawBoard();
						DrawBuffer();
						gameLogic();
						Sleep(10);
						++frame;
					}

					play = !p.dead;
					++level;
				}
			}
		}

		void onEnd()
		{
			FillBuffer(' ', F_BLACK | o.backgroundAttributes);
			DrawBuffer();
		}

	private:
		int level, points;
		long frame;
		bool isRunning;
		Player p;
		std::vector<Enemy> enemies;
		std::vector<Shoot> shoots;
		std::vector<Upgrade> upgrades;
		Options o;
};

int main()
{
	SpaceShooterGame g;
	g.run();
	return EXIT_SUCCESS;
}

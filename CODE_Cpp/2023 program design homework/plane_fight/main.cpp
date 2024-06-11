#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm> // 包含remove_if

using namespace std;

// 定义战场的大小
const int HEIGHT = 35;
const int WIDTH = 55;

// 定义我方飞机的形状
const char* myPlaneShape[3] = {
    "  ^  ",
    " /|\\ ",
    "/ | \\"
};

// 定义敌方飞机的形状
const char* enemyPlaneShape[3] = {
    "\\ | /",
    " \\|/ ",
    "  V  "
};

// 飞机位置结构
struct Position {
    int x, y;
};

// 飞机类
class Plane {
public:
    Position pos;
    vector<Position> bullets;

    Plane(int x, int y) : pos{x, y} {}

    void move(int dx, int dy) {
        pos.x += dx;
        pos.y += dy;
        if (pos.x < 0) pos.x = 0;
        if (pos.x >= WIDTH) pos.x = WIDTH - 1;
        if (pos.y < 0) pos.y = 0;
        if (pos.y >= HEIGHT) pos.y = HEIGHT - 1;
    }

    void shoot() {
        bullets.push_back({pos.x + 2, pos.y - 1});
    }

    void moveBullets(bool isEnemy = false) {
        for (auto& bullet : bullets) {
            bullet.y += (isEnemy ? 1 : -1);
        }
        bullets.erase(remove_if(bullets.begin(), bullets.end(), [](Position p) { return p.y < 0 || p.y >= HEIGHT; }), bullets.end());
    }
};

// 控制台光标移动函数
void gotoXY(int x, int y) {
    COORD pos = {short(x), short(y)};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

// 隐藏光标
void HideCursor() {
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

// 显示飞机
void displayPlane(const Plane& plane, const char* shape[3]) {
    for (int i = 0; i < 3; ++i) {
        gotoXY(plane.pos.x, plane.pos.y + i);
        cout << shape[i];
    }
}

// 显示子弹
void displayBullets(const vector<Position>& bullets) {
    for (const auto& bullet : bullets) {
        gotoXY(bullet.x, bullet.y);
        cout << "|";
    }
}

// 清屏函数
void clearScreen() {
    system("cls");
}

// 检查两个矩形是否重叠
bool isCollision(Position p1, int w1, int h1, Position p2, int w2, int h2) {
    return p1.x < p2.x + w2 &&
           p1.x + w1 > p2.x &&
           p1.y < p2.y + h2 &&
           p1.y + h1 > p2.y;
}

// 游戏主函数
int main() {
    srand(time(0));
    HideCursor();

    Plane myPlane(WIDTH / 2, HEIGHT - 3);
    vector<Plane> enemyPlanes;

    int score = 0;

    // 创建敌方飞机
    for (int i = 0; i < 10; ++i) {
        int x = rand() % WIDTH;
        int y = rand() % (HEIGHT / 2);
        enemyPlanes.emplace_back(x, y);
    }

    while (true) {
        clearScreen();

        // 显示我方飞机和子弹
        displayPlane(myPlane, myPlaneShape);
        myPlane.moveBullets();
        displayBullets(myPlane.bullets);

        // 显示敌方飞机和子弹
        for (auto& enemy : enemyPlanes) {
            // 敌方飞机随机移动
            int dx = (rand() % 3) - 1; // -1, 0, or 1
            int dy = (rand() % 3) - 1; // -1, 0, or 1
            enemy.move(dx, dy);

            // 敌方飞机随机发射子弹
            if (rand() % 10 == 0) {
                enemy.shoot();
            }

            displayPlane(enemy, enemyPlaneShape);
            enemy.moveBullets(true);
            displayBullets(enemy.bullets);
        }

        // 检查我方飞机和敌方飞机之间的碰撞
        for (const auto& enemy : enemyPlanes) {
            if (isCollision(myPlane.pos, 5, 3, enemy.pos, 5, 3)) {
                cout << "Game Over!" << endl;
                return 0;
            }
        }

        // 检查我方子弹与敌方飞机之间的碰撞
        for (auto it = myPlane.bullets.begin(); it != myPlane.bullets.end();) {
            bool hit = false;
            for (auto et = enemyPlanes.begin(); et != enemyPlanes.end();) {
                if (isCollision(*it, 1, 1, et->pos, 5, 3)) {
                    it = myPlane.bullets.erase(it);
                    et = enemyPlanes.erase(et);
                    score += 1;
                    hit = true;
                    break;
                } else {
                    ++et;
                }
            }
            if (!hit) {
                ++it;
            }
        }

        // 检查敌方子弹与我方飞机之间的碰撞
        for (auto& enemy : enemyPlanes) {
            for (auto it = enemy.bullets.begin(); it != enemy.bullets.end();) {
                if (isCollision(*it, 1, 1, myPlane.pos, 5, 3)) {
                    it = enemy.bullets.erase(it);
                    score -= 1;
                    if (score < 0) {
                        cout << "Game Over!" << endl;
                        return 0;
                    }
                } else {
                    ++it;
                }
            }
        }

        // 显示得分
        gotoXY(0, HEIGHT);
        cout << "Score: " << score;

        // 控制我方飞机移动
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'w') myPlane.move(0, -1);
            if (ch == 's') myPlane.move(0, 1);
            if (ch == 'a') myPlane.move(-1, 0);
            if (ch == 'd') myPlane.move(1, 0);
        }
        myPlane.shoot();
        Sleep(50);
    }

    return 0;
}

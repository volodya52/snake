using namespace std;
#include <iostream>
#include <conio.h>
#include <windows.h>
int width = 20;
int height = 10;
int foodX;
int foodY;
int score;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
struct Snake {
    int x, y;
    Snake* next;
};
void input();
void FoodGenerate(Snake* head);
void Draw(Snake* head);
bool CheckLoose(Snake* head);
void Moving(Snake*& head, Snake*& tail);
bool FoodCheck(Snake* head);
void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': dir = LEFT; break;
        case 'd': dir = RIGHT; break;
        case 'w': dir = UP; break;
        case 's': dir = DOWN; break;
        case '0': dir = STOP; break;
        }
    }
}

void FoodGenerate(Snake* head) {
    bool foodOnSnake;
    do {
        foodX = rand() % width;
        foodY = rand() % height;
        foodOnSnake = false;
        Snake* temp = head;
        while (temp != nullptr) {
            if (temp->x == foodX && temp->y == foodY) {
                foodOnSnake = true;
                break;
            }
            temp = temp->next;
        }
    } while (foodOnSnake);
}

void Draw(Snake* head) {
    system("cls");
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#";
            bool body = false;
            Snake* temp = head;
            while (temp != nullptr) {
                if (temp->x == j && temp->y == i) {
                    cout << "O";
                    body = true;
                }
                temp = temp->next;
            }
            if (!body) {
                if (foodX == j && foodY == i) cout << "o";
                else cout << " ";
            }

            if (j == width - 1) cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

bool CheckLoose(Snake* head) {
    if (head->x < 0 || head->x >= width || head->y < 0 || head->y >= height)
        return true;

    Snake* temp = head->next;
    while (temp != nullptr) {
        if (temp->x == head->x && temp->y == head->y)
            return true;
        temp = temp->next;
    }

    return false;
}

void Moving(Snake*& head, Snake*& tail) {
    int prevX = head->x;
    int prevY = head->y;
    int tempX, tempY;

    switch (dir) {
    case LEFT: head->x--; break;
    case RIGHT: head->x++; break;
    case UP: head->y--; break;
    case DOWN: head->y++; break;
    default: break;
    }

    if (FoodCheck(head)) {
        Snake* newSnake = new Snake();
        newSnake->x = prevX;
        newSnake->y = prevY;
        newSnake->next = nullptr;
        tail->next = newSnake;
        tail = newSnake;
        FoodGenerate(head);
    }
    else {
        Snake* temp = head->next;
        while (temp != nullptr) {
            tempX = temp->x;
            tempY = temp->y;
            temp->x = prevX;
            temp->y = prevY;
            prevX = tempX;
            prevY = tempY;
            temp = temp->next;
        }
    }
}

bool FoodCheck(Snake* head) {
    if (head->x == foodX && head->y == foodY) {
        score += 10;
        return true;
    }
    return false;
}

int main() {
    Snake* head = new Snake();
    head->x = width / 2;
    head->y = height / 2;
    head->next = nullptr;
    Snake* tail = head;
    score = 0;
    dir = RIGHT;
    FoodGenerate(head);
    while (dir != STOP) {
        Draw(head);
        input();
        Moving(head, tail);
        if (CheckLoose(head)) {
            cout << "Game over!" << endl;           
            break;
        }
        Sleep(100);
    }    
}


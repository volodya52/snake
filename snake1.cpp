// snake1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <random>
int width=20, height=10;
struct SnakeNode 
{
    int x, y;
};



void Draw(int headx, int heady,int foodx,int foody)
{
    system("cls");
    bool snake = false;
    for (int i = 0; i < width; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
    for (int x = 1; x < height - 1; x++) {
        std::cout << "#";
        for (int y = 1; y < width - 1; y++) {
            if (y == headx && x == heady) {
                std::cout << "0";
                snake = true;
                
            }
            else if(y==foodx&&x==foody) {
                std::cout << "o";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "#" << std::endl;
    }
    for (int i = 0; i < width; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
}
void CheckEat() {

}
void CheckLoose() {

}
int main()
{
    int score = 0;
    bool gameover=false;
    int headx, heady,foodx,foody;
    headx = width / 2;
    heady = height / 2;
    foodx = std::rand() % width;
    foody = std::rand() % height;
    std::cout << foodx<<std::endl;
    std::cout << foody<<std::endl;
    std::cout << "Welcome to the game - Snake!\n";
    std::cout << "Control:\nW-up\nA-left\nD-right\nS-down\n"; 
    while (gameover==false) {
        Draw(headx,heady,foodx,foody);
        Sleep(10);
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

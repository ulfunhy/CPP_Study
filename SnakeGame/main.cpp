﻿#include <SFML/Graphics.hpp>
#include <stdlib.h>		// srand(), rand()
#include <time.h>		// time()
#include <stdio.h>

#define DIR_UP		0
#define DIR_DOWN	1
#define DIR_RIGHT	2
#define DIR_LEFT	3

using namespace sf;

class Snake {

public:
	int dir_;
	int x_;
	int y_;
	RectangleShape sprite_;
};

class Apple {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};

int main(void)
{
	const int WIDTH = 1000;						// 픽셀 너비
	const int HEIGHT = 800;						// 픽셀 높이
	const int BLOCK_SIZE = 50;					// 한 칸이 가지고 있는 픽셀
	const int G_WIDTH = WIDTH / BLOCK_SIZE;		// 그리드 너비
	const int G_HEIGHT = HEIGHT / BLOCK_SIZE;	// 그리드 높이

	srand(time(NULL));
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Snake Game");	// 윈도우 창 만들기

	// 컴퓨터가 1초동안 처리하는 횟수는 60으로 제한한다.
	// Frame Per Second를 30으로 조절
	window.setFramerateLimit(10);

	Snake snake;
	snake.x_ = 1, snake.y_ = 2;	// 뱀의 그리드 좌표
	snake.dir_ = DIR_DOWN;		// 뱀이 이도아는 방향
	snake.sprite_.setFillColor(Color::White);
	snake.sprite_.setPosition(snake.x_ * BLOCK_SIZE, snake.y_ * BLOCK_SIZE);
	snake.sprite_.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	Apple apple;
	apple.x_ = rand() % G_WIDTH, apple.y_ = rand() % G_HEIGHT;
	apple.sprite_.setFillColor(Color::Red);
	// 640에 50을 뺀 이유는 사과가 화면 밖에 벗어나지 않게 하기 위함
	apple.sprite_.setPosition(apple.x_ * BLOCK_SIZE, apple.y_ * BLOCK_SIZE);
	apple.sprite_.setSize(Vector2f(BLOCK_SIZE, BLOCK_SIZE));

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			// 윈도우의 x를 눌렀을 때 창이 닫아지도록
			if (e.type == Event::Closed)
				window.close();
		}
		// 방향키가 동시에 눌러지지 않도록 else 처리(else commit에 실수로 미작성됨)
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			snake.dir_ = DIR_RIGHT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			snake.dir_ = DIR_LEFT;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up)) {
			snake.dir_ = DIR_UP;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			snake.dir_  = DIR_DOWN;
		}

		// update
		if (snake.dir_ == DIR_UP) {
			snake.y_--;
		}
		else if (snake.dir_ == DIR_DOWN) {
			snake.y_++;
		}
		else if (snake.dir_ == DIR_RIGHT) {
			snake.x_++;
		}
		else if (snake.dir_ == DIR_LEFT) {
			snake.x_--;
		}		// 그리드 좌표
		snake.sprite_.setPosition(snake.x_ * BLOCK_SIZE, snake.y_ * BLOCK_SIZE);		// 픽셀 좌표

		// 뱀이 사과를 먹었을 때, 
		if (snake.x_ == apple.x_ && snake.y_ == apple.y_) {
			apple.x_ = rand() % G_WIDTH, apple.y_ = rand() % G_HEIGHT;
			apple.sprite_.setPosition(apple.x_ * BLOCK_SIZE, apple.y_ * BLOCK_SIZE);
		}


		// render
		window.clear();

		window.draw(snake.sprite_);
		window.draw(apple.sprite_);	// draw를 늦게 할 수로 더 위에 있다.

		window.display();
	}

	return 0;	// 창 지우기
}
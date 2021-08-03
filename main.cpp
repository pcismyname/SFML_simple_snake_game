#include <SFML/Graphics.hpp>

#include<iostream>
#include <time.h>
#include<random>

int SIZE = 30;
int vx = SIZE * SIZE;
int vy = SIZE * SIZE;
int vline = 30;
int hline =30;
int dir = 1;
int num = 3;

struct Snake
{
    int x;
    int y;
}snake[100];

struct Fruit
{
    int x,y;
} fruit;

void gameAction()
{
    for(int i=num;i>0;i--)
    {
      snake[i].x = snake[i-1].x;
      snake[i].y = snake[i-1].y;
    }
    if(dir == 0)
    {
        snake[0].y +=1;

    }
    else if(dir == 1)
    {
        snake[0].x -=1;

    }
    else if(dir == 2)
    {
        snake[0].x +=1;

    }
    else if(dir == 3)
    {
        snake[0].y -=1;

    }

    if((snake[0].x == fruit.x) && (snake[0].y == fruit.y))
    {
        num++;
        fruit.x = rand()%30;
        fruit.y = rand()%15;
    }

    if(snake[0].x > 30)
    {
        snake[0].x = 0;
        snake[0].y = 0;
        num = 3;
    }
    if(snake[0].y > 15)
    {
        snake[0].x = 0;
        snake[0].y = 0;
        num = 3;
    }

    if(snake[0].y < 0)
    {
        snake[0].x = 0;
        snake[0].y = 0;
        num = 3;
    }
    if(snake[0].y < 0)
    {
        snake[0].x = 0;
        snake[0].y = 0;
        num = 3;
    }
    for(int i=1;i<num;i++)
    {
        if(snake[0].x == snake[i].x && snake[0].y == snake[i].y)
        {
        snake[0].x = 0;
        snake[0].y = 0;
        num = 3;
        }
    }
}

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(vx,vy), "Snake Game");
    sf::RectangleShape block;
    sf::Clock clock;
    sf::RectangleShape snakeblock;
    sf::RectangleShape fruitblock;
    float chrono =0;
    float delay = 0.1;

    block.setSize(sf::Vector2f(SIZE,SIZE));
    block.setFillColor(sf::Color::Black);
    block.setOutlineThickness(1);
    block.setOutlineColor(sf::Color::White);

    fruitblock.setSize(sf::Vector2f(SIZE,SIZE));
    fruitblock.setFillColor(sf::Color::Red);
    fruitblock.setOutlineThickness(1);
    fruitblock.setOutlineColor(sf::Color::White);

    fruit.x = rand() % 30;
    fruit.y = rand() % 15;

    snakeblock.setSize(sf::Vector2f(SIZE,SIZE));
    snakeblock.setFillColor(sf::Color::Green);
    snakeblock.setOutlineThickness(1);
    snakeblock.setOutlineColor(sf::Color::White);


    while(window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        chrono += time;
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            dir = 0;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            dir = 1;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            dir = 2;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            dir = 3;
        }


        if(chrono > delay)
        {
            chrono = 0;
            gameAction();
        }

        window.clear();
        for(int i=0;i<vline;i++)
        {
            for(int j=0;j<hline;j++)
            {
                block.setPosition(j * SIZE, i*SIZE );
                window.draw(block);
            }
        }
        for(int i=0;i<num;i++)
        {
            snakeblock.setPosition(snake[i].x * SIZE,snake[i].y * SIZE);
            window.draw(snakeblock);
        }
        fruitblock.setPosition(fruit.x*SIZE, fruit.y*SIZE);
        window.draw(fruitblock);
        window.display();

    }
}

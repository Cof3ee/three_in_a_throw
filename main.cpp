#include <SFML/Graphics.hpp>
#include <vector>

#include <iostream> //Временно

#include "game.h"
#include "board_element.h"
#include "tile_field.h"

int determine_x(const int& number_col)
{
    int x;

    if (number_col == 0)
    {
      return  x = 50;
    }
    else if (number_col == 1)
    {
      return x = 110;
    }
    else if (number_col == 2)
    {
      return x = 170;
    }
    else if (number_col == 3)
    {
      return x = 230;
    }
}

int determine_y(const unsigned int& number_row)
{
    int y;

    if (number_row == 0)
    {
       return y = 150;
    }
    else if (number_row == 1)
    {
       return y = 210;
    }
    else if (number_row == 2)
    {
       return y = 270;
    }
    else if (number_row == 3)
    {
       return y = 330;
    }
    else if (number_row == 4)
    {
       return y = 390;
    }
}

int main()
{
    int fieldXStart = 50;
    int fieldYStart = 150;
    int fieldXEnd = 230;
    int fieldYEnd = 390;

    // Вычисляем размеры поля
    int fieldWidth = fieldXEnd - fieldXStart;
    int fieldHeight = fieldYEnd - fieldYStart;

    const unsigned int ROWS = 5;
    const unsigned int COLS = 4;
    const int TILE_SIZE = 58;
    game g(ROWS, COLS);

    sf::RenderWindow win(sf::VideoMode({ 308,460 }), L"Три в ряд");

    
        sf::Texture Textur_Info_Panel;
        Textur_Info_Panel.loadFromFile("Image/statuds.png");
        sf::RectangleShape Game_Info_Panel(sf::Vector2f(202, 26));
        Game_Info_Panel.setTexture(&Textur_Info_Panel);
        Game_Info_Panel.setPosition(sf::Vector2f(50, 0));

        //Фон
        sf::Texture texture_background;
        texture_background.loadFromFile("Image/fon.png");
        sf::Sprite Game_background(texture_background);

        //Прогресс уровня
        sf::Texture Textur_Uroven;
        Textur_Uroven.loadFromFile("Image/uroven.png");
        sf::RectangleShape Game_Info_Uroven(sf::Vector2f(168, 39));
        Game_Info_Uroven.setTexture(&Textur_Uroven);
        Game_Info_Uroven.setPosition(sf::Vector2f(70, 28));

        //Номер уровня
        sf::Texture Textur_Number_Level;
        Textur_Number_Level.loadFromFile("Image/level.png");
        sf::RectangleShape Game_Number_Level(sf::Vector2f(141, 50));
        Game_Number_Level.setTexture(&Textur_Number_Level);
        Game_Number_Level.setPosition(sf::Vector2f(90, 78));

        //Маскот авокадо
        sf::Texture Textur_Maskot_Avokado;
        Textur_Maskot_Avokado.loadFromFile("Image/mascot01.png");
        sf::RectangleShape Game_Maskot_Avokado(sf::Vector2f(79, 136));
        Game_Maskot_Avokado.setTexture(&Textur_Maskot_Avokado);
        Game_Maskot_Avokado.setPosition(sf::Vector2f(50, 58));

        //Маскот клубника
        sf::Texture Textur_Maskot_Klubnika;
        Textur_Maskot_Klubnika.loadFromFile("Image/mascot2.png");
        sf::RectangleShape Game_Maskot_Klubnika(sf::Vector2f(101, 130));
        Game_Maskot_Klubnika.setTexture(&Textur_Maskot_Klubnika);
        Game_Maskot_Klubnika.setPosition(sf::Vector2f(205, 64));

    //Клубника
    sf::Texture Textur_Pole_Klubnika;
    Textur_Pole_Klubnika.loadFromFile("Image/klubnika-tenm.png");
    sf::RectangleShape Game_Pole_Klubnika(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    Game_Pole_Klubnika.setTexture(&Textur_Pole_Klubnika);

    //Авокадо
    sf::Texture Textur_Pole_Avokado;
    Textur_Pole_Avokado.loadFromFile("Image/avokado-tmn.png");
    sf::RectangleShape Game_Pole_Avokado(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    Game_Pole_Avokado.setTexture(&Textur_Pole_Avokado);

    //Лимон
    sf::Texture Textur_Pole_Limon;
    Textur_Pole_Limon.loadFromFile("Image/limon.png");
    sf::RectangleShape Game_Pole_Limon(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    Game_Pole_Limon.setTexture(&Textur_Pole_Limon);

    //Светлая клубника
    sf::Texture Textur_Pole_Klubnika_Light;
    Textur_Pole_Klubnika_Light.loadFromFile("Image/klubnika-svet.png");
    sf::RectangleShape Game_Pole_Klubnika_Light(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    Game_Pole_Klubnika_Light.setTexture(&Textur_Pole_Klubnika_Light);

    //Светлое авокадо
    sf::Texture Textur_Pole_Avokado_Light;
    Textur_Pole_Avokado_Light.loadFromFile("Image/avokado.png");
    sf::RectangleShape Game_Pole_Avokado_Light(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    Game_Pole_Avokado_Light.setTexture(&Textur_Pole_Avokado_Light);

    //Светлый лимон
    sf::Texture Textur_Pole_Limon_Light;
    Textur_Pole_Limon_Light.loadFromFile("Image/limon-svetl.png");
    sf::RectangleShape Game_Pole_Limon_Light(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    Game_Pole_Limon_Light.setTexture(&Textur_Pole_Limon_Light);

    // --- Создание фигур (RectangleShape) ---
    std::vector<std::vector<tile_field>> board_rects;

    //Отрисовка поля
    auto board = g.get_board();
    int number_row = 0;
    for (auto row : board)
    {
        int number_col = 0;
        std::vector<tile_field> row_rects;
        for (auto col : row)
        {
            tile_field t;
            int x = determine_x(number_col);
            int y = determine_y(number_row);

            switch (col)
            {
            case 0:
                Game_Pole_Klubnika.setPosition(sf::Vector2f(x, y));
                t.field_texture = Game_Pole_Klubnika;
                row_rects.push_back(t);
                break;

            case 1:
                Game_Pole_Avokado.setPosition(sf::Vector2f(x, y));
                t.field_texture = Game_Pole_Avokado;
                row_rects.push_back(t);
                break;

            case 2:
                Game_Pole_Limon.setPosition(sf::Vector2f(x, y));
                t.field_texture = Game_Pole_Limon;
                row_rects.push_back(t);
                break;
            }
            number_col++;
        }
        board_rects.push_back(row_rects);
        number_row++;
    }
   
    while (win.isOpen())
    {
        while (const std::optional event = win.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                win.close();
            }

            if(sf::Mouse::isButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(win);
                //Преобразуем в координаты игрового мира
                sf::Vector2f worldPos = win.mapPixelToCoords(mousePos);

                ////Проверяем был ли клик в поле
                //if (mousePos.x >= fieldXStart && mousePos.x <= fieldXEnd &&
                //    mousePos.y >= fieldYStart && mousePos.y <= fieldYEnd)
                //{
                    // Вычисляем смещение клика относительно верхнего левого угла поля
                    int offsetX = mousePos.x - fieldXStart;
                    int offsetY = mousePos.y - fieldYStart;

                    // Вычисляем индекс столбца и строки
                    int columnIndex = offsetX / TILE_SIZE;
                    int rowIndex = offsetY / TILE_SIZE;

                    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        std::cout << "Click left!" << std::endl;
                        int x = determine_x(columnIndex);
                        int y = determine_y(rowIndex);

                        Game_Pole_Limon_Light.setPosition(sf::Vector2f(x, y));
                        board_rects[rowIndex][columnIndex].field_texture = Game_Pole_Limon_Light;
                        
                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
                    {
                        std::cout << "Click right!" << std::endl;
                    }
                //}
                //else
                //{
                //    /*std::cout << "Click is inside the field!" << std::endl;*/
                //}
            }
        }


        win.clear();
        
        //Отрисовка фона
        win.draw(Game_background);

        ////Отрисовка текстур
        win.draw(Game_Info_Panel);
        win.draw(Game_Info_Uroven);
        win.draw(Game_Number_Level);
        win.draw(Game_Maskot_Avokado);
        win.draw(Game_Maskot_Klubnika);
        
        //Отрисовка полей
          //  0 - клубника
          //  1 - авокадо
          //  2 - лимон
        
       // Отрисовываем все плитки
        for (const auto& row : board_rects)
        {
            for (const auto& col : row)
            {
                win.draw(col.field_texture);
            }
        }

        win.display();
    }
    return 0;
}
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

bool chec_adjancet_cells(const board_element& first,const board_element& second)
{
    if (first.row == second.row && first.col == second.col)
    {
        return false;
    }

    int row_diff = std::abs(first.row - second.row);
    int col_diff = std::abs(first.col - second.col);

    bool horizontal_adjacent = (row_diff == 0 && col_diff == 1);
    bool vertical_adjacent = (col_diff == 0 && row_diff == 1);

    return horizontal_adjacent || vertical_adjacent;
}

int main()
{
    int game_field_X_start = 50;
    int game_field_Y_start = 150;
    int game_field_X_end = 290;
    int game_field_Y_end = 450;

    // Вычисляем размеры поля
    const  int GAME_FIELD_WIDTH = game_field_X_end - game_field_X_start;
    const  int GAME_FIELD_HEIGHT = game_field_Y_end - game_field_Y_start;

    const  int GAME_ROWS = 5;
    const  int GAME_COLS = 4;
    const int GAME_CELL_SIZE = 58;

    const  int GAME_CELL_Strawberry = 0;
    const  int GAME_CELL_Avocado = 1;
    const  int GAME_CELL_Limon = 2;

    game game_field(GAME_ROWS, GAME_COLS);

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
        sf::Texture Textur_Maskot_Strawberry;
        Textur_Maskot_Strawberry.loadFromFile("Image/mascot2.png");
        sf::RectangleShape Game_Maskot_Strawberry(sf::Vector2f(101, 130));
        Game_Maskot_Strawberry.setTexture(&Textur_Maskot_Strawberry);
        Game_Maskot_Strawberry.setPosition(sf::Vector2f(205, 64));

    //Клубника
    sf::Texture Textur_Cell_Strawberry;
    Textur_Cell_Strawberry.loadFromFile("Image/klubnika-tenm.png");
    sf::RectangleShape Game_Cell_Strawberry(sf::Vector2f(GAME_CELL_SIZE, GAME_CELL_SIZE));
    Game_Cell_Strawberry.setTexture(&Textur_Cell_Strawberry);

    //Авокадо
    sf::Texture Textur_Cell_Avokado;
    Textur_Cell_Avokado.loadFromFile("Image/avokado-tmn.png");
    sf::RectangleShape Game_Cell_Avokado(sf::Vector2f(GAME_CELL_SIZE, GAME_CELL_SIZE));
    Game_Cell_Avokado.setTexture(&Textur_Cell_Avokado);

    //Лимон
    sf::Texture Textur_Cell_Limon;
    Textur_Cell_Limon.loadFromFile("Image/limon.png");
    sf::RectangleShape Game_Cell_Limon(sf::Vector2f(GAME_CELL_SIZE, GAME_CELL_SIZE));
    Game_Cell_Limon.setTexture(&Textur_Cell_Limon);

    //Светлая клубника
    sf::Texture Textur_Cell_Strawberry_Light;
    Textur_Cell_Strawberry_Light.loadFromFile("Image/klubnika-svet.png");
    sf::RectangleShape Game_Cell_Strawberry_Light(sf::Vector2f(GAME_CELL_SIZE, GAME_CELL_SIZE));
    Game_Cell_Strawberry_Light.setTexture(&Textur_Cell_Strawberry_Light);

    //Светлое авокадо
    sf::Texture Textur_Cell_Avokado_Light;
    Textur_Cell_Avokado_Light.loadFromFile("Image/avokado.png");
    sf::RectangleShape Game_Cell_Avokado_Light(sf::Vector2f(GAME_CELL_SIZE, GAME_CELL_SIZE));
    Game_Cell_Avokado_Light.setTexture(&Textur_Cell_Avokado_Light);

    //Светлый лимон
    sf::Texture Textur_Cell_Limon_Light;
    Textur_Cell_Limon_Light.loadFromFile("Image/limon-svetl.png");
    sf::RectangleShape Game_Cell_Limon_Light(sf::Vector2f(GAME_CELL_SIZE, GAME_CELL_SIZE));
    Game_Cell_Limon_Light.setTexture(&Textur_Cell_Limon_Light);

    // --- Создание фигур (RectangleShape) ---
    std::vector<std::vector<tile_field>> board_rects;

    //  0 - клубника
    //  1 - авокадо
    //  2 - лимон
    auto game_board = game_field.get_board();
    int number_row = 0;
    for (auto row : game_board)
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
                Game_Cell_Strawberry.setPosition(sf::Vector2f(x, y));
                t.field_texture = Game_Cell_Strawberry;
                t.field_name_number = 0;
                row_rects.push_back(t);
                break;

            case 1:
                Game_Cell_Avokado.setPosition(sf::Vector2f(x, y));
                t.field_texture = Game_Cell_Avokado;
                t.field_name_number = 1;
                row_rects.push_back(t);
                break;

            case 2:
                Game_Cell_Limon.setPosition(sf::Vector2f(x, y));
                t.field_texture = Game_Cell_Limon;
                t.field_name_number = 2;
                row_rects.push_back(t);
                break;
            }
            number_col++;
        }
        board_rects.push_back(row_rects);
        number_row++;
    }
   
    board_element cell_to_swap;
    while (win.isOpen())
    {
        while (const std::optional event = win.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                win.close();
            }
            if(const auto* mouse_button_pressed = event->getIf<sf::Event::MouseButtonReleased>())
            {
                sf::Event::MouseButtonReleased a;
                sf::Vector2i mousePos = sf::Mouse::getPosition(win);
                //Преобразуем в координаты игрового мира
                sf::Vector2f worldPos = win.mapPixelToCoords(mousePos);

                //Проверяем был ли клик в поле
                if (mousePos.x >= game_field_X_start && mousePos.x <= game_field_X_end &&
                    mousePos.y >= game_field_Y_start && mousePos.y <= game_field_Y_end)
                {
                    // Вычисляем смещение клика относительно верхнего левого угла поля
                    int offsetX = mousePos.x - game_field_X_start;
                    int offsetY = mousePos.y - game_field_Y_start;

                    board_element selected_cell;
                    // Вычисляем индекс столбца и строки
                    selected_cell.col = offsetX / GAME_CELL_SIZE;
                    selected_cell.row = offsetY / GAME_CELL_SIZE;

                    int x = determine_x(selected_cell.col);
                    int y = determine_y(selected_cell.row);

                    if (mouse_button_pressed->button == sf::Mouse::Button::Left)
                    {
                        std::cout << "Click left!" << std::endl;
                        

                        cell_to_swap.row = selected_cell.row;
                        cell_to_swap.col= selected_cell.col;

                        if (board_rects[selected_cell.row][selected_cell.col].field_name_number == GAME_CELL_Strawberry)
                        {
                            Game_Cell_Strawberry_Light.setPosition(sf::Vector2f(x, y));
                            board_rects[selected_cell.row][selected_cell.col].field_texture = Game_Cell_Strawberry_Light;
                        }
                        else if (board_rects[selected_cell.row][selected_cell.col].field_name_number == GAME_CELL_Avocado)
                        {
                            Game_Cell_Avokado_Light.setPosition(sf::Vector2f(x, y));
                            board_rects[selected_cell.row][selected_cell.col].field_texture = Game_Cell_Avokado_Light;
                        }
                        else if (board_rects[selected_cell.row][selected_cell.col].field_name_number == GAME_CELL_Limon)
                        {
                            Game_Cell_Limon_Light.setPosition(sf::Vector2f(x, y));
                            board_rects[selected_cell.row][selected_cell.col].field_texture = Game_Cell_Limon_Light;
                        }   
                    }
                    else if (mouse_button_pressed->button == sf::Mouse::Button::Right)
                    {
                        std::cout << "Click right!" << std::endl;

                        if (chec_adjancet_cells(cell_to_swap,selected_cell))
                        {
                            game_field.display();
                            game_field.make_move(cell_to_swap, selected_cell);
                            std::cout << std::endl;
                            game_field.display();

                            board_rects.clear();
                            auto game_board = game_field.get_board();
                            int number_row = 0;
                            for (auto row : game_board)
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
                                        Game_Cell_Strawberry.setPosition(sf::Vector2f(x, y));
                                        t.field_texture = Game_Cell_Strawberry;
                                        t.field_name_number = 0;
                                        row_rects.push_back(t);
                                        break;

                                    case 1:
                                        Game_Cell_Avokado.setPosition(sf::Vector2f(x, y));
                                        t.field_texture = Game_Cell_Avokado;
                                        t.field_name_number = 1;
                                        row_rects.push_back(t);
                                        break;

                                    case 2:
                                        Game_Cell_Limon.setPosition(sf::Vector2f(x, y));
                                        t.field_texture = Game_Cell_Limon;
                                        t.field_name_number = 2;
                                        row_rects.push_back(t);
                                        break;
                                    }
                                    number_col++;
                                }
                                board_rects.push_back(row_rects);
                                number_row++;

                                selected_cell.row = -1;
                                selected_cell.col = -1;
                            }
                        }
                    }
                }
                else
                {
                    std::cout << "Click is inside the field!" << std::endl;
                }
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
        win.draw(Game_Maskot_Strawberry);
       
        
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
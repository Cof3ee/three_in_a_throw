#include <SFML/Graphics.hpp>
#include <vector>

#include <iostream> //Временно

#include "game_board_logic.h"
#include "board_element.h"
#include "tile_field.h"
#include "constants.h"
#include "game_window_textures.h"

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
    game_board_logic game_field(GAME_ROWS, GAME_COLS);

    sf::RenderWindow win(sf::VideoMode({ 330,460 }), L"Три в ряд");

    game_window_textures textures;

    textures.Info_Panel.texture.loadFromFile("Image/statuds.png");
    textures.Info_Panel.game_view.setSize(sf::Vector2f(202, 26));
    textures.Info_Panel.game_view.setTexture(&textures.Info_Panel.texture);
    textures.Info_Panel.game_view.setPosition(sf::Vector2f(50, 0));

    textures.Background.texture.loadFromFile("Image/fon.png");
    textures.Background.game_view.setSize(sf::Vector2f(390, 460));
    textures.Background.game_view.setTexture(&textures.Background.texture);
    textures.Background.game_view.setPosition(sf::Vector2f(-40, 0));

    textures.Level_Progress.texture.loadFromFile("Image/uroven.png");
    textures.Level_Progress.game_view.setSize(sf::Vector2f(168, 39));
    textures.Level_Progress.game_view.setTexture(&textures.Level_Progress.texture);
    textures.Level_Progress.game_view.setPosition(sf::Vector2f(70, 28));

    textures.Number_Level.texture.loadFromFile("Image/level.png");
    textures.Number_Level.game_view.setSize(sf::Vector2f(141, 50));
    textures.Number_Level.game_view.setTexture(&textures.Number_Level.texture);
    textures.Number_Level.game_view.setPosition(sf::Vector2f(90, 78));

    textures.Maskot_Avokado.texture.loadFromFile("Image/mascot01.png");
    textures.Maskot_Avokado.game_view.setSize(sf::Vector2f(79, 136));
    textures.Maskot_Avokado.game_view.setTexture(&textures.Maskot_Avokado.texture);
    textures.Maskot_Avokado.game_view.setPosition(sf::Vector2f(50, 58));

    textures.Maskot_Strawberry.texture.loadFromFile("Image/mascot2.png");
    textures.Maskot_Strawberry.game_view.setSize(sf::Vector2f(101, 130));
    textures.Maskot_Strawberry.game_view.setTexture(&textures.Maskot_Strawberry.texture);
    textures.Maskot_Strawberry.game_view.setPosition(sf::Vector2f(205, 64));

    textures.Key.texture.loadFromFile("Image/key.png");
    textures.Key.game_view.setSize(sf::Vector2f(40, 40));
    textures.Key.game_view.setTexture(&textures.Key.texture);
    textures.Key.game_view.setPosition(sf::Vector2f(10, 420));

    textures.Settings.texture.loadFromFile("Image/settings.png");
    textures.Settings.game_view.setSize(sf::Vector2f(40, 40));
    textures.Settings.game_view.setTexture(&textures.Settings.texture);
    textures.Settings.game_view.setPosition(sf::Vector2f(290, 420));

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
    std::vector<std::vector<tile_field>> board_textures;

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
        board_textures.push_back(row_rects);
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
                if (mousePos.x >= GAME_FIELD_X_START && mousePos.x <= GAME_FIELD_X_END &&
                    mousePos.y >= GAME_FIELD_Y_START && mousePos.y <= GAME_FIELD_Y_END)
                {
                    // Вычисляем смещение клика относительно верхнего левого угла поля
                    int offsetX = mousePos.x - GAME_FIELD_X_START;
                    int offsetY = mousePos.y - GAME_FIELD_Y_START;

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

                        if (board_textures[selected_cell.row][selected_cell.col].field_name_number == GAME_CELL_Strawberry)
                        {
                            Game_Cell_Strawberry_Light.setPosition(sf::Vector2f(x, y));
                            board_textures[selected_cell.row][selected_cell.col].field_texture = Game_Cell_Strawberry_Light;
                        }
                        else if (board_textures[selected_cell.row][selected_cell.col].field_name_number == GAME_CELL_Avocado)
                        {
                            Game_Cell_Avokado_Light.setPosition(sf::Vector2f(x, y));
                            board_textures[selected_cell.row][selected_cell.col].field_texture = Game_Cell_Avokado_Light;
                        }
                        else if (board_textures[selected_cell.row][selected_cell.col].field_name_number == GAME_CELL_Limon)
                        {
                            Game_Cell_Limon_Light.setPosition(sf::Vector2f(x, y));
                            board_textures[selected_cell.row][selected_cell.col].field_texture = Game_Cell_Limon_Light;
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

                            board_textures.clear();
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
                                board_textures.push_back(row_rects);
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
        win.draw(textures.Background.game_view);
        ////Отрисовка текстур
        win.draw(textures.Info_Panel.game_view);
        win.draw(textures.Level_Progress.game_view);
        win.draw(textures.Number_Level.game_view);
        win.draw(textures.Maskot_Avokado.game_view);
        win.draw(textures.Maskot_Strawberry.game_view);
        win.draw(textures.Key.game_view);
        win.draw(textures.Settings.game_view);
       
       // Отрисовываем все плитки
        for (const auto& row : board_textures)
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
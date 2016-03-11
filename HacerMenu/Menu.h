/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: alfon
 *
 * Created on 10 de marzo de 2016, 17:46
 */

#ifndef MENU_H
#define MENU_H

#define MAX_NUMBER_OF_ITEMS 6

#include <SFML/Graphics.hpp>
class Menu {
public:
    Menu(float width, float height);
    Menu(const Menu& orig);
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    virtual ~Menu();
    
    int GetPressedItem(){
        return selectedItemIndex;
    }
    void nuevaPartida(sf::RenderWindow &window);
    void cargarPartida(sf::RenderWindow &window);
    void controles(sf::RenderWindow &window);
    
    void creditos(sf::RenderWindow &window);
private:
    int selectedItemIndex;
    sf::Font fuente;
    
    sf::Text menu [MAX_NUMBER_OF_ITEMS];

};

#endif /* MENU_H */


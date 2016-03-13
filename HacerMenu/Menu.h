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
#include <vector>
#include <iostream>
#include <string> 


class Menu {
public:
    Menu(float width, float height);
    Menu(const Menu& orig);
    void draw(sf::RenderWindow &window);
    void moveUp(sf::Text textomenu[]);
    void moveDown(sf::Text textomenu[], int max);
   
    int run(sf::RenderWindow &window);
    void nuevaPartida(sf::RenderWindow &window);
    void cargarPartida(sf::RenderWindow &window);
    void controles(sf::RenderWindow &window);
    void opciones(sf::RenderWindow &window);
    void creditos(sf::RenderWindow &window);
    //int pulsarTecla(sf::RenderWindow &window, sf::Event event);
    void submenu(sf::RenderWindow &window);
    void mostrarOpcionesInGame(sf::RenderWindow &window);
    void guardar(sf::RenderWindow &window);
    
    
    virtual ~Menu();
    
    int GetPressedItem(){
        return selectedItemIndex;
    };
    
private:
    int selectedItemIndex;
    sf::Font fuente;
    std::vector<sf::Text*> menu;
    std::vector<sf::Text*> menuInGame;
    //sf::Text menu [MAX_NUMBER_OF_ITEMS];
    //sf::Text menuInGame [5];
    bool enPartida;
    bool enCargar;
    bool enOpciones;
    bool enCreditos;
    bool enControles;
    bool enPausa;
    bool guardando;
};

#endif /* MENU_H */
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: alfon
 * 
 * Created on 10 de marzo de 2016, 17:46
 */

#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height) {
    
    if(!fuente.loadFromFile("resources/arial.ttf")){
        exit(0);
    }
    
    menu[0].setFont(fuente);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Nueva Partida");
    menu[0].setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *1));
    
    menu[1].setFont(fuente);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Cargar Partida");
    menu[1].setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *1.75));
    
    menu[2].setFont(fuente);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Controles");
    menu[2].setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *2.5));
    
    menu[3].setFont(fuente);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Opciones");
    menu[3].setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *3.25));
    
    sf::String stringCreditos(L"Créditos");
    menu[4].setFont(fuente);
    menu[4].setColor(sf::Color::White);
    menu[4].setString(stringCreditos);
    menu[4].setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *4));
    
    menu[5].setFont(fuente);
    menu[5].setColor(sf::Color::White);
    menu[5].setString("Salir del juego");
    menu[5].setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *4.75));
    
    selectedItemIndex=0;
    
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}

void Menu::draw(sf::RenderWindow &window){
    for(int i=0; i<MAX_NUMBER_OF_ITEMS; i++){
        window.draw(menu[i]);
    }
}

void Menu::moveUp(){
    if(selectedItemIndex-1>=0){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::moveDown(){
    if(selectedItemIndex+1<MAX_NUMBER_OF_ITEMS){
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::nuevaPartida(sf::RenderWindow &window){
    sf::Texture texturaBackground;
    if (!texturaBackground.loadFromFile("resources/background.jpg"))
    {
        std::cerr << "Error cargando la imagen background.jpg";
        exit(0);
    }
    
    /***Sprites**/
    
    sf::Sprite background(texturaBackground);
    background.setPosition(0.0, 0.0);
    window.draw(background);
}

void Menu::cargarPartida(sf::RenderWindow& window){
    if(!fuente.loadFromFile("resources/arial.ttf")){
        exit(0);
    }    
    sf::Text *textoCargarPartida = new sf::Text("Aqui vendria la partida cargada", fuente); //aqui irian las lineas del layout de cargar partida
    textoCargarPartida->setPosition(window.getSize().x/2, window.getSize().y/2);
    window.clear();
    window.draw(*textoCargarPartida);
    
}

void Menu::controles(sf::RenderWindow& window){
    if(!fuente.loadFromFile("resources/arial.ttf")){
        exit(0);
    } 
    sf::Text *izquierda = new sf::Text("Moverse a la izquierda: Left/A", fuente);
    sf::Text *derecha = new sf::Text("Moverse a la derecha: Right/D", fuente);
    sf::Text *saltar = new sf::Text("Saltar: Up/W", fuente);
    sf::Text *golpear = new sf::Text("Golpear o disparar: Barra espaciadora", fuente);
    sf::Text *personaje1 = new sf::Text("Intercambiar personaje por el personaje principal: 1", fuente);
    sf::Text *personaje2 = new sf::Text("Intercambiar personaje por el primero en reserva: 2", fuente);
    sf::Text *personaje3 = new sf::Text("Intercambiar personaje por el segundo en reserva: 3", fuente);
    
    izquierda->setPosition(window.getSize().x*0.2, 100);
    derecha->setPosition(window.getSize().x*0.2, 150);
    saltar->setPosition(window.getSize().x*0.2, 200);
    golpear->setPosition(window.getSize().x*0.2, 250);
    personaje1->setPosition(window.getSize().x*0.2, 300);
    personaje2->setPosition(window.getSize().x*0.2, 350);
    personaje3->setPosition(window.getSize().x*0.2, 400);    
    window.clear();
    window.draw(*izquierda);
    window.draw(*derecha);
    window.draw(*saltar);
    window.draw(*golpear);
    window.draw(*personaje1);
    window.draw(*personaje2);
    window.draw(*personaje3);
}

void Menu::creditos(sf::RenderWindow& window){
    if(!fuente.loadFromFile("resources/arial.ttf")){
        exit(0);
    } 
    sf::Text *textocreditos = new sf::Text("Aqui apareceran los creditos", fuente);
    textocreditos->setPosition(window.getSize().x*0.3, window.getSize().y/2);
    
    window.clear();
    window.draw(*textocreditos);
}


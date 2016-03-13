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
#include <vector>
#include <iostream>
#include <string>
#include <array>
Menu::Menu(float width, float height) {
    

   
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
    
    menuInGame[0].setFont(fuente);
    menuInGame[0].setColor(sf::Color::Red);
    menuInGame[0].setString("Continuar");
    menuInGame[0].setPosition(sf::Vector2f(width*0.45,150));
    
    menuInGame[1].setFont(fuente);
    menuInGame[1].setColor(sf::Color::White);
    menuInGame[1].setString("Guardar Partida");
    menuInGame[1].setPosition(sf::Vector2f(width*0.42, 225));
    
    menuInGame[2].setFont(fuente);
    menuInGame[2].setColor(sf::Color::White);
    menuInGame[2].setString("Controles");
    menuInGame[2].setPosition(sf::Vector2f(width*0.45, 300));
    
    menuInGame[3].setFont(fuente);
    menuInGame[3].setColor(sf::Color::White);
    menuInGame[3].setString("Opciones");
    menuInGame[3].setPosition(sf::Vector2f(width*0.45, 375));
    
    menuInGame[4].setFont(fuente);
    menuInGame[4].setColor(sf::Color::White);
    menuInGame[4].setString("Volver al menu principal");
    menuInGame[4].setPosition(sf::Vector2f(width*0.35, 450));
    

    
    enPartida = false;
    enCargar = false;
    enOpciones = false;
    enCreditos = false;
    enControles = false;
    enPausa=false;
    guardando=false;
    
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}

int Menu::run(sf::RenderWindow& window){
    
    int mostrarLayout=6; //variable para poder mostrar las diferentes partes del menu principal
    int mostrarLayoutInGame = 4; //variable para controlar el menu ingame
    while(window.isOpen()){
        
        sf::Event event;
        while (window.pollEvent(event)){
            if(!enPartida && !enCargar && !enOpciones && !enCreditos && !enControles && !guardando){
                /*con este if controlamos que estemos en el menu principal donde aparecerán las opciones:
                 *Nueva Partida
                 * Cargar Partida
                 * Controles
                 * Opciones
                 * Creditos
                 * Salir del juego 
                 */
               
                switch(event.type){
                    //Si se recibe el evento de cerrar la ventana la cierro
                    case sf::Event::Closed:
                        window.close();
                        break;
                    //Se pulsó una tecla, imprimo su codigo
                    case sf::Event::KeyPressed:
                        //Verifico si se pulsa alguna tecla de movimiento
                        switch(event.key.code) {
                            //Mapeo del cursor                        
                            case sf::Keyboard::Up:
                                moveUp(menu);
                                break;

                            case sf::Keyboard::Down:
                                moveDown(menu, 6);
                                break;

                            case sf::Keyboard::Return:
                            case sf::Keyboard::Space:     
                                switch(GetPressedItem()){
                                    case 0:
                                        std::cout<<"Nueva Partida ha sido seleccionado"<<std::endl;                                    
                                        mostrarLayout = GetPressedItem();
                                        break;
                                    case 1:
                                        std::cout<<"Cargar Partida ha sido seleccionado"<<std::endl;
                                        mostrarLayout = GetPressedItem();
                                        break;
                                    case 2:
                                        std::cout<<"Controles ha sido seleccionado"<<std::endl;
                                        mostrarLayout = GetPressedItem();
                                        break;
                                    case 3:
                                        std::cout<<"Opciones ha sido seleccionado"<<std::endl;
                                        mostrarLayout = GetPressedItem();
                                        break;
                                    case 4:
                                        std::cout<<"Creditos ha sido seleccionado"<<std::endl;
                                        mostrarLayout = GetPressedItem();
                                        break;
                                    case 5:
                                        window.close();
                                        mostrarLayout = GetPressedItem();
                                        break;                                    

                                } 
                                break;



                            case sf::Keyboard::Escape:

                                break;

                            //Cualquier tecla desconocida se imprime por pantalla su código
                            default:
                                std::cout << event.key.code << std::endl;
                                break;

                        }

                }
            }if(enPartida){
                //si hemos seleccionado NuevaPartida
                if(!enPausa){
                    //estamos jugando, aqui vendria los movimientos de derecha, izquierda, salto, disparo etc
                    switch(event.type){
                        //Si se recibe el evento de cerrar la ventana la cierro
                        case sf::Event::Closed:
                            window.close();
                            break;
                        //Se pulsó una tecla, imprimo su codigo
                        case sf::Event::KeyPressed:
                            //Verifico si se pulsa alguna tecla de movimiento
                            switch(event.key.code) {
                                //Mapeo del cursor                        
                                case sf::Keyboard::Right:
                                    //std::cout<<"Me muevo a la derecha"<<std::endl;
                                    break;

                                case sf::Keyboard::Left:
                                    //std::cout<<"Me muevo a la izquierda"<<std::endl;
                                    break;
                                case sf::Keyboard::Escape:
                                    std::cout<<"Presionando Escape en pausa"<<std::endl;
                                    enPausa=true;
                                    break;

                                //Cualquier tecla desconocida se imprime por pantalla su código
                                default:
                                    std::cout << event.key.code << std::endl;
                                    break;

                            }

                    }
                }else{
                    //hemos pulsado ESC en algun momento cuando estabamos en el juego y estamos en pausa
                    switch(event.type){
                        //Si se recibe el evento de cerrar la ventana la cierro
                        case sf::Event::Closed:
                            window.close();
                            break;
                        //Se pulsó una tecla, imprimo su codigo
                        case sf::Event::KeyPressed:
                            //Verifico si se pulsa alguna tecla de movimiento
                            switch(event.key.code) {
                                //Mapeo del cursor                        
                                case sf::Keyboard::Up:
                                    moveUp(menuInGame);
                                    break;

                                case sf::Keyboard::Down:
                                    moveDown(menuInGame, 5);
                                    break;
                                case sf::Keyboard::Escape:
                                    //con esto pausamos el juego
                                    std::cout<<"Presionando Escape mientras juego"<<std::endl;
                                    enPausa=false;
                                    break;
                                case sf::Keyboard::Return:
                                case sf::Keyboard::Space:
                                    switch(GetPressedItem()){
                                        case 0:
                                            std::cout<<"Continuar"<<std::endl;                                    
                                            mostrarLayoutInGame = GetPressedItem();
                                            break;
                                        case 1:
                                            std::cout<<"Guardar"<<std::endl;
                                            guardando=true;
                                            break;
                                        case 2:
                                            std::cout<<"Controles"<<std::endl;
                                            mostrarLayoutInGame = GetPressedItem();
                                            break;
                                        case 3:
                                            std::cout<<"Opciones"<<std::endl;
                                            mostrarLayoutInGame = GetPressedItem();
                                            break;
                                        case 4:
                                            std::cout<<"Volver a menu"<<std::endl;
                                            mostrarLayoutInGame = GetPressedItem();
                                            break;
                                                                            

                                    } 
                                    break;
                                //Cualquier tecla desconocida se imprime por pantalla su código
                                default:
                                    std::cout << event.key.code << std::endl;
                                    break;

                            }

                    }
                }
                if(guardando){
                    //estamos guardando
                    switch(event.type){
                        //Si se recibe el evento de cerrar la ventana la cierro
                        case sf::Event::Closed:
                            window.close();
                            break;
                        //Se pulsó una tecla, imprimo su codigo
                        case sf::Event::KeyPressed:
                            //Verifico si se pulsa alguna tecla de movimiento
                            switch(event.key.code) {
                                //Mapeo del cursor                        


                                case sf::Keyboard::Escape:
                                    
                                    //con esto pausamos el juego
                                    std::cout<<"Presionando Escape en guardar"<<std::endl;
                                    guardando=false;
                                    break;
                                
                                //Cualquier tecla desconocida se imprime por pantalla su código
                                default:
                                    std::cout << event.key.code << std::endl;
                                    break;

                            }

                    }
                }else{
                    //salimos de guardar
                }
            }
        }
        
        window.clear();
        draw(window);
        //segun la tecla presionada 
        if(mostrarLayout == 0){
            enPartida=true;
            nuevaPartida(window);
        }
        if(mostrarLayout == 1){
            cargarPartida(window);
        }
        if(mostrarLayout == 2){
            controles(window);
        }
        if(mostrarLayout == 3){
            
        }
        if(mostrarLayout == 4){
            creditos(window);
        }
        if(enPausa){
            submenu(window);
        }
        if(mostrarLayoutInGame == 0){
            enPausa=false;
        }
        if(guardando){
            guardar(window);
        }
        if(mostrarLayoutInGame == 4){
            //aqui falta borrar el menuInGame cuando selecciono salir del juego
            mostrarLayoutInGame=5;
        }
        if(mostrarLayoutInGame == 2){
            controles(window);
        }
        if(mostrarLayoutInGame == 3){
            
        }
    
        window.display();
    }
    
    return 0;
}

void Menu::draw(sf::RenderWindow &window){
    for(int i=0; i<MAX_NUMBER_OF_ITEMS; i++){
        window.draw(menu[i]);
    }
    

}

void Menu::moveUp(sf::Text textomenu[]){
    if(selectedItemIndex-1>=0){
        textomenu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        textomenu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::moveDown(sf::Text textomenu[], int max){
    
    if(selectedItemIndex+1<max){
        textomenu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        textomenu[selectedItemIndex].setColor(sf::Color::Red);
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

    sf::Text *textocreditos = new sf::Text("Aqui apareceran los creditos", fuente);
    textocreditos->setPosition(window.getSize().x*0.3, window.getSize().y/2);
    
    window.clear();
    window.draw(*textocreditos);
}

void Menu::submenu(sf::RenderWindow& window){
    sf::RectangleShape *submenu = new sf::RectangleShape(sf::Vector2f(500, 400));
    submenu->setFillColor(sf::Color::Black);
    submenu->setPosition((window.getSize().x-submenu->getSize().x)/2, 100);

    /***Sprites**/
    
    window.draw(*submenu);
    mostrarOpcionesInGame(window);
    //std::cout<<"estoy aqui, en el metodo submenu"<<std::endl;
    

}

void Menu::mostrarOpcionesInGame(sf::RenderWindow& window){
   
    window.draw(menuInGame[0]);
    window.draw(menuInGame[1]);
    window.draw(menuInGame[2]);
    window.draw(menuInGame[3]);
    window.draw(menuInGame[4]);
}

void Menu::guardar(sf::RenderWindow &window){
    sf::RectangleShape *submenu = new sf::RectangleShape(sf::Vector2f(500, 400));
    submenu->setFillColor(sf::Color::Black);
    submenu->setPosition((window.getSize().x-submenu->getSize().x)/2, 100);
    sf::String interrogacion(L"¿");
    /***Sprites**/
    sf::Text *desea = new sf::Text(interrogacion+"Desea guardar la partida?", fuente);
    desea->setPosition(350, 150);
    sf::Text *si = new sf::Text("Si", fuente);
    si->setPosition(400, 225);
    sf::Text *no = new sf::Text("No", fuente);
    no->setPosition(600, 225);
    sf::Text *sobreescribir = new sf::Text("Ya hay una partida guardada,", fuente);
    sobreescribir->setPosition(350, 270);
    sf::Text *sobreescribir2 = new sf::Text(interrogacion+"desea sobreescribirla?", fuente);
    sobreescribir2->setPosition(350, 305);
    sf::Text *si2 = new sf::Text("Si", fuente);
    si2->setPosition(400, 345);
    sf::Text *no2 = new sf::Text("No", fuente);
    no2->setPosition(600, 345);
    sf::Text *sobrescrita = new sf::Text("Partida guardada correctamente", fuente);
    sobrescrita->setPosition(325, 400);
    
    
    window.draw(*submenu);
    window.draw(*desea);
    window.draw(*no);
    window.draw(*si);
    window.draw(*sobreescribir);
    window.draw(*sobreescribir2);
    window.draw(*no2);
    window.draw(*si2);
    window.draw(*sobrescrita);
    
  
    
}
#include <iostream>
#include "Menu.h"
#include <SFML/Graphics.hpp>

/*
 * Pantalla que muestra el menú principal del juego y el menú in-game. El menú 
 * principal definiremos las opciones de nueva partida, cargar partida, las 
 * opciones de volumen, los créditos y salir. El menú In-game cuando salga durante 
 * la partida saldrá un menú con las opciones de continuar, guardar partida y las 
 * opciones del volumen.
 */

int main(){
    
    //Creamos la ventana de juego con unas dimensiones de 1280x600
    sf::RenderWindow window(sf::VideoMode(1066, 600), "Hacer Menu!");
    
        /****PARTE DEL TEXTO****/
    //Declaro los tipos de fuentes
    sf::Font fuenteParaMenu;
    
    //Cargo las fuentes 
    if (!fuenteParaMenu.loadFromFile("resources/arial.ttf")){
        std::cerr << "Error al cargar la fuente arial.ttf";
    }
    
    Menu menu(window.getSize().x, window.getSize().y);
    
    int mostrarLayout=6; //variable para poder mostrar las diferentes partes del menu
    
    while(window.isOpen()){
        
        
        sf::Event event;
        while (window.pollEvent(event)){
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
                            menu.moveUp();
                            break;
                        
                        case sf::Keyboard::Down:
                            menu.moveDown();
                            break;
                                                   
                        case sf::Keyboard::Return:
                        case sf::Keyboard::Space:     
                            switch(menu.GetPressedItem()){
                                case 0:
                                    std::cout<<"Nueva Partida ha sido seleccionado"<<std::endl;                                    
                                    mostrarLayout = menu.GetPressedItem();
                                    break;
                                case 1:
                                    std::cout<<"Cargar Partida ha sido seleccionado"<<std::endl;
                                    mostrarLayout = menu.GetPressedItem();
                                    break;
                                case 2:
                                    std::cout<<"Controles ha sido seleccionado"<<std::endl;
                                    mostrarLayout = menu.GetPressedItem();
                                    break;
                                case 3:
                                    std::cout<<"Opciones ha sido seleccionado"<<std::endl;
                                    mostrarLayout = menu.GetPressedItem();
                                    break;
                                case 4:
                                    std::cout<<"Creditos ha sido seleccionado"<<std::endl;
                                    mostrarLayout = menu.GetPressedItem();
                                    break;
                                case 5:
                                    window.close();
                                    mostrarLayout = menu.GetPressedItem();
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
            
        }
        
        window.clear();
        menu.draw(window);
        //segun la tecla presionada 
        if(mostrarLayout == 0){
            menu.nuevaPartida(window);
        }
        if(mostrarLayout == 1){
            menu.cargarPartida(window);
        }
        if(mostrarLayout == 2){
            menu.controles(window);
        }
        if(mostrarLayout == 3){
            
        }
        if(mostrarLayout == 4){
            menu.creditos(window);
        }
    
        window.display();
    }
    
    return 0;
}
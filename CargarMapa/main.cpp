#include <SFML/Graphics.hpp>
#include <iostream>
/**
 * el ejecutable deberá leer de la fuente de información donde esté el mapa 
 * almacenado y mostrará los sprites y realizará el scroll horizontal correctamente. 
 */
int main(){
    
    //Creamos la ventana de juego
    sf::RenderWindow window(sf::VideoMode(1280, 600), "Cargar mapa!");
   
    
    
        /***Shapes***/
    sf::RectangleShape personaje(sf::Vector2f(20,20));
    sf::RectangleShape background();
    //Tranformaciones
    
    personaje.setFillColor(sf::Color::Red);
    personaje.setOutlineColor(sf::Color::Blue);
    personaje.setOutlineThickness(10);
    personaje.setOrigin(-20,-20);
    
    /****Textures****/
    sf::Texture 
    
    
    
    while(window.isOpen()){
        personaje.move(0.1, 0);
        
        sf::Event event;
        while(window.pollEvent(event)){ //CIERRE DE VENTANA
            if(event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        window.draw(personaje);
        window.display();
    }
    
    return 0;
}
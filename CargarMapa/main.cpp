#include <SFML/Graphics.hpp>

int main(){
    
    //Creamos la ventana de juego
    sf::RenderWindow window(sf::VideoMode(1280, 600), "Cargar mapa!");
    sf::CircleShape shape(380.f);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(800.0, -20.0);
    while(window.isOpen()){
        
        //printf("%f", shape.getPosition().x);
        if(shape.getPosition().x<1000)
            shape.move(0.1, 0.00); //PRUEBA
        
        sf::Event event;
        while(window.pollEvent(event)){ //CIERRE DE VENTANA
            if(event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();
        window.draw(shape);
        window.display();
    }
    
    return 0;
}
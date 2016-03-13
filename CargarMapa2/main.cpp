#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(380.f);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(800.0, -20.0);
    while(window.isOpen()){
        
        //printf("%f", shape.getPosition().x);
        if(shape.getPosition().x<820)
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
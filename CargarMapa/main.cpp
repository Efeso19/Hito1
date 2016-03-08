#include <SFML/Graphics.hpp>
#include <iostream>

#define kVel 15
/**
 * el ejecutable deberá leer de la fuente de información donde esté el mapa 
 * almacenado y mostrará los sprites y realizará el scroll horizontal correctamente. 
 */
int main(){
    
    
    //Creamos la ventana de juego
    sf::RenderWindow window(sf::VideoMode(1066, 600), "Cargar mapa!");
   
    
    
        /***Shapes***/
    sf::RectangleShape *personaje;
    personaje = new sf::RectangleShape(sf::Vector2f(20, 20));
    
    
    
    
     /****Textures****/
    sf::Texture texturaBackground;
    if (!texturaBackground.loadFromFile("resources/background.jpg"))
    {
        std::cerr << "Error cargando la imagen background.jpg";
        exit(0);
    }
    
    /***Sprites**/
    
    sf::Sprite background(texturaBackground);
    
    /***Views***/
    sf::View *camara;
    camara= new sf::View(sf::FloatRect(0,0, 1066, 600));
    //los dos primeros valores son para posicionar la camara. Los otros dos valores son para definir el alto y el ancho de la camara
    
    //Tranformaciones
    
    personaje->setFillColor(sf::Color::Red);
    personaje->setOutlineColor(sf::Color::Blue);
    personaje->setOutlineThickness(10);
    personaje->setPosition(100, 415);
    //personaje.setOrigin(-20,-20);
    
    background.setPosition(0.0, 0.0);
    
   


    //Bucle del juego
    while (window.isOpen())
    {
        //Bucle de obtención de eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            
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
                            //Escala por defecto
                            personaje->move(kVel,0);
                            if(personaje->getPosition().x >= 493 && camara->getCenter().x <=2023){
                                camara->move(kVel,0);
                            }
                            std::cout<< camara->getCenter().x<<std::endl;
                            std::cout<< "aaaaaaaaa"<<std::endl;
                            std::cout<< personaje->getPosition().x<<std::endl;
                            
                        
                        break;

                        case sf::Keyboard::Left:
                            //Reflejo vertical
                            personaje->move(-kVel,0);
                            if(personaje->getPosition().x <= 2023 && camara->getCenter().x != 533 ){
                                camara->move(-kVel,0);
                            }    
                            std::cout<< camara->getCenter().x<<std::endl;

                        break;
                        
                        /*
                        case sf::Keyboard::Up:
                            personaje.move(0,-kVel); 
                            camara.move(kVel,0);

                        break;
                         */
                        /*
                        case sf::Keyboard::Down:
                            personaje.move(0,kVel);
                            camara.move(kVel,0);
                        break;
                        */
                        
                        //Tecla ESC para salir
                        case sf::Keyboard::Escape:
                            window.close();
                        break;
                        
                        //Cualquier tecla desconocida se imprime por pantalla su código
                        default:
                            std::cout << event.key.code << std::endl;
                        break;
                              
                    }

            }
            
        }

        window.clear();
        window.draw(background);
        window.draw(*personaje);
         window.setView(*camara);
        window.display();
    }

    return 0;
}
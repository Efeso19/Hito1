#include <iostream>

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
    sf::RenderWindow window(sf::VideoMode(1280, 600), "Hacer Menu!");
    
        /****PARTE DEL TEXTO****/
    //Declaro los tipos de fuentes
    sf::Font fuenteParaMenu;
    
    //Cargo las fuentes 
    if (!fuenteParaMenu.loadFromFile("resources/arial.ttf")){
        std::cerr << "Error al cargar la fuente arial.ttf";
    }
    
    
    //Declaro el array
    sf::Text nuevaPartida("Nueva Partida", fuenteParaMenu);
    sf::Text cargarPartida("Cargar Partida", fuenteParaMenu);
    sf::Text controles("Controles", fuenteParaMenu);
    sf::Text opciones("Opciones", fuenteParaMenu);
    sf::String stringCreditos(L"Créditos");
    sf::Text creditos(stringCreditos, fuenteParaMenu);
    sf::Text salirDelJuego("Salir del Juego", fuenteParaMenu);
    
    
    //Cambio los parametros del texto
    nuevaPartida.setCharacterSize(30);
    nuevaPartida.setColor(sf::Color::White);
    
    cargarPartida.setCharacterSize(30);
    cargarPartida.setColor(sf::Color::White);
    
    controles.setCharacterSize(30);
    controles.setColor(sf::Color::White);
    
    opciones.setCharacterSize(30);
    opciones.setColor(sf::Color::White);
    
    creditos.setCharacterSize(30);
    creditos.setColor(sf::Color::White);
    
    salirDelJuego.setCharacterSize(30);
    salirDelJuego.setColor(sf::Color::White);
    
    
    
    /****POSITION****/
    nuevaPartida.setPosition(560, 150);
    cargarPartida.setPosition(555, 190);
    controles.setPosition(580, 230);
    opciones.setPosition(585, 270);
    creditos.setPosition(583, 310);
    salirDelJuego.setPosition(555, 350);
    
    while(window.isOpen()){
        
        
        sf::Event event;
        while(window.pollEvent(event)){ 
            if(event.type == sf::Event::Closed){
                window.close();
            }
                
        }
        
        window.clear();
        window.draw(nuevaPartida);
        window.draw(cargarPartida);
        window.draw(controles);
        window.draw(opciones);
        window.draw(creditos);
        window.draw(salirDelJuego);
        
        window.display();
    }
    
    return 0;
}
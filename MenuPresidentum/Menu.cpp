/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: alfon
 * 
 * Created on 14 de marzo de 2016, 11:05
 */

#include "Menu.h"
#include <iostream>


Menu::Menu(float width, float height) {
    
    
    
    if(!fuente.loadFromFile("resources/arial.ttf")){
        exit(0);
    }
    int i=0;
    for(i=0; i<6; i++){
        menu.push_back(new sf::Text("elemento", fuente));
        menu[i]->setColor(sf::Color::White);
        
    }
    menu[0]->setColor(sf::Color::Red);
    menu[0]->setString("Nueva Partida");
    menu[0]->setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *1));
    
    menu[1]->setString("Cargar Partida");
    menu[1]->setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *1.75));
    
    menu[2]->setString("Controles");
    menu[2]->setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *2.5));
    
    menu[3]->setString("Opciones");
    menu[3]->setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *3.25));
    
    sf::String stringCreditos(L"Créditos");
    menu[4]->setString(stringCreditos);
    menu[4]->setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *4));
    
    menu[5]->setString("Salir del juego");
    menu[5]->setPosition(sf::Vector2f(width*0.45, height/(MAX_NUMBER_OF_ITEMS) *4.75));
    
    for(i=0; i<5; i++){
        menuInGame.push_back(new sf::Text("elemento", fuente)); 
        menuInGame[i]->setColor(sf::Color::White);
    }    
    
    menuInGame[0]->setColor(sf::Color::Red);
    menuInGame[0]->setString("Continuar");
    menuInGame[0]->setPosition(sf::Vector2f(width*0.45,150));
    
    menuInGame[1]->setString("Guardar Partida");
    menuInGame[1]->setPosition(sf::Vector2f(width*0.42, 225));
    
    menuInGame[2]->setString("Controles");
    menuInGame[2]->setPosition(sf::Vector2f(width*0.45, 300));
    
    menuInGame[3]->setString("Opciones");
    menuInGame[3]->setPosition(sf::Vector2f(width*0.45, 375));
    
    menuInGame[4]->setString("Volver al menu principal");
    menuInGame[4]->setPosition(sf::Vector2f(width*0.35, 450));
    
    for(i=0; i<2; i++){
        guardarsino.push_back(new sf::Text("elemento", fuente)); 
        sobreescribirsino.push_back(new sf::Text("elemento", fuente)); 
    }    
    
    guardarsino[0]->setColor(sf::Color::Red);
    guardarsino[0]->setString("Si");
    guardarsino[0]->setPosition(sf::Vector2f(400,225));
    
    guardarsino[1]->setString("No");
    guardarsino[1]->setPosition(sf::Vector2f(600, 225));
    
    sobreescribirsino[0]->setColor(sf::Color::Red);
    sobreescribirsino[0]->setString("Si");
    sobreescribirsino[0]->setPosition(sf::Vector2f(400,345));
    
    sobreescribirsino[1]->setString("No");
    sobreescribirsino[1]->setPosition(sf::Vector2f(600, 345));
    
    
    
    
    
    
    opcionMenuppal=6;//para saber que opcion he seleccionado en el menuprincipal
    opcionMenuInGame=5;//para saber que opcion he seleccionado en el menu in game
    selectedItemIndex=0;//iterador para moverse hacia arriba y hacia abajo en los menus
    selectedItemIndexInPausa=0;
    selectedItemIndexGuardar=0;
    selectedItemIndexSobreescribir=2;
    
    mostrarMenuppal = true;//con esto sabemos que estamos en el menu principal
    /*
    //Aqui cargo el fondo para poder lanzar el juego. Metodo: nuevaPartida
    sf::Texture *texturaBackground;
    if (!texturaBackground->loadFromFile("resources/background.jpg"))
    {
        std::cerr << "Error cargando la imagen background.jpg";
        exit(0);
    }    
    std::cout<<"hasta aqui llgo en la funcion nuevaPartida"<<std::endl;
    background =new sf::Sprite(*texturaBackground);
    background->setPosition(0.0, 0.0);
    
    */
    
    if (!texturaBackground.loadFromFile("resources/background.jpg"))
    {
        std::cerr << "Error cargando la imagen background.jpg";
        exit(0);
    }
    background = new sf::Sprite(texturaBackground);

    //booleanos para controlar en que aprte estoy del juego.
    enPartida = false;
    enCargar = false;
    enOpciones = false;
    enCreditos = false;
    enControles = false;
    enPausa=false;
    guardando=false;
    sobreescrito=false;
            
    //para los metodos submenu y guardar
    FondomenuInPausa = new sf::RectangleShape(sf::Vector2f(500, 400));
    fondo = new sf::RectangleShape(sf::Vector2f(width, height));
    transparente= new sf::Color(255,255,255,128);
    FondomenuInPausa->setFillColor(sf::Color::Black);
    FondomenuInPausa->setPosition((width-FondomenuInPausa->getSize().x)/2, 100);
    fondo->setFillColor(*transparente);
    
    //para el metodo guardar
   
    interrogacion=L"¿";
    desea = new sf::Text(interrogacion+"Desea guardar la partida?", fuente);
    desea->setPosition(350, 150);
    
    //para el metodo sobreescribir
    sobreescribirText = new sf::Text("Ya hay una partida guardada,", fuente);
    sobreescribirText->setPosition(350, 270);
    sobreescribir2Text = new sf::Text(interrogacion+"desea sobreescribirla?", fuente);
    sobreescribir2Text->setPosition(350, 305);
    sobrescrita = new sf::Text("Partida guardada correctamente", fuente);
    sobrescrita->setPosition(325, 400);
    
    //metodo controles
    
    izquierda = new sf::Text("Moverse a la izquierda: Left/A", fuente);
    derecha = new sf::Text("Moverse a la derecha: Right/D", fuente);
    saltar = new sf::Text("Saltar: Up/W", fuente);
    golpear = new sf::Text("Golpear o disparar: Barra espaciadora", fuente);
    personaje1 = new sf::Text("Intercambiar personaje por el personaje principal: 1", fuente);
    personaje2 = new sf::Text("Intercambiar personaje por el primero en reserva: 2", fuente);
    personaje3 = new sf::Text("Intercambiar personaje por el segundo en reserva: 3", fuente);
    
    izquierda->setPosition(width*0.2, 100);
    derecha->setPosition(width*0.2, 150);
    saltar->setPosition(width*0.2, 200);
    golpear->setPosition(width*0.2, 250);
    personaje1->setPosition(width*0.2, 300);
    personaje2->setPosition(width*0.2, 350);
    personaje3->setPosition(width*0.2, 400); 
    
    //para creditos
    textocreditos = new sf::Text("Aqui apareceran los creditos", fuente);
    textocreditos->setPosition(width*0.3, height/2);
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}

int Menu::run(sf::RenderWindow &window){
    
      
    while(window.isOpen()){
        
       
        sf::Event event;
        while(window.pollEvent(event)){ 
            
            teclas(window, event);
        }
        
        
        render(window);

    }
    
    
  
    return 0;
}

void Menu::render(sf::RenderWindow &window){
    window.clear();
    if(mostrarMenuppal){

        
        std::cout<<"-------------------------------------"<<std::endl;
        //enPausa=false;
        
        draw(window, menu);
        if(opcionMenuppal!=6){
            //actualizamos el valor de mostrar menuppal
            mostrarMenuppal=false;
        } 
    }else{
        if(opcionMenuppal==0){
            //dibujamos el juego
            enPartida=true;
            nuevaPartida(window);
            if(enPausa){
                //si estoy pausado me pinta el menuingame
                submenu(window); 
                if(opcionMenuInGame==0){
                    enPausa=false;
                    opcionMenuInGame=5;
                }if(opcionMenuInGame==1){
                    guardar(window);
                    if(guardando){
                        sobreescribir(window);
                        if(sobreescrito){
                            sobreescritocorrectamente(window);
                        }
                    }
                }
            }
            
        }
        if(opcionMenuppal==1){
            //cargarPartida(window);
        }
        if(opcionMenuppal==2 || enControles){
            //dibujamos el juego
            enControles=true;
            controles(window);
            /*std::cout<<"Viendo que valor tiene las variables"<<std::endl;
            std::cout<<enPartida<<std::endl;
            std::cout<<enPausa<<std::endl;
            std::cout<<enControles<<std::endl;*/
        }
        if(opcionMenuppal==3 || enOpciones){
            opciones(window);
            enOpciones=true;
            
        }
        if(opcionMenuppal==4 || enCreditos){
            creditos(window);
            enCreditos=true;
        }
        if(opcionMenuppal==5){
            window.close();
        }   
    }
    //estoy mostrando la opcion seleccionada en el menu principal
    std::cout<<mostrarMenuppal<<std::endl;
    window.display();
}

void Menu::draw(sf::RenderWindow& window, std::vector<sf::Text*> menu){

    for(sf::Text* i : menu){
         window.draw(*i);
    }
}

void Menu::teclas(sf::RenderWindow& window, sf::Event event){
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
                    if(opcionMenuInGame==1){
                        //estoy guardando la partida
                        if(!guardando){
                            moveDown(guardarsino, selectedItemIndexGuardar);
                        }else{
                            moveDown(sobreescribirsino, selectedItemIndexSobreescribir);
                        }
                    }
                break;

                case sf::Keyboard::Left:
                    if(opcionMenuInGame==1){
                        //estoy guardando la partida
                        if(!guardando){
                            moveUp(guardarsino, selectedItemIndexGuardar);
                        }else{
                            moveUp(sobreescribirsino, selectedItemIndexSobreescribir);
                        }
                    }           
                break;

                case sf::Keyboard::Up:
                    if(mostrarMenuppal){
                        moveUp(menu, selectedItemIndex);
                    }
                    if(enPausa){
                        moveUp(menuInGame, selectedItemIndexInPausa);
                    }
                break;

                case sf::Keyboard::Down:
                    if(mostrarMenuppal){
                        moveDown(menu, selectedItemIndex);
                    }
                    if(enPausa){
                        moveDown(menuInGame, selectedItemIndexInPausa);
                    }
                break;
                    
                case sf::Keyboard::Return:
                case sf::Keyboard::Space:                    
                    if(mostrarMenuppal){
                        opcionMenuppal=GetPressedItem();
                    }
                    if(enPausa){
                        if(opcionMenuInGame!=1){
                            if(GetPressedItemInPausa()==2){
                                enControles=true;
                                selectedItemIndexInPausa=0;
                                    int i=0;
                                    for(i=0; i<menuInGame.size(); i++){
                                        if(GetPressedItem()==i){
                                            menuInGame[i]->setColor(sf::Color::Red);
                                        }else{
                                            menuInGame[i]->setColor(sf::Color::White);
                                        }   
                                    }
                            }
                            if(GetPressedItemInPausa()==3){
                                enOpciones=true;
                                selectedItemIndexInPausa=0;
                            }
                            if(GetPressedItemInPausa()==4){
                                std::cout<<"he presionado salir al menu principal"<<std::endl;
                                mostrarMenuppal=true;
                                enPausa=false;
                                enPartida=false;
                                opcionMenuppal=6;
                            }
                            opcionMenuInGame=GetPressedItemInPausa();
                            selectedItemIndexInPausa=0;
                            selectedItemIndexGuardar=0;
                            selectedItemIndexSobreescribir=0;
                            guardarsino[0]->setColor(sf::Color::Red);
                            guardarsino[1]->setColor(sf::Color::White);
                            sobreescribirsino[0]->setColor(sf::Color::Red);
                            sobreescribirsino[1]->setColor(sf::Color::White);
                        }else{
                            if(guardando && GetPressedItemSobreescribir()==0 && !sobreescrito){
                                
                                sobreescrito=true;
                            }
                            if(GetPressedItemGuardar()==0){
                                guardando=true;
                            } 
                            
                        }
                    }
   
                break;

                //Tecla ESC para salir
                case sf::Keyboard::Escape:
                    if(mostrarMenuppal){
                        window.close();
                    }
                    if(enPartida){
                        if(enPausa){
                            selectedItemIndexInPausa=0;
                            int i=0;
                            for(i=0; i<menuInGame.size(); i++){
                                if(GetPressedItem()==i){
                                    menuInGame[i]->setColor(sf::Color::Red);
                                }else{
                                    menuInGame[i]->setColor(sf::Color::White);
                                }   
                            }
                            if(opcionMenuInGame==1){
                                opcionMenuInGame=5;
                                std::cout<<"Saliendo de guardar"<<std::endl;
                                guardando=false;
                                sobreescrito=false;
                            }else{
                                if(opcionMenuInGame==2){
                                    
                                    enControles=false;
                                }
                                if(opcionMenuInGame==3){
                                    enOpciones=false;
                                }
                                else{
                                    enPausa=false;
                                    std::cout<<"Ya no estoy en pausa"<<std::endl;
                                }
                               
                            }
                            
                        }else{
                            enPausa=true;
                            std::cout<<"Estoy en pausa"<<std::endl;
                            
                        }
                        
                    }  
                    if(enControles){
                        if(enPausa){
                            enControles=false;
                        }else{
                            mostrarMenuppal=true;
                            enControles=false;
                            opcionMenuppal=6;
                            
                        }
                    }
                    if(enOpciones){
                        enOpciones=false;
                        opcionMenuppal=6;
                        mostrarMenuppal=true;
                    }
                    if(enCreditos){
                        enCreditos=false;
                        opcionMenuppal=6;
                        mostrarMenuppal=true;
                    }


                break;

                //Cualquier tecla desconocida se imprime por pantalla su código
                default:
                    std::cout << event.key.code << std::endl;
                break;

            }

    }
    
}

void Menu::moveUp(std::vector<sf::Text*> menu, int &iterator){
    if(iterator-1>=0){
        menu[iterator]->setColor(sf::Color::White);
        iterator--;
        menu[iterator]->setColor(sf::Color::Red);
    }    
}

void Menu::moveDown(std::vector<sf::Text*> menu, int &iterator){
    
    if(iterator+1<menu.size()){
        menu[iterator]->setColor(sf::Color::White);
        iterator++;
        menu[iterator]->setColor(sf::Color::Red);
    }
}

void Menu::nuevaPartida(sf::RenderWindow &window){
    //Aqui cargo el fondo para poder lanzar el juego. Metodo: nuevaPartida
        
    //std::cout<<"hasta aqui llego en la funcion nuevaPartida"<<std::endl;
    //cargartextura(texturaBackground, background);// de momento no tengo que usarlo
    window.draw(*background);
}

void Menu::submenu(sf::RenderWindow& window){
    
    
    window.draw(*fondo);//para poder una transparencia
    window.draw(*FondomenuInPausa);
    draw(window, menuInGame);
    //std::cout<<"estoy aqui, en el metodo submenu"<<std::endl;
    

}

void cargartextura(sf::Texture textura, sf::Sprite &sprite){
    //metodo que no he de usar porque cargo la textura en el contructor
}

void Menu::guardar(sf::RenderWindow &window){
 
    window.draw(*FondomenuInPausa);
    window.draw(*desea);
    window.draw(*guardarsino[0]);
    window.draw(*guardarsino[1]);
    
}

void Menu::sobreescribir(sf::RenderWindow& window){
   
    window.draw(*sobreescribirText);
    window.draw(*sobreescribir2Text);
    window.draw(*sobreescribirsino[0]);
    window.draw(*sobreescribirsino[1]);
    
}

void Menu::sobreescritocorrectamente(sf::RenderWindow &window){
    window.draw(*sobrescrita);
}

void Menu::controles(sf::RenderWindow& window){

    window.clear();
    window.draw(*izquierda);
    window.draw(*derecha);
    window.draw(*saltar);
    window.draw(*golpear);
    window.draw(*personaje1);
    window.draw(*personaje2);
    window.draw(*personaje3);
    
}

void Menu::opciones(sf::RenderWindow& window){
    
    window.clear(sf::Color::Blue);
    
}

void Menu::creditos(sf::RenderWindow& window){
   
    window.draw(*textocreditos);    
    
}


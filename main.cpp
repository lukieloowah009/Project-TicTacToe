
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Player.hpp"
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;


int main(int, char const**)
{
    // Create the main window
    RenderWindow window(VideoMode(1920, 1080), "Shippuden TicTacToe");

    //loading textures
    int option;
    cout<<"Choose Theme:" <<endl;
    cout<<"1. Naruto Shippuden" <<endl;
    cout<< "2. One Punch Man" <<endl;
    cin>>option;
    
    
    Texture texture1;
    
    if(option == 1){
        if(!texture1.loadFromFile(resourcePath() + "wallpaper2.jpg")){
            return EXIT_FAILURE;
        }
    }
    else{
        if(!texture1.loadFromFile(resourcePath() + "wallpaper3.jpg")){
            return EXIT_FAILURE;
        }
    }
        
    Sprite wallpaper (texture1);
    
    Texture texture2;
    if(!texture2.loadFromFile(resourcePath() + "grid2.png" , IntRect(0 , 0 , 420 , 415))){
        return EXIT_FAILURE;
    }
    Sprite grid (texture2);
    
    Texture texture3;
    Texture texture4;
    if (option == 1){
        if(!texture3.loadFromFile(resourcePath() + "kunai.png")){
            return EXIT_FAILURE;
        }
   
        if(!texture4.loadFromFile(resourcePath() + "shuriken.png")){
            return EXIT_FAILURE;
        }
        
    }
    else{
        if(!texture3.loadFromFile(resourcePath() + "saitama.jpg")){
            return EXIT_FAILURE;
        }
        
        if(!texture4.loadFromFile(resourcePath() + "genos.png")){
            return EXIT_FAILURE;
        }
    }
    
    
    Sprite kunai (texture3);
    Sprite shuriken (texture4);
    
    Texture texture5;
    if(!texture5.loadFromFile(resourcePath() + "player1.png")){
        return EXIT_FAILURE;
    }
    Sprite player1Victory (texture5);
    
    Texture texture6;
    if(!texture6.loadFromFile(resourcePath() + "player2.png")){
        return EXIT_FAILURE;
    }
    Sprite player2Victory (texture6);
    
    
    
    
    
    
    
    

    // Load a music to play
    Music music;
    
    if(option == 1){
        if (!music.openFromFile(resourcePath() + "Music.ogg")) {
            return EXIT_FAILURE;
        }
    }
    else{
        if (!music.openFromFile(resourcePath() + "Music2.ogg")) {
            return EXIT_FAILURE;
        }
    }
    
    //Sound effect
//    sf::SoundBuffer buffer;
//    buffer.loadFromFile("clash.ogg");
//    sf::Sound sound;
//    sound.setBuffer(buffer);
    
    
    //Create objects
    Player Player1;
    Player Player2;
    Player1.SetGC();
    Player2.SetGC();
    
    Player1.playerturn = true;
    Player2.playerturn = false;
    
    //Victory coordinates
    vector<vector<int>>Vic1;
    vector<vector<int>>Vic2;
    vector<vector<int>>Vic3;
    vector<vector<int>>Vic4;
    vector<vector<int>>Vic5;
    vector<vector<int>>Vic6;
    vector<vector<int>>Vic7;
    vector<vector<int>>Vic8;
    
    for ( int i = 500 ; i <= 780  ; i += 140){
        vector<int>temp { 750 , i};
        vector<int>temp2 { 890 , i};
        vector<int>temp3 { 1030 , i};
        Vic1.push_back(temp);
        Vic2.push_back(temp2);
        Vic3.push_back(temp3);
    }
    for ( int i = 750 ; i <= 1030  ; i += 140){
        vector<int>temp { i , 500};
        vector<int>temp2 { i , 640};
        vector<int>temp3 { i , 780};
        Vic4.push_back(temp);
        Vic5.push_back(temp2);
        Vic6.push_back(temp3);
    }
    int j1 = 500;
    int j2 = 780;
    for (int i = 750 ; i < 1030 ; i+=140){
        vector<int>temp { i , j1};
        Vic7.push_back(temp);
        j1+=140;
        
        vector<int>temp2 {i , j2};
        Vic8.push_back(temp2);
        j2-=140;
    }
    
    
    
    
    
    
    //Left click coordinates
    int Lx , Ly;
    
    bool draw = false;

    // Play the music
    music.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            else if (event.type == Event::MouseButtonPressed){
                //Input
                if (event.mouseButton.button == Mouse::Left){
                    Lx = Mouse::getPosition(window).x;
                    Ly = Mouse::getPosition(window).y;
                    
                    //sound.play();
                    
                    if(Player1.coord.size() == 0 || Player1.coord.size() == Player2.coord.size()){
                        
                        for ( int i = 750 ; i <= 1030 ; i += 140){
                            for ( int j = 500 ; j <= 780 ; j+=140){
                                if(Lx >= i && Lx <= i+140 && Ly >= j && Ly <= j + 140){
                                    vector<int> temp;
                                    temp.push_back(i);
                                    temp.push_back(j);
                                    
                                    //checking if it already exist
                                    bool push = true;
                                    for ( int k = 0 ; k < Player2.coord.size() ; k++){
                                        if( i == Player2.coord[k][0] && j == Player2.coord[k][1])
                                            push = false;
                                    }
                                    if(push)
                                        Player1.coord.push_back(temp);
                                }
                            }
                        }
                    }
                    else if (Player1.coord.size() > Player2.coord.size()){
                        for ( int i = 750 ; i <= 1030 ; i += 140){
                            for ( int j = 500 ; j <= 780 ; j+=140){
                                if(Lx >= i && Lx <= i+140 && Ly >= j && Ly <= j + 140){
                                    vector<int> temp;
                                    temp.push_back(i);
                                    temp.push_back(j);
                                    
                                    
                                    //checking if it exists
                                    bool push = true;
                                    for ( int k = 0 ; k < Player1.coord.size() ; k++){
                                        if( i == Player1.coord[k][0] && j == Player1.coord[k][1])
                                            push = false;
                                    }
                                    if(push)
                                        Player2.coord.push_back(temp);
                                }
                            }
                        }
                    }
                    
                }
            }
        }

        // Clear screen
        window.clear(Color(255 , 255 , 255, 255));

        // Draw the sprite
        window.draw(wallpaper);
        
        
        
        //Drawing Grid
        grid.setPosition(750,500);
        window.draw(grid);
        
        
        
        //Draw the (player1) (kunai/saitama)
        for ( int i = 0 ; i < Player1.coord.size() ; i++){
            kunai.setPosition(Player1.coord[i][0] + 10 , Player1.coord[i][1] + 10);
            window.draw(kunai);
        }
        
        
        //Draw the (player2) (shuriken/genos)
        if(option == 1){
            for ( int i = 0 ; i < Player2.coord.size() ; i++){
                shuriken.setPosition(Player2.coord[i][0] + 10, Player2.coord[i][1] + 10);
                window.draw(shuriken);
            }
        }
        else{
            for ( int i = 0 ; i < Player2.coord.size() ; i++){
                shuriken.setPosition(Player2.coord[i][0] + 10, Player2.coord[i][1] + 30);
                window.draw(shuriken);
            }
        }
        
        //Checking victory condition
            //Player1
        
        

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}

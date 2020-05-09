//include librrary
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<math.h>

#include "classes.h"

sf::RenderWindow window( sf::VideoMode( 1920, 1080), "MEME GENERATOR", sf::Style::Close );
sf::Event ev;

int main()
{
    window.setFramerateLimit(60);
    Text text_up;
    Text text_down;
    text_up.load_font("font.ttf");
    text_down.load_font("font.ttf");
    text_up.text.setOutlineThickness(4);
    text_down.text.setOutlineThickness(4);
    text_up.text.setString("12224");
    text_up.text.setOutlineColor(sf::Color::Black);
    text_up.text.setCharacterSize(0);

    int max_font = 200;
    int min_font = 30;
    while(true)
    {
        //event loop
        while(window.pollEvent(ev))
        {
            //close window
            if(ev.type == ev.Closed)
            {
                return 0;
            }
        }

            //change text size
            if(text_up.text.getCharacterSize() < min_font)
            {
                text_up.text.setCharacterSize(min_font);
            } else if(text_up.text.getCharacterSize() > max_font)
            {
                text_up.text.setCharacterSize(max_font);
            }

            //draw window & stuff
            window.clear(sf::Color::Blue);
            text_up.draw();
            text_down.draw();
            window.display();
    }
    
}
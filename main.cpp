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
            //draw window & stuff
            window.clear();
            window.display();
    }
    
}
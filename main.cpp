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
    //Text class
    Text text_up;
    Text text_down;
    
    //set text defould variables
    text_up.load_font("font.ttf");
    text_down.load_font("font.ttf");
    text_up.text.setOutlineThickness(4);
    text_down.text.setOutlineThickness(4);
    text_up.text.setString("12224");
    text_up.text.setOutlineColor(sf::Color::Black);
    text_up.text.setCharacterSize(0);

    //set maximum text size and minimum text size
    int max_font = 200;
    int min_font = 30;

    //string for text
    std::string text_up_string;
    std::string text_up_string;

    //mode of text (false = edit up text, true = edit down text)
    bool mode;

    //set frame limit to 60fps
    window.setFramerateLimit(60);

    //game loop
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

         /*change text size*/
            //change up text size to minimum or maximum
        if(text_up.text.getCharacterSize() < min_font)
        {
            text_up.text.setCharacterSize(min_font);
        } else if(text_up.text.getCharacterSize() > max_font)
        {
            text_up.text.setCharacterSize(max_font);            
        }
             //change down text size to minimum or maximum
        if(text_down.text.getCharacterSize() < min_font)
        {
           text_down.text.setCharacterSize(min_font);
        } else if(text_down.text.getCharacterSize() > max_font)
        {
            text_down.text.setCharacterSize(max_font);
        }

        //draw window & stuff
            //clear window
        window.clear(sf::Color::Blue);
            //draw text
        text_up.draw();
        text_down.draw();
            //dispaly window
        window.display();
    }
    
}
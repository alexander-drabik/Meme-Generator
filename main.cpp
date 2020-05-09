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
    
    //set text defout variables
    text_up.load_font("font.ttf");
    text_down.load_font("font.ttf");
    text_up.text.setOutlineThickness(4);
    text_down.text.setOutlineThickness(4);
    text_up.text.setString("[enter text here");
    text_up.text.setOutlineColor(sf::Color::Black);
    text_up.text.setCharacterSize(0);

    //set maximum text size and minimum text size
    int max_font = 200;
    int min_font = 30;

    //string for text
    std::string text_up_string;
    std::string text_down_string;

    //mode of text (false = edit up text, true = edit down text)
    bool mode = false;

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

            //type to string
            if(ev.type == sf::Event::TextEntered)
            {
                if(mode == false)
                {
                    //if backspace is pressed delete last character
                    if(ev.text.unicode == 8)
                    {
                        if(text_up_string.length()>0)
                        {
                            text_up_string.pop_back();
                        }
                    } else
                    {
                        //if not, add last character to string
                        text_up_string+=ev.text.unicode;
                    }
                    text_up.text.setString(text_up_string);
                } else
                {
                    //if backspace is pressed delete last character
                    if(ev.text.unicode == 8)
                    {
                        if(text_down_string.length()>0)
                        {
                            text_down_string.pop_back();
                        }
                    } else
                    {
                        //if not, add last character to string
                        text_down_string+=ev.text.unicode;
                    }
                    text_down.text.setString(text_down_string);
                }
                
            }
            
        }

        //change mode when enter is clicked
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            mode = true;
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
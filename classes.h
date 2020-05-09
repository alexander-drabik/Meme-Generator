#include<iostream>
#include<SFML/Graphics.hpp>

#ifndef classes_h;
#define classes_h;

extern sf::RenderWindow window;

class Text
{
public:
  sf::Text text;
  sf::Font font;

  void load_font(std::string path)
  {
    font.loadFromFile(path);
    text.setFont(font);
  }
  void draw()
  {
    window.draw(text);
  }
};

#endif
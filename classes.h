#include<iostream>
#include<SFML/Graphics.hpp>

#ifndef classes_h;
#define classes_h;

//add window from main.cpp
extern sf::RenderWindow window;

//this class is making meme text
class Text
{
public:
  sf::Text text;
  sf::Font font;
  //loading font from path
  void load_font(std::string path)
  {
    font.loadFromFile(path);
    text.setFont(font);
  }
  //drawing text
  void draw()
  {
    window.draw(text);
  }
};

void save()
{
  sf::Texture texture;
  texture.create(window.getSize().x, window.getSize().y);
  texture.update(window);
  texture.copyToImage().saveToFile("meme.png");
}
#endif
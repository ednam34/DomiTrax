#ifndef TRAXGRIDGRAPHICS_HPP
#define TRAXGRIDGRAPHICS_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "../../hpp/traxGrid.hpp"

struct traxTuileGraphics {
    sf::Texture texture;
    sf::Texture Tilecolor;
    std::array<sf::Texture, 7> textures;
    std::array<TilesDetails, 7> tilesDetails;
};

class traxGridGraphics {
   public:
    // make traxGridGraphics constructor take in a traxGrid object
    // traxGridGraphics();
    traxGridGraphics(traxGrid grid, sf::RenderWindow& window);
    //~traxGridGraphics();
    void renderGG(sf::RenderWindow& window, traxGrid grid);
    // Grid of traxGridGraphics
    void rotateTile(traxGrid grid);

   private:
    std::mt19937 rng;
    sf::Texture generateRandomTexture();
    int generateRandomTextureIndex();
};

#endif
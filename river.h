#pragma once
#include "SFML/Graphics.hpp"
#include "const.h"
class River {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed{ sf::Vector2f(RIVER_SPEED_X, RIVER_SPEED_Y) };
public:
	River(float x, float y) {
		texture.loadFromFile(IMAGES_FOLDER + RIVER_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setScale(RIVER_X, RIVER_Y);
		sprite.setPosition(x, y);
	}
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().y >= WINDOW_HEIGHT) {
			sprite.setPosition(0.f, -WINDOW_HEIGHT);
		}
	}
};
#include "player.h"
#include "const.h"
Player::Player() {
	texture.loadFromFile(IMAGES_FOLDER + SHIP_FILE_NAME);
	sprite.setTexture(texture);
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	sprite.setPosition(WINDOW_WIDTH / 2 - 50,
		WINDOW_HEIGHT - 150);
}
void Player::update() {
	sf::Vector2f position = sprite.getPosition();
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		position.x > 0)
		sprite.move(-PLAYER_SPEED_X, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		position.x < WINDOW_WIDTH - g_bounds.width)
		sprite.move(PLAYER_SPEED_X, 0.f);

	
}
void Player::draw(sf::RenderWindow& window) { window.draw(sprite); }
sf::FloatRect Player::getHitBox() { return sprite.getGlobalBounds(); }
void Player::setDel(bool a) { del = a; }
bool Player::getDel() { return del; }
sf::Vector2f Player::getPosition() { return sprite.getPosition(); }
void Player::decreaseHp(size_t dmg) { hp -= dmg; }
void Player::increaseHp(size_t add_hp) { hp += add_hp; }
int Player::getHp() { return hp; }
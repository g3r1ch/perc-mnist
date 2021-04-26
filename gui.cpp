#include "gui.h"


Gui::Gui(int x, int y, string name) {
	window.create(sf::VideoMode(x, y), name);
	weight = x;
	height = y;
	window.clear(sf::Color(50, 50, 125, 125));
}

void Gui::matrix_from_double_vec(vector<double> aInp,int xx,int yy) {
	sf::VertexArray quad(sf::Quads, 4);
	window.clear();
	window.clear(sf::Color(50, 50, 125, 125));
	int gen = 0;
	quad[0].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
	quad[1].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
	quad[2].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);
	quad[3].color = sf::Color::Color(255 / 2, 255 / 2, 255 / 2);

	for (int x = 0; x < xx * 10; x += 10) {
		for (int z = 0; z < yy * 10; z += 10, gen++) {
			quad[0].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);
			quad[1].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);
			quad[2].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);
			quad[3].color = sf::Color::Color((1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255, (1. / (1. + exp(-(aInp[gen])))) * 255);
			
			quad[0].position = sf::Vector2f(z+20, x + 20);
			quad[1].position = sf::Vector2f(z + 8 + 20, x + 20);
			quad[2].position = sf::Vector2f(z + 8 + 20, x + 8 + 20);
			quad[3].position = sf::Vector2f(z + 20, x + 8 + 20);

			window.draw(quad);
		}
	}
}

int Gui::graphik(vector<double> aInp) {
	if (aInp.size() > weight)
		return 1;

	window.clear();

	sf::VertexArray line(sf::Lines, 2);
	line[0].color = sf::Color::White;
	line[1].color = sf::Color::White;

	for (int i = 0, gen = 0; gen < aInp.size()-1; i+=2,gen++) {
		line[0].position = sf::Vector2f(i, height - abs(aInp[gen]) * 500);
		line[1].position = sf::Vector2f(i + 2, height - abs(aInp[gen + 1]) * 500);
		window.draw(line);
	}

	return 0;
}

void Gui::render() {
	window.display();
}

Gui::EventType Gui::evnt() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window.close();
			return Gui::EventType::CLOSE;
		}
		if (event.type == sf::Event::KeyPressed)
		{

			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
				return Gui::EventType::CLOSE;
			}
			else if (event.key.code == sf::Keyboard::P) {
				return Gui::EventType::PAUSE;
			}
			else if (event.key.code == sf::Keyboard::R) {
				return Gui::EventType::PRINT;
			}
			else if (event.key.code == sf::Keyboard::Q) {
				return Gui::EventType::RET;
			}
			else if (event.key.code == sf::Keyboard::N) {
				return Gui::EventType::NEXT;
			}
		}
	}
	return Gui::EventType::NON;
}

int Gui::isOpen() {
	if (window.isOpen())
		return 1;

	return 0;
}

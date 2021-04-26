#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
class Gui {
private:
	int weight,height;
	sf::RenderWindow window;
public:
	enum EventType {CLOSE, PAUSE, PRINT, NON, RET, NEXT};
	Gui(int x = 800, int y = 600, string name = "default");
	void matrix_from_double_vec(vector<double> aInp,int xx,int yy);
	int graphik(vector<double> aInp);
	void render();
	int isOpen();
	EventType evnt();
};
#endif // !GUI_H

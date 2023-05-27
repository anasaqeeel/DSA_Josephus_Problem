//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <cmath>
//#include<utility>
//using namespace std;
//#define PI 3.14159 
//template <typename T>
//struct node {
//	T data;
//	node* next;
//};
//template <typename T>
//class queue {
//	node<T>* top;
//	node<T>* tail;
//	int c = 0;
//public:
//	queue() {
//		top = tail = NULL; c = 0;
//	}
//	void push(T x) {
//		node<T>* t = new node<T>;
//		t->data = x;
//		t->next = NULL;
//		if (tail == NULL) {
//			tail = t;
//			top = t;
//		}
//		else {
//			tail->next = t;
//			tail = t;
//		}
//		c++;
//	}
//	T pop() {
//		if (!isempty()) {
//			node<T>* y = top;
//			top = top->next;
//			c--;
//			return y->data;
//		}
//		else {
//			cout << "empty!";
//		}
//	}
//	bool isempty() {
//		if (top == NULL) {
//			return 1;
//		}
//		return 0;
//	}
//	void print() {
//		node<T>* p = top;
//		while (p != NULL) {
//			cout << p->data << " "; p = p->next;
//		}
//	}
//	int size() {
//		return c;
//	}
//
//};
//int main() {
//	float x = 0, y = 0;
//	int cc = 0;
//	int input, k, i = 0, ki = 0;
//	bool f = 0, okie = 0;
//	sf::Sprite temp1;
//
//	queue<sf::Sprite> q1;
//	queue<sf::Sprite> q2;
//	queue<sf::Sprite> tq;
//
//
//	sf::Event a;
//	sf::Texture  img1, img;
//
//	cout << "enter the number of patricipants >>: ";
//	cin >> input;
//	cout << "enter the value of K >>: ";
//	cin >> k;
//	sf::Sprite* ab1 = new sf::Sprite[input];
//	sf::Sprite* ab2 = new sf::Sprite[input];
//
//	sf::RenderWindow win(sf::VideoMode(1250,600), " SFML! ", sf::Style::Default);
//	//img.loadFromFile("11.png");K
//	img1.loadFromFile("11.png");
//	//sf::CircleShape cirle(275, 375);
//	win.setFramerateLimit(1);
//	sf::Sprite tt;
//	double ang = (2 * PI) / input;
//
//	for (int i = 0; i < input; i++) {
//		double angle = i * ang;
//		x = 375 + 350 * cos(angle);
//		y = 275 + 250 * sin(angle);
//		ab1[i].setTexture(img1);
//		ab1[i].setPosition(x,y);
//		ab1[i].setColor(sf::Color::Red);
//		ab1[i].setScale(0.3, 0.3);
//		q1.push(ab1[i]);
//	}
//	for (int i = 0; i < input; i++) {
//		double angle = i * ang;
//		x = 375 + 350 * cos(angle);
//		y = 275 + 250 * sin(angle);
//		ab2[i].setTexture(img);
//		ab2[i].setPosition(x, y);
//		//ab2[i].setColor(sf::Color::Red);
//		ab2[i].setScale(0.3, 0.3);
//		q2.push(ab2[i]);
//	}
//	
//	while (win.isOpen())
//	{
//        while (win.pollEvent(a)) {
//            switch (a.type)
//            {
//            case sf::Event::Closed:
//                win.close();
//                break;
//            }
//        }
//		if (q1.isempty()||q1.size() <= 1) {
//			continue;
//		}
//		/*else {
//			q1.pop();
//			while(!q1.isempty()) {
//				sf::Sprite ss = q1.pop();
//				win.draw(ss);
//			}
//			win.display();
//		}*/
//		/*else if  (okie != 1) {*/
//			while (q1.size()!=1) {
//				if (i == k - 1) {
//					
//					q1.pop();
//					temp1 = q2.pop();
//					q2.push(temp1);
//
//					/*if (q1.size() == 1) {
//					
//					}
//					else {
//						q2.push(temp1);
//					}*/
//										
//					/*if ((ki++)==(k)-2) {
//						temp1 = q2.pop(); ki--; 
//					}
//					else {
//						
//
//					}*/
//
//					
//					ki++;
//					f = 1;
//					cc = 1;
//					
//				}
//				else {
//					q1.push(q1.pop());
//					q2.push(q2.pop());
//				}
//				if (f == 1) {
//					i = 0; f = 0;
//				}
//				else { i++; }
//
//				//while (q1.size() != 0()) {
//				//	tq.push(q1.pop());
//				//}
//				//while (!tq.isempty()) {
//				//	sf::Sprite temp = tq.pop();
//				//	q1.push(temp);
//				//	win.draw(tq.pop());
//				//}
//				//win.draw(temp1); 
//				///*if (cc == 1) {
//				//	
//				//}*/
//				//win.display();
//				//okie = 1;
//				//temp1 = tt;
//			}
//		int eik = 0;
//		while (!q1.isempty()) {
//			sf::Sprite ss = q1.pop();
//			win.draw(ss);
//		}
//
//		while (!q2.isempty()) {
//			sf::Sprite ss = q2.pop();
//			win.draw(ss);
//		}
//		win.display();
//		/*if(q1.isempty()){
//		}*/
//		/*for (int i = 0; i < input; i++) {
//			sf::Sprite temp = q1.pop();
//			sf::Sprite temp1 = q2.pop();
//			win.draw(temp);
//			win.draw(temp1);
//		}	
//		win.display();*/
//	}
//    return 0;
//}
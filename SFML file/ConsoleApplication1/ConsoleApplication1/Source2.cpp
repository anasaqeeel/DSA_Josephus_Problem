#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include<utility>

#define PI 3.14159 

using namespace sf;

template <typename T>
struct node
{
    T data;
    node* next;
    node(T input)
    {
        data = input;
        next = nullptr;
    }
};

template <typename T>
class Queue
{
private:
    node<T>* front, * rear;
    int size;

public:
    Queue()
    {
        front = nullptr;
        rear = front;
        size = 0;
    }
    Queue(T input)
    {
        front = new node<T>(input);
        rear = front;
        size = 1;
    }
    bool enqueue(T input)
    {
        if (size == 0)
        {
            front = new node<T>(input);
            rear = front;
            size = 1;
        }
        else
        {
            front->next = new node<T>(input);
            front = front->next;
            size++;
        }
        return 1;
    }
    bool dequeue()
    {
        if (size == 0)
        {
            return 0;
        }
        else if (size == 1)
        {
            delete rear;
            front = nullptr;
            rear = nullptr;
            size = 0;
        }
        else
        {
            node<T>* temp = rear;
            rear = rear->next;
            delete temp;
            size--;
        }
        return 1;
    }

    bool isEmpty()
    {
        return (size == 0);
    }
    ~Queue()
    {
        while (rear != nullptr)
        {
            node<T>* temp = rear->next;
            delete rear;
            rear = temp;
        }
        front = nullptr;
    }
    int Size()
    {
        return size;
    }
    T Front()
    {
        return front->data;
    }
    T Rear()
    {
        return rear->data;
    }
};
int main()
{
    int n = 0, k = 0;
    std::cout << "number of soliders >>: ";
    std::cin >> n;
    std::cout << "enter k >>: ";
    std::cin >> k;
    int start = k;
    bool flag = 1;

    Queue<std::pair<Sprite, int>> q1;
    RenderWindow window(VideoMode(750, 600), "JOSEPHUS PROBLEM !");
    window.setFramerateLimit(1);
    CircleShape shape(250.f);


    shape.setFillColor(Color(Color::Black));
    Texture t;
    t.loadFromFile("11.png");
    Sprite s;
    s.setTexture(t);
    s.setScale(0, 0);
    Texture t2;
    t2.loadFromFile("pic2.png");
    s.setPosition(220, 220);

    std::pair<Sprite, int>* ab = new std::pair<Sprite, int>[n];

    for (int i = 0; i < n; i++) {

        ab[i].first.setTexture(t2);
        ab[i].second = i + 1;
        ab[i].first.setPosition(250 + 220 * sin(2 * (i + 1) * PI / n) - 10, 250 - 220 * cos(2 * (i + 1) * PI / n) - 10);
        ab[i].first.setScale(0.4, 0.4);
        //ab[i].first.setColor(sf::Color::Red);
        q1.enqueue(ab[i]);
    }
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        if (flag){s.setTexture(t2);flag = 0;}
        else{s.setTexture(t);flag = 1;}
        shape.setFillColor(sf::Color::Black);
        window.draw(shape);// firstly outlining circle
        int size = q1.Size();
        if (k > size) {
            k -= size;
        }
        int i = 1;
        bool flag1 = 1;
        while (size--) {
            std::pair<Sprite, int> sol = q1.Rear();
            q1.dequeue(); // poping the first img
            if (i == k && flag1) {  // if it is to be deleted (poped)
                sol.first.setTexture(t);
                flag1 = 0;
            }
            else       // if this is a survivor (pushed again from end)
                q1.enqueue(sol);
            i++;
            window.draw(sol.first);   // img drawing 
        }
        k += start - 1;
        while (k > q1.Size())    // subtracting remaining player 
            k -= q1.Size();
        window.draw(s);
        window.display();
        if (q1.Size() == 1)
            break;
    }
    std::cout << "survior is >>: ";
    std::cout << q1.Front().second << std::endl;
}
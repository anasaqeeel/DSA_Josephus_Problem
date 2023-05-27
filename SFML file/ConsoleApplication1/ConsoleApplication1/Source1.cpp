//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <cmath>
//#include<utility>
//#define PI 3.14159 
//using namespace sf;
//using namespace std;
//template <typename T>
//struct node
//{
//    T data;
//    node* next;
//    node(T input)
//    {
//        data = input;
//        next = nullptr;
//    }
//};
//
//template <typename T>
//class Queue
//{
//private:
//    node<T>* front, * rear;
//    int size;
//
//public:
//    Queue()
//    {
//        front = nullptr;
//        rear = front;
//        size = 0;
//    }
//    Queue(T input)
//    {
//        front = new node<T>(input);
//        rear = front;
//        size = 1;
//    }
//    bool enqueue(T input)
//    {
//        if (size == 0)
//        {
//            front = new node<T>(input);
//            rear = front;
//            size = 1;
//        }
//        else
//        {
//            front->next = new node<T>(input);
//            front = front->next;
//            size++;
//        }
//        return 1;
//    }
//    bool dequeue()
//    {
//        if (size == 0)
//        {
//            return 0;
//        }
//        else if (size == 1)
//        {
//            delete rear;
//            front = nullptr;
//            rear = nullptr;
//            size = 0;
//        }
//        else
//        {
//            node<T>* temp = rear;
//            rear = rear->next;
//            delete temp;
//            size--;
//        }
//        return 1;
//    }
//
//    bool isEmpty()
//    {
//        return (size == 0);
//    }
//    ~Queue()
//    {
//        while (rear != nullptr)
//        {
//            node<T>* temp = rear->next;
//            delete rear;
//            rear = temp;
//        }
//        front = nullptr;
//    }
//    int Size()
//    {
//        return size;
//    }
//    T Front()
//    {
//        return front->data;
//    }
//    T Rear()
//    {
//        return rear->data;
//    }
//};
//
//int validator(int upper, int lower)
//{
//    int input;
//    while ((!(std::cin >> input)) || input < lower || input > upper)
//    {
//        std::cin.clear();
//        std::cin.ignore(100, '\n');
//        std::cout << "invalid input try again: ";
//    }
//    return input;
//}
//int main()
//{
//    std::cout << "Enter total no of soldiers: ";
//    int n = validator(100, 2);
//    std::cout << "Enter the value of k: ";
//    int k = validator(n, 0);
//    int start = k;
//    bool flag = 1;
//
//    Queue<std::pair<Sprite, int>> q1;
//    RenderWindow window(VideoMode(500, 500), "SFML works!");
//    window.setFramerateLimit(1.5);
//    CircleShape shape(250.f);
//    shape.setFillColor(Color(120, 120, 120));
//    Texture t;
//    t.loadFromFile("[removal.ai]_tmp-635d73d645aca.png");
//    Sprite s;
//    s.setTexture(t);
//    s.setScale(0.1, 0.1);
//    Texture t2;
//    t2.loadFromFile("[removal.ai]_tmp-635d73d645aca.png");
//    s.setPosition(220, 220);
//    std::pair<Sprite, int>* character = new std::pair<Sprite, int>[n];
//    for (int i = 0; i < n; i++) {
//
//        character[i].first.setTexture(t2);
//       // character[i].second.setString(to_string(i + 1));
//        //character[i].second.setCharacterSize(100);
//        //character[i].second.setFillColor(Color::Red);
//        //character[i].second = i + 1;
//
//        character[i].first.setPosition(250 + 220 * sin(2 * (i + 1) * PI / n) - 10, 250 - 220 * cos(2 * (i + 1) * PI / n) - 10);
//        //character[i].second.setPosition(350 + 300 * sin(2 * (i + 1) * PI / n) - 10, 350 - 300 * cos(2 * (i + 1) * PI / n) - 10);
//        character[i].first.setScale(0.3, 0.3);
//
//        q1.enqueue(character[i]);
//    }
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        if (flag)
//        {
//            s.setTexture(t2);
//            flag = 0;
//        }
//        else
//        {
//            s.setTexture(t);
//            flag = 1;
//        }
//        window.draw(shape);
//        int size = q1.Size();
//        if (k > size) {
//            k -= size;
//        }
//        int i = 1;
//        bool flag1 = 1;
//        while (size--) {
//            std::pair<Sprite, int> sol = q1.Rear();
//            q1.dequeue();
//            if (i == k && flag1) {
//
//                sol.first.setTexture(t);
//                flag1 = 0;
//            }
//            else
//                q1.enqueue(sol);
//            i++;
//            window.draw(sol.first);
//           // window.draw(sol.second);
//        }
//        k += start - 1;
//        while (k > q1.Size())
//            k -= q1.Size();
//        window.draw(s);
//        window.display();
//        if (q1.isEmpty())
//            continue;
//    }
//    std::cout << "The survivor is no.: " << q1.Front().second << std::endl;
//    return 0;
//}
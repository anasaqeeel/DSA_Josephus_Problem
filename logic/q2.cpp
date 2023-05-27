 //Q2 //
#include <iostream>
#include <queue>
using namespace std;
void radixsort(queue<int> q1[10],
queue<int> temp1[10],
queue<int> &q,
queue<int> &temp,int x)
{
	int f = 0, c = 0, n = 0, c2 = 0, c1 = 0;
	while (f != x) {
		while (!q.empty()) {
			c = temp.front(); temp.pop(); int c2 = c;
			c1 = q.front(); q.pop(); c %= 10;
			q1[c].push(c1);
			c2 /= 10;
			temp1[c].push(c2);
		}
		for (int i = 0; i < 10; i++) {
			if (!q1[i].empty()) {
				while (!q1[i].empty()) {
					n = q1[i].front(); q1[i].pop();
					q.push(n);
					int n2 = temp1[i].front(); temp1[i].pop();
					temp.push(n2);
				}
			}
		}
		f++;
	}
}
void radixsort(queue<string>& q,
	queue<string>& temp,
	queue<string> q1[52],int max)
{
	int ascii;
	string val, val1;
	bool tt = 0;
	for (int i = 0; i < max; i++) {
		while (!q.empty()) {
			val1 = temp.front(); temp.pop(); 
			if (val1.size()<=(max-1)-i) {

				ascii = 0; 
				tt = 1;
			}
			else {
				ascii = (int)val1[(max - 1) - i];
			}
			if (ascii > 90&&tt!=1) { ascii -= 71; }
			/*if (tt == 1) {
				ascii = 0;
			}*/
			else if(tt!=1) { ascii -= 65; }
			if (tt == 1) {
				//val1 = '\0';
				tt = 0;
			}
			q1[ascii].push(val1);
			q.pop();
		}
		for (int i = 0; i < 52; i++) {
			while (!q1[i].empty()) {
				val1 = q1[i].front(); q1[i].pop();
				q.push(val1);
				temp.push(val1);
			}
		}
	}
}
int main() {
	int anas;
	cout << "string (1) or integers(0) >>: ?";
	cin >> anas;
	if (anas) {
		queue<string> q;
		queue<string> temp;
		queue<string> q1[52];
		int size;
		string val;
		string max = "";
		cout << "enter size >>: ";
		cin >> size;
		cout << "enter elements >>: ";
		for (int i = 0; i < size; i++) {
			cin >> val; q.push(val); temp.push(val);
			if (max.size() < val.size()) {
				max = val;
			}
		}
		radixsort(q, temp, q1,max.size());
		cout << endl;
		while (!q.empty()) {
			cout << q.front(); q.pop(); cout << endl;
		}
	}
	else {
		queue<int> q1[10];
		queue<int> temp1[10];
		queue<int> q;
		queue<int> temp;
		int val, c = 0, c1 = 0, n = 0, t = 0, size;
		cout << "enter size >>: ";
		cin >> size;
		int* arr = new int[size];
		cout << "enter elements >>: ";
		for (int i = 0; i < size; i++) {
			cin >> val; q.push(val); temp.push(val); arr[i] = val;
		}
		int m = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > m) {
				m = arr[i];
			}
		}
		int ttt = m;
		int x = 0;
		while (ttt) {
			ttt /= 10;
			x++;
		}
		int f = 0;
		radixsort(q1, temp1, q, temp, x);
		for (int i = 0; i < size; i++) {
			cout << " >>: " << q.front(); q.pop();
			cout << endl;
		}
	}
}

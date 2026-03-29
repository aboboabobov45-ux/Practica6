#include <iostream>
using namespace std;
#include "math.h"


//----Задача 1----

float distance(int x1, int y1, int z1, int x2, int y2, int z2) {
	return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2), 0.5);
}

void main() {
	setlocale(LC_ALL, "Ru");

	int falcx = 1;
	int falcy = 2;
	int falcz = 3;

	int tie[4][3]{
		{1, 2, 3},
		{12, 22, 1},
		{5, 7, 9},
		{8, 21, 45}
	};

	int ship1[4];
	int ship2[4];
	int ship3[4];

	for (int i = 0; i < 4; i++) {
		ship1[i] = tie[i][0];
		ship2[i] = tie[i][1];
		ship3[i] = tie[i][2];
	};

	double dist[3];
	dist[0] = distance(falcx, falcy, falcz, ship1[1], ship1[2], ship1[3]);
	dist[1] = distance(falcx, falcy, falcz, ship2[1], ship2[2], ship2[3]);
	dist[2] = distance(falcx, falcy, falcz, ship3[1], ship3[2], ship3[3]);

	float coordmin = dist[0];
	int shipalert = 1;

	for (int i = 0; i < 3; i++) {
		if (dist[i] < coordmin) {
			coordmin = dist[i];
			shipalert = tie[0][i];
		}
	}

	float xtie = (ship1[1] + ship2[1] + ship3[1]) / 3.0;
	float ytie = (ship1[2] + ship2[2] + ship3[2]) / 3.0;
	float ztie = (ship1[3] + ship2[3] + ship3[3]) / 3.0;

	float xnapr = falcx - xtie;
	float ynapr = falcy - ytie;
	float znapr = falcz - ztie;

	float xnew = falcx + 2 * xnapr; //я не очень поняла, что значит рассчитать координаты точки перемещения на максимальном удалении.
	float ynew = falcy + 2 * ynapr; //чуть выше, получается, высчитывается центр скопления вражин и здесь от него корабль улетает на удвоенное расстояние.
	float znew = falcz + 2 * znapr; //но эдак можно и на тысячу умножить, и на миллион

	cout << "Больше всего угрожает корабль с номером " << shipalert << "\n";
	cout << "Координаты точки перемещения сокола:" << "\n";
	cout << "x: " << xnew << "\n";
	cout << "y: " << ynew << "\n";
	cout << "z: " << znew << "\n";
}


//----Задача 2----
// 
//void main() {
//    setlocale(LC_ALL, "Ru");
//    char str[32] = "I have a bad feeling about this";
//    char res[32];
//    int index = 0;
//
//    bool spaces = 1;
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] != ' ') {
//            spaces = 0;
//            break;
//        }
//    }
//    if (spaces == 1) {
//        cout << "Предложение состоит только из пробелов или пустой строки";
//        return;
//    }
//
//    for (int i = 0; i <= strlen(str); i++) {
//        char crnt = tolower(str[i]);
//        int cnt = 0;
//        for (int j = 0; str[j] != '\0'; j++) {
//            if (tolower(str[j]) == crnt) {
//                cnt++;
//            }
//        }
//
//        if (cnt == 1) {
//            res[index] = str[i];
//            index++;
//        }
//    }
//
//    if (index == 0) {
//        cout << "Нет уникальных символов" << "\n";
//    }
//    else {
//        cout << "Символы, встречающиеся один раз: " << "\n";
//        for (int i = 0; i < index; i++) {
//            cout << res[i] << "\n";
//        }
//    }
//}


//Это тоже задача 2, если всё же нужно использовать класс string. Обе программы работают однаково
//void main() {
//    setlocale(LC_ALL, "Ru");
//    string str = "I have a bad feeling about this";
//    string res;
//
//    bool spaces = 1;
//    for (char i : str) {
//        if (i != ' ') {
//            spaces = 0;
//            break;
//        }
//    }
//    if (spaces) {
//        cout << "Предложение состоит только из пробелов или пустой строки";
//        return;
//    }
//
//    for (int i = 0; i < str.length(); i++) {
//        char crnt = tolower(str[i]);
//        int cnt = 0;
//        for (int j = 0; j < str.length(); j++) {
//            if (tolower(str[j]) == crnt) {
//                cnt++;
//            }
//        }
//        if (cnt == 1) {
//            res += str[i];
//        }
//    }
//
//    if (res.length() == 0) {
//        cout << "Нет уникальных символов";
//    }
//    else {
//        cout << "Символы, встречающиеся один раз: " << "\n";
//        for (int i = 0; i < res.length(); i++) {
//            cout << res[i] << "\n";
//        }
//    }
//}
#include <iostream>
#include <Windows.h> // Pour les accents dans la console sous Windows
#include "Vecteur2D.h"
#include "Cercle.h"
#include "Segment.h"
#include "Triangle.h"

using namespace std;
int main()
{
	cout << "essai des vecteurs 2D \n";

	Vecteur2D u1(2, 3), u2(2, 3), w, v1(35, -63), u3(3, 4), u4(3, -4), v3;
	Cercle c1(1, 2, 3);
	Segment s1(1,2,3,4);
	Triangle t1(2,2,10,2,8,8), t2(-3,1,4,2,2,5);

	cout << " u1 = " << u1 << endl;
	cout << " u2 = " << u2 << endl;
	cout << " u1 - u2 = " << u1 - u2 << endl;
	cout << " 5*u1 = " << u1 * 5 << "\n" << endl;

	cout << c1 << endl;
	cout << "aire du cerlce: " << c1.getAire() << "\n" << endl;

	cout << s1 << endl;
	cout << "aire du segment: " << s1.getAire() << "\n" << endl;

	cout << t1 << endl;
	
	//cout << "determinant du triangle: " << t1.getV1().determinant(t1.getV2()) << endl;
	cout << "aire du triangle: " << t1.getAire() <<"\n"<< endl; //67.05

	cout << t2 << endl;
	cout << "aire du triangle: " << t2.getAire() << "\n" << endl;

	cout <<"AB: "<< t2.getV1().norme(t1.getV2()) << endl;
	cout <<"AC: "<< t2.getV1().norme(t1.getV3()) << endl;
	cout <<"BC: "<< t2.getV2().norme(t1.getV3()) << endl;

	system("pause");
	return EXIT_SUCCESS;
}
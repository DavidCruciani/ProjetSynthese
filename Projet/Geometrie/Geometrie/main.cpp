#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

#include "Vecteur2D.h"
#include "Cercle.h"
#include "Segment.h"
#include "Triangle.h"
#include "Polygone.h"
#include "TraitementForme.h"
#include "TraitementSegment.h"
#include "TraitementCercle.h"
#include "TraitementPolygone.h"
#include "TraitementTriangle.h"
#include "TraitementComposee.h"
#include "Composee.h"

using namespace std;
int main()
{
	cout << "essai des vecteurs 2D \n";

	Vecteur2D u1(2, 3), u2(2, 3), w, v1(35, -63), u3(3, 4), u4(3, -4), v3;
	Vecteur2D* A = new Vecteur2D(-9, 7);
	Vecteur2D* B = new Vecteur2D(-2, -6); 
	Vecteur2D* C = new Vecteur2D(8, -2);
	Vecteur2D* D = new Vecteur2D(9, 3);
	Vecteur2D* E = new Vecteur2D(4, 9);
	Vecteur2D* F = new Vecteur2D(-3, 4);
	//FormeGeometrique *  c1=new Cercle(200, 100, 50);
	//FormeGeometrique *  c1=new Cercle(20, 10,20);
	FormeGeometrique *  c1 = new Cercle("blue",20, 10, 20);
	//FormeGeometrique * s1=new Segment(1,2,3,4);
	FormeGeometrique * s1=new Segment("red",1,2,3,4);
	Triangle t1(2, 2, 10, 2, 8, 8), t2(-3, 1, 4, 2, 2, 5), t3(0, 0, 0, 2, 2, 0), t4(1, 1, 3, 3, 5, 1);
	FormeGeometrique * t5 = new Triangle(2, 2, 10, 2, 8, 8);
	Polygone * p = new Polygone("green");
	Composee * comp = new Composee("green");

	Dessin *d=new Dessin() ;

	cout << " u1 = " << u1 << endl;
	cout << " u2 = " << u2 << endl;
	cout << " u1 - u2 = " << u1 - u2 << endl;
	cout << " 5*u1 = " << u1 * 5 << "\n" << endl;
	
	cout << (string)*c1 << endl;
	cout << "aire du cerlce: " << c1->getAire() << "\n" << endl;
	
	cout << s1 << endl;
	cout << "aire du segment: " << s1->getAire() << "\n" << endl;
	
	//cout << t1 << endl;
	
	//cout << "determinant du triangle: " << t5.getV1().determinant(t1.getV2()) << endl;
	cout << "aire du triangle: " << t1.getAire() <<"\n"<< endl; //67.05

//	cout << t2 << endl;
	cout << "aire du triangle: " << t2.getAire() << "\n" << endl;

	cout << "aire du triangle: " << t3.getAire() << "\n" << endl;

	cout << "aire du triangle 4: " << t4.getAire() << "\n" << endl;

	cout <<"AB: "<< t2.getV1().norme(t1.getV2()) << endl;
	cout <<"AC: "<< t2.getV1().norme(t1.getV3()) << endl;
	cout <<"BC: "<< t2.getV2().norme(t1.getV3()) << endl;

	cout << "\n";
	//t5->dessiner(*d);
	//system("pause");

	cout << "\n";
	//c1->dessiner(*d);
	//system("pause");

	cout << "\n";

	//s1->dessiner(*d);

	p->addPoint(A);
	p->addPoint(B);
	p->addPoint(C);
	p->addPoint(D);
	p->addPoint(E);
	p->addPoint(F);

	cout << "aire du polygone : " << p->getAire() << "\n" << endl;

	//p->dessiner(*d);
	
	
	/*comp->addForme(c1);
	comp->addForme(s1);
	comp->addForme(t5);
	comp->dessiner(*d);*/

	// TEST chaine de responsabilite
	/*const char* instruction;
	TraitementForme *traitement, *segment, *cercle, *polygone, *triangle, *composee;
	segment = new TraitementSegment(NULL);
	cercle = new TraitementCercle(segment);
	polygone = new TraitementPolygone(cercle);
	triangle = new TraitementTriangle(polygone);
	composee = new TraitementComposee(triangle);
	traitement = composee;
	
	//////// CREATION Segment //////////
	instruction = "Segment(10,15,20,26)";
	//const char *insSegment = "(5,6,7,8);";
	FormeGeometrique *s = traitement->traiter(instruction);
	cout << "Forme attendue : Segment (10,15,20,26)\n\n" << endl;
	cout << "Forme obtenue ==>     " << s << "\n\n\n" << endl;

	//s->dessiner(*d);

	//////// CREATION CERCLE //////////
	instruction = "Cercle(11,20,30)";
	FormeGeometrique *c = traitement->traiter(instruction);
	cout << "Forme attendue : Cercle(11,20,30)\n\n" << endl;
	cout << "Forme obtenue ==>     " << c << "\n\n\n" << endl;

	//c->dessiner(*d);
	*/
	//////// CREATION Triangle //////////
	/*instruction = "Triangle(20,10.5,30,25,17,30)";
	FormeGeometrique *t = traitement->traiter(instruction);
	cout << "Forme attendue : Triangle(20,10,30,25,17,43)\n\n" << endl;
	cout << "Forme obtenue ==>     " << t << "\n\n\n" << endl;
	//t->dessiner(*d);
	t = t->rotation2(Vecteur2D(10, 10), 30);

	//t->dessiner(*d);
	
	//////// CREATION POLYGONE //////////
	instruction = "Polygone{(5,1)(6,7)(7,8)(4,6)}";
	FormeGeometrique *poly = traitement->traiter(instruction);
	cout << "Forme attendue : Polygone{(5,1)(6,7)(7,8)(4,6)}\n\n" << endl;
	cout << "Forme obtenue ==>     " << poly << "\n\n\n" << endl;

	//poly->dessiner(*d);

	
	//////// CREATION Composee //////////
	instruction = "Composee{=Rouge;\n*Segment(5,4,3,6)*\n*Cercle(5,9,10)*}";
	FormeGeometrique *compo = traitement->traiter(instruction);
	cout << "Forme attendue : Composee{ Segment(5,4,3,6), Cercle(5,9,10)}" << endl;
	cout << "Forme obtenue ==>     " << compo << "\n\n\n" << endl;*/
	system("pause");
	return EXIT_SUCCESS;
}
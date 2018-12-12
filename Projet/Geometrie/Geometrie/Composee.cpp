#include "Composee.h"

Composee::Composee() :FormeGeometrique() {}

Composee::Composee(const string c) : FormeGeometrique(c) {}

Composee::~Composee() {
	groupe.erase(groupe.begin(), groupe.end());
}

void Composee::addForme(const FormeGeometrique*) {

}

void Composee::delForme(const FormeGeometrique *f) {
	vector<FormeGeometrique*>::iterator it = find(groupe.begin(), groupe.end(), f);
	groupe.erase(it);
}

void Composee::delForme(const int pos) {
	groupe.erase(groupe.begin() + pos);
}

FormeGeometrique* Composee::cloner() const {
	return new Composee(*this);
}

void Composee::dessiner(const Dessin& d) {
	for (int i = 0; i < groupe.size(); i++) {
		groupe[i]->dessiner(d);
	}
}

double Composee::getAire() const {
	double aire = 0;
	for (int i = 0; i < groupe.size(); i++) {
		aire = aire + groupe[i]->getAire();
	}
	return aire;
}

Composee::operator string() const {
	ostringstream oss;
	for (int i = 0; i < groupe.size(); i++) {
		oss <<groupe[i];
	}
	return oss.str();
}

void Composee::homothetie(const Vecteur2D &p, const double zoom) {
	for (int i = 0; i < groupe.size(); i++) {
		groupe[i]->homothetie(p, zoom);
	}
}

void Composee::rotation(const Vecteur2D &centre, const double angle) {
	for (int i = 0; i < groupe.size(); i++) {
		groupe[i]->rotation(centre, angle);
	}
}

void Composee::translation(const Vecteur2D &trans) {
	for (int i = 0; i < groupe.size(); i++) {
		groupe[i]->translation(trans);
	}
}

/*FormeGeometrique* Composee::homothetie2(const Vecteur2D& v, const double r) {

}

FormeGeometrique* Composee::rotation2(const Vecteur2D& v, const double r) {

}

FormeGeometrique* Composee::translation2(const Vecteur2D& v) {

}*/
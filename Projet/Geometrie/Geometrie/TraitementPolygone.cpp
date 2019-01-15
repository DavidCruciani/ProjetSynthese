#include "TraitementPolygone.h"
#include "Polygone.h"

TraitementPolygone::TraitementPolygone(TraitementForme *suivant) : TraitementForme(suivant) {}

FormeGeometrique* TraitementPolygone::traiter1(const char *instruction) const {
	if (strstr(instruction, "Polygone") != NULL) {
		string ins, donnee;
		int posDeb, posPoint, posFin;
		ins = instruction;
		posDeb = ins.find("{");
		donnee = ins.substr(0, posDeb+1);
		if (donnee == "Polygone{") {
			Polygone *p = new Polygone();
			if (strchr(instruction, '=') != NULL) {
				string couleur = strchr(instruction, '=');
				posFin = couleur.find(";");
				couleur = couleur.substr(1, posFin-1);
				p->setCouleur(couleur);
			}							
			posDeb = 0;
			posFin = ins.find("}");
			posPoint = 0;
			while (posPoint + 1 != posFin) {
				posDeb = ins.find("(", posDeb + 1);
				posPoint = ins.find(")", posPoint + 1);
				donnee = ins.substr(posDeb, posPoint);
				p->addPoint(new Vecteur2D(donnee));
			}
			return p;
		}
	}
	else
		return NULL;
}
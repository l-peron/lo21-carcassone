#ifndef LO21_CARCASSONE_PLATEAU_H
#define LO21_CARCASSONE_PLATEAU_H

#include <map>

#include "tuile.h"
#include "groupement.h"
#include "pioche.h"
#include "joueur.h"

class Plateau {
private:

    // Singleton properties
    static Plateau* instance;
    Plateau();
    Plateau(Plateau const&);
    void operator=(Plateau const&);
    virtual ~Plateau() {};

    // Board and Groupements properties
    int orientationTuile=0;
    int idCurrentTuile;
    std::map<pair<int,int>, Tuile*> plateau;
    std::list<Groupement*> groupements = {};

public:
    // Singleton methods
    static Plateau& getInstance();
    static void libereInstance();

    // Getters & Setters
    std::map<pair<int,int>, Tuile*> getMap() {return plateau;};
    Tuile* getTuile(int x, int y);
    std::vector<Tuile*> getVoisins(int x, int y);
    std::vector<std::pair<int,int>> getNullVoisins(int x, int y);
    Tuile* getVoisinByOrientation(int x, int y, TypeCardinaux::points t);

    // Finders
    Groupement* getGroupementWithElement(Element* e);
    Groupement* getGroupementWithMeeple(Meeple* m);
    std::vector<std::pair<TypeElement::points, int>> getSizeOfGroupements();

    std::vector<std::pair<int, int>> getCasesLibres();

    bool isTuileCompatible(int x, int y, Tuile* t);
    void placerTuile(Tuile* t, int x, int y);

    bool isMeeplePlacable(Tuile* t, Element* e);
    void placerMeeple(Tuile* t, Meeple* m, Element* e);

    int evaluerGroupement(Groupement* g);

    int compterVoisins(int x, int y) { return getVoisins(x,y).size(); }
};


#endif //LO21_CARCASSONE_PLATEAU_H

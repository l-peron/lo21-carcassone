#ifndef jeu_h
#define jeu_h

#include <list>
#include "joueur.h"
#include "plateau.h"
#include "enum.h"

#include "iostream"

class Jeu{
private:
    static Jeu* instance;
    Jeu();
    ~Jeu();
    Tuile* currentTuile;
    std::list<Joueur*> joueurs;
    Joueur* currentJoueur;
    Plateau* plateau;
    Pioche* pioche;
    std::list<TypeExtension> extensions;
public:
    static Jeu& getJeu();
    void libererJeu();
    Jeu(const Jeu& j)=delete;
    Jeu& operator=(const Jeu& j)=delete;

    void initialiser();

    Pioche *const getPioche() const {return pioche;}
    Tuile* getCurrentTuile() const {return currentTuile;}
    const Joueur* getCurrentJoueur() const {return currentJoueur;}
    Plateau *const getPlateau() const {return plateau;}
    std::list<Joueur*> getJoueurs() const {return joueurs;}
    void setExtensions(bool m, bool r, bool ac);
    void nextTurn();
    
    void addJoueur(std::string nom) {joueurs.push_back(new Joueur(nom));}

    void poserMeeple(Joueur* j, Element* e, TypeMeeple t);
    void recupererMeeple(Meeple* m);
    void updateJoueur();
    void updateTuile();
    void tourTuile(int x, int y);
};

#endif


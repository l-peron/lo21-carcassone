#ifndef LO21_CARCASSONE_PIOCHE_H
#define LO21_CARCASSONE_PIOCHE_H

class Pioche {
private:
    const int nbTuilesMax;
    const int nbTuilesRiviereMax;
    int nbTuilesRiviere;
    int nbTuiles;
    Tuiles *tuiles_riviere;
    Tuiles *tuiles;
public:
    Pioche() = default;
    ~Pioche() = default;

    const Tuile& piocher();
    int getNbTuiles() const {return nbTuiles;}
    bool estVide() const {return nbTuiles == 0;}
    void genererTuiles();

    Pioche(const Pioche&) = delete;
    Pioche& operator=(const Pioche&) = delete;
};

#endif //LO21_CARCASSONE_PIOCHE_H
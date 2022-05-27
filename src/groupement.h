#if !defined(_GROUPEMENT_H)
#define _GROUPEMENT_H
#include <iostream>
#include <string>
#include "meeple.h"
#include "element.h"
#include <list>

using namespace std;
enum class Type {riviere, ville, abbaye, pre, route, jardin};

class Groupement{
private:
    list<Meeple*> meeples; // Liste de meeples
    Type type;
    size_t int points;
    list<Element*> element;
    bool complete=false;
public:
    size_t int getPoints() const {return points;}
    list<Meeple*> getMeeple() const {return meeple;}
    Types getType() const {return types;}
    bool isComplete(){return complete;}
    list<Element*> getElement() const {return element;}

    inline void addMeeples(const Meeple* m){
        meeple.push_back(m);
    }

    inline void addElement(const Element e){
        element.push_back(e);
    }

    void setComplete(){
        complete=true;
    }

    virtual ~Groupement(){delete[] element; delete[] liste;}
    
    Groupement(const Groupement& g): types(g.types='pre'),complete(g.complete){}
    
    virtual Groupement& operator=(const Groupement& g)=delete;

   /* 
    class iterator{ //Accès en écriture ici
        friend class Groupement;
        double* courant;
        double* fin;
        iterator(double* deb, double* f):courant(deb), fin(f){}
    public:
        void next(){
            if(courant==fin) throw "erreur:débordement d'iterator";
            ++courant;
        }
        bool is_done(){return courant==fin;}
        double& current_item(){return *courant;}
    };
    iterator get_iterator(){return iterator(liste, liste+sizeof(list);}
};
    */
    
    
    class GroupementRoute: public Groupement{
    private:
        int nbSegments;
        int nbAuberges;
    public:
        GroupementRoute(const GroupementRoute& g): nbSegments(g.nbSegments), nbAuberges(g.nbAuberges){}
        ~GroupementRoute()=default;
        int getNbSegments()const {return nbSegments;}
        int getNbAuberges()const {return nbAuberges;}

        void setNbSegments(int nb) {
            nbSegments = nb;
        }

        void setNbAuberges(int nb) {
            nbAuberges = nb;
        }
    };
    
    class GroupementVille: public Groupement{
    private:
        int nbSegments;
    public:
        GroupementVille(const GroupementVille& g): nbSegments(g.nbSegments){}
        ~GroupementVille()=default;
        int getNbSegments()const {return nbSegments;}
        void setNbSegments(int nb) {
            nbSegments = nb;
        }
    };
    
    class GroupementPre: public Groupement{
    private:
        int nbSegments;
    public:
        GroupementPre(const GroupementPre& g): nbSegments(g.nbSegments){}
        ~GroupementPre()=default;
        int getNbSegments()const {return nbSegments;}
        void setNbSegments(int nb) {
            nbSegments = nb;
        }
    };
    
    class GroupementAbbaye: public Groupement{
    private:
        int nbCases;
    public:
        GroupementAbbaye(const GroupementAbbaye& g): nbCases(g.nbCases){}
        ~GroupementAbbaye()=default;
        int getNbCases()const {return nbCases;}
        void setNbCases(int nb) {
            nbCases = nb;
        }
    };
    
    class GroupementJardin: public Groupement{
    private:
        int nbCases;
    public:
        GroupementJardin(const GroupementJardin& g): nbCases(g.nbCases){}
        ~GroupementJardin()=default;
        int getNbCases()const {return nbCases;}
        void setNbCases(int nb) {
            nbCases = nb;
        }
    };

#endif



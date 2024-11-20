#ifndef HEADERS_PROSTREDI_H
#define HEADERS_PROSTREDI_H

#include <list>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "organismus.h"

class Organismus; // Forward declaration

class Prostredi
{
public:
    int vyska, sirka;
    std::list<Organismus *> organismy;

    Prostredi(int vyska, int sirka);

    void krok();

    template <typename T>
    void pridejOrganismus()
    {
        T *organismus = new T(rand() % sirka, rand() % vyska, this);
        organismy.push_back(organismus);
    }

    template <typename T>
    void pridejOrganismus(int x, int y)
    {
        int new_position_x = std::max(0, std::min(sirka - 1, x));
        int new_position_y = std::max(0, std::min(vyska - 1, y));

        T *organismus = new T(new_position_x, new_position_y, this);
        organismy.push_back(organismus);
    }

    void odeberOrganismus(Organismus *o);

    void vypisStav();
};

#endif // HEADERS_PROSTREDI_H
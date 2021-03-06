#ifndef ASTERIOD_H
#define ASTERIOD_H

#include "SDL.h"
#include "game_object.h"

class Asteriod : public GameObject
{
    public:
        Asteriod();
        ~Asteriod();
        
        Asteriod(int grid_w, int grid_h);
        Asteriod(const Asteriod &source);
        Asteriod(Asteriod &&source);
        Asteriod& operator=(const Asteriod &source);
        Asteriod& operator=(Asteriod &&source);

        // getter and setter
        Color *GetBodyColor(){return _bodyColor.get();}

        // Move the Asteriod. (override virtual function)
        void Move();

        // Check if is Asteriod Cell
        bool IsAsteriodCell(const int &x, const int &y);
    
    private:
        // Velocity of the asteriod
        float _vx;
        float _vy;
        float _nextx;
        float _nexty;
        void Reset();
};

#endif



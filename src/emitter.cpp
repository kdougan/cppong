#include <iostream>
#include <random>

#include "game.hpp"
#include "transient.hpp"
#include "emitter.hpp"
#include "random.hpp"

Emitter::Emitter( 
        float x, float y, float width, float height, 
        float vx, float vy, float lifespan) 
        : Transient(x, y, width, height, vx, vy, lifespan) {
}

Emitter::~Emitter() {
}

// seg fault on entity delete if emitter is not deleted first
// put spawn freq above 0.2 to see

void Emitter::step(Game& game){
    Transient::step(game);
    if(frand(0, 1) < 0.1){
        Transient *new_subentity = new Transient(
            float(x), float(y), 
            frand(1, 5), frand(1, 5),
            frand(-10, 10), frand(-10, 10),
            frand(0.1, 2)
        );
        game.entities.push_back(new_subentity);
    }
}

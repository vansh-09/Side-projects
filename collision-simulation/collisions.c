
#include <stdio.h>
#include "raylib.h"


#define WIDTH 900
#define HEIGHT 600

#define NUM_OF_PARTICLES 15

typedef struct {
    float x,y,r,vx,vy;
} Particle;

void DrawParticle(Particle *particle)
{
    DrawCircle(particle->x, particle->y, particle->r, WHITE);
}

void UpdateParticle(Particle *particle)
{
   particle->x += particle->vx;
    particle->y += particle->vy;

    float x = particle->x;
    float y = particle->y;
    float r = particle->r;

    //collision with walls
    if(x-r<0){
        particle->x = r; //left wall
        particle->vx *= -particle->vx;
    }    
    if(x+r>WIDTH){
        particle->x = WIDTH - r; //right wall
        particle->vx *= -particle->vx;
    }   
    if(y+r>HEIGHT){
        particle->y = HEIGHT - r; //bottom wall
        particle->vy *= -particle->vy;
    }   
    if(y-r<0){
        particle->y = r; //top wall
        particle->vy *= -particle->vy;
    }
}

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Particle Collision Simulation");
    SetTargetFPS(60);

    Particle particle = {300, 300, 50, -10, 4};
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawParticle(&particle);
            UpdateParticle(&particle);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
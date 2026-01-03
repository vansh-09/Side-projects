#include<stdio.h>
#include<math.h>

#include "raylib.h"

#define FPS 120
#define WIDTH 900
#define HEIGHT 600
#define THICKNESS 5
#define MASS_WIDTH 100
#define K 5
#define FRICTION 0.5
#define FLOOR_Y (HEIGHT*0.6)

#define X_REST (WIDTH/3)

#define NUM_SPRING_ELEMENT 16
#define SPRING_ELEM_LENGTH 60


float x_mass = WIDTH*0.8;
float v= 300;
float a = 2;

typedef struct {
    Vector2 start,end;

} SpringElement;

SpringElement spring_elements[NUM_SPRING_ELEMENT];


void drawSpring(){
    float x_springdelta  = x_mass / NUM_SPRING_ELEMENT;
    float y_end = sqrt(pow(SPRING_ELEM_LENGTH, 2) - pow(x_springdelta , 2));
    for(int i=0; i<NUM_SPRING_ELEMENT; i+=2){
        Vector2 start = {x_springdelta * i , FLOOR_Y - MASS_WIDTH/2+SPRING_ELEM_LENGTH/2};
        Vector2 end = {start.x + x_springdelta ,start.y-y_end};
        spring_elements[i] = (SpringElement){start, end};
        DrawLineEx(start, end, THICKNESS/2, GRAY);

        
    }

    for(int i=1; i<NUM_SPRING_ELEMENT; i+=2){
        float y_end = sqrt(pow(SPRING_ELEM_LENGTH, 2) - pow(x_springdelta , 2));
        Vector2 start = spring_elements[i-1].end;
        Vector2 end = {start.x + x_springdelta ,start.y+y_end};
        DrawLineEx(start, end, THICKNESS/2, LIGHTGRAY);

        
    }
}

void drawFloor(){   
    Vector2 start = {0  ,FLOOR_Y};
    Vector2 end = {WIDTH, FLOOR_Y}; 
    DrawLineEx(start, end,THICKNESS, GRAY);
}

void drawMass(){
    Rectangle rect = {x_mass, FLOOR_Y - MASS_WIDTH-THICKNESS/2, MASS_WIDTH, MASS_WIDTH};
    DrawRectangleRec(rect, RED );
}

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Mass on Spring Simulation");



    float dt;
    SetTargetFPS(FPS);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawFPS(10, 10);
            dt = GetFrameTime();
            drawFloor();
            float friction = a>0 ? FRICTION : -FRICTION;
            a =  - K * (x_mass - X_REST) - v * FRICTION;
            v += a * dt;
            x_mass += v * dt;
            drawMass();
            drawSpring();
            DrawText("Mass on Spring Simulation", WIDTH/10, 100, 30, GREEN);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
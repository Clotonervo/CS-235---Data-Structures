

#ifndef Maze_h
#define Maze_h
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include "MazeInterface.h"
using std::string;
enum {OPEN = 0, BLOCKED, PATH, EXIT, TEMPORARY};

class Maze : public MazeInterface{
private:
    int*** labrynth;
    int labrynthHeight;
    int labrynthWidth;
    int labrynthLayer;
public:
    Maze();
    Maze(int height, int width, int depth);
    ~Maze();
    
    virtual void setValue(int height, int width, int layer, int value);
    virtual bool find_maze_path();
    bool find_maze_path(int height, int width, int layer);
    virtual string toString() const;
    
};

#endif /* Maze_h */

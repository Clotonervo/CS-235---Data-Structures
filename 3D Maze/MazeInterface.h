//
//  MazeInterface.h
//  3D Maze
//
//  Created by Sam Hopkins on 6/3/18.
//  Copyright © 2018 Sam Hopkins. All rights reserved.
//

#ifndef MazeInterface_h
#define MazeInterface_h
#include <string>
using std::string;

class MazeInterface {
public:
    MazeInterface(void) {}
    ~MazeInterface(void) {}
    
    /** Set maze value
     @parm height
     @parm width
     @parm layer
     @parm value
     */
    virtual void setValue(int height, int width, int layer, int value) = 0;
    
    /** Solve maze
     @return true if solveable, else false
     */
    virtual bool find_maze_path() = 0;
    
    /** Output maze (same order as input maze)
     @return string of 2D layers
     */
    virtual string toString() const = 0;
    
};





#endif /* MazeInterface_h */

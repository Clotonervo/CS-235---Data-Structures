
#include "Maze.h"

/***************************************** Maze constructors/destructor ****************************************/
Maze::Maze(int height, int width, int depth) {
    labrynthHeight = height;
    labrynthWidth = width;
    labrynthLayer = depth;
    labrynth = new int**[height];
    for(int x = 0; x < height; ++x) {
        labrynth[x] = new int*[width];
        for(int y = 0; y < width; ++y) {
            labrynth[x][y] = new int[depth];
        }
    }
}
Maze::~Maze() {
    delete[] labrynth;
}

/***************************************** Set maze value ******************************************/
void Maze::setValue(int height, int width, int layer, int value){
    labrynth[height][width][layer] = value;
    return;
}

/***************************************** Solve maze ****************************************/
bool Maze::find_maze_path(){
    if (this->find_maze_path(0, 0, 0)){         //starter function
        return true;
    }
    else {
        return false;
    }
}

bool Maze::find_maze_path(int height, int width, int layer){                //recursive function
    if ((height < 0) || (height >= labrynthHeight) ||           // check boundary (base case #1)
        (width < 0) || (width >= labrynthWidth) ||
        (layer < 0) || (layer >= labrynthLayer)) return false;
    
    if (labrynth[height][width][layer] != OPEN) return false; // blocked (base case #2)
    
    if ((height == labrynthHeight - 1) && (width == labrynthWidth - 1) && (layer == labrynthLayer - 1)){
        labrynth[height][width][layer] = EXIT; // Success! (base case #3)
        return true;
    }
    
    labrynth[height][width][layer] = PATH; // Recursive case
    if (find_maze_path(height, width - 1, layer) ||
        find_maze_path(height, width + 1, layer) ||
        find_maze_path(height, width, layer + 1) ||
        find_maze_path(height, width, layer - 1) ||
        find_maze_path(height - 1, width, layer) ||
        find_maze_path(height + 1, width, layer)) return true;
    labrynth[height][width][layer] = TEMPORARY;
    return false;
}

/***************************************** Output maze ****************************************/
string Maze::toString() const{
    std::stringstream OS;
    for (int z = 0; z < labrynthLayer; z++){
        OS << "Layer " << z + 1 << std::endl;
        for (int x = 0; x < labrynthHeight; x++){
            for (int y = 0; y < labrynthWidth; y++){
                if (labrynth[x][y][z] == OPEN || labrynth[x][y][z] == TEMPORARY){
                    OS << "_ ";
                }
                else if (labrynth[x][y][z] == PATH || labrynth[x][y][z] == EXIT){
                    OS << labrynth[x][y][z] << " ";
                }
                else if (labrynth[x][y][z] == BLOCKED){
                    OS << "X ";
                }
            }
            OS << std::endl;
        }
    }
    return OS.str();
}


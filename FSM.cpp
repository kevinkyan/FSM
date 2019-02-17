#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
        int currentState;
        string line;
        string input = argv[2];
        ifstream myfile(argv[1]);
        if(myfile.is_open()) {
          while(getline(myfile, line)) {
            istringstream iss(line) {
              string type;
              string state;
              string second;
              string third;
            }
          }
        }
}
int *makeIntArray(int length)
{
        int *p = NULL;
        if( length > 0 )
        {
                p = (int *) malloc(length*sizeof(int));
        }
        return p;
}
void deleteIntArray(int *p)
{
        if( p != NULL )
        {
                free(p);
        }
}
int **makeIntMatrix(int width, int height)
{
        int **p = (int **) NULL;
        int *pData = (int *) NULL;
        if( (width > 0) && (height > 0) )
        {
                p = (int **) malloc(width*sizeof(int*));
                pData = (int *) malloc(width*height*sizeof(int));
                5 of 6
                Due 2/17
                int i = 0;
                while( i < width )
                {
                        p[i] = pData+(i*height);
                        i = i+1;
                }
        }
        return p;
}
void deleteIntMatrix(int **p)
{
        if( p != NULL )
        {
                if( p[0] != NULL )
                {
                        free(p[0]);
                }
                free(p);
        }
}

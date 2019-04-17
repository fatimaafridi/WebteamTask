#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

//Grid declaration
int N = 0;
int E = 1;
int S = 2;
int W = 3;
void robotTest(string);

int main(){
    ifstream inFile;
    string array;
    inFile.open("test.txt");
    while(inFile >> array){
        robotTest(array);
    }
}
void robotTest(string array){
    int curr = N; 
    int x = 0;
    int y = 0;
    int val = array.length();
    for (int i=0 ; i<val ; i++){
        if (array[i] == 'R'){
            curr = (curr+1) % 4;
        }
        else if (array[i] == 'L'){
            curr = (curr+3) % 4;
        }
        else{
            if (curr == N){
                y++;
            }
            else if(curr == E){
                x++;
            }
            else if(curr == S){
                y--;
            }
            else{
                x--;
            }
        }
    }
    if (x==0 && y==0){
        cout<<"Success!"<<endl;
        return;
    }
    cout<<"Failure!"<<endl;
}
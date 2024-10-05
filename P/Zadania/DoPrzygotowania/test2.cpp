#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile << "It would be so awesome... It would be so cool.\n";
  myfile << "I added this! \n";
  myfile.close();
  return 0;
}
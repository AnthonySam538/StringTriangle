#include <iostream>
#include <fstream>

using namespace std;

//Creates an isosceles triangle using a string and puts it in a file called triangle.txt
int main()
{
  //declare necessary variables
  string myString;
	ofstream outfile;

  //Retrieve and store the string
  cout << "Enter your string: ";
  getline(cin, myString);

  //open (or create) the output file
  outfile.open("triangle.txt");

  //top half of the triangle (including the phrase)
  for(int x = 0; x < myString.length(); x++)
  {
    if(isspace(myString[x])) x++; //skips "duplicate" rows (distinguishable only by whitespace)

    for(int y = 0; y < x + 1; y++) //amount of characters printed: row+1
    {
      outfile << myString[y];
    }
    outfile << endl; //move to next row/line
  }

  //bottom half of the triangle
  for(int x = myString.length() - 1; x > 0; x--)
  {
    if(isspace(myString[x])) x--; //also for skipping "duplicate" rows

    for(int y = 0; y < x; y++) //the amount of characters printed depends on the current row
    {
      outfile << myString[y];
    }
    outfile << endl; //move to next row/line
  }

  //close the file
  outfile.close();

  return 0;
}

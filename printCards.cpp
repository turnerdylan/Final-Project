#include <iostream>
#include <fstream>

using namespace std;


void printTable(char* arr[][35])
{
  cout << "Here are the current cards:" << endl;
  for(int i =0; i<5; i++)
  {
    for(int j=0; j<35; j++)
    {
      cout << arr[i][j];
    }
    cout << endl;
  }
}

void initializeTable()
{

}

void insertCard(int location, char *arr[][35]) //location will be some value 1-5
{
  cout << "What card do you want?" << endl;
  string input;
  cin >> input;

  string sample;
  bool flag = true;

  ifstream myInput;
  myInput.open("cards.txt");
  if(myInput.fail())
  {
    cout << "opening failed" << endl;
  }
  else
  {
    while(flag)
    {
      getline(myInput, sample);
      if(sample == input)
      {
        flag = false;
        string currentLine;
        //copy until you hit an empty line
        for(int i=0; i<5; i++)
        {
          getline(myInput, currentLine);
          for(int j=0; j<7; j++)
          {

            /////////////////////////////fix
            //read the next 5 lines
            //for each line save it as:
            arr[i][location*i] = currentLine[]
          }
        }
      }
    }
  }
  bool flag = true;

}

int main()
{
  //we need 1 2D array for each person
  //we need 1 2D array for the table
  char cardsOnTable[5][35];

  //initialize the array to all zeros
  for(int i =0; i<5; i++)
  {
    for(int j=0; j<35; j++)
    {
      cardsOnTable[i][j] = '0';
    }
  }

  printTable();

  insertCard(1, cardsOnTable);

  printTable();



  //print array


  //insert card



}

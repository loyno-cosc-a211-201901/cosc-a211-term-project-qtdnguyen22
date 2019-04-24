#include <iostream>

using namespace std;

// constants for menu choices
const int NOMINAL = 1,
          ORDINAL = 2,
          INTERVALRATIO = 3,
          EXIT = 4;

// Function prototypes
void techniqueMenu();
int nominal();
int ordinal();
int intervalRatio();

int main()
{
      // Title and brief information about program
      // SWITCH
      //      Ask user questions regarding the nature of the variables they are testing
      // Calculate the best available statistical measure that the user should run
      // Tell the calculated suggestion

      cout << "What is the nature of the variables?\n"
           << "1. Nominal (nonparametric)\n"
           << "2. Ordinal (nonparametric)\n"
           << "3. Interval/Ratio (parametric)\n"
           << "4. Exit the program" << endl;
      techniqueMenu();
}

void techniqueMenu()
{
      // Present menu of the three types of functions
      // Ask user to choose between the 3 functions or exit(4)
      int menuChoice;

      cout << "Enter one of the choices: ";
      cin >> menuChoice;

      cout << endl;

      switch (menuChoice)
      {
            case NOMINAL:
                  nominal();
                  break;

            case ORDINAL:
                  ordinal();
                  break;

             case INTERVALRATIO:
                  intervalRatio();
                  break;

            case EXIT:
                  cout << "Quitting the program" << endl;
                  break;

            default:
                  cout << "Invalid input. The valid choices are 1 through 4."
                       << "Run the program again and select one of those." << endl;
        }

}

int nominal();

int ordinal();

int intervalRatio();

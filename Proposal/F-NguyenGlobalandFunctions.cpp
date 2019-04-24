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

      // Other things to add:
      // - Ask user if they want to run program again
      // - Allow user to return to previous decision

      cout << "Welcome to the Inferential Statistics Decision Tree.\n"
           << "This program will allow you to figure out what univariate \n"
           << "technique you should use for your statistical data.\n";

      cout << endl;

      cout << "To use this program, please answer the following questions.\n";

      cout << endl;

      techniqueMenu();
}

void techniqueMenu()
{
      // Present menu of the three types of functions
      // Ask user to choose between the 3 functions or exit(4)

      // variables
      int menuChoice;

      cout << "What is the nature of the variables?\n"
           << "1. Nominal (nonparametric)\n"
           << "2. Ordinal (nonparametric)\n"
           << "3. Interval/Ratio (parametric)\n"
           << "4. Exit the program" << endl;

      cout << endl;

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

int nominal()
{
      // constants
      const int CHOICE1 = 1,
                CHOICE2 = 2;
      int variableChoice;

      cout << "Are you: \n"
           << "1. comparing observed vs. expected values?\n"
           << "2. looking at the relationship between 2 variables?\n";
      cout << "I am: ";
      cin >> variableChoice;

      cout << endl;

      switch (variableChoice)
      {
            case CHOICE1:
                  cout << "You should run a Chi square goodness of fit.\n";
                  break;

            case CHOICE2:
                  cout << "You should run a Chi square test of independence.\n";
                  break;

            default:
                  cout << "Invalid input. The valid choices are 1 or 2."
                       << "Run the program again and select one of those." << endl;

      }
      return 0;
}

int ordinal()
{
      // variables
      char confirmBS,
           confirmSample;
      int numGroups;


      cout << "Are you using a between subjects design? (Y/N) ";
      cin >> confirmBS;

      switch (confirmBS)
      {
            case 'n':
            case 'N':
                  cout << "How many groups are there? ";
                  cin >> numGroups;

                  cout << endl;

                  if (numGroups == 2)
                        cout << "You should use a Wilcoxon or sign test.\n";

                  else if (numGroups > 2)
                        cout << "You should use a Friedman test.\n";

                  else
                        cout << "Invalid input. The valid choice is a value greater than 1."
                             << "Run the program again and select one of those." << endl;
                  break;

            case 'y':
            case 'Y':
                  cout << "How many groups are there? ";
                  cin >> numGroups;

                  cout << endl;

                  if (numGroups == 2)
                  {
                        cout << "Is n (sample size per cell) < 20? (Y/N) ";
                        cin >> confirmSample;

                        cout << endl;

                        switch (confirmSample)
                        {
                          case 'n':
                          case 'N':
                                cout << "You should use a rank-sum test.\n";
                                break;

                          case 'y':
                          case 'Y':
                                cout << "You should use a Mann-Whitney U test.\n";
                                break;

                          default:
                                cout << "Invalid input. The valid choices are Y or N."
                                     << "Run the program again and select one of those." << endl;
                        }

                  }

                  else if (numGroups > 2)
                        cout << "You should use a Kruskal-Wallis test.\n";

                  else
                        cout << "Invalid input. The valid choice is a value greater than 1."
                             << "Run the program again and select one of those." << endl;

                  break;

            default:
                  cout << "Invalid input. The valid choices are Y or N."
                       << "Run the program again and select one of those." << endl;
      }

      return 0;
}


int intervalRatio()
{
      // variables
      char confirmIV,
           confirmSD,
           confirmBS;
      int numIV,
          numLevels,
          manipIV;

      cout << "Are there independent variables? (Y/N) ";
      cin >> confirmIV;

      switch (confirmIV)
      {
            case 'n':
            case 'N':
                  cout << "Is the standard deviation known? (Y/N) ";
                  cin >> confirmSD;

                  cout << endl;

                  switch (confirmSD)
                  {
                        case 'n':
                        case 'N':
                              cout << "You should run a Student's t-test.\n";
                              break;

                        case 'y':
                        case 'Y':
                              cout << "You should run a z-test.\n";
                              break;

                        default:
                              cout << "Invalid input. The valid choices are Y or N."
                                   << "Run the program again and select one of those." << endl;
                  }
                  break;

            case 'y':
            case 'Y':
                  cout << "Number of independent variables: ";
                  cin >> numIV;

                  cout << endl;

                  if (numIV == 1)
                  {
                        cout << "How many levels of independent variables are there? ";
                        cin >> numLevels;

                        cout << endl;

                        if (numLevels == 2)
                        {
                              cout << "Are the independent variables between subjects? (Y/N) ";
                              cin >> confirmBS;

                              cout << endl;

                              switch (confirmBS)
                              {
                                    case 'y':
                                    case 'Y':
                                          cout << "You should run an independent samples t-test or\n"
                                               << "1-way between subjects ANOVA.\n";
                                          break;

                                    case 'n':
                                    case 'N':
                                          cout << "You should run a dependent/related samples t-test or\n"
                                               << "1-way within subjects ANOVA";
                                          break;

                                    default:
                                          cout << "Invalid input. The valid choices are Y or N."
                                               << "Run the program again and select one of those." << endl;
                                  }
                            }

                            else if (numLevels > 2)
                                  cout << "You should run a 1-way ANOVA.\n";

                            else
                                  cout << "Invalid input. The valid choice is a value greater than 1."
                                       << "Run the program again and select one of those." << endl;


                  }

                  else if (numIV > 1)
                  {
                        cout << "How are the independent variables manipulated?\n"
                             << "1. All are between subjects.\n"
                             << "2. All are within subjects.\n"
                             << "3. At least 1 is between subjects and at least 1 is within subjects.\n";

                        cout << endl;

                        cout << "Please select 1, 2, or 3: ";
                        cin >> manipIV;

                        cout << endl;

                        switch (manipIV)
                        {
                              case 1:
                                    cout << "You should run a 2-way (or higher) between subjects ANOVA.";
                                    break;

                              case 2:
                                    cout << "You should run a 2-way (or higher) within subjects ANOVA.";
                                    break;

                              case 3:
                                    cout << "You should run a 2-way (or higher) mixed ANOVA.";
                                    break;

                              default:
                                    cout << "Invalid input. The valid choices are 1 through 3."
                                         << "Run the program again and select one of those." << endl;
                        }
                  }

                  else
                        cout << "Invalid input. The valid choice is a value grater than 1."
                             << "Run the program again and select one of those." << endl;
                  break;

            default:
                  cout << "Invalid input. The valid choices are Y or N."
                       << "Run the program again and select one of those." << endl;
      }

      return 0;
}

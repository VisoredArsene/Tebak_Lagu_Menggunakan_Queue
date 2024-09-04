/* Yonathan Arya Dhamma | 20215520001
   Jullius Celvin       | 20215520004
   Andre Surya          | 20215520002 */

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void compInput();
void userInput();
void randomInput();
void judulProgram();
void enqueueUc(int, int);
void dequeueUser();
void dequeueComp();
void refreshSystem();

int rearQueueUser = 0;
int frontQueueUser = 0;
int overSizeUser = 3;

int rearQueueComp = 0;
int frontQueueComp = 0;
int overSizeComp = 3;

int judulLagu[6] = {1, 2, 3, 4, 5, 6};
int antrianUser[3];
int antrianComp[3];
int comPoint = 0;
int userPoint = 0;
int soalUser, soalComp;
int tebakLaguUser, tebakLaguComp;

string namaLagu[6] = {"Favorite Girl", "Hati-Hati Di Jalan", "Baby", "One Last Time", "Sparkle", "Gurenge"};
int pilihMenu, randomChecker, inputTebakan;

int main()
{
mainMenu:
    system("cls");
    cout << "==============================\n";
    cout << "Welcome To Guess Song Games\n";
    cout << "==============================\n";
    cout << "1. Choose Song For User\n";
    cout << "2. Start Game Vs COM\n";
    cout << "3. Show Points For User & COM\n";
    cout << "4. Option For Checking Front, Rear, Over Size\n";
    cout << "5. Refresh System\n";
    cout << "6. Show Answer\n";
    cout << "7. Exit\n";
    cout << "Choose Menu: ";
    cin >> pilihMenu;
    switch (pilihMenu)
    {
    case 1:
        system("cls");
        judulProgram();
        cout << "Maximum Array Size: " << overSizeUser << endl
             << endl;
        if (rearQueueUser >= overSizeUser || rearQueueComp >= overSizeComp)
        {
            cout << "Queue Status Is: Overflow!" << endl
                 << endl;
        }
        else
        {
            cout << "Please Choose Song For COM : ";
            cin >> soalUser;
            srand(time(0));
            randomChecker = rand() % 6 + 1;
            randomInput();
            enqueueUc(soalUser, soalComp);
        }
        system("\npause");
        goto mainMenu;
        break;

    case 2:
        if (frontQueueUser == rearQueueUser || frontQueueComp == rearQueueComp)
        {
            cout << "Queue status is : Underflow!" << endl
                 << endl;
            system("\n\npause");
            goto mainMenu;
        }
        else
        {
            int i = 0;
            judulProgram();
            do
            {
                userInput();
                compInput();
                i++;
            } while (i < 3);

            cout << endl;

            for (int i = 0; i < 3; i++)
            {
                antrianUser[i] = 0;
                antrianComp[i] = 0;
            }

            system("\npause");
            goto mainMenu;
        }
        break;

    case 3:
        system("cls");

        if (userPoint < 0)
        {
            userPoint = 0;
        }
        if (comPoint < 0)
        {
            comPoint = 0;
        }
        cout << "Point User: " << userPoint;
        cout << "\nPoint COM: " << comPoint;

        if (userPoint > comPoint)
        {
            cout << "\nUser Winner!\n";
        }
        else if (userPoint < comPoint)
        {
            cout << "\nCOM Winner!\n";
        }
        else
        {
            cout << "\nDraw!\n";
        }

        system("\npause");
        goto mainMenu;
        break;

    case 4:
        system("cls");
        cout << "Front Queue User : " << frontQueueUser << endl;
        cout << "Rear Queue User  : " << rearQueueUser << endl;
        cout << "Queue Max User   : " << overSizeUser << endl;
        cout << "\nFront Queue COM : " << frontQueueComp << endl;
        cout << "Rear Queue COM  : " << rearQueueComp << endl;
        cout << "Queue Max COM   : " << overSizeComp << endl;
        system("\npause");
        goto mainMenu;
        break;

    case 5:
        refreshSystem();
        system("\npause");
        goto mainMenu;
        break;

    case 6:
        system("cls");
        for (int i = 0; i < 3; i++)
        {
            cout << "User Answers: " << antrianUser[i] << endl;
        }
        cout << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "COM Answer: " << antrianComp[i] << endl;
        }
        system("\npause");
        goto mainMenu;
        break;

    case 7:
        system("cls");
        cout << "GoodBye And Thanks For Playing With COM";
        exit(0);
        break;

    default:
        break;
    }
}

void refreshSystem()
{
    rearQueueUser = 0;
    frontQueueUser = 0;
    overSizeUser = 3;

    rearQueueComp = 0;
    frontQueueComp = 0;
    overSizeComp = 3;
}

void dequeueComp()
{
    antrianComp[frontQueueComp];
    frontQueueComp++;
    overSizeComp--;

    cout << "Dequeue Successful" << endl;
}

void dequeueUser()
{
    antrianUser[frontQueueUser];
    frontQueueUser++;
    overSizeUser--;

    cout << "Dequeue Successful" << endl;
}

void enqueueUc(int inputUser, int inputComp)
{
    antrianUser[rearQueueUser] = inputUser;
    antrianComp[rearQueueComp] = inputComp;
    rearQueueUser++;
    rearQueueComp++;
}

void compInput()
{
    if (antrianUser[frontQueueUser] == 1)
    {
        cout << "\nI always knew you were the best The coolest girl I know";
    }
    else if (antrianUser[frontQueueUser] == 2)
    {
        cout << "\nKukira kita akan bersama Begitu banyak yang sama";
    }
    else if (antrianUser[frontQueueUser] == 3)
    {
        cout << "\nYou know you love me, I know you care Just shout whenever and I'll be there";
    }
    else if (antrianUser[frontQueueUser] == 4)
    {
        cout << "\nI was a liar I gave in to the fire";
    }
    else if (antrianUser[frontQueueUser] == 5)
    {
        cout << "\nCaught in a never-ending game Seems like the worlds still trying to tame me";
    }
    else if (antrianUser[frontQueueUser] == 6)
    {
        cout << "\nDorodarake no soumatou ni you kowabaru kokoro furueru te wa tsukamitai mono ga aru sore dake sa";
    }
    srand(time(0));
    tebakLaguComp = rand() % 6 + 1;
    cout << "\nComputer's Choose: " << tebakLaguComp;
    cout << endl;
    if (tebakLaguComp == antrianUser[frontQueueUser])
    {
        cout << "Congratulations COM Win" << endl;
        comPoint += 10;
    }
    else if (tebakLaguComp != antrianUser[frontQueueUser])
    {
        cout << "Computer Wrong Answer" << endl;
        comPoint -= 5;
    }
    dequeueUser();
}

void userInput()
{
    if (antrianComp[frontQueueComp] == 1)
    {
        cout << "\nI always knew you were the best The coolest girl I know";
    }
    else if (antrianComp[frontQueueComp] == 2)
    {
        cout << "\nKukira kita akan bersama Begitu banyak yang sama";
    }
    else if (antrianComp[frontQueueComp] == 3)
    {
        cout << "\nYou know you love me, I know you care Just shout whenever and I'll be there";
    }
    else if (antrianComp[frontQueueComp] == 4)
    {
        cout << "\nI was a liar I gave in to the fire";
    }
    else if (antrianComp[frontQueueComp] == 5)
    {
        cout << "\nCaught in a never-ending game Seems like the worlds still trying to tame me";
    }
    else if (antrianComp[frontQueueComp] == 6)
    {
        cout << "\nDorodarake no soumatou ni you kowabaru kokoro furueru te wa tsukamitai mono ga aru sore dake sa";
    }
    cout << "\nGuess The Song Title: ";
    cin >> tebakLaguUser;

    if (tebakLaguUser == antrianComp[frontQueueComp])
    {
        cout << "Congratulations User Win" << endl;
        userPoint += 10;
    }
    else if (tebakLaguUser != antrianComp[frontQueueComp])
    {
        cout << "User Wrong Answer" << endl;
        userPoint -= 5;
    }
    dequeueComp();
}

void randomInput()
{
    if (randomChecker == 1)
    {
        randomChecker = judulLagu[0];
    }
    else if (randomChecker == 2)
    {
        randomChecker = judulLagu[1];
    }
    else if (randomChecker == 3)
    {
        randomChecker = judulLagu[2];
    }
    else if (randomChecker == 4)
    {
        randomChecker = judulLagu[3];
    }
    else if (randomChecker == 5)
    {
        randomChecker = judulLagu[4];
    }
    else if (randomChecker == 6)
    {
        randomChecker = judulLagu[5];
    }
    soalComp = randomChecker;
}

void judulProgram()
{

    cout << "Group 2 | Guess Song Name\n"
         << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << "Song " << i + 1 << ". " << namaLagu[i] << endl;
    }
    cout << endl;
}

/* Yonathan Arya Dhamma | 20215520001
   Jullius Celvin       | 20215520004
   Andre Surya          | 20215520002 */
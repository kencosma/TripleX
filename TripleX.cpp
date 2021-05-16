#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty)
{
    //print welcome messages to the terminal 
    std::cout << "\n\n You are a hungry hippo in search for food. You have to unlock a level " << Difficulty;
    std::cout << " fridge full of food..enter the correct code in order to get into the top secret fridge.\n\n";
   
    
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // declare 3 number code 
    const int CodeA = rand() % Difficulty + Difficulty; 
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to terminal
    std::cout << "\n+ There are 3 numbers in the code";
    std::cout << " \n+ The code add up to: " << CodeSum;
    std::cout << "\n+ The code multiply to give: " << CodeProduct << std::endl;

    // Store player guess 
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;

    // Here is where conditions are met if the answer is correct 
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nCHOW TIME! move on to the next level";
        return true;
    }
    else
    {
        std::cout << "\nYoure still a hungry hungry hippo...try again";
        return false;
    }


}
int main() 
{ 
    srand(time(NULL)); // Creates new random sequence at the based on time of day
    int LevelDifficulty = 1;
    int const MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // loop until levels are complete
{ 
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); // Clears errors
    std::cin.ignore(); // Discards buffer
    
    if (bLevelComplete)
    {
        ++LevelDifficulty;
    }
}
     std::cout << "\nCongrats! You get to eat! ";
    return 0;
}
#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n{-_-}{-_-}{-_-}{-_-}{-_-}{-_-}{-_-}{-_-}{-_-}{-_-}";
    std::cout << "\n{-_-}{-_-}{-_-}{-_-}{-_-}{-_-}{-_-}{-_-}{-_-}{-_-}";

    std::cout << "\nYou are a soldier on the explosive ordinance team.\n";
    std::cout << "This bomb is a level " << Difficulty;
    std::cout << "\nYou must enter the correct sequence of keys to prevent an explosion\n\n";
    
}

bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty);
    
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "There are 3 numbers in the code\n";
    std::cout << "The code adds up to " << CodeSum;
    std::cout << "\nThe code multiplies to give " << CodeProduct;

    int GuessA, GuessB, GuessC;
    //std::cout << "Enter the code";
    std::cout << std::endl;
    std::cin >> GuessA >> GuessB >> GuessC;
  
    std::cout << "You guessed " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    std::cout << std::endl;
    
    //Check if players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct){
        
        std::cout << "You lived! Great job, you successfully defused the bomb\n";  
        return true;
    }
    else {
        std::cout << "BOOOOOOOOOOOM.....You're wrong, and blew yourself up\n";
        return false;

    }
}



int main()
{
    srand(time(NULL));
    
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (MaxLevel <= 5) 
{
    bool bLevelComplete = PlayGame(LevelDifficulty);
   
    std::cin.clear(); //Clears any errors
    std::cin.ignore(); //Discards the buffer
    

    if (bLevelComplete)
    {
        ++LevelDifficulty;
    }

    if (PlayGame) 
    {
            if (LevelDifficulty == 5) 
        {
            break;
        }
        std::cout << "Moving to level " << LevelDifficulty;
    
    }
    else if (!PlayGame) 
    {
        std::cout << "Retrying level " << LevelDifficulty;
    }
    
    
}
    

    std::cout << "Congratulations, you successfully prevented the explosion, and are now a hero";
    return 0;
}
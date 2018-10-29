/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : Rosalie Chhen, Robin Reuteler, Doran Kayoumi
 Date        : 17.10.2018
 But         : Mettre en place un système de comptage de point pour le jeu de
               fléchette 501 double out.
 Remarque(s) : Les valeurs données par l'utilisateur ne sont pas fiable.
 Compilateur : MinGW-g++ <6.3.0>
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> 

using namespace std;

int main() {

   const int THROWS_PER_SET = 3;
   const int STARTING_SCORE = 501;
   const int TARGET_SCORE = 0;
   const int BUST_SCORE = 1;
   
   const int MIN_INPUT_SCORE = 0;
   const int MAX_INPUT_SCORE = 20;
   const int BULLSEYE = 25;
   
   const int DEFAULT_MULTIPLIER = 1;
   const int D_MULTIPLIER = 2;
   const int T_MULTIPLIER = 3;
   
   int totalScore = STARTING_SCORE;
   int currentScore = STARTING_SCORE;
   int multiplier = DEFAULT_MULTIPLIER;
   
   // throw number x/3
   int nbThrow = 0;
    // total of throws
   int totalThrows = 0;

   
   while (currentScore != TARGET_SCORE) {
      nbThrow++;
      totalThrows++;
      
      string inputScore;
      int score;
      // Flag to determine if the user inputed a correct value
      bool error;
      do {
         multiplier = DEFAULT_MULTIPLIER;
         error = false;

         cout << "Score: " << currentScore 
              << " - Jouez la flechette " 
              << nbThrow << "/" << THROWS_PER_SET << endl;
         
         // Check if a value was entered and it's valid(ish)
         if (not(cin >> inputScore) or inputScore.empty()) {
            error = true;
            continue;
         }
         cin.clear();
         
         // Check the first char of the given score
         //    so we can determine which multiplier to use
         switch (inputScore[0]) {
            case 'T': case 't':
               multiplier = T_MULTIPLIER;
               inputScore[0] = ' ';
               break;
               
            case 'D': case 'd':
               multiplier = D_MULTIPLIER;
               inputScore[0] = ' ';
               break;
         }

         // Add user input to string stream
         stringstream ss(inputScore);

         // Try and convert the user input into an integer
         if (ss >> score) {
            // Check if the score is within the score range
            if ((score < MIN_INPUT_SCORE or score > MAX_INPUT_SCORE) 
                    and score != BULLSEYE) {
               error = true;
               continue;
            }
            
            // Check for non existing case
            //    it's impossible to have a triple bullseye
            if (multiplier == T_MULTIPLIER and score == BULLSEYE) {
               error = true;
               continue;
            }
         }
         else {
            // The input couldn't be converted into an integer so return an error
            error = true;
            continue;
         }

      } while (error and 
              cout << "Entree non valide" << endl);
      
      // Decrement score
      currentScore -= (score * multiplier);
      
      // Check if it's a bust.
      // There's 3 different ways for it to be a bust
      // 1. The score is lower than the 0 (TARGET_SCORE)
      // 2. The score is equal to 1 (BUST_SCORE), 
      //    which means it's impossible to finish with a double
      // 3. The scored reached 0 (TARGET_SCORE) with the last shot not being a double
      //
      // If any of theses cases happen, the score is reset 
      //    to before the start of the set and a new set is started.
      if (currentScore == BUST_SCORE or
          currentScore < TARGET_SCORE or 
         (currentScore == 0 and multiplier != D_MULTIPLIER)) {  
         currentScore = totalScore;
         cout << "Bust" << endl;
         nbThrow = 0;
         continue;
      }

      // Check if the user finished hers/his set of throws
      if (nbThrow == THROWS_PER_SET) {
         nbThrow = 0;
         totalScore = currentScore;
      }
   }
   
   // YAY! User won
   cout << "Score: " << currentScore << " en " << totalThrows << " flechettes" 
        << endl << "Bravo!" << endl;

   return 0;
}

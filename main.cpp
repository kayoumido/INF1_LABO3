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

using namespace std;

int main() {

   const int THROWS_PER_SET = 3;
   const int STARTING_SCORE = 501;

   int totalScore = STARTING_SCORE;
   int currentScore = STARTING_SCORE;
   int nbThrow = 0;

   while (currentScore != 0) {

      // get user input
      string throwValue;
      bool validInput(0);
      bool validNum(0);
      do {
            cout<<"Score: "<<currentScore<<"  - Jouez la flechette "<<nbThrow<<"/"<<THROWS_PER_SET<<endl;
            if(not(cin>>throwValue) or throwValue.empty())
            {
                throwValue="_";
            }

            switch(throwValue[0])
            {
                case 'T':
                {
                    validInput=true;
                    break;
                }

                case 'D':
                {
                    validInput=true;
                    break;
                }

                default:
                {
                    validInput=false;
                    cout<<"Entree non valide"<<endl;
                }
            }
      }
      while (validInput and validNum);



   }

   return 0;
}


/* "Dead and the injured".
It consists of discovering a four-digit number generated randomly by the computer.
The number must consist of distinct digits, for example, 3257. Numbers with repeated digits will not be considered by the program,
for example, 3378 or 4894.

The number to find will be generated randomly by the program, using the "time.h" library and the srand(time(NULL)) command, among others.

The player will have 7 attempts to guess the number, and in each attempt, the program will return information about the quantity of
"Dead and injured" in their guess. The "Dead" represent the digits that belong to the correct answer and are in the correct position,
while the "injured" are digits that belong to the correct answer but are in the wrong position.
*/


#include<ctype.h>
#include<iostream>
#include<time.h>
#include<windows.h>

using namespace std;

//Visual function declarations

void start(); //display welcome screen and information
void line();
void line2();
void finalMessageBad(string,int); //bad ending
void finalMessageGod(string,int); //good ending


main(){
    
    
    //Variable declarations
    string name="admin";
    char t=3;
    
    int randomVariable;
    int controlVariable1,controlVariable2,controlVariable3,controlVariable4; //variables to check if the random numbers are different
    int auxiliarVariable1,auxiliarVariable2,auxiliarVariable3,auxiliarVariable4;   
    int hearts=7;
    int valueUser=0001;
    int injured,dead;
    
    
    //Changes all text to Spanish
    setlocale(LC_ALL, "spanish");
    
    
    start();
    
    
    //Data collection
    line();
    cout<<"\t\t\t\t\tData."<<endl;
    cout<<" \t\t\t\tYour name is: ";getline(cin,name);
    line2();

    
    repeatSequence1:
    
    //Random number generator from 1000 to 9999
    srand(time(NULL));
    randomVariable = 1000 + rand()%8999;
    
    
    //Decomposes the randomVariable into units
    controlVariable1=randomVariable/1000;
    controlVariable2=(randomVariable/100) - (controlVariable1*10);
    controlVariable3=(randomVariable/10) - ((controlVariable1*100) + (controlVariable2*10));
    controlVariable4=randomVariable - ((controlVariable1*1000) + (controlVariable2*100) + (controlVariable3*10));
    
    //Verification to check if each number in randomVariable is different
    if(controlVariable1!=controlVariable2 and controlVariable1!=controlVariable3 and controlVariable1!=controlVariable4 and controlVariable2!=controlVariable3 and controlVariable2!=controlVariable4 and controlVariable3!=controlVariable4){
        repetir999:
        line();
        cout<<"\t\t\t\t\tPlayer No.1."<<endl;
        cout<<"\t\t\t\t\t"<<name<<"."<<endl;
        cout<<"\t\t\t\t\t";
        
        //Displays and projects how many lives are left
        for(int i=0;i<hearts;i++){
            cout<<t<<" ";
        }
        
        cout<<endl;
        repeatSequence2:  
         
        cout<<"\t\t\tEnter a number: ";cin>>valueUser;
        
        //Evaluates whether a non-numeric value is entered into the variable valueUser
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error: only integers are allowed." << endl;
            goto repeatSequence2;
        }

		
	//Evaluates that the entered data/number is greater than 1000 and less than 9999
	if(valueUser<1000 or valueUser>9999){
		//If 0000 is entered, the program displays the response for 1 second and then clears it
		if(valueUser==0000){
			cout<<randomVariable<<endl;
			Sleep(1000);
			system("cls");
			goto repetir999;
		}else{
			cout<<"The entered number cannot be greater than 9999 and less than 1000."<<endl;
			goto repeatSequence2;    
		}   
	}

	injured=0;
	dead=0;

	//Decomposes the number entered by the player into units
	auxiliarVariable1=valueUser/1000;
	auxiliarVariable2=(valueUser/100) - (auxiliarVariable1*10);
	auxiliarVariable3=(valueUser/10) - ((auxiliarVariable1*100) + (auxiliarVariable2*10));
	auxiliarVariable4=valueUser - ((auxiliarVariable1*1000) + (auxiliarVariable2*100) + (auxiliarVariable3*10));

	//Checks that all numbers entered by the user are different in each position
	if(auxiliarVariable1!=auxiliarVariable2 and auxiliarVariable1!=auxiliarVariable3 and auxiliarVariable1!=auxiliarVariable4 and auxiliarVariable2!=auxiliarVariable3 and auxiliarVariable2!=auxiliarVariable4 and auxiliarVariable3!=auxiliarVariable4){
		//Evaluates if the thousand unit (entered/data) matches any other position number (randomVariable)
		if(auxiliarVariable1==controlVariable2 or auxiliarVariable1==controlVariable3 or auxiliarVariable1==controlVariable4){
			injured++;
		//Evaluates if the thousand unit (entered/data) matches the thousand unit (randomVariable)
		}else if(auxiliarVariable1==controlVariable1){
			dead++;
		}
		//Evaluates if the hundred (entered/data) matches any other position number (randomVariable)
		if(auxiliarVariable2==controlVariable1 or auxiliarVariable2==controlVariable3 or auxiliarVariable2==controlVariable4){
			injured++;
		//Evaluates if the hundred (entered/data) matches the hundred (randomVariable)
		}else if(auxiliarVariable2==controlVariable2){
			dead++;
		}
		//Evaluates if the ten (entered/data) matches any other position number (randomVariable)
		if(auxiliarVariable3==controlVariable2 or auxiliarVariable3==controlVariable1 or auxiliarVariable3==controlVariable4){
			injured++;
		//Evaluates if the ten (entered/data) matches the ten (randomVariable)
		}else if(auxiliarVariable3==controlVariable3){
			dead++;
		}
		//Evaluates if the unit (entered/data) matches any other position number (randomVariable)
		if(auxiliarVariable4==controlVariable2 or auxiliarVariable4==controlVariable3 or auxiliarVariable4==controlVariable1){
			injured++;
		//Evaluates if the unit (entered/data) matches the unit (randomVariable)
		}else if(auxiliarVariable4==controlVariable4){
			dead++;
		}

		cout<<"injured: "<<injured<<endl;
		cout<<"Dead: "<<dead<<endl;

		//If the entered number matches randomVariable, leads to good ending; otherwise, subtracts a heart and repeats the process
		if(auxiliarVariable1==controlVariable1 and auxiliarVariable2==controlVariable2 and auxiliarVariable3==controlVariable3 and auxiliarVariable4==controlVariable4){
			finalMessageGod(name,hearts);
		}else{
			hearts--;
			if(hearts==0){
				finalMessageBad(name,randomVariable);
			}else{
				goto repetir999;
			}

		}

	}else{
		cout<<"The entered number must have different digits."<<endl;
		goto repeatSequence2;
	}
	}else{
		goto repeatSequence1;
	}

}

void start(){
    char t = 3;
    system("color 06"); // Sets yellow color
    cout << "X - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X\t\t\t\t\t!Welcome to the Game of Dead and Injured!                                    X" << endl;
    cout << "X\t\t\t\tGuess the correct number and you will win a great surprise.                          X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X\t\t\t\t\t                                                                              X" << endl;
    cout << "X\t\t\t\t\tDaniel Fernandez Feo V-29.966.683                                             X" << endl;
    cout << "X\t\t\t\t\t                                                                              X" << endl;
    cout << "X - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - X" << endl;    
 
    system("pause");
    system("cls");
    
    cout << "X - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - X" << endl;
    cout << "X\t\t\t\t\tAbout the Game.                                                               X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X\tThe game is probably more than 100 years old. In Spanish, it is also known as Picas y Fijas or Punto y Fama, X" << endl;
    cout << "X while in English its most popular name is Bulls and Cows. This version, invented by Mordecai Meirowitz in 1970  X" << endl;
    cout << "X and initially marketed in the UK by Invicta, has been a great sales success worldwide ever since.                  X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X\tDead and Injured is a logic game focused on deciphering a 4-digit number where   X" << endl;
    cout << "X no digits repeat. The Dead represents the number of digits that match with one in the correct number    X" << endl;
    cout << "X and are also in the correct position. The Injured represents the number of digits that match one in the correct  X" << endl;
    cout << "X number but are not in the correct position.                                                                         X" << endl;
    cout << "X\t\t\t\t\tIMPORTANT                                                                    X" << endl;
    cout << "X\tYou only have 7 lives available, and these will be represented as hearts "<<t<<", each time you               X" << endl;
    cout << "X enter a number, these hearts will decrease.                                                                         X" << endl;
    cout << "X\tOnly numbers between 1000 and 9999 are allowed, but since digits cannot repeat, you will have more X" << endl;
    cout << "X chances.                                                                                                           X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X\t\t\t\t\t!Good Luck!                                                                  X" << endl;
    cout << "X - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - X" << endl;

    system("pause");
    system("cls");
}

void line(){
    system("color 07");
    cout << "X - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - X" << endl;
}

void line2(){
    system("color 07");
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - X" << endl;

    system("pause");
    system("cls");
}

void finalMessageBad(string f, int a){
    system("cls");
    system("color 04");
    cout << "X - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X\t\t\t\t\t\t\t!Game over!                                                   X" << endl;
    cout << "X\t\t\t\tYou have lost all your lives. I hope you enjoyed the game :)                      X" << endl;
    cout << "X\t\t\t\t\t\t!Better luck next time "<<f<<" !                            X" << endl;
    cout << "X\t\t\t\t\t        The correct number was: "<<a<<"                                        X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X                                                                                                                     X" << endl;
    cout << "X - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - X" << endl;

    system("pause");
}

void finalMessageGod(string b,int hearts){
	system("cls");
	system("color 06");
	hearts = 7 - hearts; //Muestra en cuantos intentos se logro completar la tarea
	cout << "X - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X\t\t\t\t\t!Felicidades "<<b<<" Ganaste el juego!                                "<<endl;
	cout << "X\t\t\t\tAdivinaste el número correcto con "<<hearts<<" intentos, Ahora                                   X"<<endl;
	cout << "X\t\t\t\t\tserás agregado a los mejores jugadores                                        X"<<endl;
	cout << "X                                           Top Mejores Jugadores                                                     X"<<endl;
	cout << "X                                        1."<<b<<"        "<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X                                                                                                                     X"<<endl;
	cout << "X - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - X"<<endl;
	system("pause");
}
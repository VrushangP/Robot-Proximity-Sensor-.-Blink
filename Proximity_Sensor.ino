int IRpin = A0;               
int IRemitter = 2;          
int ambientIR;                
int obstacleIR;              
int value[10];                
int distance;                 

void setup(){
  Serial.begin(9600);        
  pinMode(IRemitter,OUTPUT);  
  digitalWrite(IRemitter,LOW);
  pinMode(11,OUTPUT);         
}

void loop(){
  distance = readIR(5);       
  Serial.println(distance);   
  buzzer();   
  init();  // make sure your arduino has a console window open, not serial window but CONSOLE.
//why was buzzer commented  
}

int readIR(int times){
  for(int x=0;x<times;x++){     
    digitalWrite(IRemitter,LOW);         
    delay(1);                                             
    ambientIR = analogRead(IRpin);  
    digitalWrite(IRemitter,HIGH);          
    delay(1);                                            
    obstacleIR = analogRead(IRpin);  
    value[x] = ambientIR-obstacleIR;   
  }
 
  for(int x=0;x<times;x++){        
    distance+=value[x];
  }
  return(distance/times);            
}



void buzzer(){
  if (distance>1){
    if(distance>100){ 
      digitalWrite(11,HIGH);
    }
    else{  
      digitalWrite(11,HIGH);
      delay(150-distance); 
      digitalWrite(11,LOW);
      delay(150-distance);  
    }
  }
  else{  
    digitalWrite(11,LOW);
  }
}


static void init()
        {
            while (true)
            {
                Console.WriteLine(@"
888                                                           
888                                                           
888                                                           
88888b.  8888b. 88888b.  .d88b. 88888b.d88b.  8888b. 88888b.  
888 '88b     88b888  88bd88P'88b888 '888 '88b    '88b888 '88b 
888  888.d888888888  888888  888888  888  888.d888888888  888 
888  888888  888888  888Y88b 888888  888  888888  888888  888 
888  888'Y888888888  888 'Y88888888  888  888'Y888888888  888 
                             888                              
                        Y8b d88P                              
                         'Y88P'");                               
                Random rando = new Random();// Initializing new random 
                int lives = 5;
                char Userguess;
                int LettersRevealed = 0;
                List<char> RightGuess = new List<char>();
                List<char> WrongGuess = new List<char>();
                string[,] wordbank=new string[4,10] {{ "Apple", "Orange", "Banana", "Grapes", "Watermalon", "Peach", "Blueberry", "Strawberry", "Mango", "Pears" }, // Initializing 2 dimentional array of words
                                                          {"Onion", "Tomato", "Potato", "Lettus", "Zucini", "Spinich", "Garlic", "Ginger", "Carrot", "Lemon" },
                                                          { "Car", "Plane", "Boat", "Bike", "Train", "Bus", "SpaceShip", "Submarine", "Motorcycle", "ShuttleBus"},
                                                          {"Hand", "Foot", "Leg", "Head", "Finger", "Toe", "Ear", "Thigh", "Nose", "Tounge"}};
  
                
               


                int row = rando.Next(0, 4); // Using rando to pick a number related to row
                int col = rando.Next(0, 9); // Using rando to pick a number related to collumn

                string wordGuess = wordbank[row, col]; //Word found in the row and collumn picked becomes new variable; WordGuess
                string wordGuessUppercase = wordGuess.ToUpper(); //Converts all letters to uppercase and sets new variable
                
                  
                    StringBuilder Display = new StringBuilder(wordGuess.Length); // Each letter in word is replaced and displayed as '_' 
                    for (int i = 0; i < wordGuess.Length; i++) // Replaces each letter for the amount of letters in word (.length)
                        Display.Append('-');
                    Console.WriteLine(Display.ToString()); // Displays the hidden word to player 
                
                bool won = false; //Setting variable won as false until they win
                while (!won && lives > 0) //While they have not won or lost they will conintue the loop of guessing 
                {
                    if (row == 0) // All the hints corrosponding to which row is picked
                    {
                        Console.WriteLine("Hint: The word is a fruit");
                    }
                    else if (row == 1)
                    {
                        Console.WriteLine("Hint: The word is a Vegetable");
                    }
                    else if (row == 2)
                    {
                        Console.WriteLine("Hint: The word is a mode of transportation");
                    }
                    else if (row == 3)
                    {
                        Console.WriteLine("Hint: The word is a body part");
                    }
                    Console.WriteLine("Guess a letter to this word");
                    string userinput = Console.ReadLine().ToUpper(); // Converting users input to upper case
                    Userguess = userinput[0]; // Users current letter gets converted to veriable Userguess for use

                    if (RightGuess.Contains(Userguess)) // checking to see if the list of 'Right guess' has users guess
                    {
                        Console.WriteLine("You have already tried '{0}' and it was right, try a different letter" , Userguess); 
                        continue;
                    }

                    else if (WrongGuess.Contains(Userguess)) // checking to see if the list of 'Wrong guess' has users guess
                    {
                        Console.WriteLine("You have already tried '{0}' and it was wrong, try a different letter" , Userguess);
                        continue;
                    }

                    if (wordGuessUppercase.Contains(Userguess)) // If the word contains the users guess then it is added to list of right guesses
                    {
                        RightGuess.Add(Userguess); // Adding users guess to list of right guesses

                        for (int i = 0; i < wordGuess.Length; i++)
                        {
                            if (wordGuessUppercase[i] == Userguess) 
                            {
                                Display[i] = wordGuess[i];
                                LettersRevealed++; // Adds to letters revealed to match how many letters are being revealed of the word
                            }
                        }
                        if (LettersRevealed == wordGuess.Length) //When the amount of letters revealed is = to the amount of letters in word, won becomes true and it breaks out of loop
                            won = true;
                    }


                    else
                    {
                        WrongGuess.Add(Userguess); // All leters not in word are added to list of wrong guesses 
                        Console.WriteLine("Sorry there is no '{0}' in the word", Userguess);
                        lives = lives - 1;
                        if (lives == 4) // Displaying a visual for when lives are lost, until they lose 
                        {
                            Console.WriteLine(@"
     _______
    |/      |
    |      (_)
    |       |
    |       |
    |       
    |
   _|
     \
^^^^^^^^^^^^^^^^^^^^^");
                        }
                        else if (lives == 3)
                        {
                            Console.WriteLine(@"
     _______
    |/      |
    |      (_)
    |       |/
    |       |
    |       
    |
   _|
     \
^^^^^^^^^^^^^^^^^^^^^");
                        }
                        else if (lives == 2)
                        {
                            Console.WriteLine(@"
     _______
    |/      |
    |      (_)
    |      \|/
    |       |
    |       
    |
   _|
     \
^^^^^^^^^^^^^^^^^^^^^");
                        }
                        if (lives > 1)
                        {
                            Console.WriteLine("You have '{0}' lives left", lives);
                        }
                        else
                        {
                            Console.WriteLine(@"                  
     _______
    |/      |
    |      (_)
    |      \|/
    |       |
    |      /
    |
   _|
     \
^^^^^^^^^^^^^^^^^^^^^");
                            Console.WriteLine("You only have 1 life left!");
                        }
                    }
                    Console.WriteLine(Display.ToString());
                }

                if (won)
                    Console.WriteLine("Congratz! You are Winner!");
                else
                {
                    Console.WriteLine(@"
     ,%%%%%%%%,
    %%o%%/%%%%%%
   %%%%\%%%<%%%%%
   %%>%%%/%%%%o%%
   %%%%%o%%\%%//%
   %\o%\%%/%o/%%'
    '%%\ `%/%%%'
      '%| |%|%'
        | | (O
        | | |\
        | | >>
        | |
       /   \
^^^^^^^^^^^^^^^^^^^^");
                    Console.WriteLine("Sorry you lost, the word was:'{0}'", wordGuess);
                }


                Console.WriteLine("Would you like to play again? Enter 'yes' or 'no'");
                string Userinput2 = Console.ReadLine();
                if (Userinput2 != "yes")
                    break;   // end the while loop
                Console.Clear();
            }  

            
        }

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//reference:https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm 
//reference:http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
//reference: http://stackoverflow.com/questions/19724346/generate-random-characters-in-c
char inputChar()
{
    // TODO: rewrite this function
	//select rand char between ' ' and } to meet conditional in test function
	int randChoice = (rand() % (126-32)) + 32;
	char myRandChar = randChoice;

    return myRandChar;
}

char *inputString()
{
    // TODO: rewrite this function
	//alloc memory
	char *myChar = (char*)malloc(sizeof(char) * 5);
	int i = 0;
	for(i = 0; i < 5; i++){
		//enough to reach reset edge case 
		myChar[i] = "efghijklmnopqrst"[rand() % 16];
	}
	
    return myChar;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}

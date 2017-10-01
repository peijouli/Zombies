/********************************************************
 * CS 103 Zombie-pocalypse PA
 * Name: Pei Jou Liu (Vicky)
 * USC email: peijouli@usc.edu
 * Comments (you want us to know):
 *
 *
 ********************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

const int MAXPOP = 100000;

int main()
{
  // Array with enough entries for the maximum population size possible.
  bool pop[MAXPOP];

  // Your code here
  int N; 
  int k;
  int M;
  int s;

  cout << "Enter the following: N k M seed" << endl;
  cin >> N;
  cin >> k;
  cin >> M;
  cin >> s;

  srand(s); // use seed value to seed the random generator 

  
  int maxNight = -1;
  int minNight = INT_MAX;
  int sumOfNight = 0;
  double average = 0;
  for (int i= 0; i<M; i++){
  	bool allZombie = false; // set a boolean statement to find out 
  							// if everyone is turned into zombie
  	int night = 0;
  	for(int i=0; i<=k-1;i++) 
  	{
  		pop[i]=true;
  	} // true if the person in the array is a zombie
  	for(int j=k; j<N;j++)
  	{
  		pop[j]=false; // false if the person in the array is a human
  	}
  	while (allZombie == false)
  	{
  		night++; 
  		int count =0;
  		for(int i=0; i<N; i++)
  		{
  			if (pop[i]==true)
  				count ++;
  		}
  		for (int i=0; i<count; i++)
  		{

  		int random = rand()%N; // randomly choose someone to bite 
  								//(may or may not be zombie)
  		
  		if (pop[random] == false) 
  		{
  			pop[random] = true;
  		}//becomeZombie: if a zombie bites a human, 
  		//then human is changed to zombie
	
		}
  	
  		allZombie= true;
  		for (int i=0; i<N;i++)
  		{
  			if (pop[i]== false)// check if everyone is zombie
  				allZombie = false;
  		}
  		
  		//jump out of the loop when everyone is turned into zombie
  	}
  	if (maxNight < night){
  		maxNight = night;}
  	if (minNight > night){
  		minNight = night;}

  	sumOfNight= night +sumOfNight;
  }
  average = ((double) sumOfNight)/M;
  // count the number of night the zombie need in order to eat all human
  			//use M 
  			//to find the minimum night and max night (insdie loop)
  			//average night - outside the looop

  
  	
  
  // Print out your average, max, and min number of nights here
  // Be sure to follow the format shown in the assignment writeup.
 cout << "Average Nights:" << average << endl;
 cout << "Max Nights:" << maxNight << endl;
 cout << "Min Nights:" << minNight << endl;

  return 0;
}
/*
Courtney Ng
Period 4
Program Desc: Day of the Week
Extra Credit: Account for leap years -- 2020
*/

#include <iostream>
using namespace std;

//prototypes
int getC(int yyyy, int mm);
int getY(int yyyy, int mm);
void printDay(int W);
void leapCheck(int yyyy, int mm, int d);
void DoW(int yyyy, int mm, int d, int Y, int C, int m){
	int W;
	C = getC(yyyy, mm);
	Y = getY(yyyy, mm);
	
	W = d + (int(2.6 * m - 0.2)) - (2 * C) + Y + (int(Y/4)) + (int(C/4)); // formula
	W = W % 7; // make sure mod works
	printDay(W);
	cout << endl << W;
}



int main(){
	int d, m, Y, C, W;
	int mm, dd, yyyy;
	
	cout << "Please enter the day as mm dd yyyy separated by spaces: ";
	cin >> mm >> dd >> yyyy;
	
	// months start w/ march (1)
	d = dd;								//day
	
	
	if (mm == 1 || mm == 2){		//if month is march/april m+10 to make jan feb
		m = mm + 10;		
			
	}
	
	else{
		m = mm-2;				//month not march or april month is month is -2 to make march 1
	}
	
	cout << "century: " << getC(yyyy, mm) << endl;  //easier to see when things go wrong with the numbers
	cout << "year: " << getY(yyyy, mm) << endl;
	cout << "month (reg): " << mm << endl;
	cout << "month (variation): " << m << endl;
	cout << "day: " << d << endl;
	//leapCheck(yyyy, mm, d);
	
	if (mm > 12){ // if months exceed 12
		cout <<  "not a valid date";
	}
	
	else if (mm == 4,6,9,11 && d > 30){ // 2 is april 4 is june 7 is sept 9 is nov no more than 30 days //problem
		cout <<  "not a valid date";
	}
	
	//leap year
	else if(mm == 2 && d == 29){			//if february and above 28 days 
		if (yyyy % 4 == 0){					
	      if (yyyy % 100 == 0){
	         if(yyyy % 400 == 0){
	         	DoW(yyyy, mm, d, Y, C, m);
	         }
	         else{
	            cout <<  "not a valid date" << endl;
	         }
	      }
	      else{
	        DoW(yyyy, mm, d, Y, C, m);
	      }
	   }
	   else{
	      cout <<  "not a valid date" << endl;
	   }
		
	}
	else if (d > 28 && mm == 2){ // if the day is more than 28 on february
		cout << "not a valid date";
	}
	
	
	else {
		DoW(yyyy, mm, d, Y, C, m);
		/*
		C = getC(yyyy);
		Y = getY(yyyy, mm);
		
		W = d * (int(2.6 * mm - 0.2)) - (2 * C) + Y + (int(Y/4)) + (int(C/4)); // formula
		W = W % 7; // make sure mod works
		printDay(W);
		cout << endl << W;
		*/
	}
}																									//main

int getC(int yyyy, int mm){					//century
	int C;
	C = yyyy / 100;
	
	if (C % 2 == 0 && yyyy % 100 == 0){ // checks for century if mod 0 minus 1 year 20-1=19 (also not for all cases)
		C -= 1;							//would not work if was 2020 (fix, yyyy mod)
		return C;
	}
	
	else{
		return C;
	}
}

int getY(int yyyy, int mm){			
	yyyy %= 100;
	
	if(yyyy == 0){
		yyyy = 99;
		return yyyy;
	}
	
	else if(mm == 1 || mm == 2){			//gets if month is jan/feb year
		yyyy -= 1;
		return yyyy;
	}
}

void printDay(int W){
		
	if (W < 0) 
		W = W + 7; // if goes into negatives
	switch (W){
		case 0: cout << "sunday"; break;
		case 1: cout << "monday"; break;
		case 2: cout << "tuesday"; break;
		case 3: cout << "wednesday"; break;
		case 4: cout << "thursday"; break;
		case 5: cout << "friday"; break;
		case 6: cout << "saturday"; break;
		default: cout << "broken"; break;
	}
}

void leapCheck(int yyyy, int mm, int d){
	if(mm == 2 && d == 29){			//if february and above 28 days
		if (yyyy % 4 == 0){
	      if (yyyy % 100 == 0){
	         if(yyyy % 400 == 0){
	         }
	         else{
	            cout <<  "not a valid date" << endl;
	         }
	      }
	      else{
	        
	      }
	   }
	   else{
	      cout <<  "not a valid date" << endl;
	   }
		
	}
}






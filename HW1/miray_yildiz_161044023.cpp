/* CSE 241 Homework Assignment 1
**       MIRAY YILDIZ
**        161044023
*/

#include <iostream> 
const int limit (46*46); /* Define limit for array size, if number>46 integer values exceed */
using namespace std;

void print_Fibonacci(int number, int arr[]){ /* The function that print Fibonacci pyramid */
	
	int i,j;

	for (i = 0; i<limit; i++){ /* Fill the array with zero */
		arr[i] = 0;	
	}

	 
	arr[0] = 1; /* First element is 1 */
	if (number == 0){ 
		cout << arr[0] << '\n';
		cout << "Biggest number: "
			<< arr[0] << '\n';
	        return ;
	}

	else if (number == 1){ 

		arr[number + 1] = 1; /* Fill array's second and third elements */
		arr[number + 2] = 1;

		cout << arr[0] << '\n';
		cout << arr[number + 1] <<' '<< arr[number + 2]<< '\n';
		cout << "Biggest number: "
			<< arr[0] <<'\n';
		cout <<"Heart of the pyramid: " 
		     << arr[number + 1] <<' '<< arr[number + 2];
		
	}

		
	else{ 
	        arr[number + 1] = 1; /* Fill array's second and third elements */
	        arr[number + 2] = 1;
	
	        cout << arr[0] << '\n'; /* Print first second and third elements */
	        cout << arr[number + 1] << ' ';
	        cout << arr[number + 2] << '\n';


	        /* Fibonacci pyramids conditions */

	        for(i = 0; i<(number - 1); i++){  /* First, I've calculated the last fibonacci element of each line */ 
		        /* To make this calculation, the last two fibonacci elements of the two lines above are collected. */
		        arr[(number + 1) * (i + 2) + (i + 2)] = arr[(number + 1) * i + i] + arr[(number + 1) * (i + 1) + (i + 1)];
		        cout << arr[(number + 1) * (i + 2) + (i + 2)] << ' ';

		        for(j = i + 2; j > 0; j--){ /* Other elements in that line are also calculated. */
		        /* In this calculation, the sum of the elements in the two lines above the element we want is taken. */
			        arr[(number + 1)*(i + 2) + (j - 1)] = arr[(number + 1) * i + (j - 1)] + arr[(number + 1) * (i + 1) + (j - 1)];
			        cout << arr[(number + 1)*(i + 2) + (j - 1)] << ' ';
		        }
		        cout << '\n' ; /* Bottom line */

	        }

	        cout << "Biggest number: "  /* Print biggest number, biggest number is the last calculated number */
	        //<< arr[limit-1]
		         << arr[(number + 1)*(i + 2) + (j - 1)]
		         <<'\n';

		        /* Conditions which calculate heart of the pyramid */

	        if(number % 2 == 0){ /* If number is even */
		        if((((number + 2) / 2 ) * (number + 1) + number + 1) % 2 == 0){
			        cout <<"Heart of the pyramid: " 
				         << arr[((number+2) / 2  ) * (number + 1)  + ((number+2) / 2 + 1) / 2 - 1] 
				         << ' '
				         << arr[((number+2) / 2 ) * (number + 1) + ((number+2) / 2 + 1) / 2  ];
			        }
		        else{
			        cout <<"Heart of the pyramid: " 
				         << arr[((number+2) / 2  ) * (number + 1) + ((number + 2) / 4 )]; 
		        }
	        }

	        else { /* If number is odd */
		        if((((number + 1) / 2 ) * (number + 1) + (number + 1) / 2 ) % 2 != 0){
			        cout <<"Heart of the pyramid: " 
				         << arr[((number+1) / 2  ) * (number + 1)  + ((number+1) / 2 + 1) / 2 - 1] 
				         << ' '
				         << arr[((number+1) / 2 ) * (number + 1) + ((number+1) / 2 + 1) / 2  ];
		        }
		        else{
			        cout <<"Heart of the pyramid: " 
				         << arr[((number+1) / 2 ) * (number + 1) + ((number + 1) / 4 )]; 
		        }

	        }
        }

}


int main(){
	int number;
	cin >> number; /* Get a number from the user */
	while(1){ /* Condition */
		if(number < 0 || number > 46){ /* If the number smaller than 0 or greater than 46 retrieve number from the user again */
			cin >> number;
		}
		else /* If the number is not smaller than 0 or greater than 46, break */
			break;
	}
	//int limit = (number+1) * (number+1);
	int arr[limit]; /* Define array */
	print_Fibonacci(number, arr); /* Call the function */
	return 0;

}

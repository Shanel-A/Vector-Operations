#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;


// Loop/Exit
void prmpt() {
  cout << "\n\nPress any key to go back to MAIN MENU or X/x to exit." << endl;
}

//-----------------------------------------------------------------------------------------------------------------------

int main() {
  int ans;
  int x1, y1, x2, y2, x3, y3;
  double view_vector_x, view_vector_y;
  double length, lengthSquared;
  double speed, doubleSpeed, halfSpeed;
  double directionX, directionY, viewX, viewY;
  float view_vector_length;
  
  system("cls");

  cout << "MENU FOR VECTOR OPERATIONS" << endl;
  cout << "[1] Calculating the current position of a game character" << endl;
  cout << "[2] Subtracting Vectors" << endl;
  cout << "[3] Adding Vectors" << endl;
  cout << "[4] Vector Length" << endl;
  cout << "[5] Distance Comparison" << endl;
  cout << "[6] Vector Scaling" << endl;
  cout << "[7] Unit Length" << endl;
  cout << "[8] Exit" << endl;
  cout << "Enter your choice: ";
  cin >> ans;

  switch (ans) {
    case 1:
    	system("cls");
    	cout << "Input previous position of Pacman in x-coordinate: ";
    	cin >> x1;
    	cout << "Input previous position of Pacman in y-coordinate: ";
    	cin >> y1;
    	system("cls");
    	cout << "Input vector of Pacman in x-coordinate: ";
    	cin >> x2;
    	cout << "Input vector of Pacman in y-coordinate: ";
    	cin >> y2;
    	system("cls");
    	cout << "The game's character NEW POSITION (current) is at (" << x1 + x2 << ", " << y1 + y2 << ")" << endl;
    	break;
    case 2:
    	system("cls");
		cout << "Input position of Pacman in x-coordinate: ";
    	cin >> x1;
    	cout << "Input position of Pacman in y-coordinate: ";
    	cin >> y1;
    	system("cls");
		cout << "Input position on Inky in x-coordinate: ";
    	cin >> x2;
    	cout << "Input position on Inky in y-coordinate: ";
    	cin >> y2;
    	cout << "\nThe vector that will take Inky to Pacman is (" << x1 - x2 << ", " << y1 - y2 << ")" << endl;
      	break;
    case 3:
    	system("cls");
		cout << "Input the first direction where Pacman wants to go in x-coordinate: ";
    	cin >> directionX;
    	cout << "Input the first direction where Pacman wants to go in y-coordinate: ";
    	cin >> directionY;
    	system("cls");
		cout << "Input the second direction where Pacman wants to in x-coordinate: ";
    	cin >> x2;
    	cout << "Input the second direction where Pacman wants to in y-coordinate: ";
    	cin >> y2;
    	system("cls");
    	cout << "Pacman's new velocity (diagonally) is (" << directionX + x2 << ", " << directionY + y2 << ")" << endl;
    	break;
    case 4:
    	system("cls");
    	cout << "Input Pacman's x-coordinate: ";
    	cin >> x1;
    	cout << "Input Pacman's y-coordinate: ";
    	cin >> y1;
    	system("cls");
		cout << "Input Inky's x-coordinate: ";
    	cin >> x2;
    	cout << "Input Inky's y-coordinate: ";
    	cin >> y2;
    	length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    	system("cls");
		cout << "The distance from Inky to Pacman is " << length << endl;
    	break;
    case 5:
    	system("cls");
		cout << "Input location of Pacman in x-coordinate: ";
    	cin >> x1;
    	cout << "Input location of Pacman in y-coordinate: ";
    	cin >> y1;
    	system("cls");
    	cout << "Input location of Inky in x-coordinate: ";
    	cin >> x2;
    	cout << "Input location of Inky in y-coordinate: ";
    	cin >> y2;
    	system("cls");
    	cout << "Input location of Clyde in x-coordinate: ";
    	cin >> x3;
    	cout << "Input location of Clyde in y-coordinate: ";
    	cin >> y3;
    	system("cls");
    	//Inky to Pacman
		lengthSquared = pow(x2 - x1, 2) + pow(y2 - y1, 2);
								//Clyde to Pacman
			if (lengthSquared < pow(x3 - x1, 2) + pow(y3 - y1, 2)) {
				cout << "Length squared of Inky to Pacman is " << lengthSquared << endl;
				cout << "Length squared of Clyde to Pacman is " << pow(x3 - x1, 2) + pow(y3 - y1, 2) << endl;
				cout << "\nTherefore, Inky can go to Pacman faster as compared to Clyde." << endl;
			} else {
				cout << "Length squared of Clyde to Pacman is " << pow(x3 - x1, 2) + pow(y3 - y1, 2) << endl;
				cout << "Length squared of Inky to Pacman is " << pow(x2 - x1, 2) + pow(y2 - y1, 2) << endl;
				cout << "\nTherefore, Clyde can go to Pacman faster as compared to Inky." << endl;
			}
    	break;
    case 6:
    	system("cls");
		cout << "Input Pacman's initial direction in x-coordinate: ";
    	cin >> directionX;
    	cout << "Input Pacman's initial direction in y-coordinate: ";
    	cin >> directionY;
    	speed = sqrt(pow(float(directionX), 2) + pow(float(directionY), 2));
    	doubleSpeed = speed * 2;
    	halfSpeed = speed / 2;
    	system("cls");
		cout << "Pacman's initial speed is " << speed << endl;
    	cout << "Pacman's double speed is " << doubleSpeed << endl;
    	cout << "Pacman's half speed is " << halfSpeed << endl;
    	break;
    case 7:
    	system("cls");
		cout << "Input direction of Inky in x-coordinate: ";
    	cin >> directionX;
    	cout << "Input direction of Inky in y-coordinate: ";
    	cin >> directionY;
    	system("cls");
    	cout << "Input direction of Pacman in x-coordinate: ";
    	cin >> viewX;
    	cout << "Input direction n of Pacman in y-coordinate: ";
    	cin >> viewY;
    	// Compute the view vector.
		view_vector_x = directionX - viewX;
		view_vector_y = directionY - viewY;
		
		// Normalize the view vector.
		view_vector_length = sqrt(view_vector_x * view_vector_x + view_vector_y * view_vector_y);
		  if (view_vector_length == 0) {
		    view_vector_length = 1;
		  } else {
		    	view_vector_x /= view_vector_length;
		        view_vector_y /= view_vector_length;
			}

    	system("cls");
		cout << "Pacman's view vector is (" << fixed << setprecision(6) << view_vector_x << ", " << view_vector_y << ")" << endl;
    	cout << "Pacman's view length is " << view_vector_length << endl;
    	break;
    case 8:
    	return(0);
    default:
    	cout << "Invalid choice!" << endl;
    	break;
  }
  
  	// Print the message to press any key to go back to the main menu or X/x to exit.
	prmpt();
	
	// Get the user's input
	char ch;
	cin >> ch;
	
	// If the user presses any key, go back to the main menu.
	if (ch != 'X' && ch != 'x') {
	  main();
	}

  return 0;
}


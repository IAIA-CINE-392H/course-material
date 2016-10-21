#include <iostream>
#include <string>
#include "artist.h"

using namespace std;

int main()
{
	Artist Artist1;   
	Artist Artist2;

	Artist1.firstName = "Sherwin";
	Artist1.lastName = "Bitsui";
	Artist1.description = "Sherwin Bitsui is originally from Baa'oogeedí, on the Navajo Nation. His book, Floodsong, won the American Book Award and the PEN Open Book Award.";

	Artist2.firstName = "Joy";
	Artist2.lastName = "Harjo";
	Artist2.description = "Joy Harjo is a Mvskoke poet, musician, and author. She is often cited as playing a formidable role in the second wave of what critic Kenneth Lincoln termed the Native American Renaissance of the late 20th century.";

	string input;

	while (true) {

		cout << "Make a selection: Bitsui, Harjo, All. Type Quit to exit.";

		getline(cin, input);

		if (input == "Bitsui") {
			Artist1.print();
		}
		else if (input == "Harjo") {
			Artist2.print();
		}
		else if (input == "All") {
			Artist ArtistList[2];
			ArtistList[0] = Artist1;
			ArtistList[1] = Artist2;

			for (auto a : ArtistList) {
				a.print();
			}
		}
		else if (input == "Quit") {
			break;
		}
		else {
			cout << "Invalid entry" << endl;
		}
	}
}
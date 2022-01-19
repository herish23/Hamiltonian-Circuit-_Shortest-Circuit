
#include<iostream> 
#include<iomanip>
using namespace std;

double ary[10][10]; //can be set to any size 
int completed[10];
double dis = 0;
int n;
bool hasCycle;

void display()
{
	int i, j;

	cout << "Enter the number of destination: ";
	cin >> n;

	cout << "\nEnter the Matrix\n";

	for (i = 0; i < n; i++)
	{
		cout << "\nEnter Elements of Row: " << i + 1 << "\n";

		for (j = 0; j < n; j++)
			cin >> ary[i][j];

		completed[i] = 0;
	}

	cout << "\n\nThe matrix list is:";

	for (i = 0; i < n; i++)
	{
		cout << "\n";

		for (j = 0; j < n; j++)
			cout << "\t" << ary[i][j] << setw(4);
		cout << "\n";
	}



}

int least(int c)
{
	int newcity = 999;
	double min = 999, max;


	for (int i = 0; i < n; i++)
	{
		if ((ary[c][i] != 0) && (completed[i] == 0))
			if (ary[c][i] + ary[i][c] < min)
			{
				min = ary[i][c] + ary[c][i];
				max = ary[c][i];
				newcity = i;

			}
	}

	if (min != 999)
		dis += max;

	return newcity;
}

void mindist(int city)
{
	int i, newcity;

	completed[city] = 1;

	cout << city + 1 << "--->";
	newcity = least(city);

	if (newcity == 999)    //if city distance in table is 999
	{
		newcity = 0;		 //ncity will be taken as 0 and next path will be taken 
		cout << newcity + 1;
		dis += ary[city][newcity]; //new city will be added to prev city as it cant be traveled straight

		return;
	}

	mindist(newcity);
}





int main()
{
	display();
	cout << "\n\nThe Shortest Circuit is:\n";
	mindist(0);

	cout << "\nTotal travelling distance through is  " << dis << endl;

	return 0;
}







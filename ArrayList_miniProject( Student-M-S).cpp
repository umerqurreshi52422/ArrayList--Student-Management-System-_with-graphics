#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

HANDLE	h = GetStdHandle(STD_OUTPUT_HANDLE);

struct student
{
	string regno;
	string name;
	string cnic;
	float gpa;

	student()
	{
		regno = "Noregno";
		name = "Noname";
		cnic = "NoCnic";
		gpa = 0.0;
	}
};

class arraylist
{

public:
	student* arr;
	int size;
	int s_count = 0;
	arraylist()
	{
		SetConsoleTextAttribute(h, 90);
		cout << "\n\n\n\t\t\t -------------> Enter size of the arraylist : <---------------------\n";
		SetConsoleTextAttribute(h, 7);
		cin >> size;
		arr = new student[size];
		system("cls");
	}

	bool ismepty()
	{
		if (s_count == 0)
			return true;
		else return false;
	}

	bool isfull()
	{
		if (s_count == size)
			return true;
		else return false;
	}

	void resize()
	{
		student* temparr = new student[size * 2];
		size = size * 2;                                //yakki 1hr ->size have to change while resizing
		int arrsize = (sizeof(arr) / sizeof(arr[0]));    // to get the length of the previous array
		for (int i = 0; i < arrsize; i++)
		{
			temparr[i].regno = arr[i].regno;
			temparr[i].name = arr[i].name;
			temparr[i].cnic = arr[i].cnic;
			temparr[i].gpa = arr[i].gpa;
		}

		delete[] arr;
		arr = temparr;

	}

	void insertstudent()
	{
		int ch, in, flag = 0, position = 0;
		string r;

		if (isfull())
		{
			SetConsoleTextAttribute(h, 10);
			cout << " \n\t The ArrayList Is resized \n";
			SetConsoleTextAttribute(h, 7);
			resize();
		}

		SetConsoleTextAttribute(h, 10);
		cout << " \n\t\t\t INSERTION (ArrayList)\n";
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "\n********************************\n";
		SetConsoleTextAttribute(h, 7);
		cout << " 1. Insert at the end           *\n";
		cout << " 2. Insert at Index             *\n";
		cout << " 3. Insert after Regno          *\n";
		cout << " 4. Main Menu                   *\n";
		SetConsoleTextAttribute(h, 6);
		cout << "********************************\n";
		SetConsoleTextAttribute(h, 7);
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << " \n\n Enter Information \n";
			cout << " Name : ";
			cin >> arr[s_count].name;
			cout << " Reg No : ";
			cin >> arr[s_count].regno;
			cout << " CNIC : ";
			cin >> arr[s_count].cnic;
			cout << " GPA : ";
			cin >> arr[s_count].gpa;
			cout << endl;
			s_count++;
			cout << "\n\t Student Added Successfully \n";


			break;
		case 2:
			in = getindex();
			for (int i = s_count - 1; i >= in; i--)           //chiska k index khali kro jahan insert krna
			{											// revrse loop will only work with this condition else one value will be copied everywhere
				arr[i + 1].regno = arr[i].regno;
				arr[i + 1].name = arr[i].name;
				arr[i + 1].cnic = arr[i].cnic;
				arr[i + 1].gpa = arr[i].gpa;
			}

			cout << " \n\n Enter Information \n";
			cout << " Name : ";
			cin >> arr[in].name;
			cout << " Reg No : ";
			cin >> arr[in].regno;
			cout << " CNIC : ";
			cin >> arr[in].cnic;
			cout << " GPA : ";
			cin >> arr[in].gpa;
			cout << endl;
			s_count++;
			cout << "\n\t Student Added Successfully \n";
			break;

		case 3:
			r = getRegno();

			for (int i = 0; i < s_count; i++)
			{
				if (arr[i].regno == r)
				{
					position = i;
					flag++;
					break;
				}
			}
			if (flag == 0)
			{
				cout << "\n\t\t No Match found with the given RegNo !!! \n";
				return;
			}
			else
			{
				position = position + 1;
				for (int i = s_count - 1; i >= position; i--)
				{
					arr[i + 1].regno = arr[i].regno;
					arr[i + 1].name = arr[i].name;
					arr[i + 1].cnic = arr[i].cnic;
					arr[i + 1].gpa = arr[i].gpa;
				}

				cout << " \n\n Enter Information \n";
				cout << " Name : ";
				cin >> arr[position].name;
				cout << " Reg No : ";
				cin >> arr[position].regno;
				cout << " CNIC : ";
				cin >> arr[position].cnic;
				cout << " GPA : ";
				cin >> arr[position].gpa;
				cout << endl;
				s_count++;
				cout << "\n\t Student Added Successfully \n";
			}
			break;


		case 4:
			system("cls");
			return;
			break;
		default:
			cout << " Invalid Input ! Choose from the given options !!!";
		}


		system("cls");
	}

	void display()
	{


		int v = 1;
		for (int i = 0; i < s_count; i++)
		{
			cout << " Student " << v << " Record \n";
			SetConsoleTextAttribute(h, 13);           //changing color to make it look better 
			cout << " NAME -> " << arr[i].name << endl;
			cout << " Reg No -> " << arr[i].regno << endl;
			cout << " CNIC -> " << arr[i].cnic << endl;
			cout << " GPA -> " << arr[i].gpa << endl;
			cout << endl;
			v++;
		}
		SetConsoleTextAttribute(h, 7);          //setting back to orignal
	}

	int getstudentcount()
	{
		return s_count;
	}

	int getindex()
	{
		int index;
		cout << " Enter the Index : ";
		cin >> index;

		return index;
	}

	string getRegno()
	{
		string regno;
		cout << " Enter the Regno of the student : ";
		cin >> regno;

		return regno;
	}

	string getname()
	{
		string n;
		cout << " Enter name of the student : ";
		cin >> n;

		return n;
	}

	string getcnic()
	{
		string c;
		cout << " Enter CNIC of the student : ";
		cin >> c;

		return c;
	}

	void deletion()
	{


		string n, r;
		int ch, in, flag = 0;
		SetConsoleTextAttribute(h, 10);
		cout << " \n\t\t\t  Deletion (ArrayList)\t\t\n\n";
		SetConsoleTextAttribute(h, 7);

		SetConsoleTextAttribute(h, 6);
		cout << "\n********************************\n";
		SetConsoleTextAttribute(h, 7);
		cout << " \t 1. Delete by Index     *\n";
		cout << " \t 2. Delete by Regno     *\n";
		cout << " \t 3. Delete by Name      *\n";
		cout << "\t 4. Main menu           *\n";
		SetConsoleTextAttribute(h, 6);
		cout << "********************************\n";
		SetConsoleTextAttribute(h, 7);
		cin >> ch;
		switch (ch)
		{
		case 1:
			in = getindex();

			if (in < s_count)
			{
				for (int i = in; i < s_count - 1; i++)     //because dealing with index s_count=5 and index=0 -> 1hr ki yakki
				{
					arr[i].name = arr[i + 1].name;
					arr[i].regno = arr[i + 1].regno;
					arr[i].cnic = arr[i + 1].cnic;
					arr[i].gpa = arr[i + 1].gpa;

				}
				s_count--;
				cout << "\n\t\t Student Deleted Successfully !!! \n";
			}
			else
			{
				cout << " \n Index out of Range !! \n";
			}

			break;
		case 2:

			r = getRegno();
			for (int i = 1; i <= s_count; i++)
			{
				if (arr[i].regno == r)
				{
					flag++;
					for (int j = i; j < s_count; j++)
					{
						arr[j].name = arr[i + 1].name;
						arr[j].regno = arr[i + 1].regno;
						arr[j].cnic = arr[i + 1].cnic;
						arr[j].gpa = arr[i + 1].gpa;
						i++;
					}
					s_count--;
					cout << "\n\t\t Student Deleted Successfully !!! \n";
					break;
				}
			}
			if (flag == 0)
			{
				cout << "\n No Matched with the given Regno Found \n";
			}

			break;
		case 3:

			n = getname();
			for (int i = 0; i <= s_count; i++)
			{
				if (arr[i].name == n)
				{
					flag++;
					for (int j = i; j < s_count; j++)
					{
						arr[j].name = arr[i + 1].name;
						arr[j].regno = arr[i + 1].regno;
						arr[j].cnic = arr[i + 1].cnic;
						arr[j].gpa = arr[i + 1].gpa;
						i++;
					}
					s_count--;
					cout << "\n\t\t Student Deleted Successfully !!! \n";
					break;
				}
			}
			if (flag == 0)
			{
				cout << "\n No Matched with the given Name Found \n";
			}

			break;

		case 4:
			system("cls");
			return;
			break;

		default:
			cout << "\n Inavlid Input ! Choose from the given options\n";
		}



	}

	void search()
	{

		int ch, flag = 0;
		string n, c, r;
		SetConsoleTextAttribute(h, 10);
		cout << " \n\n\t\t\t SEARCH (ArrayList)\t\n\n";
		SetConsoleTextAttribute(h, 7);

		SetConsoleTextAttribute(h, 6);
		cout << "\n********************************\n";
		SetConsoleTextAttribute(h, 7);
		cout << " 1. Search by Name              *\n";
		cout << " 2. Seach by Regno              *\n";
		cout << " 3. Search by Cnic              *\n";
		cout << " 4. Main menu                   *\n";
		SetConsoleTextAttribute(h, 6);
		cout << "********************************\n";
		SetConsoleTextAttribute(h, 7);
		cin >> ch;
		switch (ch)
		{
		case 1:
			n = getname();
			for (int i = 0; i <= s_count; i++)
			{
				if (arr[i].name == n)
				{
					flag++;
					cout << " \n |STUDENT FOUNT| \n";
					cout << "\n REGNO : " << arr[i].regno;
					cout << "\n NAME : " << arr[i].name;
					cout << "\n CNIC : " << arr[i].cnic;
					cout << "\n GPA : " << arr[i].gpa;
					cout << "\n\n";
					break;
				}
			}
			if (flag == 0)
			{
				cout << " This Student Record doesnot Exists \n";
			}

			break;
		case 2:
			r = getRegno();
			for (int i = 0; i <= s_count; i++)
			{
				if (arr[i].regno == r)
				{
					flag++;
					cout << " \n |STUDENT FOUNT| \n";
					cout << "\n REGNO : " << arr[i].regno;
					cout << "\n NAME : " << arr[i].name;
					cout << "\n CNIC : " << arr[i].cnic;
					cout << "\n GPA : " << arr[i].gpa;
					cout << "\n\n";
					break;
				}
			}
			if (flag == 0)
			{
				cout << " This Student Record doesnot Exists \n";
			}
			break;
		case 3:

			c = getcnic();
			for (int i = 0; i <= s_count; i++)
			{
				if (arr[i].cnic == c)
				{
					flag++;
					cout << " \n |STUDENT FOUND| \n";
					cout << "\n REGNO : " << arr[i].regno;
					cout << "\n NAME : " << arr[i].name;
					cout << "\n CNIC : " << arr[i].cnic;
					cout << "\n GPA : " << arr[i].gpa;
					cout << "\n\n";
					break;
				}
			}
			if (flag == 0)
			{
				cout << " This Student Record doesnot Exists \n";
			}
			break;
		case 4:
			system("cls");
			return;
			break;
		default:
			cout << " \b Invalid Input ! Choose from the given options\n";
		}
	}


};

int main()
{


	arraylist a;
	student s;
	int repeat = 1, ch = -1, index = -1, rg, nic, n, delbreak = 0;

	SetConsoleTextAttribute(h, 90);
	cout << "\n\t\t\tSTUDENT RECORD (USING ARRAYLIST)\n\n\n";
	SetConsoleTextAttribute(h, 7);
	while (repeat == 1)
	{
		SetConsoleTextAttribute(h, 10);
		cout << "\n\t\t\t MENU\t\n";
		SetConsoleTextAttribute(h, 7);

		SetConsoleTextAttribute(h, 6);
		cout << "*************************************************";
		SetConsoleTextAttribute(h, 7);
		cout << "\n 1. Insert Student in Arraylist		        *\n";
		cout << " 2. Delete Student from Arraylist	        *\n";
		cout << " 3. Search Student in the ArrayList             *\n";
		cout << " 4. Display Students from the Arraylist         *\n";
		cout << " 5. Total Number of Students in List ?          *\n";
		SetConsoleTextAttribute(h, 6);
		cout << "*************************************************\n";
		SetConsoleTextAttribute(h, 7);

		cin >> ch;

		switch (ch)
		{
		case 1:
			system("cls");
			a.insertstudent();
			break;
		case 2:
			system("cls");
			a.deletion();

			break;
		case 3:
			system("cls");
			a.search();

			break;
		case 4:

			a.display();
			break;
		case 5:
			system("cls");
			cout << " \n\n Total Students : " << a.getstudentcount();
			break;
		case 0:
			repeat++;
			break;
		default:
			cout << " \t\t Invalid Input ! Choose from the given options !!!\n";
		}
	}


	system("pause");
	return 0;
}
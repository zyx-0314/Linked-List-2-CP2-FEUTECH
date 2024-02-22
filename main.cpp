// Store Students Information

#include <iostream>
#include <iomanip>

struct Student {
	// Address
	Student* next = NULL;
	Student* prev = NULL;
	// Informations
	std::string name, sex, course, year, standing;
	int age = 0, id = 0;
};

void MainMenu(int&);
Student* AddNewStudent();

int main()
{
	int choice, studentCounter = 0;
	Student* head = NULL, * tail = NULL, * temp = NULL;

	do
	{
		MainMenu(choice);

		switch (choice)
		{
		case 1:
			temp = AddNewStudent();
			if (studentCounter) {
				// True: meron nang karga ang linked list
				// B.2
				temp->prev = tail;
				temp->next = NULL;

				// B.3
				tail->next = temp;

				// B.4
				tail = temp;
			}
			else
			{
				// False: wala pang karga
				// A.2
				head = temp;

				// A.3
				head->prev = NULL;
				head->next = NULL;

				// A.4
				tail = head;
			}

			studentCounter++;
			break;
		case 2:
			std::cout << "Update\n";
			break;
		case 3:
			std::cout << "Read\n";

			temp = head;

			if (temp)
			{
				do
				{
					std::cout << temp->id << " - " << temp->name << " " << temp->age << " << " << temp->course << " " << temp->year << "\n";

					if (!temp->next)
						break;

					temp = temp->next;
				} while (true);
			}

			break;
		case 4:
			std::cout << "Delete\n";
			break;
		default:
			break;
		}
	} while (true);
}

void MainMenu(int& choice) {
	std::cout
		<< "1. Add Student\n"
		<< "2. Update Student\n"
		<< "3. Check Student List\n"
		<< "4. Delete Student\n";

	std::cin >> choice;

	system("cls");
}

Student* AddNewStudent() {
	Student* studentInformation;
	studentInformation = new Student;

	std::cout
		<< "-- Student Information Form --\n\n"
		<< "Name: ";
	std::cin >> studentInformation->name;
	std::cout << "Age: ";
	std::cin >> studentInformation->age;
	std::cout << "Sex: ";
	std::cin >> studentInformation->sex;
	std::cout << "Course: ";
	std::cin >> studentInformation->course;
	std::cout << "Year: ";
	std::cin >> studentInformation->year;
	std::cout << "Standing: ";
	std::cin >> studentInformation->standing;
	std::cout << "Provided ID by School: ";
	std::cin >> studentInformation->id;

	return studentInformation;
}

//Построить иерархию классов согласно схеме наследования,
//приведенной на рисунке ниже по предметной области «Графический
//пользовательский интерфейс».Каждый класс должен содержать
//необходимые конструкторы и методы работы с полями классов.Функция
//main() должна иллюстрировать работу с массивами объектов всех созданных
//классов.При необходимости самостоятельно добавить классы для
//реализации множественного наследования.

#include <iostream>
#include <windows.h>

using namespace std;

class Control {
protected:
	int id;
	float height;
	float width;
public:
	Control(int id = 0, float height = 0, float width = 0)
	{
		cout << "Enter id: "; cin >> id;
		cout << "Enter height: "; cin >> height;
		cout << "Enter Width: "; cin >> width;
		this->id = id; this->height = height; this->width = width;
	};
	~Control() { cout << "Control died" << endl; };
	void show_data() {
		cout << "id\t" << this->id << "\n"
			<< "height\t" << this->height << "\n"
			<< "width\t" << this->width << "\n";

	}
};

class Button : public virtual Control {
protected:
	string text_alignment; // right, left, center
public:
	Button(string t_al = "center") {

		this->text_alignment = t_al;
	};
	void push_button() {
		cout << "You pushed the button" << endl;
	}
	void change_text_alignment() {
		string t_al;
		cout << "Enter text alignment: ";
		cin >> t_al;
		this->text_alignment = t_al;
		cout << "text in the button is " << this->text_alignment << "-aligned" << endl;
	}

	void show_data() {
		Control::show_data();
		cout << "text alignment:\t" << this->text_alignment << endl;
	}
	~Button() { cout << "Button died" << endl; }
};


class Image : public virtual Control {
protected:
	string stretch_style; // scaled, unscaled
	string stretch_direction; // horisontal, vertical, total
public:
	Image(string str_st = "scaled", string str_dir = "total") {

		this->stretch_style = str_st;
		this->stretch_direction = str_dir;
	}
	void change_image();
	~Image() { cout << "Image died" << endl; }

	void show_data() {
		Control::show_data();
		cout << "stretch_style:\t" << this->stretch_style << endl;
		cout << "stretch_direction:\t" << this->stretch_direction << endl;
	}
	void change_stretch_style() {
		string str_st;
		cout << "Enter stretch style: ";
		cin >> str_st;
		this->stretch_style = str_st;
	}
	void change_stretch_direction() {
		string str_dir;
		cout << "Enter stretch direction: ";
		cin >> str_dir;
		this->stretch_direction = str_dir;
	}


};


void Image::change_image() {

	float percent;
	cout << "Enter % to stretch image" << endl;
	cin >> percent;
	percent = percent / 100;
	if (this->stretch_style == "scaled") {

		this->width = this->width * percent + this->width;
		this->height = this->height * percent + this->height;
		cout << "new size is: \n";
		Control::show_data();
	}
	else {
		if (this->stretch_direction == "horisontal") {
			this->width = this->width * percent + this->width;
			cout << "new size is: \n";
			Control::show_data();
		}
		else {
			this->height = this->height * percent + this->height;
			cout << "new size is: \n";
			Control::show_data();
		}
	}



}


class Image_button : public Button, public Image {
	string content_alignment;
public:
	Image_button(string cont_al = "center") {

		this->content_alignment = cont_al;
	}
	~Image_button() { cout << "Image_button died" << endl; }
	void show_data() {
		Image::show_data();
		cout << "text alignment:\t" << this->text_alignment << endl;
		cout << "content alignment\t" << this->content_alignment << endl;
	}
	void change_cont_al() {
		string cont_al;
		cout << "Enter content alignment: ";
		cin >> cont_al;
		this->content_alignment = cont_al;
	}
};



int main() {
	cout << "Control object: " << endl;
	Control control1;
	//control1.show_data();
	cout << endl;

	cout << "Button object: " << endl;
	Button button1;
	//button1.show_data();
	button1.change_text_alignment();
	button1.push_button();
	cout << endl;

	cout << "Image object: " << endl;
	Image Image1;
	//Image1.show_data();
	Image1.change_stretch_direction();
	Image1.change_stretch_style();
	cout << endl;

	cout << "Image_button object: " << endl;
	Image_button Image_button1;
	Image_button1.show_data();

	Sleep(15000);
	cout << "\a";
	system("CLS");

	cout << "Creating an array: " << endl;
	cout << "Enter size: ";
	int size;
	cin >> size;
	cout << endl << "Enter data: " << endl;
	Image_button* arr = new Image_button[size];

	cout << endl << "Objects: ";
	for (int i = 0; i < size; i++) {
		cout << endl;
		arr[i].show_data();
	}

	int user_choice;
	int arr_choice;

	cout << endl << "Enter number of object you are going to work with: ";
	cin >> arr_choice;
	arr_choice--;
	do {
		cout << endl << "Choose function you wonna see:\n"
			<< "1 - change_image()\n"
			<< "2 - change_content_alignment()\n"
			<< "3 - change_stretch_style()\n"
			<< "4 - change_ctretch_direction()\n"
			<< "5 - change_text_alignment()\n"
			<< "6 - show_data()\n"
			<< "7 - change object\n"
			<< "0 - finish the programm\n";
		cin >> user_choice;
		switch (user_choice) {
		case 1:
			arr[arr_choice].change_image();
			break;

		case 2:
			arr[arr_choice].change_cont_al();
			break;

		case 3:
			arr[arr_choice].change_stretch_style();
			break;

		case 4:
			arr[arr_choice].change_stretch_direction();
			break;

		case 5:
			arr[arr_choice].change_text_alignment();
			break;

		case 6:
			arr[arr_choice].show_data();
			break;

		case 7:
			cout << endl << "Enter number of object you are going to work with: ";
			cin >> arr_choice;
			arr_choice--;
			break;

		case 0:
			cout << "Goodbye" << endl;
			delete[]arr;
			return 0;

		}
	} while (true);

}

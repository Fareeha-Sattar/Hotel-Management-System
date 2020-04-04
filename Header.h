#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include<windows.h>
#include<fstream>

using namespace std;

class Rooms;
class Persons;
class Customer;
class Employee;
class Fooditems;
class orderFood;
class Bill;
class Check;
class DateTime;
class Rooms {
		static int total;
	protected:
		int roomNo;
		bool isEmpty;
		
	public:

		Rooms();
		Rooms(int r, bool IE);
		Rooms(const Rooms& obj);
		bool getIsEmpty();
		void setIsEmpty(bool);
		void setRoomNo(int);
		void CustomerInfo(Customer& obj);
		void UpdateRoomInfo(int,bool);
		int getRoomNo();
		static int getTotalEmptyRooms();
		static int setTotalEmptyRooms(int);
		void operator =(const Rooms& obj1);

};
int Rooms::total=0;
class Person {
	protected:
		int ID;
		char* Name;
		long int Telephone_num;
		char Gender;
		string Address;
	public:
		Person(int ,char* ,long int ,char ,string );
		Person(const Person& obj);
		void setName(char* n);
		void setTelephoneNum(long int tn);
		void setGender(char g);
		void setAddress(string a);
		void setID(int id);
		int getID();
		char* getName();
		long int getTelephoneNum();
		virtual void printinfo();
		char getGender();
		string getAddress();
		virtual ~Person();

};
class Customer:public Person {
	protected:
		static int index;
		Rooms* roomAlloted;
		orderFood** orderedFoods;
		Check *checkInOut;
	public:
		Customer(int,char*,long int,char,string);
		Customer(const Customer& obj);
		Rooms* getRoomAlloted();
		void printinfo();
		void setCheckInOut(Check *C);
		Check* getCheckInOut();
		void CheckIn();
		void CheckOut();
		bool BooksRoom(Rooms *R);
		void setOrderedFoodItems(Fooditems *F);
		void setOrderedFood(orderFood **O);
		Fooditems* getOrderedFoodItems(int);
		orderFood** getOrderedFoods();
		friend ostream& operator << (ostream &out, const Customer &obj1);
		~Customer();

};
int Customer::index;
class Employee:public Person {
	protected:
		string Designation;
		float Salary;
		int Hours;
	public:
		Employee();
		void setDesignation(string);
		void setSalary(float);
		void setHours(int);
		string getDesignation();
		float getSalary();
		int getHours();
		void printinfo();
		~Employee();
};
class Fooditems {
	protected:
		int FoodId;
		float PricePerItem;
		string Name;
	public:
		Fooditems(int,float,string);
		int getFoodId();
		void setName(string);
		string getName();
		float getPricePerItem();
		void setPricePerItem(float);
		void displayMenu();
};
class orderFood {
	protected:
		int orderNo;
		int quantity;
		Fooditems* Foodordered;
	public:
		orderFood(int q,int i,Fooditems*F);
		orderFood(int,int);
		orderFood(const orderFood& obj);
		void setFoodQuantity(int q);
		void setFoodOrdered(Fooditems* F);
		Fooditems* getFoodOrdered();
		int getFoodQuantity();
		int getOrderNo();

};

class Bill {
	protected:
		float amount;
		const static float tax=0.19;
		const static int PricePerDay=5000;
		Customer* Client;
		Check* checkInOut;
	public:
		static int billNo;
		Bill();
		float getAmount();
		float getTaxedAmount();
		float calculateRoomBill(Customer *C,Check *DT);
		static int getBillNo();
		void DisplayBill();
		void setAmount(float n);
		static int getPricePerDay();
		float calculateFoodBill(Customer *C);
		friend Bill operator +(Bill & lhs,Bill &rhs);
		friend Bill operator -(Bill & lhs,Bill &rhs);
		friend float operator ++(Bill & obj);
		friend float operator --(Bill & obj);
		float operator ++(int);
		float operator --(int);
};
class Check {
	protected:
		DateTime *dateIn;
		DateTime *dateOut;
	public:
		Check();
		Check(const Check& obj);
		DateTime* getDateIn();
		DateTime* getDateOut();
		void setDateTimeIn(int h,int m,int d,int mo,int y);
		void setDateTimeOut(int h,int m,int d,int mo,int y);
};
class DateTime {
	protected:
		int hour,min,day,month,year;
	public:
		DataTime();
		DateTime(int,int,int,int,int);
		int getHour();
		int getMin();
		int getDay();
		int getMonth();
		int getYear();
		void setDateTime(int hour,int min,int day,int month,int year);
		void DisplayDateTime();

};

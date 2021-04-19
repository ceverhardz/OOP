//POLYMORPH TUGAS KATUUK CHRISTIAN EVEHRARD

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


using namespace std;

using std :: vector;using std :: vector;

class Employee{
	private:
		string firstname;
		string lastname;
		string socialSecurityNumber;
	public:
		Employee( const string &, const string &, const string & );
		void setFirstName( const string & );
 		string getFirstName() const;
 		
		void setLastName( const string & );
 		string getLastName() const;

 		void setSocialSecurityNumber( const string & );
 		string getSocialSecurityNumber() const;

		virtual double earnings() const = 0; 
		virtual void print() const; 
};

	Employee :: Employee( const string &first, const string &last, const string &ssn ) : firstname ( first ), lastname ( last ), socialSecurityNumber( ssn ) {
	}

	void Employee::setFirstName( const string &first ) {
		firstname = first;
	}

	string Employee::getFirstName() const {
		return firstname;
	}

	void Employee::setLastName( const string &last ) {
		lastname = last;
	}

	string Employee::getLastName() const {
		return lastname;
	}

	void Employee::setSocialSecurityNumber( const string &ssn ){
		socialSecurityNumber = ssn;
	}

	string Employee::getSocialSecurityNumber() const {
		return socialSecurityNumber;
	}
	void Employee::print() const{
		cout << getFirstName() << ' ' << getLastName()<< endl << "social security number: " << getSocialSecurityNumber() << endl;
		
	}

class SalariedEmployee : public Employee {
	private:
		double weeklySalary;
	public:
		SalariedEmployee( const string &, const string &, const string &, double = 0.0 );
		
		void setWeeklySalary( double );
		double getWeeklySalary() const;
		
		virtual double earnings() const; 
		virtual void print() const;
 
};
	SalariedEmployee::SalariedEmployee( const string &first, const string &last, const string &ssn, double salary ) : Employee( first, last, ssn ) {
		setWeeklySalary( salary );
	}
	
	void SalariedEmployee::setWeeklySalary( double salary ) {
		weeklySalary = ( salary < 0.0 ) ? 0.0 : salary;
	}
	
	double SalariedEmployee::getWeeklySalary() const {
		return weeklySalary;
	}

	double SalariedEmployee::earnings() const {
		return getWeeklySalary();
	}
	
	void SalariedEmployee::print() const {
		cout << "salaried employee: ";
		Employee::print(); 
		
		cout << "weekly salary: " << getWeeklySalary() << endl;
	}
	 
class HourlyEmployee : public Employee {
	private:
		double wage;
		double hours;
	public:
		HourlyEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0 );
		
		void setWage( double );
		double getWage() const;
		
		void setHours( double );
		double getHours() const;

		virtual double earnings() const; 
		virtual void print() const;
};

	HourlyEmployee::HourlyEmployee( const string &first, const string &last, const string &ssn, double hourlyWage, double hoursWorked ) : Employee( first, last, ssn ) {
		setWage( hourlyWage ); 
		setHours( hoursWorked );
	}

	void HourlyEmployee::setWage( double hourlyWage ) {
		wage = ( hourlyWage < 0.0 ? 0.0 : hourlyWage );
	} 

	double HourlyEmployee::getWage() const {
		return wage;
	}

	void HourlyEmployee::setHours( double hoursWorked ) {
		hours = ( ( ( hoursWorked >= 0.0 ) && ( hoursWorked <= 168.0 ) ) ? hoursWorked : 0.0 );
	}
	
	double HourlyEmployee::getHours() const {
		return hours;
	}
	
	double HourlyEmployee::earnings() const {
		if ( getHours() <= 40 )
			return getWage() * getHours();
		else
			return 40 * getWage() + ( ( getHours() - 40 ) * getWage() * 1.5 );
	}
	
	void HourlyEmployee::print() const {
		cout << endl;
		cout << "hourly employee: "; 
		Employee::print();
		
		cout << "hourly wage: " << getWage() << "; hours worked: " << getHours() << endl;
	}

class CommissionEmployee : public Employee {
	private:
		double grossSales;
		double commissionRate;
	public:
		CommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0 );
		
		void setCommissionRate( double );
		double getCommissionRate() const;
		
		void setGrossSales( double );
		double getGrossSales() const;

		virtual double earnings() const; 
		virtual void print() const;
};

	CommissionEmployee::CommissionEmployee( const string &first, const string &last, const string &ssn, double sales, double rate ) : Employee( first, last, ssn ) {
		setGrossSales( sales );
		setCommissionRate( rate );
	}
	
	void CommissionEmployee::setCommissionRate( double rate ) {
		commissionRate = ( ( rate > 0.0 && rate < 1.0 ) ? rate : 0.0 );
	}
	
	double CommissionEmployee::getCommissionRate() const {
		return commissionRate;
	}
	
	void CommissionEmployee::setGrossSales( double sales ) {
		grossSales = ( ( sales < 0.0 ) ? 0.0 : sales );
	}
	
	double CommissionEmployee::getGrossSales() const {
		return grossSales;
	}
	
	double CommissionEmployee::earnings() const {
		return getCommissionRate() * getGrossSales();
	}
	
	void CommissionEmployee::print() const {
		cout << endl;
		cout << "commission employee: ";
		Employee::print();
		
		cout << "gross sales: " << getGrossSales() << "; commission rate: " << getCommissionRate();
	}

class BasePlusCommissionEmployee : public CommissionEmployee {
	private:
		double baseSalary;
	public:
		BasePlusCommissionEmployee( const string &, const string &, const string &, double = 0.0, double = 0.0, double = 0.0 );
		void setBaseSalary( double );
		double getBaseSalary() const;

		virtual double earnings() const;
		virtual void print() const;
};

	BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate, double salary ) : CommissionEmployee( first, last, ssn, sales, rate ) {
		setBaseSalary( salary );
	}

	void BasePlusCommissionEmployee::setBaseSalary( double salary ) {
		baseSalary = ( ( salary < 0.0 ) ? 0.0 : salary );
	}

	double BasePlusCommissionEmployee::getBaseSalary() const {
		return baseSalary;
	}
	
	double BasePlusCommissionEmployee::earnings() const {
		return getBaseSalary() + CommissionEmployee::earnings();
	}
	
	void BasePlusCommissionEmployee::print() const {
		cout << endl;
		cout << "base-salaried ";
		CommissionEmployee::print();
		
		cout << "; base salary: " << getBaseSalary() << endl;
	}

void virtualViaPointer( const Employee * const );
void virtualViaReference( const Employee & );

int main(){

	cout << fixed << setprecision( 2 );
	
	SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800 );
	HourlyEmployee hourlyEmployee("Karen", "Price", "222-22-2222", 16.75, 40 );
	CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06 );
	BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300 );
	
	cout << "Employees processed individually using static binding:" << endl << endl;
	
	salariedEmployee.print();
	cout << "earned $" << salariedEmployee.earnings() << " ";
	cout << endl;
	
	hourlyEmployee.print();
	cout << "earned $" << hourlyEmployee.earnings() << " ";
	cout << endl;
	
	commissionEmployee.print();
	cout << endl << "earned $" << commissionEmployee.earnings() << " ";
	cout << endl;
	
	basePlusCommissionEmployee.print();
	cout << "earned $" << basePlusCommissionEmployee.earnings() << " ";
	
	vector < Employee * > employees( 4 ); 
	
	employees[ 0 ] = &salariedEmployee; 
	employees[ 1 ] = &hourlyEmployee; 
	employees[ 2 ] = &commissionEmployee; 
	employees[ 3 ] = &basePlusCommissionEmployee;
	cout << endl << endl;
	cout << "Employees processed polymorphically via dynamic binding:" << endl << endl;
	
	cout << "Virtual function calls made off base-class pointers:" << endl << endl;
	for ( size_t i = 0; i < employees.size(); i++ )
	virtualViaPointer( employees[ i ] ); 
	
	cout << endl << "Virtual function calls made off base-class references:" << endl << endl;
	for ( size_t i = 0; i < employees.size(); i++ ) 
	virtualViaReference( *employees[ i ] );	
	
	return 0;
} 

void virtualViaPointer( const Employee * const baseClassPtr ) { 
	baseClassPtr->print(); 
	cout << "earned $" << baseClassPtr->earnings() << " " << endl;
	}

void virtualViaReference( const Employee &baseClassRef ) { 
	baseClassRef.print();
	cout << "earned $" << baseClassRef.earnings() << " " << endl;
}

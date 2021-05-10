// Deposit.cpp
// Member-function definitions for class Deposit.
#include "Deposit.h" // Deposit class definition
#include "Screen.h" // Screen class definition
#include "BankDatabase.h" // BankDatabase class definition
#include "Keypad.h" // Keypad class definition
#include "DepositSlot.h" // DepositSlot class definition

const static int CANCELED = 0; // constant representing cancel option

// Deposit constructor initializes class's data members
Deposit::Deposit( int userAccountNumber, Screen &atmScreen,BankDatabase &atmBankDatabase, Keypad &atmKeypad,DepositSlot &atmDepositSlot )
: Transaction( userAccountNumber, atmScreen, atmBankDatabase ),keypad( atmKeypad ), depositSlot( atmDepositSlot ){
	// empty body
} // end Deposit constructor

// performs transaction; overrides Transaction's pure virtual function
void Deposit::execute(){
	BankDatabase &bankDatabase = getBankDatabase(); // get reference
	Screen &screen = getScreen(); // get reference
	
	amount = promptForDepositAmount(); // get deposit amount from user

	// check whether user entered a deposit amount or canceled
	if ( amount != CANCELED ){
		// request deposit envelope containing specified amount
		screen.displayMessage("Please insert a deposit envelope containing " );
		screen.displayDollarAmount( amount );
		screen.displayMessageLine( " in the deposit slot." );

		// receive deposit envelope
		bool envelopeReceived = depositSlot.isEnvelopeReceived();
	
		// check whether deposit envelope was received
		if ( envelopeReceived ){
			screen.displayMessageLine( "Your envelope has been received.""NOTE: The money just will not be available until we""verify the amount of any enclosed cash, and any enclosed ""checks clear." );
	
			// credit account to reflect the deposit
			bankDatabase.credit( getAccountNumber(), amount );
		} // end if
		else // deposit envelope not received
		{
			screen.displayMessageLine( "You did not insert an ""envelope, so the ATM has canceled your transaction." );
		} // end else
	} // end if
	else // user canceled instead of entering amount
	{
		screen.displayMessageLine( "Canceling transaction..." );
	} // end else
} // end function execute

// prompt user to enter a deposit amount in cents
double Deposit::promptForDepositAmount() const{
	Screen &screen = getScreen(); // get reference to screen

	// display the prompt and receive input
	screen.displayMessage( "Please enter a deposit amount in ""CENTS (or 0 to cancel): " );
	int input = keypad.getInput(); // receive input of deposit amount

	// check whether the user canceled or entered a valid amount
	if ( input == CANCELED )
	return CANCELED;
	else{
		return static_cast< double >( input ) / 100; // return dollar amount
	} // end else
} // end function promptForDepositAmount

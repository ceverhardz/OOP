  // Withdrawal.cpp
  // Member-function definitions for class Withdrawal.
  #include "Withdrawal.h" // Withdrawal class definition
  #include "Screen.h" // Screen class definition
  #include "BankDatabase.h" // BankDatabase class definition
  #include "Keypad.h" // Keypad class definition
  #include "CashDispenser.h" // CashDispenser class definition
 
  // global constant that corresponds to menu option to cancel
 const static int CANCELED = 6;

 // Konstruktor penarikan menginisialisasi anggota data kelas
 Withdrawal::Withdrawal( int userAccountNumber, Screen &atmScreen,
 BankDatabase &atmBankDatabase, Keypad &atmKeypad,
 CashDispenser &atmCashDispenser )
 : Transaction( userAccountNumber, atmScreen, atmBankDatabase ),
 keypad( atmKeypad ), cashDispenser( atmCashDispenser )
 {
 // empty body
 } // end Withdrawal constructor

 // melakukan transaksi; mengesampingkan fungsi virtual murni Transaksi
 void Withdrawal::execute()
 {
 bool cashDispensed = false; // cash was not dispensed yet
 bool transactionCanceled = false; // transaction was not canceled yet

 // get references to bank database and screen
 BankDatabase &bankDatabase = getBankDatabase();
 Screen &screen = getScreen();

 // loop hingga uang tunai dibagikan atau pengguna membatalkan
 do
 {
 // dapatkan jumlah penarikan yang dipilih dari pengguna
 int selection = displayMenuOfAmounts();

 // periksa apakah pengguna memilih jumlah penarikan atau dibatalkan
 if ( selection != CANCELED )
 {
 amount = selection; // set amount to the selected dollar amount

 // dapatkan saldo akun yang tersedia
 double availableBalance =
 bankDatabase.getAvailableBalance( getAccountNumber() );

 // periksa apakah pengguna memiliki cukup uang di akun
 if ( amount <= availableBalance )
 {
// periksa apakah mesin ATM memiliki cukup uang
 if ( cashDispenser.isSufficientCashAvailable( amount ) )
 {
 // perbarui akun yang terlibat untuk mencerminkan penarikan
 bankDatabase.debit( getAccountNumber(), amount );

 cashDispenser.dispenseCash( amount ); // dispense cash
 cashDispensed = true; // cash was dispensed

 // perintahkan pengguna untuk mengambil uang tunai
 screen.displayMessageLine("Please take your cash from the cash dispenser." );
 } // end if
 else // mesin ATM tunai tidak memiliki cukup uang tunai
 screen.displayMessageLine("Insufficient cash available in the ATM.""Please choose a smaller amount." );
 } // end if
 else // tidak cukup uang yang tersedia di akun pengguna
 {
 screen.displayMessageLine("Insufficient funds in your account." "Please choose a smaller amount." );
 } // end else
 } // end if
 else // pengguna memilih opsi menu batal
 {
 screen.displayMessageLine( "Canceling transaction..." );
 transactionCanceled = true; // pengguna membatalkan transaksi
 } // end else
 } while ( !cashDispensed && !transactionCanceled ); // end do...while
 } // end function execute

// menampilkan menu jumlah penarikan dan opsi untuk membatalkan;
 // kembalikan jumlah yang dipilih atau 0 jika pengguna memilih untuk membatalkan
 int Withdrawal::displayMenuOfAmounts() const
 {
 int userChoice = 0; // variabel lokal untuk menyimpan nilai pengembalian

 Screen &screen = getScreen(); // dapatkan referensi layar

// larik jumlah yang sesuai dengan nomor menu
 int amounts[] = { 0, 20, 40, 60, 100, 200 };

 // loop while no valid choice has been made
 while ( userChoice == 0 )
 {
 // tampilkan menu
 screen.displayMessageLine( "Withdrawal options:" );
 screen.displayMessageLine( "1 - $20" );
 screen.displayMessageLine( "2 - $40" );
 screen.displayMessageLine( "3 - $60" );
 screen.displayMessageLine( "4 - $100" );
 screen.displayMessageLine( "5 - $200" );
 screen.displayMessageLine( "6 - Cancel transaction" );
 screen.displayMessage( "Choose a withdrawal option (1-6): " );

 int input = keypad.getInput(); // get user input through keypad

 
 switch ( input )
 {
 case 1: // if the user chose a withdrawal amount
 case 2: // (i.e., chose option 1, 2, 3, 4 or 5), return the
 case 3: // corresponding amount from amounts array
 case 4:
 case 5:
 userChoice = amounts[ input ]; // save user's choice
 break;
 case CANCELED: // the user chose to cancel
 userChoice = CANCELED; // save user's choice
 break;
 default: // the user did not enter a value from 1-6
 screen.displayMessageLine("Ivalid selection. Try again." );
 } // end switch
 } // end while

 return userChoice; // return withdrawal amount or CANCELED
 } // end function displayMenuOfAmounts

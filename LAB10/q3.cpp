#include <iostream>
using namespace std;

class Document{ // Document class
	public:
		//Constructors
		Document(); // default cosntructor
		Document(string text_param); //constructor with parameter
  		void setText(const string set_text); //setter
		string getText()const; // getter

		Document &operator=(const Document& assign); //assignment operator overloading

	private:
		string text;
};

class Email:public Document{ // Email class which is derived from Document class
	public:
		Email():Document(),sender(""),recipient(""),title(""){/* Body Intentionally Empty */} // default constructor
		Email(string tex,string s,string r, string t):Document(tex),sender(s),recipient(r),title(t){/* Body Intentionally Empty */} //constructor with parameter

		//SETTERS
		void setSender(const string sender_param);
		void setRecipient(const string recipient_param);
		void setTitle(const string title);
		
		//GETTERS
		string getSender()const;
		string getRecipient()const;
		string getTitle()const;

		Email& operator=(const Email& mail); //assignment operator overloading
		void show();

		private:
			string sender;
			string recipient;
			string title;
};

class File:public Document{ //File class which is derived from Document class
	public:
		//Constructors
		File():Document(),pathname(""){/* Body Intentionally Empty */ } // Default Constructor
		File(string text_param,string name):Document(text_param),pathname(name){/* Body Intentionally Empty */} //constructor with parameter
		void setPathName(const string name); // SETTER
		string getPathName()const; // GETTER
		File& operator=(const File& obj); //assignment operator overloading
		void showFileDetails();

	private:
		string pathname;
};

bool ContainsKeyword( const Document& docObject, string keyword){
	if (docObject.getText().find(keyword) != string::npos)
		return true;
	
	return false;
}


Document::Document(){
	text = " ";
}

Document::Document(string text_param){
	text = text_param;
}

void Document::setText(const string set_text){
	this->text = set_text;
}


string Document::getText()const{
	return this->text;
}

Document& Document::operator=(const Document& assign){
	this->text = assign.text;
	return *this;
}

void Email::setSender(const string sender_param){
	this->sender = sender_param;
}

string Email::getSender()const{
	return sender;
}

void Email::setRecipient(const string recipient_param){
	this->recipient = recipient_param;
}

string Email::getRecipient()const{
    return this->recipient;
}

void Email::setTitle(const string title_param){
	this->title = title_param;
}

string Email::getTitle()const{
	return this->title;
}

Email& Email::operator=(const Email& mail){
			this->sender = mail.sender;
			this->recipient = mail.recipient;
			this->title = mail.title;
			return *this;
}

void Email::show(){
	cout << "From: " << sender << "\nTo: " << recipient << "\nTitle: " << title << "\n\n" ;
}


void File::setPathName(const string nameParam){
	this->pathname = nameParam;
}
string File::getPathName()const{
	return this->pathname;
}

void File::showFileDetails(){
	cout << pathname << ": " << endl;
}

File& File::operator=(const File& obj){
	this->pathname = obj.pathname;
	return *this;
}



int main(){

	string example = "GTU is really difficult university!!!";
	string example2 = "Please, HELP ME!!!";

	Email ex1(example,"Student who studies computer engineering at GTU!","GTU-Diaconate","Difficult Education System!!!");
	Email ex2(example2,"MIT","GTU","Change your Education System for the health of your students... :)))");
	File file1(example, "gtu.txt");
	File file2(example2, "requestofmit.txt");
	string keyword = "GTU";
		if (ContainsKeyword(ex1, keyword))
			cout << "Email-1 has keyword " << keyword << endl;
		else
			cout << "Email-1 does not have keyword " << keyword << endl;
	
		if (ContainsKeyword(ex2, keyword))
			cout << "Email-2 has keyword " << keyword << endl;
		else
			cout << "Email-2 does not have keyword " << keyword << endl;
	
		if (ContainsKeyword(file1, keyword))
			cout << "File-1 has keyword " << keyword << endl;
		else
			cout << "File-1 does not have keyword " << keyword << endl;
	
		if (ContainsKeyword(file2, keyword))
			cout << "File-2 has keyword " << keyword << endl;
		else
			cout << "File-2 does not have keyword " << keyword << endl;
	
		cout << "\nEmail-1 "<< endl;
		ex1.show();
		cout << endl;
		cout << "Email-2 "<< endl;
		ex2.show();
		cout << endl;
		cout << "File-1's path: " << file1.getPathName() << endl;
		cout << "File-2's path: " << file2.getPathName() << endl;
	return 0;
}
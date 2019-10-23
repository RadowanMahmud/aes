#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<cstring>
using namespace std;

void KeyExpansion(unsigned char* key,unsigned char* extendedKay){

}

void addRoundKey(){

}

void subBytes(){

}

void shiftRows(){

}

void mixColumns(){

}

void round(){
    subBytes();
    shiftRows();
    mixColumns();
}

void finalRound(){

}

void AESencrypt(unsigned char * message, unsigned char * expandedKey, unsigned char * encryptedMessage){

}
void inputFile(){
 
   ifstream ifile;
   ifile.open("a.txt");
}
int main()
{
        string message;

	cout << "Enter the message to encrypt: ";
	getline(cin,message);
	cout << message << endl;
	
	int msgLengthAfterPadding = message.size();
	

	if ((msgLengthAfterPadding % 16) != 0) {
		msgLengthAfterPadding = (msgLengthAfterPadding / 16 + 1) * 16;
	}
	
	unsigned char* paddedMessage = new unsigned char[msgLengthAfterPadding];
	for (int i = 0; i < msgLengthAfterPadding; i++) {
		if (i >= message.size()) {
			paddedMessage[i] = 0;
		}
		else {
			paddedMessage[i] = message[i];
		}
	}
	
	
	stringstream ss;
	for(int i=0; i<message.size(); ++i){
	       ss << hex << (int)message[i];
	}

	string mystr = ss.str();
	cout<<"msg in hex"<<" : "<<mystr<<endl;
	for(int i=0;i<message.size();i++){
	   cout<<mystr[i]<<endl;
	}
       	unsigned char * encryptedMessage = new unsigned char[msgLengthAfterPadding];
       	
       	
	string str;
	ifstream infile;
	infile.open("keyfile", ios::in | ios::binary);

	if (infile.is_open())
	{
		getline(infile, str);
		infile.close();
	}

	else cout << "Unable to open file";
	
	istringstream hex_chars_stream(str);
	unsigned char key[16];
	int i = 0;
	unsigned int c;
	while (hex_chars_stream >> hex >> c)
	{
		key[i] = c;
		i++;
	}
	
	
	unsigned char expandedKey[176];

	KeyExpansion(key, expandedKey);

	for (int i = 0; i < msgLengthAfterPadding; i += 16) {
		AESencrypt(paddedMessage+i, expandedKey, encryptedMessage+i);
	}
	
	cout << "Encrypted message in hex:" << endl;
	for (int i = 0; i < msgLengthAfterPadding; i++) {
		cout << hex << (int) encryptedMessage[i];
		cout << " ";
	}
	
	cout << endl;

	// Write the encrypted string out to file "message.aes"
	ofstream outfile;
	outfile.open("message.aes", ios::out | ios::binary);
	if (outfile.is_open())
	{
		outfile << encryptedMessage;
		outfile.close();
		cout << "Wrote encrypted message to file message.aes" << endl;
	}

	else cout << "Unable to open file";

	// Free memory
	delete[] paddedMessage;
	delete[] encryptedMessage;



	
  return 0;
}

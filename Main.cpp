#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

string key_gen(string text, string key)
{
	int x = text.size();

	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == text.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

string cipher(string text, string key)
{
	string cipher;

	for (int i = 0; i < text.size(); i++)
	{
		int x = (text[i] + key[i]) % 26;

		x += 'A';

		cipher.push_back(x);
	}
	return cipher;
}

string decrypt(string text, string key)
{
	string decrypted_text;

	for (int i = 0; i < text.size(); i++)
	{
		int x = (text[i] - key[i] + 26) % 26;

		x += 'A';
		decrypted_text.push_back(x);

	}
	return decrypted_text;
}

int main()
{
	string input;
	string key;
	int choice;

	cout << "The Vigenere Cipher 2000\n\n";
	
	do
	{
		cout << "1 - Encrypt\n";
		cout << "2 - Decrypt\n";
		cout << "3 - Exit\n";
		cin >> choice;
	
			if (choice == 1 || 2)
			{

				if (choice == 1 || 2) 
				{
					cout << "Enter a message to encrypt: ";
					cin >> input;

					cout << "Enter the key you would like to use: ";
					cin >> key;

					string keygen = key_gen(input, key);
					string encrypt = cipher(input, keygen);

					cout << "Encryption activated: " << encrypt << endl;
					cout << "Decrypted text: " << decrypt(encrypt, keygen) << endl;

					if (choice == 2)
					{
						cout << "Decrypted text: " << decrypt(encrypt, keygen) << endl;
					}
				}
			
			}
			
			

	} while (choice != 3);




	system("pause");
	return 0;
}

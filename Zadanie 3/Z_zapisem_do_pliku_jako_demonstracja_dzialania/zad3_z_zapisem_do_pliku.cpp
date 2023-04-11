#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string out (string napis)
{
    
    int dlugosc = napis.size();
    
    size_t pos = napis.find(" ");
	size_t next_pos = pos;
	
	while (pos < napis.size())
	{
	    while (napis[next_pos++] == ' ');
	    
	    napis.replace(pos, next_pos - pos - 1, "");

        pos = napis.size() - 1;
		if(napis[pos] == ' ')
		{
		    napis.replace(pos, 1, "");
		}
		
	}

    while(true)
    {
        pos = napis.size() - 1;
        if(napis[pos] == ' ')
        {
            napis.replace(pos, 1, "");
        }
        else {break;}

    }


    return napis;
}




int main()
{
    
    string napis;

    ofstream pout;
	pout.open("sprawdzenie.txt", ios::out);
    
    
    
    napis = "      przykładowy string ";
    cout << napis << endl;
    cout << out(napis) << endl;
    cout<<endl<<endl;

    pout << napis << endl;
    pout << out(napis) << endl << endl << endl;

    

    napis = "   .  jakiś    przykładowy string   ";
    cout << napis << endl;
    cout << out(napis) << endl;
    cout<<endl<<endl;

    pout << napis << endl;
    pout << out(napis) << endl << endl << endl;
    


    napis = "   --        --    przykładowy          string                .       ";
    cout << napis << endl;
    cout << out(napis) << endl;
    cout<<endl<<endl;

    pout << napis << endl;
    pout << out(napis) << endl << endl << endl;



    napis = "   --    123    --    przykładowy          string                .  12345,     ";
    cout << napis << endl;
    cout << out(napis) << endl;
    cout<<endl<<endl;

    pout << napis << endl;
    pout << out(napis) << endl << endl << endl;



    napis = "   --   jakiś     --    przykładowy          string                .     123,    .       -            ";
    cout << napis << endl;
    cout << out(napis) << endl;
    cout<<endl<<endl;
    
    pout << napis << endl;
    pout << out(napis) << endl << endl << endl;
    

    pout.close();

    return 0;
}
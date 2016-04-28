#include "airline.h"
#include "airport.h"
#include "route.h"
#include "dnode.h"

void getLine(string &line);

int main()
{
    map<string,string> airlines;
    map<string,airport> airports;
    createAirlines(airlines);
    createAirports(airports);
    createConnections(airports);

    string again;

    do
    {
        string origin, destination;
        cout<<"Please enter origin: ";
        getLine(origin);
        cout<<"Please enter destination: ";
        getLine(destination);


        vector<route> path = djikstra(origin, destination, airlines, airports);

        for (vector<route>::iterator it = path.begin(); it != path.end(); ++it)
        {
            airport a1 = airports.find(it->origin)->second, a2 = airports.find(it->destination)->second;
            vector<string> al = it->airline;
            sort(al.begin(), al.end());
            cout<<"Fly "<<it->distance<<" miles"<<endl<<"    from "<<it->origin<<" ("<<a1.name<<")\n    to "
               <<it->destination<<" ("<<a2.name<<")\n    on ";
            for (short i = 0; i < al.size(); ++i)
            {
                cout<<airlines.find(al.at(i))->second<<" or ";
                if ( i && !((i-2)%3) && i != (al.size() - 1))
                    cout<<"\n       ";
            }
            cout<<"\b\b\b\b.    \n";
//              <<al<<".\n";
        }

        cout<<"Calculate another path? ";
        getline (cin, again);
    }
    while (again.size() && toupper(again.at(0)) == 'Y');
    return 0;
}

void getLine(string &line)
{
    int pos = 0;
    getline(cin,line);
    for(int i = 0; i < line.size(); i++)
    {
        if(96<line[i]<123)
            line[i]-=32;
    }
    while((pos = line.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ "))<string::npos)
    {
        cout << "INVALID INPUT\n";
        exit(0);
    }
}

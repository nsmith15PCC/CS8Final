#include "airline.h"
#include "airport.h"
#include "route.h"
#include "dnode.h"

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
        getline (cin, origin);
        cout<<"Please enter destination: ";
        getline (cin, destination);


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
                if ( i && !((i-2)%3))
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

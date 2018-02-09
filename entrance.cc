#include "highway.h"

using namespace std;

Highway::Segment::Entrance::Entrance(unsigned int N): Node(N), RegularTolls(no_of_tolls), AutomatedTolls(no_of_auto_tolls)
{
    Toll* T;
    for(unsigned int i = 1; i <= RegularTolls+AutomatedTolls; i++)
    {
        it = Tolls.begin();
        if(i%2) T = new Toll(false, Node, Highway::max_K); /*Den einai ilektroniko to diodio*/
        else T = new Toll(true, Node, Highway::max_K); /*Einai ilektroniko to diodio*/
        it = Tolls.insert(it, T);
    }
    cout << "An Entrance has just been constructed!" << endl << endl;
}

Highway::Segment::Entrance::~Entrance()
{
    cout << "An Entrance is about to be destroyed!" << endl << endl;
    for(unsigned int i = 0; i < RegularTolls+AutomatedTolls; i++) { delete Tolls[i]; }
    Tolls.clear();
}

/*Me thn parakatw sunarthsh, afairountai oximata apo tin eisodo, afairwntas oximata apo ta diodia*/
vector<Vehicle*> Highway::Segment::Entrance::operate(unsigned int passing_vehicles)
{
    Vehicle* V;
    vector<Vehicle*> vehicles; vector<Vehicle*>::iterator it; 
    unsigned int i = 0, sum = 0, counter = 0;
    /*dyo endexomena: 1. symplirwthike i capacity tou tmimatos, 2.ola ta diodia exoun dwsei ta K/2K amaksia pou dikaiountai h exoun adeiasei*/
    while(counter < passing_vehicles  && sum < RegularTolls+AutomatedTolls)
    {   
        sum = 0; /*plithos diodiwn pou adynatoun na dwsoun pleon oximata*/
        for(i = 0; i < RegularTolls+AutomatedTolls; i++)
        {
            V = Tolls[i]->RemoveVehicleFromQueue(); /*Kathe fora kathe diodio dinei ena amaksi
            (kata auton ton tropo epitygxanetai omoiomorfo perasma twn oximatwn apo ta diodia)*/
            if(V == NULL)
            {
                sum++; /*2o endexomeno*/
                continue; /*otan to diodio exei dwsei osa amaxia mporei na dwsei*/
            }
            it = vehicles.begin();
            it = vehicles.insert(it, V);
            counter++;
            if (counter==passing_vehicles) break; /*1o endexomeno*/
        }
    }
            
    for(i = 0; i < RegularTolls+AutomatedTolls; i++)
    {
        Tolls[i]->change_K();
        Tolls[i]->AddVehiclesToQueue(Node); /*prostithentai tyxaia oxhmata sta diodia*/
    }
    return vehicles; /*to vector me ta oximata pou perasan ta diodia*/
}
        
unsigned int Highway::Segment::Entrance::VehiclesWaitingInTolls() const
{
    unsigned int sum = 0;
    for(unsigned int i = 0; i < RegularTolls+AutomatedTolls; i++) { sum += Tolls[i]->VehicleQueue.size(); }
    return sum; /*ta oximata pou perimenoun, synolika, na perasoun sta diodia*/
}
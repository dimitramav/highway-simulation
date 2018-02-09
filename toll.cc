#include "highway.h"

using namespace std;

Highway::Segment::Entrance::Toll::Toll(bool automated, unsigned int Enter_Node, unsigned int starting_K): IsAutomated(automated), K((automated)? 2*starting_K : starting_K), exit_from_tolls(0) 
{
    Vehicle* V;
    for(unsigned int i = 1; i <= new_vehicles_in_tolls; i++)
    {
        V = new Vehicle(Highway::NSegs, -1, Enter_Node);
        VehicleQueue.push(V);
    }
    cout << "A Toll has just been constructed!" << endl << endl;
}

Highway::Segment::Entrance::Toll::~Toll()
{
    cout << "A Toll is about to be destroyed!" << endl;
    Vehicle* V;
    while(!VehicleQueue.empty())
    {
        V = VehicleQueue.front();
        delete V;
        VehicleQueue.pop();
    }
    cout << endl;
}  
      
void Highway::Segment::Entrance::Toll::AddVehiclesToQueue(int Enter_Node)
{
    Vehicle* V;
    for(unsigned int i = 1; i <= new_vehicles_in_tolls; i++)
    {
        V = new Vehicle(Highway::NSegs, -1, Enter_Node);
        VehicleQueue.push(V);
    }
}   
     
Vehicle* Highway::Segment::Entrance::Toll::RemoveVehicleFromQueue()
{
    Vehicle* V;
    if(exit_from_tolls < K && VehicleQueue.size() > 0)
    {
        V = VehicleQueue.front();
        VehicleQueue.pop();
        exit_from_tolls++;
        return V;
    }
    else return NULL;
    /*synthikes termatismou: 1) ta oximata pou perasan einai osa to K 
    2)den yparxoun tosa oximata oso to K kai ara adeiase i oura*/  
}
        
void Highway::Segment::Entrance::Toll::change_K()
{
    if(exit_from_tolls < K)
    {
        K--;
        if(IsAutomated) K--;
    }
    else
    {
        K++;
        if(IsAutomated) K++;
    }
    exit_from_tolls = 0; /*telos kyklou -> midenismos twn oximatwn
    pou perasan apo ta diodia gia xrisi tou counter, ston epomeno kyklo*/
}
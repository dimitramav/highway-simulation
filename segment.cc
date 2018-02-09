#include "highway.h"

using namespace std;

Highway::Segment::Segment(unsigned int C, unsigned int S):Entry(S), Seg(S), Capacity(C), NoOfVehicles(new_vehicles_in_segments%(Capacity%5+1)+1)
{
    Vehicle* V;
    for(unsigned int i = 1; i <= NoOfVehicles; i++)
    {
        it = Vehicles.begin();
        V = new Vehicle(Highway::NSegs, Seg);
        it = Vehicles.insert(it, V); /*kataskevazetai o vector, me tous deiktes se vehicles*/
    }
    cout << "Segment has just been constructed!" << endl << endl;
}
        
Highway::Segment::~Segment()
{
    cout << "A Segment is about to be destroyed!" << endl << endl;
    for(unsigned int i = 0; i < NoOfVehicles; i++) { delete Vehicles[i]; }
    Vehicles.clear();
    cout << endl;
}

/*me thn parakatw sunarthsh, eiserxontai sto tmhma, ta oxhmata
pou einai dynato, apo ta diodia kai apo to prohgoumeno tmima*/
unsigned int Highway::Segment::enter(vector<Vehicle*> vec_lastseg)
{
    Vehicles.insert(Vehicles.end(), vec_lastseg.begin(), vec_lastseg.end()); /*prostithentai sto tmima ta amaksia apo to proigoumeno tmima*/
    NoOfVehicles = NoOfVehicles + vec_lastseg.size();
    if(NoOfVehicles < Capacity) /*an yparxei diathesimotita, tha prostethoun oximata sto tmima mesw twn diodiwn tis eisodou*/
    {
        vector<Vehicle*> vec_entrance = Entry.operate(Capacity - NoOfVehicles);
        NoOfVehicles = NoOfVehicles + vec_entrance.size();
        Vehicles.insert(Vehicles.end(), vec_entrance.begin(), vec_entrance.end());
        return vec_entrance.size(); /*epistrefei ton arithmo twn oximatwn pou mpikan apo tin eisodo sto tmima*/
    }
    else return 0;
}

/*h parakatw sunarthsh, frontizei wste to oxhma
na ekserxetai, otan ftasei ston komvo exodou tou*/
void Highway::Segment::exit()
{
    for(unsigned int i = 0; i < NoOfVehicles; i++)
     if(Vehicles[i]->IsReady() && (Vehicles[i]->ExitNode() == Vehicles[i]->get_route()+1))
     {
         delete Vehicles[i]; /*to oxhma katastrefetai otan vgei apo to highway*/
         Vehicles.erase(Vehicles.begin()+i);
         NoOfVehicles--; i--;
     } 
}
        
vector<Vehicle*> Highway::Segment::pass(Segment* next)
{
    Vehicle* V;
    vector<Vehicle*> passing_vehicles; vector<Vehicle*>::iterator t;
    unsigned int counter = next->get_no_of_vehicles();
    for(unsigned int i = 0; i < NoOfVehicles; i++)
     if(Vehicles[i]->IsReady() && (Vehicles[i]->ExitNode() != Vehicles[i]->get_route()+1) && counter < next->get_capacity())
     {
         V = Vehicles[i];
         V->not_ready(); /*to oti einai to oxhma etoimo sto parwn tmhma, den simainei oti tha einai etoimo kai sto epomeno*/
         V->move_vehicle(); /*metakinhsh oxhmatos, sto epomeno tmhma*/

         it = passing_vehicles.begin();
         it = passing_vehicles.insert(it, V);
         counter++; /*episis prepei osa oximata pernoun se epomeno tmhma, na afairountai apo to plithos kai to vector tou tmimatos autou*/
         Vehicles.erase(Vehicles.begin()+i);
         NoOfVehicles--; i--;
     }
     return passing_vehicles;
}
        
void Highway::Segment::operate(Segment* previous)
{
    vector<Vehicle*> passing_vehicles;
    unsigned int entering_vehicles, waiting_vehicles, moving_to_nextSeg = 0, ready_to_move = 0;
    if(Seg != 0)
    {
        exit(); /*apagorevetai i eksodos ston prwto komvo*/
        for(unsigned int i = 0; i < previous->get_no_of_vehicles(); i++) { if(previous->Vehicles[i]->IsReady()) ready_to_move++; }
        /*ready_to_move: plithos oximatwn tou proigoumenou tmimatos pou einai etoima na kinithoun*/
        passing_vehicles = previous->pass(this); /*kata auton ton tropo xanoume enan kyklo prosomoiwsis,
        (afou stin arxi ola ta oximata einai by default unready) kati pou symvainei kai stin pragmatikotita
        afou ta amaxia prepei na dianysoun kapoia apostasi gia na einai etoima na vgoun*/
        moving_to_nextSeg = passing_vehicles.size(); /*to plithos twn oximatwn pou metakinountai metaksy twn tmimatwn pou syndeontai*/
    }

    waiting_vehicles = Entry.VehiclesWaitingInTolls(); /*ta oximata pou perimenoun sta diodia*/
    entering_vehicles = enter(passing_vehicles); /*ta oximata pou perasan apo ta diodia sto tmima
    (apagorevetai i eisodos oxhmatwn apo diodia ston teleutaio komvo), i enter kalei tin operate tis entrance i opoia
    vazei nea oximata se kathe diodio. Wstoso den mas epireazei epeidi auto aksiopoieitai ston epomeno kyklo*/
    waiting_vehicles -= entering_vehicles; /*plithos oximatwn pou apemeinan sta diodia*/
    /*1o bullet*/
    if(entering_vehicles < waiting_vehicles)
    {
        cout << "Kathusterhseis sthn eisodo tou komvou " << Seg << "!" << endl;
        /*2o bullet*/
        if(Seg != 0 && moving_to_nextSeg < ready_to_move) cout << "Kathusterhseis meta ton komvo " << Seg << "!" << endl << endl;
        else cout << endl;
    }
    else cout << "Threite tis apostaseis asfaleias sto tmima meta ton komvo " << Seg << "!" << endl << endl;
    if(Highway::Percent <= 1.0) /*pososto oximatwn pou metavainoun se katastasi etoimothtas*/
    {
        unsigned int about_to_be_ready = NoOfVehicles*Highway::Percent; /*to apotelesma einai integer*/
        for(unsigned int i = 0; i < about_to_be_ready; i++) Vehicles[i]->ready();
    }        
}
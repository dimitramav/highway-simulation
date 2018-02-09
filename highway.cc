#include "highway.h"

using namespace std;

Highway::Highway()
{
    unsigned int Capacity;
    for(unsigned int i = 0; i < NSegs; i++)
    {
        cout << "=============================" << endl;
        cout << "Enter Capacity of Segment " << i << ": " << endl;
        cin >> Capacity;
        add_seg(Capacity,i);
        cout << endl;
    }
    cout << "==============================" << endl << "Highway in use" << endl << "==============================" << endl << endl << endl;
}

Highway::~Highway()
{
    cout << "Highway is about to be destroyed!" << endl << endl << endl;
    for(list<Segment*>::iterator i = segs.begin(); i != segs.end(); i++)
    {
        delete (*i);
        cout << "====================================" << endl;
    }
    segs.clear();
}

void Highway::operate()
{
    list<Segment*>::reverse_iterator c;
    for(list<Segment*>::reverse_iterator i = segs.rbegin(); i != segs.rend(); i++) /*reverse traversal*/
    {
        c = i;
        c++;
        (*i)->operate(*c); /*h operate efarmozetai sto trexon seg kai pairnei san orisma to proigoumeno*/
    }        
    cout << "Total number of vehicles in the highway " << get_num_of_vehicles() << endl;
    cout << "==============================================" << endl << endl;
}

void Highway::add_seg(unsigned int Capacity,unsigned int Seg)
{
    Segment* temp = new Segment(Capacity,Seg);
    segs.push_back(temp);
}

/*parakatw, exoume synartisi num_of_vehicles kai oxi data member, giati to synoliko plithos
twn oximatwn metalavaletai synexws kai einai asfalestero na to ypologizoume, mono opote to xreiazomaste*/
unsigned int Highway::get_num_of_vehicles()
{
    unsigned int num_of_vehicles = 0;
    for(list<Segment*>::iterator i = segs.begin(); i != segs.end(); i++) num_of_vehicles += (*i)->get_no_of_vehicles();
    return num_of_vehicles;
}